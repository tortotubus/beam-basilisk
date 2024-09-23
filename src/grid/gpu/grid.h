/**
# Grids on GPUs

## Useful commands

~~~bash
nvidia-settings
sudo lshw -c display
__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia  glxinfo -B | \
   grep "OpenGL vendor string"
~~~

## Tips etc.

* gpu/cpu keyword
* if 'gpu' is specified and the loop cannot run on the GPU, the code exits
* type casts in GLSL i.e. (int)... etc.
* boolean type casts i.e.   float a = (b > 0);  ... if (a) ...
* no pointers....
* local scalar lists are not really supported, but external lists are OK

GLSL: error: if-statement condition must be scalar boolean

GLSL: error: value of type float cannot be assigned to variable of type int

((coord){0}} # need 3 components

GLSL: error: too few components to construct `vec3'
*/

#include <khash.h>

typedef struct {
  GLuint id;
} Shader;

KHASH_MAP_INIT_INT(INT, Shader *)
  
typedef struct {
  GRIDPARENT parent;
  Boundary ** boundaries;
  GLuint reduct[2], ng[2], nwg[2];
  khash_t(INT) * shaders;
} GridGPU;

#define gpu_grid ((GridGPU *)grid)
  
static char * str_append_array (char * dst, const char * list[])
{
  int empty = (dst == NULL);
  int len = empty ? 0 : strlen (dst);
  for (const char ** s = list; *s != NULL; s++)
    len += strlen (*s);
  dst = (char *) sysrealloc (dst, len + 1);
  if (empty) dst[0] = '\0';
  for (const char ** s = list; *s != NULL; s++)
    strcat (dst, *s);
  return dst;
}

#define str_append(dst, ...) str_append_array (dst, (const char *[]){__VA_ARGS__, NULL})
#define xstr(a) str(a)
#define str(a) #a

static char glsl_preproc[] =
  "// #line " xstr(__LINE__) " \"" __FILE__ "\"\n"
  "#define dimensional(x)\n"
  "#define real float\n"
  "#define coord vec3\n"
  "#define ivec ivec2\n"
  "struct scalar { int i, index; };\n"
#if dimension == 2
  "#define _coord vec2\n"
  "struct vector { scalar x, y; };\n"
  "struct tensor { vector x, y; };\n"
#endif
  "#define GHOSTS " xstr(GHOSTS) "\n"
  "struct Point { int i, j; uint level;"
#if LAYERS
  " int l;"
#endif
  "};\n"
  "#define field_size() _field_size\n"
  "#define ast_pointer(x) (x)\n"
  
  GPU_CODE()
  
  "#define _NVARMAX 65536\n"
  "#define NULL 0\n"
  "#define val(s,k,l,m) ((s).i < _NVARMAX ? valt(s,k,l,m)"
  " : _constant[clamp((s).i -_NVARMAX,0,_nconst-1)])\n"
  "#define val_out_(s,i,j,k) valt(s,i,j,k)\n"
  "#define _attr(s,member) (_attr[(s).index].member)\n"
  "#define forin(type,s,list) for (int _i = 0; _i < list.length() - 1; _i++) { type s = list[_i];\n"
  "#define endforin() }\n"
#if LAYERS
  "#define foreach_block_inner() for (point.l = 0; point.l < nl; point.l++)\n"
  "#define end_foreach_block_inner() point.l = 0;\n"
#endif
  "#define forin2(a,b,c,d) for (int _i = 0; _i < c.length() - 1; _i++)"
  "  { a = c[_i]; b = d[_i];\n"
  "#define endforin2() }\n"
  "#define forin3(a,b,e,c,d,f) for (int _i = 0; _i < c.length() - 1; _i++)"
  "  { a = c[_i]; b = d[_i]; e = f[_i];\n"
  "#define endforin3() }\n"
  "#define is_face_x() { if (point.j < N + GHOSTS) {"
  "  real Delta = L0/N, Delta_x = Delta, Delta_y = Delta,"
  "  x = X0 + (point.i - GHOSTS)*Delta, y = Y0 + (point.j - GHOSTS + 0.5)*Delta;\n"
  "#define end_is_face_x() }}\n"
  "#define is_face_y() { if (point.i < N + GHOSTS) {"
  "  real Delta = L0/N, Delta_x = Delta, Delta_y = Delta,"
  "  x = X0 + (point.i - GHOSTS + 0.5)*Delta, y = Y0 + (point.j - GHOSTS)*Delta;\n"
  "#define end_is_face_y() }}\n"
  "#define NOT_UNUSED(x)\n"
  "#define pi 3.14159265359\n"
  "#define nodata (1e30)\n"
  "#define sq(x) ((x)*(x))\n"
  "#define cube(x) ((x)*(x)*(x))\n"
  "#define fabs(x) abs(x)\n"
  "#define _dirichlet(expr,p,n,_s,data)                  (2.*(expr) - val(_s,0,0,0))\n"
  "#define _dirichlet_homogeneous(expr,p,n,_s,data)      (- val(_s,0,0,0))\n"
  "#define _dirichlet_face(expr,p,n,_s,data)             (expr)\n"
  "#define _dirichlet_face_homogeneous(expr,p,n,_s,data) (0.)\n"
  "#define _neumann(expr,p,n,_s,data)               (Delta*(expr) + val(_s,0,0,0))\n"
  "#define _neumann_homogeneous(expr,p,n,_s,data)   (val(_s,0,0,0))\n"
  "const real z = 0.;\n"
  "const int ig = 0, jg = 0;\n"
  "layout (location = 0) uniform ivec2 csOrigin = ivec2(0,0);\n"
  "layout (location = 1) uniform vec2 vsOrigin = vec2(0.,0.);\n"
  "layout (location = 2) uniform vec2 vsScale = vec2(1.,1.);\n"
  ;

static inline int list_size (const External * i)
{
  int size = 0;
  if (!strcmp (i->type, "scalar")) {
    size = 1;
    if (i->nd == 1)
      for (scalar s in i->pointer) size++;
  }
  else if (!strcmp (i->type, "vector")) {
    size = 1;
    if (i->nd == 1)
      for (vector v in i->pointer) size++;
  }
  else if (!strcmp (i->type, "tensor")) {
    size = 1;
    if (i->nd == 1)
      for (tensor t in i->pointer) size++;
  }
  else
    return 0;
  return size;
}

static char * write_scalar (char * fs, scalar s)
{
  char i[20], index[20];
  snprintf (i, 19, "%d", s.i);
  snprintf (index, 19, "%d", s.i < 0 || is_constant(s) ? 0 : s.gpu.index - 1);
  return str_append (fs, "{", i, ",", index, "}");
}

static char * write_vector (char * fs, vector v)
{
  fs = str_append (fs, "{");
  fs = write_scalar (fs, v.x);
  fs = str_append (fs, ",");
  fs = write_scalar (fs, v.y);
  fs = str_append (fs, "}");
  return fs;
}

static char * write_tensor (char * fs, tensor t)
{
  fs = str_append (fs, "{");
  fs = write_vector (fs, t.x);
  fs = str_append (fs, ",");
  fs = write_vector (fs, t.y);
  fs = str_append (fs, "}");
  return fs;
}

static scalar * apply_bc_list;

static int bc_period_x = -1, bc_period_y = -1;

static
void apply_bc (Point point)
{
  if (point.i == GHOSTS) { // left
    Point neighbor = point;
    bool data;
    point.i += bc_period_x;
    for (scalar s in apply_bc_list) {
      scalar b = (s.v.x.i < 0 ? s : s.i == s.v.x.i ? s.v.x : s.v.y);
      s[] = b.boundary_left (neighbor, point, s, &data);
    }
    if (point.j == GHOSTS) { // bottom-left corner
      point.j += bc_period_y, neighbor.i += bc_period_x;
      for (scalar s in apply_bc_list) {
	scalar b = (s.v.x.i < 0 ? s : s.i == s.v.y.i ? s.v.x : s.v.y);
	s[] = b.boundary_bottom (neighbor, point, s, &data);
      }
      point.j -= bc_period_y, neighbor.i -= bc_period_x;
    }
    if (point.j == N + GHOSTS - 1) { // top-left corner
      point.j -= bc_period_y, neighbor.i += bc_period_x;
      for (scalar s in apply_bc_list) {
	scalar b = (s.v.x.i < 0 ? s : s.i == s.v.y.i ? s.v.x : s.v.y);
	s[] = b.boundary_top (neighbor, point, s, &data);
      }
      point.j += bc_period_y, neighbor.i -= bc_period_x;
    }
    point.i -= bc_period_x;
  }
  if (point.i == N + GHOSTS - 1) { // right
    Point neighbor = point;
    bool data;
    point.i -= bc_period_x;
    for (scalar s in apply_bc_list)
      if (s.face == 0 || s.i != s.v.x.i) { // fixme: bool(!s.face) not correct
	scalar b = (s.v.x.i < 0 ? s : s.i == s.v.x.i ? s.v.x : s.v.y);
	s[] = b.boundary_right (neighbor, point, s, &data);
      }
    if (point.j == GHOSTS) { // bottom-right corner
      point.j += bc_period_y, neighbor.i -= bc_period_x;
      for (scalar s in apply_bc_list) {
	scalar b = (s.v.x.i < 0 ? s : s.i == s.v.y.i ? s.v.x : s.v.y);
	s[] = b.boundary_bottom (neighbor, point, s, &data);
      }
      point.j -= bc_period_y, neighbor.i += bc_period_x;
    }
    if (point.j == N + GHOSTS - 1) { // top-right corner
      point.j -= bc_period_y, neighbor.i -= bc_period_x;
      for (scalar s in apply_bc_list) {
	scalar b = (s.v.x.i < 0 ? s : s.i == s.v.y.i ? s.v.x : s.v.y);
	s[] = b.boundary_top (neighbor, point, s, &data);
      }
      point.j += bc_period_y, neighbor.i += bc_period_x;
    }
    point.i += bc_period_x;
  }
  if (point.j == GHOSTS) { // bottom
    Point neighbor = point;
    bool data;
    point.j += bc_period_y;
    for (scalar s in apply_bc_list) {
      scalar b = (s.v.x.i < 0 ? s : s.i == s.v.y.i ? s.v.x : s.v.y);
      s[] = b.boundary_bottom (neighbor, point, s, &data);
    }
    point.j -= bc_period_y;
  }
  if (point.j == N + GHOSTS - 1) { // top
    Point neighbor = point;
    bool data;
    point.j -= bc_period_y;
    for (scalar s in apply_bc_list)
      if (s.face == 0 || s.i != s.v.y.i) { // fixme: bool(!s.face) not correct
	scalar b = (s.v.x.i < 0 ? s : s.i == s.v.y.i ? s.v.x : s.v.y);	
	s[] = b.boundary_top (neighbor, point, s, &data);
      }
    point.j += bc_period_y;
  }
}

static External * append_external (External * externals, External ** end, External * g)
{
  if (externals)
    (*end)->next = g;
  else
    externals = g;
  *end = g;
  (*end)->next = NULL;
  return externals;
}

static External * merge_external (External * externals, External ** end, External * g,
				  const ForeachData * loop)
{
  if (!strcmp (g->type, "*func()") || !strcmp (g->type, "func()"))
    for (scalar s in baseblock)
      if (g->name[0] != '.' || s.gpu.index) {
	void * ptr = g->name[0] != '.' ? g->pointer :
	  *((void **)(((char *) &_attribute[s.i]) + g->nd));
	if (ptr) {
	  External * p = _get_function ((long) ptr);
	  if (!p) {
	    fprintf (stderr, "%s:%d: GLSL: error: unregistered function pointer '%s'\n",
		     loop->fname, loop->line, g->name);
	    return NULL;
	  }
	  if (!p->used) {
	    p->used = true;
	    for (External * i = p->externals; i && i->name; i++)
	      externals = merge_external (externals, end, i, loop);
	    externals = append_external (externals, end, p);
	  }
	}
	if (g->name[0] != '.')
	    break;
      }

  for (External * i = externals; i; i = i->next)
    if (!strcmp (i->name, g->name))
      return externals;

  return append_external (externals, end, g);
}

trace
static External * merge_externals (External * externals, const ForeachData * loop)
{
  External * merged = NULL, * end = NULL;
  static External ext[] = {
    { .name = "X0", .type = "double", .pointer = &X0 },
    { .name = "Y0", .type = "double", .pointer = &Y0 },
    { .name = "Z0", .type = "double", .pointer = &Z0 },
    { .name = "L0", .type = "double", .pointer = &L0 },
    { .name = "N",  .type = "int",    .pointer = &N },
    { .name = "apply_bc_list", .type="scalar", .nd = 1},
    { .name = "apply_bc",      .type = "func()", .pointer = (void *)(long)apply_bc},
    { .name = NULL }
  };

  assert (!strcmp (ext[5].name, "apply_bc_list"));
  ext[5].pointer = loop->dirty;
  for (scalar s in ext[5].pointer) {
    s.boundary_left   = s.boundary[left];
    s.boundary_right  = s.boundary[right];
    s.boundary_top    = s.boundary[top];
    s.boundary_bottom = s.boundary[bottom];
  }

  for (External * g = externals; g->name; g++)
    g->used = false;
  foreach_function (f, f->used = false);
  for (External * g = ext; g->name; g++) {
    g->used = false;
    merged = merge_external (merged, &end, g, loop);
  }
#if LAYERS
  assert (nl == 1); // fixme: not implemented yet for more than one layer
  static External enl =  { .name = "nl",  .type = "int", .pointer = &nl };
  merged = merge_external (merged, &end, &enl, loop);
#endif
  for (External * g = externals; g->name; g++)
    merged = merge_external (merged, &end, g, loop);
#if PRINTEXTERNAL  
  for (External * i = merged; i; i = i->next)
    fprintf (stderr, "external %s %s %p\n", i->name, i->type, i->pointer);
#endif
  return merged;
}

#if 0
typedef struct {
  uint32_t s1, s2;
} Adler32Hash;

static
inline void a32_hash_init (Adler32Hash * hash)
{
  hash->s1 = 1;
  hash->s2 = 0;
}

static
inline void a32_hash_add_char (Adler32Hash * hash, uint8_t c)
{
  hash->s1 = (hash->s1 + c) % 65521;
  hash->s2 = (hash->s2 + hash->s1) % 65521;
}

static
inline void a32_hash_add (Adler32Hash * hash, const void * data, size_t size)
{
  const uint8_t * buffer = (const uint8_t*) data;
  for (size_t n = 0; n < size; n++, buffer++)
    a32_hash_add_char (hash, *buffer);
}

static
inline uint32_t a32_hash (const Adler32Hash * hash)
{
  return (hash->s2 << 16) | hash->s1;
}
#else // SDBM
typedef struct {
  uint32_t s;
} Adler32Hash;

static
inline void a32_hash_init (Adler32Hash * hash)
{
  hash->s = 0;
}

static
inline void a32_hash_add (Adler32Hash * hash, const void * data, size_t size)
{
  const uint8_t * buffer = (const uint8_t*) data;
  for (size_t n = 0; n < size; n++, buffer++)
    hash->s = *buffer + (hash->s << 6) + (hash->s << 16) - hash->s;
}

static
inline uint32_t a32_hash (const Adler32Hash * hash)
{
  return hash->s;
}
#endif

trace
uint32_t hash_shader (const External * externals, const ForeachData * loop,
		      const RegionParameters * region, const char * kernel)
{
  Adler32Hash hash;
  a32_hash_init (&hash);
  a32_hash_add (&hash, &region->level, sizeof (region->level));
  a32_hash_add (&hash, &N, sizeof (N));
  a32_hash_add (&hash, &Period, sizeof (Period));
  a32_hash_add (&hash, kernel, strlen (kernel));
  a32_hash_add (&hash, &nconst, sizeof (nconst));
  a32_hash_add (&hash, _constant, sizeof (*_constant)*nconst);
  for (const External * g = externals; g; g = g->next) {
    if (!strcmp (g->name, "nl") && !strcmp (g->type, "int"))
      a32_hash_add (&hash, g->pointer, sizeof (int));
    else if (!strcmp (g->type, "scalar") ||
	     !strcmp (g->type, "vector") ||
	     !strcmp (g->type, "tensor")) {
      // scalar, vector and tensor fields
      int size = list_size (g);
      a32_hash_add (&hash, &size, sizeof (size));
      for (int j = 0; j < size; j++)
	if (g->nd == 0 || j < size - 1) {
	  if (!strcmp (g->type, "scalar")) {
	    scalar s = ((scalar *)g->pointer)[j];
	    a32_hash_add (&hash, &s.i, sizeof (s.i));
	  }
	  else if (!strcmp (g->type, "vector")) {
	    vector v = ((vector *)g->pointer)[j];
	    for (scalar s in {v})
	      a32_hash_add (&hash, &s.i, sizeof (s.i));
	  }
	  else if (!strcmp (g->type, "tensor")) {
	    tensor t = ((tensor *)g->pointer)[j];
	    for (scalar s in {t})
	      a32_hash_add (&hash, &s.i, sizeof (s.i));
	  }
	  else
	    assert (false);
	}
    }
  }
  return a32_hash (&hash);
}

trace
char * build_shader (External * externals, const ForeachData * loop,
		     const RegionParameters * region)
{
  int Nl = region->level > 0 ? 1 << (region->level - 1) : N;
  char s[20];
  snprintf (s, 19, "%d", nconst > 0 ? nconst : 1);
  char a[20];
  snprintf (a, 19, "%g", nconst > 0 ? _constant[0] : 0);
  char * fs = str_append (NULL, "#version 430\n", glsl_preproc,
			  "#define VARIABLES real Delta = L0/N,"
			  " Delta_x = Delta, Delta_y = Delta,",
			  " x = X0 + (point.i - GHOSTS + 0.5 + ig/2.)*Delta,"
			  " y = Y0 + (point.j - GHOSTS + 0.5 + jg/2.)*Delta;\n",
			  "const int _nconst = ", s, ";\n"
			  "const real _constant[_nconst] = {", a);
  for (int i = 1; i < nconst; i++) {
    snprintf (a, 19, "%g", _constant[i]);
    fs = str_append (fs, ",", a);
  }
  fs = str_append (fs, "};\n");
  fs = str_append (fs, "layout(std430, binding = 0) buffer _data_layout { real _data[]; };\n");

  /**
  Scalar field attributes */
      
  char * attributes = NULL;
  for (const External * g = externals; g; g = g->next)
    if (g->name[0] == '.') {
      char * type =
	!strcmp (g->type, "float") || !strcmp (g->type, "double") ? "real" :
	!strcmp (g->type, "*func()") ? "int" :
	g->type;
      attributes = str_append (attributes, "  ", type, " ", g->name + 1);
      for (int * d = g->data; d && *d > 0; d++) {
	char s[20]; snprintf (s, 19, "%d", *d);
	attributes = str_append (attributes, "[", s, "]");
      }
      attributes = str_append (attributes, ";\n");
    }
  
  if (attributes) {
    fs = str_append (fs, "struct _Attributes {\n", attributes, "};\n");
    sysfree (attributes);
    int nindex = 0;
    for (scalar s in baseblock)
      if (s.gpu.index)
	nindex++;
    assert (nindex > 0);
    char s[20]; snprintf (s, 19, "%d", nindex);
    fs = str_append (fs, "const _Attributes _attr[", s, "]={");
    nindex = 0;
    for (scalar s in baseblock)
      if (s.gpu.index) {
	fs = str_append (fs, nindex ? ",{" : "{"); nindex++;
	bool first = true;
	char * data = (char *) &_attribute[s.i];
	for (const External * g = externals; g; g = g->next)
	  if (g->name[0] == '.') {
	    if (!first) fs = str_append (fs, ",");
	    first = false;
	    if (!strcmp (g->type, "int")) {
	      char s[20]; snprintf (s, 19, "%d", *((int *)(data + g->nd)));
	      fs = str_append (fs, s);
	    }
	    else if (!strcmp (g->type, "bool"))
	      fs = str_append (fs, *((bool *)(data + g->nd)) ? "true" : "false");
	    else if (!strcmp (g->type, "float")) {
	      char s[20]; snprintf (s, 19, "%g", *((float *)(data + g->nd)));
	      fs = str_append (fs, s);
	    }
	    else if (!strcmp (g->type, "double")) {
	      char s[20]; snprintf (s, 19, "%g", *((double *)(data + g->nd)));
	      fs = str_append (fs, s);
	    }
	    else if (!strcmp (g->type, "ivec")) {
	      ivec * v = (ivec *)(data + g->nd);
	      char s[20]; snprintf (s, 19, "{%d,%d}", v->x, v->y);
	      fs = str_append (fs, s);
	    }
	    else if (!strcmp (g->type, "*func()")) {
	      void * func = *((void **)(data + g->nd));
	      if (!func)
		fs = str_append (fs, "0");
	      else {
		External * ptr = _get_function ((long) func);
		char s[20]; snprintf (s, 19, "%d", ptr->nd);
		fs = str_append (fs, s);
	      }
	    }
	    else if (!strcmp (g->type, "scalar"))
	      fs = write_scalar (fs, *((scalar *)(data + g->nd)));
	    else if (!strcmp (g->type, "vector"))
	      fs = write_vector (fs, *((vector *)(data + g->nd)));
	    else if (!strcmp (g->type, "tensor"))
	      fs = write_tensor (fs, *((tensor *)(data + g->nd)));
	    else
	      fs = str_append (fs, "not implemented");
	  }
	fs = str_append (fs, "}");
      }
    fs = str_append (fs, "};\n");
  }
  
  /**
  Non-local variables */

  int location = 3; // 0,1 and 2 are reserved for csOrigin, vsOrigin and vsScale
  for (External * g = externals; g; g = g->next) {
    if (g->name[0] == '.') {
      if (!strcmp (g->type, "*func()")) {
	fs = str_append (fs, "#define _attr_", g->name + 1, "(s,args) (");
	foreach_function (f, f->used = false);
	char * expr = NULL;
	for (scalar s in baseblock)
	  if (s.gpu.index) {
	    char * data = (char *) &_attribute[s.i];
	    void * func = *((void **)(data + g->nd));
	    if (func) {
	      External * f = _get_function ((long) func);
	      if (!f->used) {
		f->used = true;
		if (!expr)
		  expr = str_append (NULL, "(", f->name, " args)");
		else {
		  char index[20];
		  snprintf (index, 19, "%d", f->nd);
		  char * s = str_append (NULL, "_attr(s,", g->name + 1, ")==", index,
					 "?(", f->name, " args):", expr);
		  sysfree (expr);
		  expr = s;
		}
	      }
	    }
	  }
	if (expr) {
	  fs = str_append (fs, expr, ")\n");
	  sysfree (expr);
	}
	else
	  fs = str_append (fs, "0)\n");
      }
    }
    else if (!strcmp (g->type, "func()")) {
      External * f = _get_function ((long) g->pointer);
      fs = str_append (fs, "\n", f->data, "\n");
      char s[20]; snprintf (s, 19, "%d", f->nd);
      fs = str_append (fs, "const int _p", g->name, " = ", s, ";\n");
    }
    else if (!strcmp (g->type, "*func()")) {
      External * f = _get_function ((long) g->pointer);
      char s[20]; snprintf (s, 19, "%d", f->nd);
      fs = str_append (fs, "const int ", g->name, " = ", s, ";\n",
		       "#define _f", g->name, "(args) (", f->name, " args)\n");
    }
    else if (strcmp (g->type, "scalar") &&
	     strcmp (g->type, "vector") &&
	     strcmp (g->type, "tensor")) {
      if (!strcmp (g->name, "N") && !strcmp (g->type, "int")) {
	int level = region->level > 0 ? region->level - 1 : depth();
	char s[20], d[20], l[20], size[30];
	snprintf (s, 19, "%d", Nl);
	snprintf (d, 19, "%d", depth());
	snprintf (l, 19, "%d", level);
	snprintf (size, 19, "%ld", (size_t) field_size());
	fs = str_append (fs,
			 "const uint N = ", s, ", _depth = ", d, ", _field_size = ", size, ";\n"
			 "const uint NY = ",
			 loop->face > 1 || loop->vertex ? "N + 1" : "N",
			 ";\n");
	if (GPUContext.fragment_shader)
	  fs = str_append (fs, "in vec2 vsPoint;\n"
			   "Point point = {int((vsPoint.x*vsScale.x + vsOrigin.x)*N) + GHOSTS,"
			   "int((vsPoint.y*vsScale.y + vsOrigin.y)*N) + GHOSTS,", l,
#if LAYERS
			   ",0"
#endif
			   "};\n"
			   "out vec4 FragColor;\n");
	else {
	  char nwgx[20], nwgy[20];
	  snprintf (nwgx, 19, "%d", gpu_grid->nwg[0]);
	  snprintf (nwgy, 19, "%d", gpu_grid->nwg[1]);
	  fs = str_append (fs, "layout (local_size_x = ", nwgx,
			   ", local_size_y = ", nwgy, ") in;\n");
	}
      }
      else if (!strcmp (g->name, "nl") && !strcmp (g->type, "int")) {

	/**
	'int nl' gets special treatment. */
	
	char nl[20];
	snprintf (nl, 19, "%d", *((int *)g->pointer));
	fs = str_append (fs, "const int nl = ", nl, ";\n");
      }
      else if (!strcmp (g->name, "bc_period_x") && !strcmp (g->type, "int"))
	fs = str_append (fs, "const int bc_period_x = ", Period.x ? "int(N)" : "-1", ";\n");
      else if (!strcmp (g->name, "bc_period_y") && !strcmp (g->type, "int"))
	fs = str_append (fs, "const int bc_period_y = ", Period.y ? "int(N)" : "-1", ";\n");
      else if (GPUContext.fragment_shader && (region->n.x > 1 || region->n.y > 1) &&
	       !strcmp (g->type, "coord") && !strcmp (g->name, "p")) {

	/**
	'coord p' is assumed to be the parameter of a region. This is
	not flexible (the parameter must be called 'p') and should be improved. */
	
	fs = str_append (fs, "coord p = vec3((vsPoint*vsScale + vsOrigin)*L0 + vec2(X0, Y0),0);\n");
      }
      else {
	char * type = !strcmp (g->type, "float") || !strcmp (g->type, "double") ? "real" :
	  !strcmp (g->type, "enum") ? "int" : g->type;
	char loc[20];
	snprintf (loc, 19, "%d", location);
	fs = str_append (fs, "layout (location = ", loc, ") uniform ",
			 type, " ", g->name, g->reduct ? "_in_" : "");
	g->location = location;
	int * d = g->data;
	location += d && *d > 0 ? *d : 1;
	for (; d && *d > 0; d++) {
	  char s[20]; snprintf (s, 19, "%d", *d);
	  fs = str_append (fs, "[", s, "]");
	}
	fs = str_append (fs, ";\n");
	if (g->reduct) {
	  fs = str_append (fs, type, " ", g->name, " = ", g->name, "_in_;\n");
	  fs = str_append (fs, "const scalar ", g->name, "_out_ = ");
	  fs = write_scalar (fs, g->s);
	  fs = str_append (fs, ";\n");
	}
      }
    }
    else { // scalar, vector and tensor fields
      int size = list_size (g);
      for (int j = 0; j < size; j++) {
	if (j == 0) {
	  fs = str_append (fs, "const ", g->type, " ", g->name);
	  if (g->nd == 0)
	    fs = str_append (fs, " = ");
	  else {
	    char s[20]; snprintf (s, 19, "%d", size);
	    fs = str_append (fs, "[", s, "] = {");
	  }
	}
	if (g->nd == 0 || j < size - 1) {
	  if (!strcmp (g->type, "scalar"))
	    fs = write_scalar (fs, ((scalar *)g->pointer)[j]);
	  else if (!strcmp (g->type, "vector"))
	    fs = write_vector (fs, ((vector *)g->pointer)[j]);
	  else if (!strcmp (g->type, "tensor"))
	    fs = write_tensor (fs, ((tensor *)g->pointer)[j]);
	  else
	    assert (false);
	}
	else { // last element of a list is always ignored (this is necessary for empty lists)
	  if (!strcmp (g->type, "scalar"))
	    fs = str_append (fs, "{0,0}");
	  else if (!strcmp (g->type, "vector"))
	    fs = str_append (fs, "{{0,0},{0,0}}");
	  else if (!strcmp (g->type, "tensor"))
	    fs = str_append (fs, "{{{0,0},{0,0}},{{0,0},{0,0}}}");
	  else
	    assert (false);
	}
	if (g->nd == 0)
	  fs = str_append (fs, ";\n");
	else if (j < size - 1)
	  fs = str_append (fs, ",");
	else
	  fs = str_append (fs, "};\n");
      }
    }
  }
    
  return fs;
}

trace
Shader * load_shader (const char * fs, uint32_t hash, const ForeachData * loop)
{
  assert (gpu_grid->shaders);
  khiter_t k = kh_get (INT, gpu_grid->shaders, hash);
  if (k != kh_end (gpu_grid->shaders)) {
    sysfree ((void *)fs);
    return kh_value (gpu_grid->shaders, k);
  }
#if PRINTSHADER
  {
    static int n = 1;
    fprintf (stderr, "=================== %s:%d: shader #%d ===================\n",
	     loop ? loop->fname : "reduction", loop ? loop->line : 0, n++);
    fputs (fs, stderr);
  }
#endif
  GLuint id;
  if (!GPUContext.fragment_shader)
    id = loadNormalShader (NULL, fs);
  else {
    const char quad[] =
      "#version 430\n"
      "layout(location = 0) in vec3 vsPos;"
      "out vec2 vsPoint;"
      "void main() {"
      "  vsPoint = vsPos.xy;"
      "  gl_Position =  vec4(2.*vsPos.xy - vec2(1.), 0., 1.);"
      "}";
    id = loadNormalShader (quad, fs);
  }
  Shader * shader = NULL;
  if (id) {
    shader = malloc (sizeof (Shader));
    shader->id = id;
    int ret;
    khiter_t k = kh_put (INT, gpu_grid->shaders, hash, &ret);
    assert (ret > 0);
    kh_value (gpu_grid->shaders, k) = shader;
  }
  sysfree ((void *)fs);
  return shader;
}

void gpu_limits (FILE * fp)
{
  GLString * i = gpu_limits_list;
  while (i->s) {
    GLint val;
    GL_C (glGetIntegerv (i->index, &val));  
    fprintf (fp, "%s: %d\n", i->s, val);
    i++;
  }
}

void gpu_free()
{
  if (!grid)
    return;
  free_boundaries();
  swap (Boundary **, boundaries, gpu_grid->boundaries);
  uint32_t hash;
  Shader * shader;
  kh_foreach (gpu_grid->shaders, hash, shader, free (shader)); hash = hash;
  kh_destroy (INT, gpu_grid->shaders);
  gpu_grid->shaders = NULL;
  if (gpu_grid->reduct[0]) {
    GL_C (glDeleteBuffers (2, gpu_grid->reduct));
    for (int i = 0; i < 2; i++)
      gpu_grid->reduct[i] = 0;
  }    
}

void gpu_init()
{
  if (!GPUContext.window) {
    if (!glfwInit ())
      exit (1);

    glfwWindowHint (GLFW_VISIBLE, GL_FALSE);
    glfwWindowHint (GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint (GLFW_SAMPLES, 0);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#if DEBUG_OPENGL    
    glfwWindowHint (GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif
    
    GPUContext.window = glfwCreateWindow (1, 1, "GPU grid", NULL, NULL);
    if (!GPUContext.window) {
      glfwTerminate();
      fprintf (stderr, "GLFW: error: could not create window!\n");
      exit (1);
    }
    glfwMakeContextCurrent (GPUContext.window);

    // load GLAD.
    assert (gladLoadGLLoader ((GLADloadproc)glfwGetProcAddress));
    assert (glBindImageTexture);

#if DEBUG_OPENGL    
    GLint flags;
    GL_C (glGetIntegerv (GL_CONTEXT_FLAGS, &flags));
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
      GL_C (glEnable(GL_DEBUG_OUTPUT));
      GL_C (glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS));
      GL_C (glDebugMessageCallback (GLDebugMessageCallback, NULL));
      GL_C (glDebugMessageControl (GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE));
    }
#endif // DEBUG_OPENGL
    
    GL_C (glGenBuffers (1, &GPUContext.ssbo));

    free_solver_func_add (gpu_free);
    free_solver_func_add (gpu_free_solver);
  }
  gpu_grid->shaders = kh_init (INT);
  for (int i = 0; i < 2; i++)
    gpu_grid->reduct[i] = 0;
    
  realloc_ssbo();
}

void gpu_free_grid (void)
{
  if (!grid)
    return;
  gpu_free();
  free_grid();
}

attribute {
  double (* boundary_left)   (Point, Point, scalar, bool *);
  double (* boundary_right)  (Point, Point, scalar, bool *);
  double (* boundary_top)    (Point, Point, scalar, bool *);
  double (* boundary_bottom) (Point, Point, scalar, bool *);
}

/**
The `stored` attibute tracks where the up-to-date field is stored:

*   0: on both the CPU and GPU (i.e. synchronized). 
*   1: on the CPU.
* - 1: on the GPU.
*/

attribute {
  struct {
    int stored, index;
  } gpu;
}

trace
static void gpu_cpu_sync_scalar (scalar s, char * sep, GLenum mode)
{
  assert ((mode == GL_MAP_READ_BIT && s.gpu.stored < 0) ||
	  (mode == GL_MAP_WRITE_BIT && s.gpu.stored > 0));
  if (s.gpu.stored > 0 && s.dirty) {
    swap (Boundary **, boundaries, gpu_grid->boundaries);
    boundary ({s});
    swap (Boundary **, boundaries, gpu_grid->boundaries);
  }
  GL_C (glBindBuffer (GL_SHADER_STORAGE_BUFFER, GPUContext.ssbo));
  size_t size = field_size()*sizeof(real);
  char * gd = glMapBufferRange (GL_SHADER_STORAGE_BUFFER, s.i*size, size, mode);
  assert (gd);
  char * cd = grid_data() + s.i*size;
  if (mode == GL_MAP_READ_BIT)
    memcpy (cd, gd, size);
  else if (mode == GL_MAP_WRITE_BIT)
    memcpy (gd, cd, size);
  else
    assert (false);
  assert (glUnmapBuffer (GL_SHADER_STORAGE_BUFFER));
  GL_C (glBindBuffer (GL_SHADER_STORAGE_BUFFER, 0));
  if (sep)
    fprintf (stderr, "%s%s", sep, s.name);
  s.gpu.stored = 0;
}

static void gpu_cpu_sync (scalar * list, GLenum mode, const char * fname, int line)
{
#if PRINTCOPYGPU
  bool copy = false;
#endif
  for (scalar s in list)
    if (s.input && ((mode == GL_MAP_READ_BIT && s.gpu.stored < 0) ||
		    (mode == GL_MAP_WRITE_BIT && s.gpu.stored > 0))) {
#if PRINTCOPYGPU
      if (!copy) {
	fprintf (stderr, "%s:%d: %s ", fname, line,
		 mode == GL_MAP_READ_BIT ? "importing" : "exporting");
	copy = true;
	gpu_cpu_sync_scalar (s, "{", mode);
      }
      else
	gpu_cpu_sync_scalar (s, ",", mode);
#else
      gpu_cpu_sync_scalar (s, NULL, mode);
#endif
    }
#if PRINTCOPYGPU
  if (copy)
    fprintf (stderr, "} %s GPU\n", mode == GL_MAP_READ_BIT ? "from" : "to");
#endif
}

trace
void reset_gpu (void * alist, float val)
{
  size_t size = field_size()*sizeof(real);
  GL_C (glBindBuffer (GL_SHADER_STORAGE_BUFFER, GPUContext.ssbo));
  scalar * list = alist;
  for (scalar s in list)
    if (!is_constant(s)) {
      GL_C (glClearBufferSubData (GL_SHADER_STORAGE_BUFFER, GL_R32F,
				  s.i*size, size,
				  GL_RED, GL_FLOAT, &val));
      s.gpu.stored = -1;
    }
  GL_C (glBindBuffer (GL_SHADER_STORAGE_BUFFER, 0));
}

#define reset(...) reset_gpu (__VA_ARGS__)

void gpu_init_grid (int n)
{
  if (grid && n == N)
    return;
  gpu_free_grid();
  init_grid (n);
  grid = realloc (grid, sizeof (GridGPU));
  gpu_grid->boundaries = NULL;
  swap (Boundary **, boundaries, gpu_grid->boundaries);
  gpu_init();
}

// overload the default various functions

#define init_grid(n)  gpu_init_grid(n)
#undef  free_grid
#define free_grid()   gpu_free_grid()

#include "reduction.h"

const char _double[] = "double";

trace
static Shader * compile_shader (ForeachData * loop, const RegionParameters * region,
				External * externals,
				const char * kernel)
{
  assert (gpu_grid->shaders);
  
  uint32_t hash = hash_shader (externals, loop, region, kernel);
  khiter_t k = kh_get (INT, gpu_grid->shaders, hash);
  if (k != kh_end (gpu_grid->shaders))
    return kh_value (gpu_grid->shaders, k);

  const char * error = strstr (kernel, "@error ");
  if (error) {
    for (const char * s = error + 7; *s != '\n' && *s != '\0'; s++)
      fputc (*s, stderr);
    fputc ('\n', stderr);
    loop->data = NULL;
    return NULL;
  }

  for (const External * g = externals; g; g = g->next)
    if (strcmp(g->type, "scalar") && strcmp(g->type, "vector") && strcmp(g->type, "tensor")) {
      if (g->reduct && !strchr ("+mM", g->reduct)) {
	if (loop->first)
	  fprintf (stderr,
		   "%s:%d: GLSL: error: unknown reduction operation '%c'\n",
		   loop->fname, loop->line, g->reduct);
	return NULL;
      }
      if (!strcmp(g->type, "coord") || !strcmp(g->type, "_coord") || !strcmp(g->type, "vec4")) {
	if (g->reduct) {
	  if (loop->first)
	    fprintf (stderr,
		     "%s:%d: GLSL: error: reductions not implemented for '%s' type\n",
		     loop->fname, loop->line, g->type);
	  return NULL;	
	}
      }
      else if (strcmp (g->type, "float") &&
	       strcmp (g->type, "double") &&
	       strcmp (g->type, "int") &&
	       strcmp (g->type, "bool") &&
	       strcmp (g->type, "enum") &&
	       strcmp (g->type, "ivec") &&
	       strcmp (g->type, "*func()") &&
	       strcmp (g->type, "func()")) {
	if (loop->first)
	  fprintf (stderr, "%s:%d: GLSL: error: unknown type '%s' for '%s'\n",
		   loop->fname, loop->line, g->type, g->name);
	return NULL;
      }
    }

  char * shader = build_shader (externals, loop, region);
  if (!shader)
    return NULL;

  /**
  ## main() */
    
  shader = str_append (shader, "void main() {\n");
  if (!GPUContext.fragment_shader) {
    char d[20];
    snprintf (d, 19, "%d", region->level > 0 ? region->level - 1 : depth());
    shader = str_append (shader, "Point point = {csOrigin.x + int(gl_GlobalInvocationID.y) + GHOSTS,"
			 "csOrigin.y + int(gl_GlobalInvocationID.x) + GHOSTS,", d,
#if LAYERS
			 ",0};\n"
#else
			 "};\n"
#endif
			 );
  }
  shader = str_append (shader,
		       "if (point.i < N + 2*GHOSTS && point.j < N + 2*GHOSTS) {\n"
		       "POINT_VARIABLES\n");
  if (loop->vertex)
    shader = str_append (shader, "  x -= Delta/2., y -= Delta/2.;\n");
  shader = str_append (shader, kernel);
  shader = str_append (shader, "\nif (point.j - GHOSTS < NY) {");
  for (const External * g = externals; g; g = g->next)
    if (g->reduct) {
      shader = str_append (shader, "\n  val_red_(", g->name, "_out_) = ", g->name, ";");
      scalar s = g->s;
      s.gpu.stored = -1;
    }
  shader = str_append (shader, "\n}",
		       loop->dirty ? "apply_bc(point);" : "",
		       "}}\n");

  /**
  For the Intel driver, it looks like this is necessary so that the
  compiled shader is independent from the exact location of the
  storage buffer. */
  
  GL_C (glBindBufferBase (GL_SHADER_STORAGE_BUFFER, 0, 0));
    
  Shader * s = load_shader (shader, hash, loop);
  loop->data = s;
  return s;
}

trace
static Shader * setup_shader (ForeachData * loop, const RegionParameters * region,
			      External * externals,
			      const char * kernel)
{
  int index = 1;
  for (scalar s in baseblock)
    if (s.input || s.output)
      s.gpu.index = index++;
    else
      s.gpu.index = 0;
  
  if (!(externals = merge_externals (externals, loop)))
    return false;
  
  /**
  ## Number of compute shader work groups and groups */

  static const int NWG[2] = {16, 16};
  int Nl = region->level > 0 ? 1 << (region->level - 1) : N;
  if (loop->face || loop->vertex) {
    for (int i = 0; i < 2; i++)
      if (Nl > NWG[i]) {
	gpu_grid->nwg[i] = NWG[i] + 1;
	gpu_grid->ng[i] = Nl/NWG[i];
	assert (gpu_grid->nwg[i]*gpu_grid->ng[i] >= Nl + 1);
      }
      else {
	gpu_grid->nwg[i] = Nl + 1;
	gpu_grid->ng[i] = 1;
      }
  }
  else
    for (int i = 0; i < 2; i++) {
      gpu_grid->nwg[i] = Nl > NWG[i] ? NWG[i] : Nl;
      gpu_grid->ng[i] = Nl/gpu_grid->nwg[i];
    }
  
  /**
  ## Allocate reduction fields */

  for (External * g = externals; g; g = g->next)
    if (g->reduct) {
      scalar s = new scalar;
      s.output = 1;
      g->s = s;
    }

  Shader * shader = compile_shader (loop, region, externals, kernel);
  
  if (!shader) {
      
    /**
    ## Free reduction fields */
    
    for (const External * g = externals; g; g = g->next)
      if (g->reduct) {
	scalar s = g->s;
	delete ({s});
      }
      
    return 0;
  }
  
  gpu_cpu_sync (baseblock, GL_MAP_WRITE_BIT, loop->fname, loop->line);

  GL_C (glUseProgram (shader->id));

  GL_C (glBindBufferBase (GL_SHADER_STORAGE_BUFFER, 0, GPUContext.ssbo));

  /**
  ## Set global variables */

  for (const External * g = externals; g; g = g->next) {
    if (g->name[0] == '.') continue;
    if (!strcmp (g->type, "*func()") || !strcmp (g->type, "func()")) continue;
    if ((!strcmp (g->name, "N") || !strcmp (g->name, "nl")) && !strcmp (g->type, "int"))
      continue;
    if (!strcmp (g->type, "int") ||
	!strcmp (g->type, "float") ||
	!strcmp (g->type, "vec4")) {
      // not an array or just a one-dimensional array
      assert (!g->data || ((int *)g->data)[1] == 0);
      GLint location;
      if (g->location)
	location = g->location;
      else {
	char name[strlen(g->name) + strlen ("_in_[]") + 20];
	strcpy (name, g->name);
	if (g->reduct)
	  strcat (name, "_in_");
	location = glGetUniformLocation (shader->id, name);
      }
      if (!strcmp (g->type, "int")) {
#if PRINTUNIFORM
	int * p = g->pointer;
	fprintf (stderr, "uniform int %s = %d\n", g->name, *p);
#endif
	glUniform1iv (location, g->data ? ((int *)g->data)[0] : 1, g->pointer);
      }
      else if (!strcmp (g->type, "float")) {
#if PRINTUNIFORM
	float * p = g->pointer;
	fprintf (stderr, "uniform float %s = %g\n", g->name, *p);
#endif
	glUniform1fv (location, g->data ? ((int *)g->data)[0] : 1, g->pointer);
      }
      else if (!strcmp (g->type, "vec4")) {
#if PRINTUNIFORM
	float * p = g->pointer;
	fprintf (stderr, "uniform vec4 %s = {%g,%g,%g,%g}\n", g->name, p[0], p[1], p[2], p[3]);
#endif
	glUniform4fv (location, g->data ? ((int *)g->data)[0] : 1, g->pointer);
      }
    }
    else if (strcmp(g->type, "scalar") &&
	     strcmp(g->type, "vector") &&
	     strcmp(g->type, "tensor")) {
      void * p = g->pointer;
      // not an array or just a one-dimensional array
      assert (!g->data || ((int *)g->data)[1] == 0);
      int nd = g->data ? ((int *)g->data)[0] : 1;      
      for (int d = 0; d < nd; d++) {
	GLint location;
	if (!g->data && g->location)
	  location = g->location;
	else {
	  char name[strlen(g->name) + strlen ("_in_[]") + 20];
	  strcpy (name, g->name);
	  if (g->reduct)
	    strcat (name, "_in_");
	  if (d > 0) {
	    char s[22];
	    snprintf (s, 21, "[%d]", d);
	    strcat (name, s);
	  }
	  location = glGetUniformLocation (shader->id, name);
	}
	if (!strcmp (g->type, "enum")) {
#if PRINTUNIFORM
	  fprintf (stderr, "uniform enum %s = %d\n", name, g->nd);
#endif
	  assert (nd == 1);
	  glUniform1i (location, g->nd);
	}
	else if (g->nd == 0) {
	  if (!strcmp (g->type, "double")) {
#if PRINTUNIFORM
	    fprintf (stderr, "uniform double %s = %g\n", name, *((double *)p));
#endif
	    glUniform1f (location, *((double *)p)); p = ((double *)p) + 1;
	  }
	  else if (!strcmp (g->type, "bool")) {
#if PRINTUNIFORM
	    bool * p = g->pointer;
	    fprintf (stderr, "uniform bool %s = %d\n", name, *p);
#endif
	    glUniform1i (location, *((bool *)p)); p = ((bool *)p) + 1;
	  }
	  else if (!strcmp (g->type, "coord")) {
#if PRINTUNIFORM
	    fprintf (stderr, "uniform coord %s = {%g,%g,%g}\n", name,
		     ((double *)p)[0], ((double *)p)[1], ((double *)p)[2]);
#endif
	    glUniform3f (location, ((double *)p)[0], ((double *)p)[1], ((double *)p)[2]);
	    p = ((double *)p) + 3;
	  }
	  else if (!strcmp(g->type, "_coord")) {
#if PRINTUNIFORM
	    fprintf (stderr, "uniform _coord %s = {%g,%g}\n", name,
		     ((double *)p)[0], ((double *)p)[1]);
#endif
	    glUniform2f (location, ((double *)p)[0], ((double *)p)[1]); p = ((double *)p) + 2;
	  }
	  else {
	    fprintf (stderr, "type: %s name: %s\n", g->type, g->name);
	    assert (false);
	  }
	}
	else
	  assert (false);
      }
    }
  }
  
  return shader;
}

static bool doloop_on_gpu (ForeachData * loop, const RegionParameters * region,
			   External * externals,
			   const char * kernel)
{
  Shader * shader = setup_shader (loop, region, externals, kernel);
  if (!shader)
    return false;
  
  /**
  ## Render 

  If this is a `foreach_point()` iteration, we draw a single point */

  int Nl = region->level > 0 ? 1 << (region->level - 1) : N;  
  if (region->n.x == 1 && region->n.y == 1) {
    int csOrigin[] = { (region->p.x - X0)/L0*Nl, (region->p.y - Y0)/L0*Nl };
    GL_C (glUniform2iv (0, 1, csOrigin));
    assert (!GPUContext.fragment_shader);
    GL_C (glDispatchCompute (1, 1, 1));
  }

  /**
  This is a region */
  
  else if (region->n.x || region->n.y) {
    float vsScale[] = {
      (region->box[1].x - region->box[0].x)/L0,
      (region->box[1].y - region->box[0].y)/L0
    };
    float vsOrigin[] = { (region->box[0].x - X0)/L0, (region->box[0].y - Y0)/L0 };
    GL_C (glUniform2fv (1, 1, vsOrigin));
    GL_C (glUniform2fv (2, 1, vsScale));
    assert (GPUContext.fragment_shader);
    GL_C (glDrawArrays (GL_TRIANGLES, 0, 6));
  }

  else {
    assert (!GPUContext.fragment_shader);
    //    tracing ("glDispatchCompute", __FILE__, __LINE__);
    GL_C (glDispatchCompute (gpu_grid->ng[0], gpu_grid->ng[1], 1));
    //    end_tracing ("glDispatchCompute", __FILE__, __LINE__);
  }
  
  GL_C (glMemoryBarrier (GL_ALL_BARRIER_BITS));

  /**
  ## Perform reductions and cleanup */

  bool nreductions = false;
  for (const External * g = externals; g; g = g->next)
    if (g->reduct) {
      nreductions = true;
      break;
    }
  if (nreductions)
    tracing ("gpu_reduction", loop->fname, loop->line);
  for (const External * g = externals; g; g = g->next)
    if (g->reduct) {
      scalar s = g->s;
      double result = gpu_reduction (field_offset (s), g->reduct, region,
				     loop->face == 1 || loop->face == 2 ?
				     Nl*(Nl + 1) :
				     loop->face == 3 || loop->vertex ? sq(Nl + 1) - 1 :
				     sq(Nl));
#if 0
      fprintf (stderr, "%s:%d: %s %c %g\n",
	       loop->fname, loop->line, g->name, g->reduct, result);
#endif
      if (!strcmp (g->type, "double")) *((double *)g->pointer) = result;
      else if (!strcmp (g->type, "float")) *((float *)g->pointer) = result;
      else if (!strcmp (g->type, "int")) *((int *)g->pointer) = result;
      else
	assert (false);
      delete ({s});
    }
  if (nreductions)
    end_tracing ("gpu_reduction", loop->fname, loop->line);

  return true;
}

bool gpu_end_stencil (ForeachData * loop,
		      const RegionParameters * region,
		      External * externals,
		      const char * kernel)
{
  bool on_gpu = (loop->parallel == 1 || loop->parallel == 3) && (loop->first || loop->data);
  if (on_gpu) {
    on_gpu = doloop_on_gpu (loop, region, externals, kernel);
    if (!on_gpu) {
      fprintf (stderr, "%s:%d: %s: foreach() done on CPU (see GLSL errors above)\n",
	       loop->fname, loop->line, loop->parallel == 3 ? "error" : "warning");
      if (loop->parallel == 3) // must run on GPU but cannot run
	exit (1);
      loop->data = NULL;
    }
  }
  if (on_gpu) {
    // do not apply BCs on CPU
    free (loop->listc), loop->listc = NULL;
    foreach_dimension()
      free (loop->listf.x), loop->listf.x = NULL;
    for (scalar s in loop->dirty)
      s.dirty = false;
    free (loop->dirty), loop->dirty = NULL;
  }
  else
    gpu_cpu_sync (baseblock, GL_MAP_READ_BIT, loop->fname, loop->line);
  
  for (scalar s in baseblock)
    if (s.output)
      s.gpu.stored = on_gpu ? -1 : 1;

  return on_gpu && loop->parallel != 3;
}

/**
## Useful links

* [Core Language (GLSL)](https://www.khronos.org/opengl/wiki/Core_Language_(GLSL))
* [Image Load Store](https://www.khronos.org/opengl/wiki/Image_Load_Store)
* [OpenGL* Performance Tips: Avoid OpenGL Calls that Synchronize CPU and GPU](https://www.intel.com/content/www/us/en/developer/articles/technical/opengl-performance-tips-avoid-opengl-calls-that-synchronize-cpu-and-gpu.html)
* [Read pixel data from default framebuffer in OpenGL: Performance of FBO vs. PBO](https://coderedirect.com/questions/611796/read-pixel-data-from-default-framebuffer-in-opengl-performance-of-fbo-vs-pbo)
* [Persistent Mapped Buffers in OpenGL](https://www.cppstories.com/2015/01/persistent-mapped-buffers-in-opengl/)
* [Best Practices for Working with Texture Data (OpenGL Programming Guide for Mac)](https://developer.apple.com/library/archive/documentation/GraphicsImaging/Conceptual/OpenGL-MacProgGuide/opengl_texturedata/opengl_texturedata.html)
* [https://github.com/Erkaman/fluid_sim]()
* [https://stackoverflow.com/questions/67529148/how-can-i-optimize-a-compute-shader-thats-heavy-on-imageload-calls]()
* [https://www.slideshare.net/Mark_Kilgard/siggraph-2012-nvidia-opengl-for-2012]()
* [https://stackoverflow.com/questions/7954927/passing-a-list-of-values-to-fragment-shader]()
* [https://computergraphics.stackexchange.com/questions/5416/why-use-image-load-stores-instead-of-fbos]()
* [https://computergraphics.stackexchange.com/questions/9956/performance-of-compute-shaders-vs-fragment-shaders-for-deferred-rendering]()
* [https://computergraphics.stackexchange.com/questions/54/when-is-a-compute-shader-more-efficient-than-a-pixel-shader-for-image-filtering]()
* [http://diaryofagraphicsprogrammer.blogspot.com/2014/03/compute-shader-optimizations-for-amd.html]()
* [DirectCompute: Optimizations and Best Practices, Eric Young, NVIDIA Corporation, 2010](http://on-demand.gputechconf.com/gtc/2010/presentations/S12312-DirectCompute-Pre-Conference-Tutorial.pdf)
* [Compute shaders in graphics: Gaussian blur](https://lisyarus.github.io/blog/graphics/2022/04/21/compute-blur.html)
* [Arm Mali GPUs Best Practices Developer Guide](https://armkeil.blob.core.windows.net/developer/Arm%20Developer%20Community/PDF/Arm%20Mali%20GPU%20Best%20Practices.pdf)
* [Rendering to a 3D texture](https://community.khronos.org/t/rendering-to-a-3d-texture/75285/2)
* [GLFW Shared Contexts](https://www.glfw.org/docs/3.3/context_guide.html#context_sharing)
* [Slides on using Array or Bindless Textures](https://www.slideshare.net/CassEveritt/beyond-porting)
* [Optimizing Compute Shaders for L2 Locality using Thread-Group ID Swizzling](https://developer.nvidia.com/blog/optimizing-compute-shaders-for-l2-locality-using-thread-group-id-swizzling/)
* [Optimizing GPU occupancy and resource usage with large thread groups](https://gpuopen.com/learn/optimizing-gpu-occupancy-resource-usage-large-thread-groups/)
*/
