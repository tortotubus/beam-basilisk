#include <gpu/glad.h>
#include <GLFW/glfw3.h>
#pragma autolink -L$BASILISK/gpu -lglfw -lgpu -ldl

static struct {
  ///// GPU /////
  GLFWwindow * window;
  GLuint vao, fbo0, vbo;  
} GPUContext = {0};

static void gpu_check_error (const char * stmt,
			     const char * fname, int line)
{
  GLenum err = glGetError();
  if (err != GL_NO_ERROR) {
    fprintf (stderr, "%s:%d: error: OpenGl %08x for '%s;'\n",
	     fname, line, err, stmt);
    abort();
  }
}

#ifdef NDEBUG
// helper macro that checks for GL errors.
#define GL_C(stmt) do {	stmt; } while (0)
#else
// helper macro that checks for GL errors.
#define GL_C(stmt) do {							\
    stmt;								\
    gpu_check_error (#stmt, __FILE__, LINENO);				\
  } while (0)
#endif

void gpu_free_solver (void)
{
  GL_C (glFinish());
  GL_C (glBindFramebuffer (GL_FRAMEBUFFER, 0));
  glDeleteBuffers (1, &GPUContext.vbo);  
  glDeleteVertexArrays (1, &GPUContext.vao);
  glDeleteFramebuffers (1, &GPUContext.fbo0);  
  glfwTerminate();
  GPUContext.window = NULL;
}

static char * getShaderLogInfo (GLuint shader)
{
  char * infoLog = NULL;
  GLint len;
  GL_C (glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &len));
  if (len > 0) {
    GLsizei actualLen;
    infoLog = malloc (len);
    GL_C (glGetShaderInfoLog (shader, len, &actualLen, infoLog));
  }
  return infoLog;
}

static char * getProgramLogInfo (GLuint program)
{
  char * infoLog = NULL;
  GLint len;
  GL_C (glGetProgramiv (program, GL_INFO_LOG_LENGTH, &len));
  if (len > 0) {
    GLsizei actualLen;
    infoLog = malloc (len);
    GL_C (glGetProgramInfoLog (program, len, &actualLen, infoLog));
  }
  return infoLog;
}

char * gpu_errors (const char * errors, const char * source, char * fout);

static GLuint createShaderFromString (const char * shaderSource,
				      const GLenum shaderType)
{
  GLuint shader;

  GL_C (shader = glCreateShader(shaderType));
  GL_C (glShaderSource (shader, 1, &shaderSource, NULL));
  GL_C (glCompileShader (shader));

  GLint compileStatus;
  GL_C (glGetShaderiv (shader, GL_COMPILE_STATUS, &compileStatus));
  if (compileStatus != GL_TRUE) {
    char * info = getShaderLogInfo (shader);
#if PRINTSHADERERROR
    fputs (shaderSource, stderr);
#endif
    char * error = gpu_errors (info, shaderSource, NULL);
    fputs (error, stderr);
    sysfree (error);
    free (info);
    glDeleteShader (shader);
    return 0;
  }

  return shader;
}

static GLuint loadNormalShader (const char * vsSource, const char * fsShader)
{
  GLuint vs = createShaderFromString (vsSource, GL_VERTEX_SHADER);
  if (!vs)
    return 0;
  GLuint fs = createShaderFromString (fsShader, GL_FRAGMENT_SHADER);
  if (!fs)
    return 0;
  
  GLuint shader = glCreateProgram();
  glAttachShader (shader, vs);
  glAttachShader (shader, fs);
  glLinkProgram (shader);

  GLint Result;
  glGetProgramiv (shader, GL_LINK_STATUS, &Result);

  if (Result == GL_FALSE) {
    char * info = getProgramLogInfo (shader);
    fprintf (stderr, "GLSL: could not link shader \n\n%s\n%s\n%s\n",
	     info, vsSource, fsShader);
    free (info);
    glDeleteProgram (shader);
    shader = 0;
  }

  if (shader) {
    glDetachShader (shader, vs);
    glDetachShader (shader, fs);
  }
    
  glDeleteShader (vs);
  glDeleteShader (fs);
  
  return shader;
}

typedef struct {
  char * s;
  int index;
} GLString;

GLString gpu_limits_list[] = {
  {"GL_MAX_DRAW_BUFFERS", GL_MAX_DRAW_BUFFERS},
  {"GL_MAX_VERTEX_UNIFORM_COMPONENTS", GL_MAX_VERTEX_UNIFORM_COMPONENTS},
  {"GL_MAX_VERTEX_UNIFORM_BLOCKS", GL_MAX_VERTEX_UNIFORM_BLOCKS},
  {"GL_MAX_VERTEX_OUTPUT_COMPONENTS", GL_MAX_VERTEX_OUTPUT_COMPONENTS},
  {"GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS", GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS},
  {"GL_MAX_VERTEX_OUTPUT_COMPONENTS", GL_MAX_VERTEX_OUTPUT_COMPONENTS},
#if 1  
  {"GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS", GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS},
  {"GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS", GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS},
  {"GL_MAX_TESS_CONTROL_INPUT_COMPONENTS", GL_MAX_TESS_CONTROL_INPUT_COMPONENTS},
  {"GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS", GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS},
  {"GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS", GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS},
  {"GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS", GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS},
  {"GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS", GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS},
  {"GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS", GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS},
  {"GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS", GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS},
  {"GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS", GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS},
  {"GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS", GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS},
  {"GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS", GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS},
#endif
#if 1  
  {"GL_MAX_COMPUTE_UNIFORM_COMPONENTS", GL_MAX_COMPUTE_UNIFORM_COMPONENTS},
  {"GL_MAX_COMPUTE_UNIFORM_BLOCKS", GL_MAX_COMPUTE_UNIFORM_BLOCKS},
  {"GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS", GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS},
#endif
  {"GL_MAX_GEOMETRY_UNIFORM_COMPONENTS", GL_MAX_GEOMETRY_UNIFORM_COMPONENTS},
  {"GL_MAX_GEOMETRY_UNIFORM_BLOCKS", GL_MAX_GEOMETRY_UNIFORM_BLOCKS},
  {"GL_MAX_GEOMETRY_INPUT_COMPONENTS", GL_MAX_GEOMETRY_INPUT_COMPONENTS},
  {"GL_MAX_GEOMETRY_OUTPUT_COMPONENTS", GL_MAX_GEOMETRY_OUTPUT_COMPONENTS},
  {"GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS", GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS},
  {"GL_MAX_GEOMETRY_OUTPUT_COMPONENTS", GL_MAX_GEOMETRY_OUTPUT_COMPONENTS},
  {"GL_MAX_FRAGMENT_UNIFORM_COMPONENTS", GL_MAX_FRAGMENT_UNIFORM_COMPONENTS},
  {"GL_MAX_FRAGMENT_UNIFORM_BLOCKS", GL_MAX_FRAGMENT_UNIFORM_BLOCKS},
  {"GL_MAX_FRAGMENT_INPUT_COMPONENTS", GL_MAX_FRAGMENT_INPUT_COMPONENTS},
  {"GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS", GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS},
  {"GL_MAX_FRAGMENT_IMAGE_UNIFORMS", GL_MAX_FRAGMENT_IMAGE_UNIFORMS},
  {"GL_MAX_IMAGE_UNITS", GL_MAX_IMAGE_UNITS},
  {NULL}
};
