#include <stdlib.h>
#include "geometry.h"
#include "../framebuffer.h"
#include "tiny.h"

mat4 TinyModelView;
mat4 TinyProjection;

static mat4 Viewport;

void tiny_viewport(const int x, const int y, const int w, const int h) {
  Viewport = (mat4){{w/2., 0, 0, x+w/2.}, {0, h/2., 0, y+h/2.}, {0,0,1,0}, {0,0,0,1}};
}

void tiny_projection(const double f) { // check https://en.wikipedia.org/wiki/Camera_matrix
  TinyProjection = (mat4){{1,0,0,0}, {0,-1,0,0}, {0,0,1,0}, {0,0,-1/f,0}};
}

// check https://github.com/ssloy/tinyrenderer/wiki/Lesson-5-Moving-the-camera
void tiny_lookat(const vec3 eye, const vec3 center, const vec3 up) {
  vec3 z = vec3_normalized (vec3_sub (center, eye));
  vec3 x = vec3_normalized (cross(up, z));
  vec3 y = vec3_normalized (cross(z, x));
  mat4 Minv = (mat4){{x.x,x.y,x.z,0},   {y.x,y.y,y.z,0},   {z.x,z.y,z.z,0},   {0,0,0,1}};
  mat4 Tr   = (mat4){{1,0,0,-eye.x}, {0,1,0,-eye.y}, {0,0,1,-eye.z}, {0,0,0,1}};
  TinyModelView = mat4_mul4 (Minv, Tr);
}

vec3 tiny_barycentric(const vec2 tri[3], const vec2 P) {
  mat3 ABC = {vec3_embed(tri[0]), vec3_embed(tri[1]), vec3_embed(tri[2])};
  // for a degenerate triangle generate negative coordinates, it will
  // be thrown away by the rasterizator
  if (mat3_det(ABC) < 1e-3) return (vec3){-1,1,1};
  return mat3_mul (mat3_invert_transpose(ABC), vec3_embed(P));
}

/**
## Framebuffer */

struct _framebuffer {
  unsigned char * image;
  int width, height;
  double * zbuffer;
};

void framebuffer_destroy (framebuffer * p) {
  free (p->image);
  free (p->zbuffer);
  free (p);
}

framebuffer * framebuffer_new (unsigned width, unsigned height)
{
  framebuffer * f = (framebuffer *) malloc (sizeof (framebuffer));
  f->image = (unsigned char *) calloc (width*height*4, sizeof (unsigned char));
  f->width = width, f->height = height;
  f->zbuffer = (double *) malloc (width*height*sizeof (double));
  double * p = f->zbuffer;
  for (unsigned int i = 0; i < width*height; i++, p++)
    *p = 1e100;
  return f;
}

unsigned char * framebuffer_image (framebuffer * p) {
  return p->image;
}

fbdepth_t * framebuffer_depth (framebuffer * p) {
  return NULL;
}

static inline
void framebuffer_set_depth (framebuffer * f, int x, int y, const Color color, double frag_depth)
{
  if (x < 0 || x >= f->width || y < 0 || y >= f->height) return;
  unsigned char * c = f->image + 4*(x + y*f->width);
  for (int i = 0; i < 4; i++)
    c[i] = color[i];
  f->zbuffer[x + y*f->width] = frag_depth;
}

/**
## Primitives */

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

void tiny_triangle (const vec4 clip_verts[3], const void * shader, const TinyShader fragment,
		    framebuffer * image)
{
  vec4 pts[3] = {
    mat4_mul (Viewport, clip_verts[0]),
    mat4_mul (Viewport, clip_verts[1]),
    mat4_mul (Viewport, clip_verts[2])
  };  // triangle screen coordinates before persp. division
  vec2 pts2[3] = {
    vec4_proj2(vec4_div (pts[0], pts[0].t)),
    vec4_proj2(vec4_div (pts[1], pts[1].t)),
    vec4_proj2(vec4_div (pts[2], pts[2].t))
  };  // triangle screen coordinates after  perps. division

  int bboxmin[2] = {image->width-1, image->height-1};
  int bboxmax[2] = {0, 0};
  for (int i=0; i<3; i++) {
    bboxmin[0] = min(bboxmin[0], pts2[i].x);
    bboxmax[0] = max(bboxmax[0], pts2[i].x);
    bboxmin[1] = min(bboxmin[1], pts2[i].y);
    bboxmax[1] = max(bboxmax[1], pts2[i].y);
  }
  // #pragma omp parallel for
  for (int x=max(bboxmin[0], 0); x<=min(bboxmax[0], image->width-1); x++)
    for (int y=max(bboxmin[1], 0); y<=min(bboxmax[1], image->height-1); y++) {
      vec3 bc_screen = tiny_barycentric(pts2, (vec2){x, y});
      vec3 bc_clip   = {bc_screen.x/pts[0].t, bc_screen.y/pts[1].t, bc_screen.z/pts[2].t};
      // check https://github.com/ssloy/tinyrenderer/wiki/Technical-difficulties-linear-interpolation-with-perspective-deformations
      bc_clip = vec3_div (bc_clip, bc_clip.x+bc_clip.y+bc_clip.z);
      double frag_depth = vec3_scalar ((vec3){clip_verts[0].z, clip_verts[1].z, clip_verts[2].z}, bc_clip);
      if (bc_screen.x<0 || bc_screen.y<0 || bc_screen.z<0 || frag_depth > image->zbuffer[x+y*image->width]) continue;
      Color color;
      if (fragment (shader, bc_clip, color)) continue; // fragment shader can discard current fragment
      framebuffer_set_depth (image, x, y, color, frag_depth);
    }
}

void tiny_line (const vec4 clip_verts0, const vec4 clip_verts1, const Color color, float thickness,
		framebuffer * image)
{	  
  vec4 pts[2]  = {
    mat4_mul (Viewport, clip_verts0),
    mat4_mul (Viewport, clip_verts1)
  };  // line screen coordinates before persp. division
  vec2 pts2[2] = {
    vec4_proj2 (vec4_div (pts[0], pts[0].t)),
    vec4_proj2 (vec4_div (pts[1], pts[1].t))
  };  // line screen coordinates after  perps. division
  int x0 = pts2[0].x, y0 = pts2[0].y, x1 = pts2[1].x, y1 = pts2[1].y;
  if (x1 == x0 && y1 == y0) return;
  double z0 = clip_verts0.z, z1 = clip_verts1.z;
  // from: http://members.chello.at/~easyfilter/bresenham.html
  int dx = abs(x1-x0), sx = x0 < x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0 < y1 ? 1 : -1;
  int err = dx-dy, e2, x2, y2;                          /* error value e_xy */
  float ed = dx+dy == 0 ? 1 : sqrt((float)dx*dx+(float)dy*dy);
  int x = x0, y = y0;
  for (thickness = (thickness+1)/2; ; ) {                                   /* pixel loop */
    double frag_depth = (abs(x1 - x0) > abs(y1 - y0) ?
			 (z0 + (x - x0)*(z1 - z0)/(double)(x1 - x0)) :
			 (z0 + (y - y0)*(z1 - z0)/(double)(y1 - y0))) - 0.01;
    int draw = frag_depth < image->zbuffer[x+y*image->width];
    if (draw)
      framebuffer_set_depth (image, x, y, color, frag_depth);
    //      setPixelColor(x,y,max(0,255*(abs(err-dx+dy)/ed-thickness+1))); // antialiasing
    e2 = err; x2 = x;
    if (2*e2 >= -dx) {                                           /* x step */
      if (draw)
	for (e2 += dy, y2 = y; e2 < ed*thickness && (y1 != y2 || dx > dy); e2 += dx)
	  framebuffer_set_depth (image, x, y2 += sy, color, frag_depth);
      // setPixelColor(x, y2 += sy, max(0,255*(abs(e2)/ed-thickness+1)));
      if (x == x1) break;
      e2 = err; err -= dy; x += sx; 
    } 
    if (2*e2 <= dy) {                                            /* y step */
      if (draw)
	for (e2 = dx-e2; e2 < ed*thickness && (x1 != x2 || dx < dy); e2 += dy)
	  framebuffer_set_depth (image, x2 += sx, y, color, frag_depth);
      // setPixelColor(x2 += sx, y, max(0,255*(abs(e2)/ed-thickness+1))); // antialising
      if (y == y1) break;
      err += dx; y += sy; 
    }
  }
}
