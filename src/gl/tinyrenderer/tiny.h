typedef unsigned char Color[4];

extern mat4 TinyModelView, TinyProjection; // "OpenGL" state matrices

void tiny_viewport (const int x, const int y, const int w, const int h);
void tiny_projection (const double coeff); // coeff = -1/c
void tiny_lookat (const vec3 eye, const vec3 center, const vec3 up);

typedef int (* TinyShader) (const void * shader, const vec3 bar, Color color);

void tiny_triangle (const vec4 clip_verts[3],
		    const void * shader, const TinyShader fragment,
		    framebuffer * image);
void tiny_line (const vec4 clip_verts0, const vec4 clip_verts1,
		const Color color, float thickness,
		framebuffer * image);
