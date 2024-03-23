/**
## Output PPM to screen on GPUs

When running on GPUs the [output_ppm()](/src/output.h#output_ppm)
function can be used to display a field directly on the video
display. The syntax is the same as that of `output_ppm()` with the
exception of the `fps` parameter which specifies the maximum number of
frames-per-second to display.

For example

~~~literatec
  output_ppm (f, fps = 30, map = jet, spread = -1, linear = true);
~~~

will display field `f` with a maximum of 30 frames per second. 

When the mouse/keyboard focus is on the window, the following keys can
be used to control the simulation:

* SPACE : start/pause
* S : do a single timestep
* Q : exits

The simulation can also be started in 'pause' mode using

~~~literatec
  Display.paused = true;
~~~

before calling 'run()'. */

typedef struct {
  float frameStartTime;
  GLFWwindow * window;
} OutputPPMGPU;

static struct {
  bool paused, step;
} Display = {false, false};

static void key_callback (GLFWwindow * window, int key, int scancode, int action, int mods)
{
  switch (key) {
    
  case GLFW_KEY_SPACE:
    if (action == GLFW_RELEASE)
      Display.paused = !Display.paused;
    break;

  case GLFW_KEY_Q:
    if (action == GLFW_PRESS)
      exit (1);
    break;
    
  case GLFW_KEY_S:
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
      Display.paused = true;
      Display.step = true;
    }
    break;
    
  }
}

void output_ppm_gpu (OutputPPMGPU * display,
		     scalar f,
		     FILE * fp = stdout,
		     int n = N,
		     char * file = NULL,
		     float min = 0, float max = 0, float spread = 5,
		     double z = 0,
		     bool linear = false,
		     coord box[2] = {{X0, Y0}, {X0 + L0, Y0 + L0}},
		     scalar mask = {-1},
		     Colormap map = jet,
		     char * opt = NULL,
		     int fps = 0)
{
  if (display->frameStartTime < 0.) // window has been closed by user
    return;

  if (!fps || fp != stdout || file || glfwGetTime() - display->frameStartTime > 1./fps) {

    /**
    This code should be the same as
    [output_ppm](/src/output.h#output_ppm), from here ... */
    
    // default values
    if (!min && !max) {
      stats s = statsf (f);
      if (spread < 0.)
	min = s.min, max = s.max;
      else {
	double avg = s.sum/s.volume;
	min = avg - spread*s.stddev; max = avg + spread*s.stddev;
      }
    }
    box[0].z = z, box[1].z = z;
  
    coord cn = {n};
    double delta = (box[1].x - box[0].x)/n;
    cn.y = (int)((box[1].y - box[0].y)/delta);
    if (((int)cn.y) % 2) cn.y++;    
    
    /**
    ... to here. */
    
    GL_C (glBindFramebuffer (GL_FRAMEBUFFER, 0));
    if (!display->window) {
      glfwWindowHint (GLFW_VISIBLE, fps ? GL_TRUE : GL_FALSE);
      display->window = glfwCreateWindow (cn.x, cn.y, f.name, NULL, GPUContext.window);
      glfwSetKeyCallback (display->window, key_callback);
      glfwMakeContextCurrent (display->window);
      
      // Bind and create VAO, otherwise, we can't do anything in OpenGL.
      GLuint vao;
      GL_C (glGenVertexArrays (1, &vao));
      GL_C (glBindVertexArray (vao));

      // enable vertex buffer used for full screen quad rendering. 
      // this buffer is used for all rendering, from now on.
      GL_C (glEnableVertexAttribArray ((GLuint)0));
      GL_C (glBindBuffer (GL_ARRAY_BUFFER, GPUContext.vbo));
      GL_C (glVertexAttribPointer ((GLuint)0, 2, GL_FLOAT, GL_FALSE,
				   2*sizeof(float), (void*)0));
    }
    else {
      glfwSetWindowSize (display->window, cn.x, cn.y);
      glfwMakeContextCurrent (display->window);
    }
    
    GL_C (glViewport(0, 0, cn.x, cn.y));
    GL_C (glColorMask (GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE));
    GL_C (glClearColor (0.0f, 0.0f, 0.0f, 0.0f));
    GL_C (glClear (GL_COLOR_BUFFER_BIT));
  
    bool masked = mask.i >= 0;
    GLuint sampler = 0;
    if (linear) {
      GL_C (glGenSamplers (1, &sampler));
      GL_C (glSamplerParameteri (sampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
      GL_C (glSamplerParameteri (sampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
      GL_C (glBindSampler (0, sampler));
      if (masked)
	GL_C (glBindSampler (1, sampler));
    }
    
    double dmap[NCMAP][3];
    (* map) (dmap);
    vec4 cmap[NCMAP];
    for (int i = 0; i < NCMAP; i++) {
      cmap[i].r = dmap[i][0];
      cmap[i].g = dmap[i][1];
      cmap[i].b = dmap[i][2];
      cmap[i].a = 0.;
    }
    
    coord p;
    foreach_region (p, box, cn, gpu) {
      float m = masked ? mask[] : 0., v = m < 0. ? nodata : f[];
      if (v == nodata)
	FragColor = (vec4){0,0,0,0};
      else {
	int i;
	float val = max != min ? (v - min)/(max - min) : 0., coef;
	if (val <= 0.) i = 0, coef = 0.;
	else if (val >= 1.) i = NCMAP - 2, coef = 1.;
	else {
	  i = (int)(val*(NCMAP - 1));
	  coef = val*(NCMAP - 1) - i;
	}
	FragColor = mix (cmap[i], cmap[i + 1], coef);
      }
    }

    if (linear) {
      GL_C (glBindSampler (0, 0));
      if (masked)
	GL_C (glBindSampler (1, 0));
      GL_C (glDeleteSamplers (1, &sampler));
    }

    /**
    File output */
    
    if (file || fp) {
      if (file)
	fp = open_image (file, opt);
    
      fprintf (fp, "P6\n%g %g 255\n", cn.x, cn.y);
      unsigned char * ppm = malloc (sizeof(unsigned char)*3*cn.x*cn.y);
      GL_C (glReadPixels (0, 0, cn.x, cn.y, GL_RGB, GL_UNSIGNED_BYTE, ppm));
      size_t len = 3*cn.x;
      unsigned char * line = ppm + len*((size_t) cn.y - 1);
      for (int i = 0; i < cn.y; i++, line -= len)
	fwrite (line, sizeof(unsigned char), len, fp);
      free (ppm);
    
      if (file)
	close_image (file, fp);
      else
	fflush (fp);
    }

    if (fps)
    glfwSwapBuffers (display->window);
    
    glfwMakeContextCurrent (GPUContext.window);
    GL_C (glBindFramebuffer (GL_FRAMEBUFFER, GPUContext.fbo0));
    GL_C (glViewport (0, 0, cartesian->n, cartesian->n));
    
    display->frameStartTime = glfwGetTime();
  }

  if (fps) {
    do
      glfwPollEvents();
    while (Display.paused && !Display.step);
    Display.step = false;
  }
    
  if (display->window && glfwWindowShouldClose (display->window)) {
    glfwDestroyWindow (display->window);
    display->frameStartTime = -1; // window closed
    return;
  }
}

#define output_ppm(...) do {			\
    static OutputPPMGPU _display = {0};		\
    output_ppm_gpu (&_display, __VA_ARGS__);	\
  } while (0)
