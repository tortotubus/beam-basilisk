/**
# Cartesian grid on GPUs

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

GLSL: error: if-statement condition must be scalar boolean

GLSL: error: value of type float cannot be assigned to variable of type int

*/

#include <grid/gpu/gpu.h>

#define GRIDNAME "Cartesian (GPU)"

#define free_grid cartesian_free_grid

static bool _gpu_done_ = false;
@undef BEGIN_FOREACH
@def BEGIN_FOREACH if (_gpu_done_)
  _gpu_done_ = false;
 else {
   tracing ("foreach", S__FILE__, S_LINENO);
@
@undef END_FOREACH
@define END_FOREACH end_tracing("foreach", S__FILE__, S_LINENO); }

typedef struct {
  coord p, * box, n;
} RegionParameters;

@undef foreach_stencil
@def foreach_stencil(_parallel, ...) {
  tracing ("foreach", S__FILE__, S_LINENO);
  static ForeachData _loop = {
    .fname = S__FILE__, .line = S_LINENO, .first = 1, .parallel = _parallel
  };
  struct {
    RegionParameters parameters;
    External * externals;
    const char * funcs, * kernel;
  } _params = S__VA_ARGS__;
  RegionParameters * region = &_params.parameters;
  if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
    _attribute[s.i].input = _attribute[s.i].output = false;
    _attribute[s.i].width = 0;
  }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
@

@undef foreach_point_stencil
@def foreach_point_stencil(_parallel, ...) {
  tracing ("foreach", S__FILE__, S_LINENO);
  static ForeachData _loop = {
    .fname = S__FILE__, .line = S_LINENO, .first = 1, .parallel = _parallel
  };
  struct {
    coord parameters;
    External * externals;
    const char * kernel;
  } _params = S__VA_ARGS__;
  RegionParameters r = { .p = _params.parameters, .n = {1,1} }, * region = &r;
  if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
    _attribute[s.i].input = _attribute[s.i].output = false;
    _attribute[s.i].width = 0;
  }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
@

@undef end_foreach_stencil
@def end_foreach_stencil()
#if PRINTIO
  if (baseblock) {
    fprintf (stderr, "%s:%d:", _loop.fname, _loop.line);
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i)
      if (_attribute[s.i].input || _attribute[s.i].output)
	fprintf (stderr, " %s:%d:%c:%d", _attribute[s.i].name, s.i,
		 _attribute[s.i].input && _attribute[s.i].output ? 'a' :
		 _attribute[s.i].input ? 'r' : 'w',
		 _attribute[s.i].width);
    fprintf (stderr, "\n");
  }
#endif // PRINTIO
  check_stencil (&_loop);
  _gpu_done_ = gpu_end_stencil (&_loop, region, _params.externals, _params.kernel);
  boundary_stencil (&_loop);
  _loop.first = 0;
  end_tracing ("foreach", S__FILE__, S_LINENO);
}
@

@ifndef tracing
@ define tracing(func, file, line) do { glFinish(); tracing(func, file, line); } while(0)
@ define end_tracing(func, file, line) do { glFinish(); end_tracing(func, file, line); } while(0)
@endif

bool gpu_end_stencil (ForeachData * loop, const RegionParameters * region,
		      External * externals, const char * kernel);

#define _GPU 1

#include "../cartesian.h"

@undef POINT_VARIABLES
@def POINT_VARIABLES
  VARIABLES
  vec4 FragColor;
  NOT_UNUSED (FragColor);
@

#include <khash.h>

KHASH_MAP_INIT_STR(STR, GLuint)

typedef struct {
  Cartesian parent;
  Array * texture;
  khash_t(STR) * shaders;
} CartesianGPU;

#define gpu_cartesian ((CartesianGPU *)grid)

typedef struct _Texture Texture;

struct _Texture {
  GLuint id;
  bool used, out[4];
  int type; // 0: scalar, 1: vector, 2: tensor
  int input, output, width;
  Texture * io;
};

#define tex_texture(tex)  (((Texture *)gpu_cartesian->texture->p) + tex - 1)
#define scalar_texture(s) tex_texture (s.gpu.texture)

@def foreach_texture(t)
  for (int _i = 0; _i < gpu_cartesian->texture->len/sizeof(Texture); _i++) {
    Texture * t = ((Texture *)gpu_cartesian->texture->p) + _i;
    if (t->used) {
@
@define end_foreach_texture() }}
  
void gpu_reset (scalar s, double value)
{
  GL_C (glFramebufferTexture2D (GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
				GL_TEXTURE_2D, scalar_texture(s)->id, 0));  
  GLenum DrawBuffers[] = { GL_COLOR_ATTACHMENT0 };
  glDrawBuffers (1, DrawBuffers);
  GL_C (glColorMask (s.gpu.component == 0, s.gpu.component == 1,
		     s.gpu.component == 2, s.gpu.component == 3));
  GL_C (glClearColor (value, value, value, value));
  GL_C (glClear (GL_COLOR_BUFFER_BIT));
  GL_C (glColorMask (GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE));
}

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

static char glsl_preproc[] =
  "// #line 134 \"" __FILE__ "\"\n"
  "#define dimensional(x)\n"
  "#define real float\n"
  "#define coord vec3\n"
#if dimension == 2
  "#define _coord vec2\n"
  "#define scalar ivec4\n"
  "struct vector { scalar x, y; };\n"
  "struct tensor { vector x, y; };\n"
#endif
  "#define Point vec2\n"
  "#define valt(s,i,j,k) (texture(s, point + vec2((i), (j))*_delta))\n"
  "#define _NVARMAX 65536\n"
  "#define NULL 0\n"
  "#define val(s,i,j,k) (s.a < 0 || i != 0 || j != 0 || k != 0 ?"
  "(s.a > - _NVARMAX ? valt(_inputs[s.r],i,j,k)[s.g] : _constant[clamp(- s.a -_NVARMAX,0,_nconst-1)])"
  ": _outputs[s.b][s.g])\n"
  "#define val_out_(s,i,j,k) (_outputs[s.b][s.g])\n"
  "#define _attr(s,member) (_attr[abs(s.a) - 1].member)\n"
  "#define forin(type,s,list) for (int _i = 0; _i < list.length() - 1; _i++) { type s = list[_i];\n"
  "#define endforin() }\n"
  "#define forin2(a,b,c,d) for (int _i = 0; _i < c.length() - 1; _i++) { a = c[_i]; b = d[_i];\n"
  "#define endforin2() }\n"
  "#define forin3(a,b,e,c,d,f) for (int _i = 0; _i < c.length() - 1; _i++) { a = c[_i]; b = d[_i]; e = f[_i];\n"
  "#define endforin3() }\n"
  "#define is_face_x() {"
  "  real Delta = L0/N, Delta_x = Delta, Delta_y = Delta,"
  "  x = X0 + point.x*L0 - Delta/2., y = Y0 + point.y*L0;\n"
  "#define is_face_y() {"
  "  real Delta = L0/N, Delta_x = Delta, Delta_y = Delta,"
  "  x = X0 + point.x*L0, y = Y0 + point.y*L0 - Delta/2.;\n"
  "#define end_is_face_x() }\n"
  "#define end_is_face_y() }\n"
  "#define VARIABLES\n"
  "#define POINT_VARIABLES real Delta = L0/N, Delta_x = Delta, Delta_y = Delta,"
  " x = X0 + point.x*L0, y = Y0 + point.y*L0;\n"
  "#define NOT_UNUSED(x)\n"
  "#define pi 3.14159265359\n"
  "#define nodata (1e30)\n"
  "#define sq(x) ((x)*(x))\n"
  "#define fabs(x) abs(x)\n"
  "const real z = 0.;\n"
  "uniform vec2 vsOrigin = vec2(0.,0.);\n"
  "uniform vec2 vsScale = vec2(1.,1.);\n"
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
  char component[20] = "0", input[20] = "0", output[20] = "0", index[20] = "1";
  if (s.i >= 0) {
    if (is_constant(s))
      snprintf (index, 19, "%d", s.i);
    else {
      snprintf (component, 19, "%d", s.gpu.component);
      snprintf (index, 19, "%d", s.gpu.index);
      Texture * t = scalar_texture(s);
      if (t->input > 0)
	snprintf (input, 19, "%d", t->input);
      if (t->output > 0)
	snprintf (output, 19, "%d", t->output);
    }
  }
  return str_append (fs, input, ",", component, ",", output, ",",
		     s.i >= 0 && !is_constant(s) && s.output ? "+" : "-", index);
}

static char * write_vector (char * fs, vector v)
{
  fs = str_append (fs, "{");
  fs = write_scalar (fs, v.x);
  fs = str_append (fs, "},{");
  fs = write_scalar (fs, v.y);
  fs = str_append (fs, "}");
  return fs;
}

static char * write_tensor (char * fs, tensor t)
{
  fs = str_append (fs, "{");
  fs = write_vector (fs, t.x);
  fs = str_append (fs, "},{");
  fs = write_vector (fs, t.y);
  fs = str_append (fs, "}");
  return fs;
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

static External * merge_external (External * externals, External ** end, External * g, const ForeachData * loop)
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
	  if (!p)
	    return NULL;
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

static External * merge_externals (External * externals, const ForeachData * loop)
{
  External * merged = NULL, * end = NULL;
  static External x0 = { .name = "X0", .type = "double", .pointer = &X0 };
  static External y0 = { .name = "Y0", .type = "double", .pointer = &Y0 };
  static External z0 = { .name = "Z0", .type = "double", .pointer = &Z0 };
  static External l0 = { .name = "L0", .type = "double", .pointer = &L0 };
  static External n =  { .name = "N",  .type = "int",    .pointer = &N };
  for (External * g = externals; g->name; g++)
    g->used = false;
  foreach_function (f, f->used = false);
  x0.used = y0.used = z0.used = l0.used = n.used = false;
  merged = merge_external (merged, &end, &x0, loop);
  merged = merge_external (merged, &end, &y0, loop);
  merged = merge_external (merged, &end, &z0, loop);
  merged = merge_external (merged, &end, &l0, loop);
  merged = merge_external (merged, &end, &n, loop);
  for (External * g = externals; g->name; g++)
    merged = merge_external (merged, &end, g, loop);
#if PRINTEXTERNAL  
  for (External * i = merged; i; i = i->next)
    fprintf (stderr, "external %s %s\n", i->name, i->type);
#endif
  return merged;
}

trace
char * build_shader (const External * externals, const char * fname, int line)
{
  char s[20];
  snprintf (s, 19, "%d", nconst > 0 ? nconst : 1);
  char a[20];
  snprintf (a, 19, "%g", nconst > 0 ? _constant[0] : 0);
  char * fs = str_append (NULL, "#version 420\n", glsl_preproc,
			  "const int _nconst = ", s, ";\n"
			  "const real _constant[_nconst] = {", a);
  for (int i = 1; i < nconst; i++) {
    snprintf (a, 19, "%g", _constant[i]);
    fs = str_append (fs, ",", a);
  }
  fs = str_append (fs, "};\n");
  foreach_texture (t) {
    t->input = t->output = -1;
    t->width = 0;
    t->out[0] = t->out[1] = t->out[2] = t->out[3] = false;
  }
  int ninputs = 0, noutputs = 0;
  for (scalar s in baseblock) {
    Texture * t = scalar_texture (s);
    if (s.input) {
      if (t->input < 0)
	t->input = ninputs++;
      if (s.width > t->width)
	t->width = s.width;
    }
    if (s.output) {
      if (t->output < 0)
	t->output = noutputs++;
      t->out[s.gpu.component] = true;
    }
  }
  {
    // fixme: check for maximum number of inputs
    char s[20];
    snprintf (s, 19, "%d", ninputs > 0 ? ninputs : 1);
    fs = str_append (fs, "uniform sampler2D _inputs[", s, "];\n");
  }
  if (noutputs > 0) {
    int max = 0;
    GL_C (glGetIntegerv (GL_MAX_DRAW_BUFFERS, &max));
    if (noutputs > max) {
      fprintf (stderr,
	       "%s:%d: GLSL: error: too many outputs (%d > GL_MAX_DRAW_BUFFERS = %d)\n",
	       fname, line, noutputs, max);
      sysfree (fs);
      return NULL;
    }
    char s[20];
    snprintf (s, 19, "%d", noutputs);
    fs = str_append (fs, "layout(location = 0) out vec4 _outputs[", s, "];\n");
  }
  else
    fs = str_append (fs, "vec4 _outputs[1];\n");
  
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
    fs = str_append (fs, "const _Attributes _attr[]={");
    for (scalar s in baseblock)
      if (s.gpu.index) {
	fs = str_append (fs, "{");
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
	    else
	      fs = str_append (fs, "not implemented");
	  }
	// fs = str_append (fs, i < nvar - 1 ? "}," : "}");
	fs = str_append (fs, "},");
      }
    fs = str_append (fs, "};\n");
  }
  
  /**
  Non-local variables */

  for (const External * g = externals; g; g = g->next) {
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
      fs = str_append (fs, "const int _p_", g->name, " = ", s, ";\n");
    }
    else if (!strcmp (g->type, "*func()")) {
      External * f = _get_function ((long) g->pointer);
      char s[20]; snprintf (s, 19, "%d", f->nd);
      fs = str_append (fs, "const int ", g->name, " = ", s, ";\n",
		       "#define _f_", g->name, "(args) (", f->name, " args)\n");      
    }
    else if (strcmp (g->type, "scalar") &&
	     strcmp (g->type, "vector") &&
	     strcmp (g->type, "tensor")) {
      if (!strcmp (g->name, "N") && !strcmp (g->type, "int"))
        fs = str_append (fs,
			 "uniform int N;\n"
			 "in Point vsPoint;\n"
			 "Point point = vsPoint*vsScale + vsOrigin;\n"
			 "out vec4 FragColor;\n"
			 "real _delta = 1.0f/N;\n");
      else if (!strcmp (g->name, "nl") && !strcmp (g->type, "int")) {

	/**
	'int nl' gets special treatment. */
	
	char nl[20];
	snprintf (nl, 19, "%d", *((int *)g->pointer));
	fs = str_append (fs, "const int nl = ", nl, ";\n");
      }
      else {
	char * type = !strcmp (g->type, "float") || !strcmp (g->type, "double") ? "real" : g->type;
	fs = str_append (fs, "uniform ", type, " ", g->name, g->reduct ? "_in_" : "");
	for (int * d = g->data; d && *d > 0; d++) {
	  char s[20]; snprintf (s, 19, "%d", *d);
	  fs = str_append (fs, "[", s, "]");
	}
	fs = str_append (fs, ";\n");
	if (g->reduct) {
	  fs = str_append (fs, type, " ", g->name, " = ", g->name, "_in_;\n");
	  fs = str_append (fs, "const scalar ", g->name, "_out_ = ");
	  fs = str_append (fs, "{");
	  fs = write_scalar (fs, g->s);
	  fs = str_append (fs, "};\n");
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
	  fs = str_append (fs, "{");
	  if (!strcmp (g->type, "scalar"))
	    fs = write_scalar (fs, ((scalar *)g->pointer)[j]);
	  else if (!strcmp (g->type, "vector"))
	    fs = write_vector (fs, ((vector *)g->pointer)[j]);
	  else if (!strcmp (g->type, "tensor"))
	    fs = write_tensor (fs, ((tensor *)g->pointer)[j]);
	  else
	    assert (false);
	  fs = str_append (fs, "}");
	}
	else { // last element of a list is always ignored (this is necessary for empty lists)
	  if (!strcmp (g->type, "scalar"))
	    fs = str_append (fs, "{0,0,0,0}");
	  else if (!strcmp (g->type, "vector"))
	    fs = str_append (fs, "{{0,0,0,0},{0,0,0,0}}");
	  else if (!strcmp (g->type, "tensor"))
	    fs = str_append (fs, "{{{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0}}}");
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
GLuint load_shader (const char * fs)
{
  assert (gpu_cartesian->shaders);
  khiter_t k = kh_get (STR, gpu_cartesian->shaders, fs);
  if (k != kh_end (gpu_cartesian->shaders)) {
    sysfree ((void *)fs);
    return kh_value (gpu_cartesian->shaders, k);
  }
#if PRINTSHADER
  fputs (fs, stderr);
#endif
  char quad[] =
    "#version 420\n"
    "layout(location = 0) in vec3 vsPos;"
    "out vec2 vsPoint;"
    "void main() {"
    "  vsPoint = vsPos.xy;"
    "  gl_Position =  vec4(2.*vsPos.xy - vec2(1.), 0., 1.);"
    "}";
  GLuint id = loadNormalShader (quad, fs);
  if (id) {
    int ret;
    khiter_t k = kh_put (STR, gpu_cartesian->shaders, fs, &ret);
    assert (ret > 0);
    kh_value (gpu_cartesian->shaders, k) = id;
  }
  else
    sysfree ((void *)fs);
  return id;
}

trace
void cpu_to_gpu (const void * buffer, Texture * t)
{
  int internalformat, format;
  switch (t->type) {
  case 0: internalformat = GL_R32F, format = GL_RED; break;
  case 1: internalformat = GL_RG32F, format = GL_RG; break;
  case 2: internalformat = GL_RGBA32F, format = GL_RGBA; break;
  default: assert (false);
  }
  GL_C (glBindTexture (GL_TEXTURE_2D, t->id));
  GL_C (glTexImage2D (GL_TEXTURE_2D, 0, internalformat,
		      cartesian->n, cartesian->n, 0,
		      format, GL_FLOAT, buffer));
  GL_C (glBindTexture (GL_TEXTURE_2D, 0));
}

trace
float * gpu_to_cpu (Texture * t)
{
  float * buffer;
  int format;
  switch (t->type) {
  case 0: // scalar
    buffer = qmalloc (sq(cartesian->n), float);
    format = GL_RED;
    break;
  case 1: // vector
    buffer = qmalloc (sq(cartesian->n)*dimension, float);
    format = GL_RG;
    break;
  case 2: // tensor
    buffer = qmalloc (sq(cartesian->n)*sq(dimension), float);
    format = GL_RGBA;
    break;
  default: assert (false);
  }
  GL_C (glBindTexture (GL_TEXTURE_2D, t->id));
  GL_C (glGetTexImage (GL_TEXTURE_2D, 0, format, GL_FLOAT, buffer));
  GL_C (glBindTexture (GL_TEXTURE_2D, 0));
  return buffer;
}

void gpu_periodic (int dir)
{
  void periodic (int dir);
  periodic (dir);
  if (grid) {
    GLuint c = dir/2 ? GL_TEXTURE_WRAP_T : GL_TEXTURE_WRAP_S;
    for (Texture * t = gpu_cartesian->texture->p; t->id; t++) {
      GL_C (glBindTexture (GL_TEXTURE_2D, t->id));
      GL_C (glTexParameteri (GL_TEXTURE_2D, c, GL_REPEAT));
    }
    GL_C (glBindTexture (GL_TEXTURE_2D, 0));
  }
}

static scalar texture_used_by (int tex)
{
  for (scalar s in all)
    if (s.gpu.texture - 1 == tex)
      return s;
  return (scalar){-1};
}

static void gpu_delete_scalar (scalar s)
{
  if (grid && gpu_cartesian->texture && scalar_texture(s)->used) {
    scalar_texture(s)->used = false;
#if DEBUG_ALLOC_TEXTURE
    fprintf (stderr, "deleting texture %d:%s %d max %ld\n",
	     s.i, s.name, s.gpu.texture - 1,
	     gpu_cartesian->texture->len/sizeof(Texture));
    int tex = 0;
    for (Texture * t = gpu_cartesian->texture->p; t->id; t++, tex++)
      if (t->used && texture_used_by (tex).i < 0) {
	fprintf (stderr, "%s:%d: error: leaked texture %d\n",
		 __FILE__, LINENO, tex);
	abort();
      }
#endif
  }
}

void gpu_print_texture_list (FILE * fp)
{
  fprintf (fp, "textures:");
  int tex = 0;
  for (Texture * t = gpu_cartesian->texture->p; t->id; t++, tex++)
    if (t->used) {
      scalar s = texture_used_by (tex);
      if (s.i < 0) {
	fprintf (stderr, "%s:%d: error: leaked texture %d\n",
		 __FILE__, LINENO, tex);
	abort();
      }
      fprintf (fp, " %d:%d:%s:%d", tex, t->type, s.name, s.i);
    }
  fprintf (fp, "\n");
}

static int get_new_texture (int type)
{
  Texture * t;
  for (t = gpu_cartesian->texture->p; t->id && (t->used || t->type != type); t++);
  
  if (!t->id) {
    size_t size;
    int format, internal_format;
    switch (type) {
    case 0:
      format = GL_RED, internal_format = GL_R32F, size = sq(cartesian->n);
      break;
    case 1:
      assert (dimension == 2);
      format = GL_RG, internal_format = GL_RG32F,
	size = dimension*sq(cartesian->n);
      break;
    case 2:
      assert (dimension == 2);
      format = GL_RGBA, internal_format = GL_RGBA32F,
	size = sq(dimension)*sq(cartesian->n);
      break;
    default:
      assert (false);
    }
    
    t = array_append (gpu_cartesian->texture, &(Texture){0}, sizeof (Texture));
    t--; // last element is always zero
    GL_C (glGenTextures (1, &t->id));
    assert (t->id);
    // fixme: NULL ???
    float * buffer = qmalloc (size, float);
    memset (buffer, 0, size*sizeof (float));
    GL_C (glBindTexture (GL_TEXTURE_2D, t->id));
    GL_C (glTexImage2D (GL_TEXTURE_2D, 0, internal_format,
			cartesian->n, cartesian->n, 0,
			format, GL_FLOAT, buffer));
    GL_C (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    GL_C (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
    // fixme: Mirror BCs do not work for vector fields (or maybe they do??)
    GL_C (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
			   Period.x ? GL_REPEAT : GL_MIRRORED_REPEAT));
    GL_C (glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
			   Period.y ? GL_REPEAT : GL_MIRRORED_REPEAT));
    GL_C (glBindTexture (GL_TEXTURE_2D, 0));
    free (buffer);
#if DEBUG_ALLOC_TEXTURE
    fprintf (stderr, "new texture %d: %ld\n", type,
	     t - (Texture *) gpu_cartesian->texture->p);
#endif
  }

  t->used = true;
  t->input = t->output = -1;
  t->type = type;
  return (t - (Texture *) gpu_cartesian->texture->p) + 1;
}

static void gpu_init_scalar_texture (scalar s)
{
  if (s.gpu.texture) // already allocated
    return;

  s.gpu.type = 0;
  s.gpu.component = 0;

  if (grid) {
    s.gpu.texture = get_new_texture (0);
    s.delete = gpu_delete_scalar;
#if DEBUG_ALLOC_TEXTURE  
    fprintf (stderr, "%d:%s uses scalar texture %d\n",
	     s.i, s.name, s.gpu.texture - 1);
#endif
  }
}

static void gpu_init_vector_texture (vector v)
{
  if (v.x.gpu.texture) // already allocated
    return;

  for (scalar s in {v})
    s.gpu.type = 1;
  
  v.x.gpu.component = 0;
  v.y.gpu.component = 1;
  
  if (grid) {
    int tex = get_new_texture (1);
    for (scalar s in {v}) {
      s.gpu.texture = tex;
      s.delete = gpu_delete_scalar;
    }
#if DEBUG_ALLOC_TEXTURE
    fprintf (stderr, "%d:%s uses vector texture %d\n",
	     v.x.i, v.x.name, v.x.gpu.texture - 1);
#endif
  }
}

static void gpu_init_tensor_texture (tensor t)
{
  if (t.x.x.gpu.texture) // already allocated
    return;

  for (scalar s in {t}) {
    s.gpu.type = 2;
    s.gpu.t = t;
  }
  
  t.x.x.gpu.component = 0;
  t.x.y.gpu.component = 1;
  t.y.y.gpu.component = 2;
  t.y.x.gpu.component = 3;
  
  if (grid) {
    int tex = get_new_texture (2);
    for (scalar s in {t}) {
      s.gpu.texture = tex;
      s.delete = gpu_delete_scalar;
    }
#if DEBUG_ALLOC_TEXTURE  
    fprintf (stderr, "%d:%s uses tensor texture %d\n",
	     t.x.x.i, t.x.x.name, t.x.x.gpu.texture - 1);
#endif
  }
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
  
    GPUContext.window = glfwCreateWindow (1, 1, "Cartesian grid on GPU", NULL, NULL);
    if (!GPUContext.window) {
      glfwTerminate();
      exit (1);
    }
    glfwMakeContextCurrent (GPUContext.window);

    // load GLAD.
    gladLoadGLLoader ((GLADloadproc)glfwGetProcAddress);

    // Bind and create VAO, otherwise, we can't do anything in OpenGL.
    GL_C (glGenVertexArrays (1, &GPUContext.vao));
    GL_C (glBindVertexArray (GPUContext.vao));

    GL_C (glGenFramebuffers(1, &GPUContext.fbo0));

    // create vertices of fullscreen quad.
    float vertices[] = {
      +0.0f, +0.0f,
      +1.0f, +0.0f,
      +0.0f, +1.0f,
      +1.0f, +0.0f,
      +1.0f, +1.0f,
      +0.0f, +1.0f
    };
    // upload geometry to GPU.
    GL_C (glGenBuffers (1, &GPUContext.vbo));
    GL_C (glBindBuffer (GL_ARRAY_BUFFER, GPUContext.vbo));
    GL_C (glBufferData (GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));

    // setup some reasonable default GL state.
    GL_C (glDisable (GL_DEPTH_TEST));
    GL_C (glDepthMask (false));
    GL_C (glDisable (GL_BLEND));
    GL_C (glColorMask (GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE));
    GL_C (glEnable (GL_CULL_FACE));
    GL_C (glFrontFace (GL_CCW));
    GL_C (glBindFramebuffer (GL_FRAMEBUFFER, 0));
    GL_C (glUseProgram (0));
    GL_C (glBindTexture (GL_TEXTURE_2D, 0));
    GL_C (glDepthFunc (GL_LESS));
    GL_C (glPointSize (1));

    // enable vertex buffer used for full screen quad rendering. 
    // this buffer is used for all rendering, from now on.
    GL_C (glEnableVertexAttribArray ((GLuint)0));
    GL_C (glBindBuffer (GL_ARRAY_BUFFER, GPUContext.vbo));
    GL_C (glVertexAttribPointer ((GLuint)0, 2, GL_FLOAT, GL_FALSE,
				 2*sizeof(float), (void*)0));

    GL_C (glBindFramebuffer (GL_FRAMEBUFFER, GPUContext.fbo0));

    free_solver_func_add (gpu_free_solver);
  }
  
  GL_C (glViewport (0, 0, cartesian->n, cartesian->n));
  
  gpu_cartesian->texture = array_new();
  array_append (gpu_cartesian->texture, &(Texture){0}, sizeof(Texture));
  gpu_cartesian->shaders = kh_init (STR);

  for (scalar s in all) {    
    switch (s.gpu.type) {
    case 0: gpu_init_scalar_texture (s); break;
    case 1: gpu_init_vector_texture (s.v); break;
    case 2: gpu_init_tensor_texture (s.gpu.t); break;
    default: assert (false);
    }
  }
}

void gpu_free()
{
  if (!grid || !gpu_cartesian->texture)
    return;
  if (GPUContext.window) {
    GL_C (glFinish());
    int tex = 0;
    for (Texture * t = gpu_cartesian->texture->p; t->id; t++, tex++) {
      if (t->used && texture_used_by (tex).i < 0) {
	fprintf (stderr, "%s:%d: error: leaked texture %d\n",
		 __FILE__, LINENO, tex);
	abort();
      }
      GL_C (glDeleteTextures (1, &t->id));
    }
  }
  array_free (gpu_cartesian->texture);
  gpu_cartesian->texture = NULL;
  const char * code;
  GLuint id;
  kh_foreach (gpu_cartesian->shaders, code, id, sysfree ((void *) code)); id = id;
  kh_destroy (STR, gpu_cartesian->shaders);
  gpu_cartesian->shaders = NULL;
  for (scalar s in all)
    s.gpu.texture = 0;
}

void reset_gpu (void * alist, double val)
{
  scalar * list = alist;
#if 1 // fixme: should only do it on GPU
  reset (list, val);
#endif
  for (scalar s in list)
    if (!is_constant(s))
      gpu_reset (s, val);
}

void gpu_free_grid (void)
{
  if (!grid)
    return;
  gpu_free();
  free_grid();
}

void gpu_init_grid (int n)
{
  if (cartesian && n == cartesian->n)
    return;
  gpu_free_grid();
  init_grid (n);
  grid = realloc (grid, sizeof (CartesianGPU));
  gpu_init();
  free_solver_func_add (gpu_free);
}

// overload the default various functions

#define init_grid(n)  gpu_init_grid(n)
#undef  free_grid
#define free_grid()   gpu_free_grid()
#define periodic(dir) gpu_periodic(dir)

/**
The `stored` attibute tracks where the up-to-date field is stored:

*   0: on both the CPU and GPU (i.e. synchronized). 
*   1: on the CPU.
* - 1: on the GPU.
*/

attribute {
  struct {
    // take care to update gpu_cartesian_scalar_clone() when this changes
    int stored;
    int texture, component, index;
    int type; // 0: scalar, 1: vector, 2: tensor
    tensor t;
  } gpu;
}

trace
void export_to_gpu (scalar s, char * sep)
{
  static char comma[] = ",";
  float * buffer;
  switch (s.gpu.type) {
  case 0: { // scalar
    assert (s.gpu.stored > 0);
    buffer = qmalloc (sq(cartesian->n), float);
    foreach (serial, noauto)
      buffer[(point.j - 1)*point.n + point.i - 1] = s[];
    if (sep)
      fprintf (stderr, "%s%s", sep, s.name);
    s.gpu.stored = 0;
    break;
  }
  case 1: { // vector
    vector v = s.v;
    buffer = qmalloc (dimension*sq(cartesian->n), float);
    foreach (serial, noauto) {
      long index = dimension*((point.j - 1)*point.n + point.i - 1), k = 0;
      foreach_dimension()
	buffer[index + k++] = v.x[];
    }
    foreach_dimension() {
      assert (v.x.gpu.stored >= 0);
      if (sep)
	fprintf (stderr, "%s%s", sep, v.x.name), sep = comma;
      v.x.gpu.stored = 0;
    }
    break;
  }
  case 2: { // tensor
    tensor t = s.gpu.t;
    buffer = qmalloc (sq(dimension)*sq(cartesian->n), float);
    foreach (serial, noauto) {
      // fixme: long???
      int index = sq(dimension)*((point.j - 1)*point.n + point.i - 1), k = 0;
      foreach_dimension() {
	buffer[index + k++] = t.x.x[];
	buffer[index + k++] = t.x.y[];
      }
    }
    foreach_dimension() {
      assert (t.x.x.gpu.stored >= 0);
      if (sep)
	fprintf (stderr, "%s%s", sep, t.x.x.name), sep = comma;
      t.x.x.gpu.stored = 0;
      assert (t.x.y.gpu.stored >= 0);
      if (sep)
	fprintf (stderr, "%s%s", sep, t.x.y.name), sep = comma;
      t.x.y.gpu.stored = 0;
    }
    break;
  }
  default: assert (false);
  }

  cpu_to_gpu (buffer, scalar_texture (s));
  free (buffer);
}

#define REDUCTION_VS						\
  "#version 420\n"						\
  "layout(location = 0) in vec3 vsPos;"				\
  "uniform float f;"						\
  "out vec2 point;"						\
  "void main()"							\
  "{"								\
  "  point = f*vsPos.xy;"					\
  "  gl_Position =  vec4(2.*vsPos.xy - vec2(1.), 0., 1.);"	\
  "}"
#define REDUCTION_FS				\
  "uniform real _delta;\n"			\
  "uniform sampler2D s;\n"			\
  "in vec2 point;\n"				\
  "layout(location = 0) out real reduction;\n"	\
  "void main() {\n"

static GLuint load_reduction_shader (char * start, char * reduct)
{
  char * fs = str_append (NULL,
			  "#version 420\n", glsl_preproc, REDUCTION_FS,
			  start,
			  "for (int i = 0; i < 2; i++)\n"
			  "  for (int j = 0; j < 2; j++)\n",
			  reduct,
			  "\n}\n");
#if PRINTSHADER
  fputs (fs, stderr);
#endif
  GLuint id = loadNormalShader (REDUCTION_VS, fs);
  sysfree (fs);
  return id;
}

double gpu_reduction (scalar s, const char op, const RegionParameters * region)
{
  if (region->n.x == 1 && region->n.y == 1) {
    int i =  (region->p.x - X0)/L0*cartesian->n;
    int j =  (region->p.y - Y0)/L0*cartesian->n;
    GL_C (glFramebufferTexture2D (GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
				  GL_TEXTURE_2D, scalar_texture(s)->id, 0));
    float result = 0.;
    GL_C (glReadPixels (i, j, 1, 1, GL_RED, GL_FLOAT, &result));
    return result;
  }

  GLuint id = 0;

  switch (op) {
    
  case '+': {
    static GLuint shader = 0;
    if (!shader)
      shader = load_reduction_shader ("reduction = 0.;",
				      "reduction += valt(s,i,j,k).r;");
    id = shader;
    break;
  }

  case 'M': {
    static GLuint shader = 0;
    if (!shader)
      shader =
	load_reduction_shader ("reduction = valt(s,0,0,0).r;",
			       "reduction = max(reduction, valt(s,i,j,k).r);");
    id = shader;
    break;    
  }

  case 'm': {
    static GLuint shader = 0;
    if (!shader)
      shader =
	load_reduction_shader ("reduction = valt(s,0,0,0).r;",
			       "reduction = min(reduction, valt(s,i,j,k).r);");
    id = shader;
    break;
  }

  default: // unknown reduction operation
    assert (false);
  }
  
  if (!id)
    exit (1);

  int hmin = 32; // below this size, just use GLReadPixels and the CPU

  if (cartesian->n <= hmin) {
    hmin = cartesian->n;
    assert (s.v.x.i == -1); // fixme
    GL_C (glFramebufferTexture2D (GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
				  GL_TEXTURE_2D, scalar_texture(s)->id, 0));
  }
  else {
    scalar s1[], s2[];
  
    GL_C (glUseProgram (id));
    GLint location = glGetUniformLocation (id, "_delta");
    assert (location >= 0);
    int nr = 2;
    GL_C (glUniform1f (location, - 1.0f/(float)(nr*cartesian->n)));
    
    location = glGetUniformLocation (id, "s");
    assert (location >= 0);
    GL_C (glUniform1i (location, 0));
    GL_C (glActiveTexture (GL_TEXTURE0));

    GLenum DrawBuffers =  GL_COLOR_ATTACHMENT0;
    glDrawBuffers (1, &DrawBuffers);
      
    GLint flocation = glGetUniformLocation (id, "f");
    assert (flocation >= 0);

    // Initially draw/compute from s  
#if PRINTCOPYGPU
    if (s.gpu.stored > 0)
      fprintf (stderr, "%s:%d: exporting {%s} to GPU\n", __FILE__, LINENO, s.name);
#endif
    if (s.gpu.stored > 0)
      export_to_gpu (s, NULL);
    GL_C (glBindTexture (GL_TEXTURE_2D, scalar_texture(s)->id));

    int h = cartesian->n/nr;
    while (h >= hmin) {
      // Select which texture to draw/compute into
      GL_C (glFramebufferTexture2D (GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
				    GL_TEXTURE_2D, scalar_texture(s2)->id,
				    0));
      // Scale to smaller square
      GL_C (glViewport (0, 0, h, h));
      GL_C (glUniform1f (flocation, 2.*(float)h/(float)cartesian->n));
      GL_C (glDrawArrays (GL_TRIANGLES, 0, 6));
      // ping pong
      swap (scalar, s1, s2);
      // draw/compute from s1
      GL_C (glBindTexture (GL_TEXTURE_2D, scalar_texture(s1)->id));
      h /= nr;
    }
    GL_C (glFramebufferTexture2D (GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
				  GL_TEXTURE_2D, scalar_texture(s1)->id, 0));
    GL_C (glViewport (0, 0, cartesian->n, cartesian->n));
  }
  
  float result = 0., a[hmin*hmin];
  GL_C (glReadPixels (0, 0, hmin, hmin, GL_RED, GL_FLOAT, a));
  switch (op) {
  case '+':
    for (int i = 0; i < hmin*hmin; i++)
      result += a[i];
    break;
  case 'M':
    result = a[0];
    for (int i = 1; i < hmin*hmin; i++)
      result = max (result, a[i]);
    break;
  case 'm':
    result = a[0];
    for (int i = 1; i < hmin*hmin; i++)
      result = min (result, a[i]);
    break;
  default: assert (false);
  }
  
  return result;
}

trace
static void import_from_gpu (scalar s, char * sep)
{
  static char comma[] = ",";
  float * buffer = gpu_to_cpu (scalar_texture (s));

  switch (s.gpu.type) {
  case 0: { // scalar
    assert (s.gpu.stored < 0);
    foreach (serial, noauto)
      s[] = buffer[(point.j - 1)*point.n + point.i - 1];
    if (sep)
      fprintf (stderr, "%s%s", sep, s.name);
    s.gpu.stored = 0;
    s.dirty = true;
    break;
  }
  case 1: { // vector
    vector v = s.v;
    foreach (serial, noauto) {
      int k = 0;
      foreach_dimension() {
	if (v.x.gpu.stored < 0)
	  v.x[] = buffer[dimension*((point.j - 1)*point.n + point.i - 1) + k];
	k++;
      }
    }
    foreach_dimension()
      if (v.x.gpu.stored < 0) {
	if (sep)
	  fprintf (stderr, "%s%s", sep, v.x.name), sep = comma;
	v.x.gpu.stored = 0, v.x.dirty = true;
      }
    break;
  }
  case 2: { // tensor
    tensor t = s.gpu.t;
    foreach (serial, noauto) {
      long index = sq(dimension)*((point.j - 1)*point.n + point.i - 1), k = 0;
      foreach_dimension() {
	if (t.x.x.gpu.stored < 0)
	  t.x.x[] = buffer[index + k];
	k++;
	if (t.x.y.gpu.stored < 0)
	  t.x.y[] = buffer[index + k];
	k++;
      }
    }
    foreach_dimension() {
      if (t.x.x.gpu.stored < 0) {
	if (sep)
	  fprintf (stderr, "%s%s", sep, t.x.x.name), sep = comma;
	t.x.x.gpu.stored = 0, t.x.x.dirty = true;
      }
      if (t.x.y.gpu.stored < 0) {
	if (sep)
	  fprintf (stderr, "%s%s", sep, t.x.y.name), sep = comma;
	t.x.y.gpu.stored = 0, t.x.y.dirty = true;
      }
    }
    break;
  }    
  default: assert (false);
  }
  
  free (buffer);
}

static void inputs_from_gpu (ForeachData * loop)
{
#if PRINTCOPYGPU
  bool copy = false;
#endif
  for (scalar s in baseblock)
    if (s.input && s.gpu.stored < 0) {
#if PRINTCOPYGPU
      if (!copy) {
	fprintf (stderr, "%s:%d: importing ", loop->fname, loop->line), copy = true;
	import_from_gpu (s, "{");
      }
      else
	import_from_gpu (s, ",");
#else
      import_from_gpu (s, NULL);
#endif
    }
#if PRINTCOPYGPU
  if (copy)
    fputs ("} from GPU\n", stderr);
#endif
}

static void inputs_to_gpu (ForeachData * loop)
{
#if PRINTCOPYGPU
  bool copy = false;
#endif
  for (scalar s in baseblock)
    if (s.input && s.gpu.stored > 0) {
#if PRINTCOPYGPU
      if (!copy) {
	fprintf (stderr, "%s:%d: exporting ", loop->fname, loop->line), copy = true;
	export_to_gpu (s, "{");
      }
      else
	export_to_gpu (s, ",");
#else
      export_to_gpu (s, NULL);
#endif
    }
#if PRINTCOPYGPU
  if (copy)
    fputs ("} to GPU\n", stderr);
#endif
}

const char _double[] = "double";

static bool doloop_on_gpu (ForeachData * loop, const RegionParameters * region,
			   External * externals,
			   const char * kernel)
{
  GLuint shaderid = (long)loop->data;
  if (!loop->first && !shaderid)
    // already tried and failed, do not try again
    return false;

  const char * error = strstr (kernel, "@error ");
  if (error) {
    for (const char * s = error + 7; *s != '\n' && *s != '\0'; s++)
      fputc (*s, stderr);
    fputc ('\n', stderr);
    loop->data = NULL;
    return false;
  }

  int index = 1;
  for (scalar s in baseblock)
    if (s.input || s.output)
      s.gpu.index = index++;
    else
      s.gpu.index = 0;
  
  if (!(externals = merge_externals (externals, loop)))
    return false;
  
  for (const External * n = externals; n; n = n->next)
    if (strcmp(n->type, "scalar") && strcmp(n->type, "vector") && strcmp(n->type, "tensor")) {
      if (n->reduct && !strchr ("+mM", n->reduct)) {
	if (loop->first)
	  fprintf (stderr,
		   "%s:%d: GLSL: error: unknown reduction operation '%c'\n",
		   loop->fname, loop->line, n->reduct);
	return false;
      }
      if (!strcmp(n->type, "coord") || !strcmp(n->type, "_coord") || !strcmp(n->type, "vec4")) {
	if (n->reduct) {
	  if (loop->first)
	    fprintf (stderr,
		     "%s:%d: GLSL: error: reductions not implemented for '%s' type\n",
		     loop->fname, loop->line, n->type);
	  return false;	
	}
      }
      else if (strcmp (n->type, "float") &&
	       strcmp (n->type, "double") &&
	       strcmp (n->type, "int") &&
	       strcmp (n->type, "bool") &&
	       strcmp (n->type, "*func()") &&
	       strcmp (n->type, "func()")) {
	if (loop->first)
	  fprintf (stderr, "%s:%d: GLSL: error: unknown type '%s' for '%s'\n",
		   loop->fname, loop->line, n->type, n->name);
	return false;
      }
    }
    
  /**
  ## Allocate reduction fields */

  for (External * g = externals; g; g = g->next)
    if (g->reduct) {
      scalar s = new scalar;
      s.output = 1;
      g->s = s;
    }

  char * shader = build_shader (externals, loop->fname, loop->line);
  if (shader) {

    /**
    ## main() */
    
    shader = str_append (shader, "void main() { POINT_VARIABLES\n");
    foreach_texture (t)
      if (t->input >= 0 && t->output >= 0) {
	// initialize the central value of input/output fields
	char input[20], output[20];
	snprintf (input, 19, "%d", t->input);
	snprintf (output, 19, "%d", t->output);
	shader = str_append (shader, "  _outputs[", output, "] ="
			     " valt(_inputs[", input, "],0,0,0);\n");
      }
    shader = str_append (shader, kernel);
    for (const External * g = externals; g; g = g->next)
      if (g->reduct)
	shader = str_append (shader, "\nval_out_(", g->name, "_out_,0,0,0) = ", g->name, ";");
    shader = str_append (shader, "\n}\n");
    shaderid = load_shader (shader);
    loop->data = (void *) ((long) shaderid);
  }
    
  if (!shaderid) {

    if (loop->parallel == 3) // must run on GPU but cannot run
      exit (1);
    
    /**
    ## Free reduction fields */
    
    for (const External * g = externals; g; g = g->next)
      if (g->reduct) {
	scalar s = g->s;
	delete ({s});
      }
    return false;
  }
  
  inputs_to_gpu (loop);
  
  /**
  ## Allocate input/output texture */

  foreach_texture (t)
    if (t->input >= 0 && t->output >= 0 && t->width > 0) {
      int tmp = get_new_texture (t->type);
      t = ((Texture *)gpu_cartesian->texture->p) + _i;
      t->io = tex_texture (tmp);
#if DEBUG_ALLOC_TEXTURE
      fprintf (stderr, "%s:%d: input/output texture input: %d output: %d\n",
	       loop->fname, loop->line, t->id, t->io->id);
#endif
    }
  
  GL_C (glUseProgram (shaderid));

  /**
  ## Set input fields */

  foreach_texture (t)
    if (t->input >= 0) {
      GLint location;
      char s[30];
      snprintf (s, 29, "_inputs[%d]", t->input);
      location = glGetUniformLocation (shaderid, s);
    
      /** 
      If 'location' is negative the input field has been optimised out
      by the GLSL compiler. */
    
      if (location >= 0) {
	// fixme: check maximum of allowed textures
	GL_C (glUniform1i (location, t->input));
	GL_C (glActiveTexture (GL_TEXTURE0 + t->input));
	GL_C (glBindTexture (GL_TEXTURE_2D, t->id));
#if DEBUG_ALLOC_TEXTURE
	fprintf (stderr, "%s:%d: attached texture %d to _inputs[%d]\n",
		 loop->fname, loop->line, t->id, t->input);
#endif
      }
#if PRINTUNIFORM
      else
	fprintf (stderr, "%s:%d: '%s' not located (optimized out?)\n",
		 loop->fname, loop->line, s);
#endif
    }
  
  /**
  ## Set output fields */

  int draw_buffer = 0;
  foreach_texture (t)
    if (t->output >= 0) {
      if (t->io) { // swap input and output textures
	GLuint tex = t->io->id;
	t->io->id = t->id;
	t->io->used = false;
	t->io = NULL;
	t->id = tex;
      }
      GL_C (glFramebufferTexture2D (GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + t->output,
				    GL_TEXTURE_2D, t->id, 0));
      GL_C (glColorMaski (t->output, t->out[0], t->out[1], t->out[2], t->out[3]));
#if DEBUG_ALLOC_TEXTURE
      fprintf (stderr, "%s:%d: attached texture %d to _outputs[%d] mask [%d,%d,%d,%d]\n",
	       loop->fname, loop->line, t->id, t->output,
	       t->out[0], t->out[1], t->out[2], t->out[3]);
#endif
      if (t->output + 1 > draw_buffer)
	draw_buffer = t->output + 1;
    }

  if (draw_buffer) {
    GLenum DrawBuffers[draw_buffer];
    for (int i = 0; i < draw_buffer; i++)
      DrawBuffers[i] = GL_COLOR_ATTACHMENT0 + i;
    glDrawBuffers (draw_buffer, DrawBuffers);
  }

  /**
  ## Set global variables */

  int nreductions = 0;  
  for (const External * g = externals; g; g = g->next) {
    if (g->name[0] == '.') continue;
    if (!strcmp (g->type, "*func()") || !strcmp (g->type, "func()")) continue;
    if (g->reduct)
      nreductions++;
    if (!strcmp (g->type, "int") ||
	!strcmp (g->type, "float") ||
	!strcmp (g->type, "vec4")) {
      // not an array or just a one-dimensional array
      assert (!g->data || ((int *)g->data)[1] == 0);
      GLint location;
      char name[strlen(g->name) + strlen ("_in_[]") + 20];
      strcpy (name, g->name);
      if (g->reduct)
	strcat (name, "_in_");
      location = glGetUniformLocation (shaderid, name);
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
	char name[strlen(g->name) + strlen ("_in_[]") + 20];
	strcpy (name, g->name);
	if (g->reduct)
	  strcat (name, "_in_");
	if (d > 0) {
	  char s[22];
	  snprintf (s, 21, "[%d]", d);
	  strcat (name, s);
	}
	GLint location = glGetUniformLocation (shaderid, name);
	if (g->nd == 0) {
	  if (!strcmp (g->type, "double")) {
#if PRINTUNIFORM
	    fprintf (stderr, "uniform double %s = %g\n", g->name, *((double *)p));
#endif
	    glUniform1f (location, *((double *)p)); p = ((double *)p) + 1;
	  }
	  else if (!strcmp (g->type, "bool")) {
#if PRINTUNIFORM
	    bool * p = g->pointer;
	    fprintf (stderr, "uniform bool %s = %d\n", g->name, *p);
#endif
	    glUniform1i (location, *((bool *)p)); p = ((bool *)p) + 1;
	  }
	  else if (!strcmp (g->type, "coord")) {
#if PRINTUNIFORM
	    fprintf (stderr, "uniform coord %s = {%g,%g,%g}\n", g->name,
		     ((double *)p)[0], ((double *)p)[1], ((double *)p)[2]);
#endif
	    glUniform3f (location, ((double *)p)[0], ((double *)p)[1], ((double *)p)[2]); p = ((double *)p) + 3;
	  }
	  else if (!strcmp(g->type, "_coord")) {
#if PRINTUNIFORM
	    fprintf (stderr, "uniform _coord %s = {%g,%g}\n", g->name,
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
    
  /**
  ## Render 

  If this is a `foreach_point()` iteration, we draw a single point */

  if (region->n.x == 1 && region->n.y == 1) {
    int i =  (region->p.x - X0)/L0*cartesian->n;
    int j =  (region->p.y - Y0)/L0*cartesian->n;
    float vertices[] = { (i + 0.5)/cartesian->n, (j + 0.5)/cartesian->n };
    GLuint vbo;
    GL_C (glGenBuffers (1, &vbo));
    GL_C (glBindBuffer (GL_ARRAY_BUFFER, vbo));
    GL_C (glVertexAttribPointer ((GLuint)0, 2, GL_FLOAT, GL_FALSE,
				 2*sizeof(float), (void*)0));
    GL_C (glBufferData (GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));
    GL_C (glDrawArrays (GL_POINTS, 0, 1));
    GL_C (glBindBuffer (GL_ARRAY_BUFFER, GPUContext.vbo));
    GL_C (glVertexAttribPointer ((GLuint)0, 2, GL_FLOAT, GL_FALSE,
				 2*sizeof(float), (void*)0));
    glDeleteBuffers (1, &vbo);
  }

  /**
  This is a region */
  
  else if (region->n.x && region->n.y) {
    float vsScale[] = {
      (region->box[1].x - region->box[0].x)/L0,
      (region->box[1].y - region->box[0].y)/L0
    };
    float vsOrigin[] = { (region->box[0].x - X0)/L0, (region->box[0].y - Y0)/L0 };
    GLint location = glGetUniformLocation (shaderid, "vsOrigin");
    GL_C (glUniform2fv (location, 1, vsOrigin));
    location = glGetUniformLocation (shaderid, "vsScale");
    GL_C (glUniform2fv (location, 1, vsScale));
    GL_C (glDrawArrays (GL_TRIANGLES, 0, 6));
  }

  /**
  Otherwise, we draw "fullscreen". */
  
  else
    GL_C (glDrawArrays (GL_TRIANGLES, 0, 6));

  /**
  ## Perform reductions and cleanup */
  
  if (nreductions)
    tracing ("gpu_reduction", loop->fname, loop->line);
  for (const External * g = externals; g; g = g->next)
    if (g->reduct) {
      scalar s = g->s;
      double result = gpu_reduction (s, g->reduct, region);
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
  bool on_gpu = loop->parallel == 1 || loop->parallel == 3;
  if (on_gpu) {
    on_gpu = doloop_on_gpu (loop, region, externals, kernel);
    if (loop->first && !on_gpu)
      fprintf (stderr, "%s:%d: warning: loop done on CPU (see GLSL errors above)\n",
	       loop->fname, loop->line);
  }
  if (on_gpu) {
    // fixme: apply boundary conditions...
    free (loop->listc), loop->listc = NULL;
    foreach_dimension()
      free (loop->listf.x), loop->listf.x = NULL;
  }
  else
    inputs_from_gpu (loop);
  
  for (scalar s in baseblock)
    if (s.output)
      s.gpu.stored = on_gpu ? -1 : 1;

  return on_gpu;
}

static scalar gpu_cartesian_init_scalar (scalar s, const char * name)
{
  s = cartesian_init_scalar (s, name);
  gpu_init_scalar_texture (s);  
  return s;
}

static scalar gpu_cartesian_init_vertex_scalar (scalar s, const char * name)
{
  s = cartesian_init_vertex_scalar (s, name);
  gpu_init_scalar_texture (s);  
  return s;
}

static vector gpu_cartesian_init_vector (vector v, const char * name)
{
  v = cartesian_init_vector (v, name);
  gpu_init_vector_texture (v);
  return v;
}

static vector gpu_cartesian_init_face_vector (vector v, const char * name)
{
  v = cartesian_init_face_vector (v, name);  
  gpu_init_vector_texture (v);
  return v;
}

static tensor gpu_cartesian_init_tensor (tensor t, const char * name)
{
  t = cartesian_init_tensor (t, name);
  gpu_init_tensor_texture (t);
  return t;
}

static void gpu_cartesian_scalar_clone (scalar clone, scalar src)
{
  int stored = clone.gpu.stored, texture = clone.gpu.texture,
    type = clone.gpu.type, component = clone.gpu.component;
  tensor t = clone.gpu.t;
  cartesian_scalar_clone (clone, src);
  clone.gpu.stored = stored, clone.gpu.texture = texture, clone.gpu.type = type;
  clone.gpu.component = component;
  clone.gpu.t = t;
}

static void gpu_cartesian_methods()
{
  cartesian_methods();
  init_scalar        = gpu_cartesian_init_scalar;
  init_vertex_scalar = gpu_cartesian_init_vertex_scalar;
  init_vector        = gpu_cartesian_init_vector;
  init_face_vector   = gpu_cartesian_init_face_vector;
  init_tensor        = gpu_cartesian_init_tensor;
  scalar_clone       = gpu_cartesian_scalar_clone;
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

*/
