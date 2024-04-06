#include "grid/gpu/cartesian.h"
#include "saint-venant.h"

int LEVEL = 7;

int main (int argc, char * argv[])
{
  if (argc > 1)
    LEVEL = atoi (argv[1]);
  origin (-0.5, -0.5);
  periodic (right);
  periodic (top);
  init_grid (1 << LEVEL);
  run();
}

#if 0 // _GPU
event display (i++)
{
  output_ppm (h, map = blue_white_red, n = 1024, spread = -1, fps = 30, linear = true);
}
#endif

event init (i = 0)
{
  double a = 1., b = 200.;
  foreach()
    h[] = 0.1 + a*exp(- b*(x*x + y*y));
}

#if !BENCHMARK
event logfile (i++) {
  stats s = statsf (h);
  fprintf (stderr, "%g %d %g %g %.8f\n", t, i, s.min, s.max, s.sum);
}
#endif

event outputfile (t <= 2.5; t += 2.5/8);

/**
## Benchmarks

Without any outputs (logfile() commented out).

~~~bash
CFLAGS='-DBENCHMARK -DTRACE=2' make bump2D-gpu.tst
# Ignore diff error since the log has not been generated
cd bump2D-gpu

OpenGL renderer string: NVIDIA GeForce RTX 3050 Ti Laptop GPU/PCIe/SSE2
Dedicated video memory: 4096 MB

__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia ./bump2D-gpu 10 2> /dev/null

# Cartesian (GPU), 3615 steps, 11.7002 CPU, 11.7 real, 3.24e+08 points.step/s, 30 var
   calls    total     self   % total   function
    7230     4.76     4.05     34.6%   foreach():/home/popinet/basilisk-gpu/src/saint-venant.h:277
    7230     2.42     2.42     20.6%   foreach():/home/popinet/basilisk-gpu/src/utils.h:271
    7230     2.10     2.10     17.9%   foreach():/home/popinet/basilisk-gpu/src/saint-venant.h:322
    7230     1.80     1.80     15.4%   foreach():/home/popinet/basilisk-gpu/src/saint-venant.h:131
    7230     0.71     0.71      6.1%   gpu_reduction():/home/popinet/basilisk-gpu/src/saint-venant.h:209
    7230     9.78     0.50      4.3%   update_saint_venant():/home/popinet/basilisk-gpu/src/saint-venant.h:332
       1    11.71     0.09      0.8%   run():/home/popinet/basilisk-gpu/src/predictor-corrector.h:75

glxinfo -B
...
Device: Mesa Intel(R) UHD Graphics (TGL GT1) (0x9a60)
...
Video memory: 3072MB

./bump2D-gpu 10 2> /dev/null

# Cartesian (GPU), 3615 steps, 10.5471 CPU, 86.07 real, 4.4e+07 points.step/s, 30 var
   calls    total     self   % total   function
    7230    30.92    27.62     32.1%   foreach():/home/popinet/basilisk-gpu/src/saint-venant.h:277
    7230    26.37    26.37     30.6%   foreach():/home/popinet/basilisk-gpu/src/utils.h:271
    7230    14.80    14.80     17.2%   foreach():/home/popinet/basilisk-gpu/src/saint-venant.h:322
    7230    12.71    12.71     14.8%   foreach():/home/popinet/basilisk-gpu/src/saint-venant.h:131
    7230     3.31     3.31      3.8%   gpu_reduction():/home/popinet/basilisk-gpu/src/saint-venant.h:209
    7230    73.08     0.98      1.1%   update_saint_venant():/home/popinet/basilisk-gpu/src/saint-venant.h:332
       1    86.08     0.24      0.3%   run():/home/popinet/basilisk-gpu/src/predictor-corrector.h:75

cd ..
CFLAGS='-DTRACE=2 -grid=cartesian -fopenmp' make bump2D.tst
cd bump2D
OMP_NUM_THREADS=8 ./bump2D 10 2> /dev/null

# Cartesian, 3615 steps, 3220.14 CPU, 402.8 real, 9.41e+06 points.step/s, 28 var
   calls    total     self   % total   function
    7230   303.74   301.49     74.8%   update_saint_venant():/home/popinet/basilisk-gpu/src/saint-venant.h:335
    7230    98.86    98.86     24.5%   advance_saint_venant():/home/popinet/basilisk-gpu/src/saint-venant.h:133
   14460     2.24     2.24      0.6%   boundary_internal():/home/popinet/basilisk-gpu/src/grid/cartesian-common.h:531
       1   402.81     0.20      0.1%   run():/home/popinet/basilisk-gpu/src/predictor-corrector.h:75
~~~
*/
