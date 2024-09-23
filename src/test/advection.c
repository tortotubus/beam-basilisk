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

# Multigrid (GPU), 412 steps, 0.041317 CPU, 0.07295 real, 2.31e+07 points.step/s, 8 var
# Multigrid (GPU), 796 steps, 0.062611 CPU, 0.1866 real, 6.99e+07 points.step/s, 8 var
# Multigrid (GPU), 1566 steps, 0.188348 CPU, 0.8819 real, 1.16e+08 points.step/s, 8 var
# Multigrid (GPU), 3100 steps, 0.935142 CPU, 5.815 real, 1.4e+08 points.step/s, 8 var
# Multigrid (GPU), 6163 steps, 3.65141 CPU, 39.36 real, 1.64e+08 points.step/s, 8 var
# Multigrid (GPU), 12280 steps, 8.63733 CPU, 313.3 real, 1.64e+08 points.step/s, 8 var

OpenGL renderer string: NVIDIA GeForce RTX 3050 Ti Laptop GPU/PCIe/SSE2
Dedicated video memory: 4096 MB

__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia ./advection.gpu/advection.gpu 2048 2> /dev/null | grep steps

# Multigrid (GPU), 412 steps, 0.053072 CPU, 0.05309 real, 3.18e+07 points.step/s, 8 var
# Multigrid (GPU), 796 steps, 0.09939 CPU, 0.09939 real, 1.31e+08 points.step/s, 8 var
# Multigrid (GPU), 1566 steps, 0.252559 CPU, 0.2526 real, 4.06e+08 points.step/s, 8 var
# Multigrid (GPU), 3100 steps, 0.829254 CPU, 0.8297 real, 9.79e+08 points.step/s, 8 var
# Multigrid (GPU), 6163 steps, 4.60561 CPU, 4.609 real, 1.4e+09 points.step/s, 8 var
# Multigrid (GPU), 12282 steps, 33.5036 CPU, 33.5 real, 1.54e+09 points.step/s, 8 var

# Cartesian (GPU), 412 steps, 0.053788 CPU, 0.05393 real, 3.13e+07 points.step/s, 8 var
# Cartesian (GPU), 796 steps, 0.099883 CPU, 0.09993 real, 1.31e+08 points.step/s, 8 var
# Cartesian (GPU), 1566 steps, 0.251522 CPU, 0.2517 real, 4.08e+08 points.step/s, 8 var
# Cartesian (GPU), 3100 steps, 0.826971 CPU, 0.8277 real, 9.82e+08 points.step/s, 8 var
# Cartesian (GPU), 6163 steps, 4.63577 CPU, 4.649 real, 1.39e+09 points.step/s, 8 var
# Cartesian (GPU), 12282 steps, 34.2162 CPU, 34.22 real, 1.51e+09 points.step/s, 8 var
~~~
*/
