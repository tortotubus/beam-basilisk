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
  output_ppm (f, fps = 30, map = jet, spread = -1, linear = false);
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

./advection.gpu 2048 2> /dev/null | grep steps

# Cartesian (GPU), 412 steps, 0.05227 CPU, 0.07506 real, 2.25e+07 points.step/s, 10 var
# Cartesian (GPU), 796 steps, 0.095438 CPU, 0.1655 real, 7.88e+07 points.step/s, 10 var
# Cartesian (GPU), 1566 steps, 0.213242 CPU, 0.4688 real, 2.19e+08 points.step/s, 10 var
# Cartesian (GPU), 3100 steps, 0.473144 CPU, 1.919 real, 4.23e+08 points.step/s, 10 var
# Cartesian (GPU), 6163 steps, 3.72473 CPU, 18.4 real, 3.51e+08 points.step/s, 10 var
# Cartesian (GPU), 12280 steps, 13.0437 CPU, 172.7 real, 2.98e+08 points.step/s, 10 var

OpenGL renderer string: NVIDIA GeForce RTX 3050 Ti Laptop GPU/PCIe/SSE2
Dedicated video memory: 4096 MB

__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia ./advection.gpu 2048 2> /dev/null | grep steps

# Cartesian (GPU), 412 steps, 0.112393 CPU, 0.1124 real, 1.5e+07 points.step/s, 10 var
# Cartesian (GPU), 796 steps, 0.124608 CPU, 0.1246 real, 1.05e+08 points.step/s, 10 var
# Cartesian (GPU), 1566 steps, 0.31128 CPU, 0.3113 real, 3.3e+08 points.step/s, 10 var
# Cartesian (GPU), 3100 steps, 0.871066 CPU, 0.8711 real, 9.33e+08 points.step/s, 10 var
# Cartesian (GPU), 6163 steps, 4.51371 CPU, 4.514 real, 1.43e+09 points.step/s, 10 var
# Cartesian (GPU), 12282 steps, 30.6285 CPU, 30.63 real, 1.68e+09 points.step/s, 10 var

On CPU:

CFLAGS='-grid=cartesian -fopenmp' make advection.tst
cd ./advection/
OMP_NUM_THREADS=8 ./advection 1024 2> /dev/null | grep steps

# Cartesian, 412 steps, 0.532963 CPU, 0.06942 real, 2.43e+07 points.step/s, 7 var
# Cartesian, 796 steps, 1.50317 CPU, 0.1872 real, 6.97e+07 points.step/s, 7 var
# Cartesian, 1566 steps, 6.81518 CPU, 0.8633 real, 1.19e+08 points.step/s, 7 var
# Cartesian, 3100 steps, 44.2539 CPU, 5.531 real, 1.47e+08 points.step/s, 7 var
# Cartesian, 6163 steps, 913.012 CPU, 114.1 real, 5.66e+07 points.step/s, 7 var
~~~
*/
