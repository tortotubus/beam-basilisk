real cpu_reduction (GLuint src, size_t offset, size_t nb, const char op)
{
  GL_C (glBindBuffer (GL_SHADER_STORAGE_BUFFER, src));
  real result = 0., * a = glMapBufferRange (GL_SHADER_STORAGE_BUFFER,
					    offset*sizeof(real), nb*sizeof(real),
					    GL_MAP_READ_BIT);
  assert (a);
  switch (op) {
  case '+':
    for (int i = 0; i < nb; i++)
      result += a[i];
    break;
  case 'M':
    result = a[0];
    for (int i = 1; i < nb; i++)
      result = max (result, a[i]);
    break;
  case 'm':
    result = a[0];
    for (int i = 1; i < nb; i++)
      result = min (result, a[i]);
    break;
  default: assert (false);
  }
  assert (glUnmapBuffer (GL_SHADER_STORAGE_BUFFER));
  GL_C (glBindBuffer (GL_SHADER_STORAGE_BUFFER, 0));
  return result;
}

real gpu_reduction (scalar s, const char op, const RegionParameters * region)
{
  real result = 0.;
  size_t nb = sq(cartesian->n), offset = s.i*sq(cartesian->n + 2);

  if (region->n.x == 1 && region->n.y == 1) {
    int i =  (region->p.x - X0)/L0*cartesian->n;
    int j =  (region->p.y - Y0)/L0*cartesian->n;
    if (i >= 0 && i < cartesian->n && j >= 0 && j < cartesian->n) {
      GL_C (glBindBuffer (GL_SHADER_STORAGE_BUFFER, GPUContext.ssbo));
      real * a = glMapBufferRange (GL_SHADER_STORAGE_BUFFER,
				   offset*sizeof(real), nb*sizeof(real),
				   GL_MAP_READ_BIT);
      assert (a);
      result = a[i*cartesian->n + j];
      assert (glUnmapBuffer (GL_SHADER_STORAGE_BUFFER));
      GL_C (glBindBuffer (GL_SHADER_STORAGE_BUFFER, 0));
    }
    else
      assert (false); // not implemented yet
    return result;
  }

  const int stride = 64, nwgr = 64;
  if (nb < nwgr*stride)
    return cpu_reduction (GPUContext.ssbo, offset, nb, op);
  
  nb /= stride;
  assert (nb >= nwgr);
  
  GLuint * br = gpu_cartesian->reduct;
  if (!br[0]) {
    GL_C (glGenBuffers (2, br));
    for (int i = 0; i < 2; i++) {
      GL_C (glBindBuffer (GL_SHADER_STORAGE_BUFFER, br[i]));
      GL_C (glBufferData (GL_SHADER_STORAGE_BUFFER, nb*sizeof(real), NULL, GL_DYNAMIC_READ));
    }
    GL_C (glBindBuffer (GL_SHADER_STORAGE_BUFFER, 0));
  }
  
  const char * start, * operation;
  static const char * startsum = "reduct = 0.;",
    * opsum = "reduct += val;";
  static const char * startmin = "reduct = val;",
    * opmin = "if (val < reduct) reduct = val;";
  static const char * startmax = "reduct = val;",
    * opmax = "if (val > reduct) reduct = val;";
  switch (op) {
  case '+': start = startsum, operation = opsum; break;
  case 'M': start = startmax, operation = opmax; break;
  case 'm': start = startmin, operation = opmin; break;
  default: // unknown reduction operation
    assert (false);
  }

  char nwgrs[20], strides[20];
  snprintf (nwgrs, 19, "%d", nwgr);
  snprintf (strides, 19, "%d", stride);
  
  char * fs =
    str_append (NULL,
		"#version 430\n", glsl_preproc,
		"layout (std430, binding = 0) readonly buffer _data_layout {"
		" real _data[]; };\n"
		"layout (std430, binding = 1) writeonly buffer _reduct_layout {"
		" real _reduct[]; };\n"
		"uniform uint offset;\n"
		"const uint stride = ", strides, ";\n"
		"layout (local_size_x = ", nwgrs, ") in;\n"
		"void main() {\n"
		"  uint index = offset + stride*gl_GlobalInvocationID.x;\n"
		"  real val = _data[index];\n"
		"  real ", start, "\n"
		"  for (uint j = 0; j < stride; j++) {\n"
		"    val = _data[index + j];\n"
		"    ", operation, "\n"
		"  }\n"
		"  _reduct[gl_GlobalInvocationID.x] = reduct;\n"
		"}\n");
  GLuint shader = load_shader (fs);
  assert (shader);
  GL_C (glUseProgram (shader));
  GLint loffset = glGetUniformLocation (shader, "offset");
  assert (loffset >= 0);
  GL_C (glUniform1ui (loffset, offset));
  GL_C (glBindBufferBase (GL_SHADER_STORAGE_BUFFER, 0, GPUContext.ssbo));
  GL_C (glBindBufferBase (GL_SHADER_STORAGE_BUFFER, 1, br[1]));
  GL_C (glDispatchCompute (nb/nwgr, 1, 1));
  GL_C (glMemoryBarrier (GL_ALL_BARRIER_BITS));

  int src = 1, dst = 0;
  if (nb/stride > nwgr) {
    GL_C (glUniform1ui (loffset, 0));
    while (nb/stride > nwgr) {
      nb /= stride;
      GL_C (glBindBufferBase (GL_SHADER_STORAGE_BUFFER, 0, br[src]));
      GL_C (glBindBufferBase (GL_SHADER_STORAGE_BUFFER, 1, br[dst]));
      GL_C (glDispatchCompute (nb/nwgr, 1, 1));
      GL_C (glMemoryBarrier (GL_ALL_BARRIER_BITS));
      swap (int, src, dst);
    }
  }

  return cpu_reduction (br[src], 0, nb, op);
}
