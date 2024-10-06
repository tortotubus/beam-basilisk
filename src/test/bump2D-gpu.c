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

#if 0
event display (i++)
{
  output_ppm (h, fp = NULL, map = blue_white_red, n = 1024, spread = -1, fps = 30, linear = true);
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
rm -f bump2D-gpu.tst && CFLAGS='-DBENCHMARK -DTRACE=2' make bump2D-gpu.tst
# Ignore diff error since the log has not been generated

OpenGL renderer string: NVIDIA GeForce RTX 3050 Ti Laptop GPU/PCIe/SSE2
Dedicated video memory: 4096 MB

__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia bump2D-gpu/bump2D-gpu 10

# Cartesian (GPU), 3615 steps, 13.3367 CPU, 13.34 real, 2.84e+08 points.step/s, 28 var
   calls    total     self   % total   function
    7230     5.12     4.23     31.7%   foreach():/src/saint-venant.h:275
    7230     2.60     2.57     19.2%   foreach():/src/utils.h:266
    7230     2.50     2.47     18.5%   foreach():/src/saint-venant.h:321
    7230     2.41     2.38     17.8%   foreach():/src/saint-venant.h:129
    7230     0.69     0.69      5.1%   gpu_reduction():/src/saint-venant.h:207
    7230    10.84     0.59      4.4%   update_saint_venant():/src/saint-venant.h:331
   28923     0.31     0.18      1.4%   setup_shader():/src/grid/gpu/grid.h:1403

glxinfo -B
...
Device: Mesa Intel(R) UHD Graphics (TGL GT1) (0x9a60)
...
Video memory: 3072MB

./bump2D-gpu/bump2D-gpu 10

# Cartesian (GPU), 3615 steps, 14.4777 CPU, 121 real, 3.13e+07 points.step/s, 28 var
   calls    total     self   % total   function
    7230    53.22    44.82     37.0%   foreach():/src/saint-venant.h:275
    7230    29.79    29.36     24.3%   foreach():/src/utils.h:266
    7230    19.10    18.53     15.3%   foreach():/src/saint-venant.h:321
    7230    16.67    16.05     13.3%   foreach():/src/saint-venant.h:129
    7230     7.57     7.55      6.2%   gpu_reduction():/src/saint-venant.h:207
   28923     2.45     1.96      1.6%   setup_shader():/src/grid/gpu/grid.h:1396
    7230   103.84     1.73      1.4%   update_saint_venant():/src/saint-venant.h:331

CFLAGS='-DTRACE=2 -grid=cartesian -fopenmp' make bump2D.tst
cd bump2D
OMP_NUM_THREADS=8 ./bump2D 10

# Cartesian, 3615 steps, 2115.91 CPU, 264.5 real, 1.43e+07 points.step/s, 27 var
   calls    total     self   % total   function
    7230   223.97   222.45     84.1%   update_saint_venant():/src/saint-venant.h:331
    7230    40.40    40.40     15.3%   advance_saint_venant():/src/saint-venant.h:130
   14460     1.52     1.52      0.6%   boundary_internal():/src/grid/cartesian-common.h:530
       1   264.52     0.14      0.1%   run():/src/predictor-corrector.h:75
~~~
*/
