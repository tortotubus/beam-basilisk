/**
# Time-reversed advection in a vortex

~~~gnuplot Error field for N = 256
set term @PNG enhanced size 640,640 font ",10"
set output 'error.png'
set pm3d
set pm3d map interpolate 1,1
set palette defined ( 0 0 0 0.5647, 0.125 0 0.05882 1, 0.25 0 0.5647 1,\
     0.375 0.05882 1 0.9333, 0.5 0.5647 1 0.4392, 0.625 1 0.9333 0, 0.75 1 0.4392 0,\
     0.875 0.9333 0 0, 1 0.498 0 0 )
set size ratio -1
splot 'out' t ""
~~~

~~~gnuplot Convergence of the error with spatial resolution
reset
set term @SVG size 640,480 font ",10"
ftitle(a,b) = sprintf("%.0f/x^{%4.2f}", exp(a), -b)
f(x)=a+b*x
fit f(x) 'log' u (log($1)):(log($4)) via a,b
f2(x)=a2+b2*x
fit f2(x) 'log' u (log($1)):(log($2)) via a2,b2
set xlabel 'Maximum resolution'
set ylabel 'Maximum error'
set logscale
set xrange [32:512]
set xtics 32,2,512
set grid ytics
set cbrange [1:2]
plot 'log' u 1:4 t 'max', 'log' u 1:2 t 'norm1', \
      exp(f(log(x))) t ftitle(a,b),              \
      exp(f2(log(x))) t ftitle(a2,b2)
~~~
*/

#include "advection.h"

scalar f[];
scalar * tracers = {f};

int main (int argc, char * argv[])
{
  // coordinates of lower-left corner
  size (1.[0]); // dimensionless
  origin (-0.5, -0.5);
  // maximum timestep
  DT = .1;
  // CFL number
  CFL = 0.8;
  for (N = 64; N <= (argc == 1 ? 256 : atoi(argv[1])); N *= 2)
    run();
}

#define bump(x,y) (exp(-100.*(sq(x + 0.2) + sq(y + .236338))))

event init (i = 0)
{
  foreach()
    f[] = bump(x,y);
}

event velocity (i++) {
  vertex scalar psi[];
  foreach_vertex()
    psi[] = - 1.5*sin(2.*pi*t/5.)*sin((x + 0.5)*pi)*sin((y + 0.5)*pi)/pi;
  trash ({u});
  coord f = {-1.,1.};
  foreach_face()
    u.x[] = f.x*(psi[0,1] - psi[])/Delta;
}

event logfile (t = {0,5}) {
  stats s = statsf (f);
  fprintf (stderr, "# %f %.12f %g %g\n", t, s.sum, s.min, s.max);
}

event field (t = 5) {
  scalar e[];
  foreach()
    e[] = f[] - bump(x,y);
  norm n = normf (e);
  fprintf (stderr, "%d %g %g %g\n", N, n.avg, n.rms, n.max);
  
  if (N == 256)
    output_field ({e}, stdout, N);
}

#if 0 // Uncomment for real-time display when running on GPUs
event display (i++)
{
  output_ppm (f, fps = 30, map = jet, spread = -1, linear = false, n = 512);
}
#endif

/**
## Benchmark on GPUs

~~~bash
cd $BASILISK/src/test/
make advection.gpu.tst

cd advection.gpu
glxinfo -B

...
Device: Mesa Intel(R) UHD Graphics (TGL GT1) (0x9a60)
...
Video memory: 3072MB

./advection.gpu/advection.gpu 2048 2> /dev/null | grep steps

# Multigrid (GPU), 412 steps, 0.064315 CPU, 0.1119 real, 1.51e+07 points.step/s, 8 var
# Multigrid (GPU), 796 steps, 0.086363 CPU, 0.258 real, 5.05e+07 points.step/s, 8 var
# Multigrid (GPU), 1566 steps, 0.218996 CPU, 0.9957 real, 1.03e+08 points.step/s, 8 var
# Multigrid (GPU), 3100 steps, 1.24108 CPU, 6.538 real, 1.24e+08 points.step/s, 8 var
# Multigrid (GPU), 6163 steps, 4.01258 CPU, 43.59 real, 1.48e+08 points.step/s, 8 var

OpenGL renderer string: NVIDIA GeForce RTX 3050 Ti Laptop GPU/PCIe/SSE2
Dedicated video memory: 4096 MB

__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia ./advection.gpu/advection.gpu 2048 2> /dev/null | grep steps

# Multigrid (GPU), 412 steps, 0.058513 CPU, 0.05867 real, 2.88e+07 points.step/s, 8 var
# Multigrid (GPU), 796 steps, 0.108939 CPU, 0.109 real, 1.2e+08 points.step/s, 8 var
# Multigrid (GPU), 1566 steps, 0.27631 CPU, 0.2764 real, 3.71e+08 points.step/s, 8 var
# Multigrid (GPU), 3100 steps, 0.8745 CPU, 0.8758 real, 9.28e+08 points.step/s, 8 var
# Multigrid (GPU), 6163 steps, 4.78215 CPU, 4.785 real, 1.35e+09 points.step/s, 8 var
# Multigrid (GPU), 12282 steps, 34.6086 CPU, 34.65 real, 1.49e+09 points.step/s, 8 var
~~~
*/
