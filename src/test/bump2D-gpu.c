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
cd bump2D-gpu

OpenGL renderer string: NVIDIA GeForce RTX 3050 Ti Laptop GPU/PCIe/SSE2
Dedicated video memory: 4096 MB

__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia bump2D-gpu/bump2D-gpu 10

# Multigrid (GPU), 3615 steps, 13.271 CPU, 13.27 real, 2.86e+08 points.step/s, 28 var
   calls    total     self   % total   function
    7230     5.22     4.21     31.7%   foreach():/src/saint-venant.h:275
    7230     2.56     2.52     19.0%   foreach():/src/utils.h:266
    7230     2.49     2.43     18.3%   foreach():/src/saint-venant.h:321
    7230     2.40     2.33     17.6%   foreach():/src/saint-venant.h:129
    7230     0.74     0.73      5.5%   gpu_reduction():/src/saint-venant.h:207
    7230    10.83     0.51      3.8%   update_saint_venant():/src/saint-venant.h:331
      27     0.16     0.16      1.2%   gpu_cpu_sync_scalar():/src/grid/gpu/grid.h:1085

# Multigrid (GPU), 3615 steps, 15.0121 CPU, 15.01 real, 2.53e+08 points.step/s, 28 var
   calls    total     self   % total   function
    7230     6.17     4.40     29.3%   foreach():/src/saint-venant.h:275
    7230     2.47     2.46     16.4%   foreach():/src/saint-venant.h:321
    7230     3.17     2.37     15.8%   foreach():/src/utils.h:266
    7230     2.35     2.34     15.6%   foreach():/src/saint-venant.h:129
   28920     0.87     0.81      5.4%   foreach():/src/grid/gpu/grid.h:967
   28920     0.75     0.71      4.7%   foreach():/src/grid/gpu/grid.h:970
    7230    12.56     0.71      4.7%   update_saint_venant():/src/saint-venant.h:331
    7230     0.71     0.71      4.7%   gpu_reduction():/src/saint-venant.h:207
      35     0.14     0.14      0.9%   gpu_cpu_sync_scalar():/src/grid/gpu/grid.h:897
   14460     1.74     0.11      0.7%   boundary_internal():/src/grid/gpu/../cartesian-common.h:535
   86763     0.11     0.11      0.7%   hash_shader():/src/grid/gpu/grid.h:362
       1    15.02     0.09      0.6%   run():/src/predictor-corrector.h:75
      28     0.06     0.06      0.4%   load_shader():/src/grid/gpu/grid.h:679

glxinfo -B
...
Device: Mesa Intel(R) UHD Graphics (TGL GT1) (0x9a60)
...
Video memory: 3072MB

./bump2D-gpu/bump2D-gpu 10

# Multigrid (GPU), 3615 steps, 12.479 CPU, 126.6 real, 2.99e+07 points.step/s, 28 var
   calls    total     self   % total   function
    7230    52.79    44.67     35.3%   foreach():/src/saint-venant.h:275
    7230    37.79    37.41     29.5%   foreach():/src/utils.h:266
    7230    18.81    18.26     14.4%   foreach():/src/saint-venant.h:321
    7230    16.13    15.55     12.3%   foreach():/src/saint-venant.h:129
    7230     7.37     7.36      5.8%   gpu_reduction():/src/saint-venant.h:207

# Multigrid (GPU), 3615 steps, 16.9834 CPU, 122.1 real, 3.11e+07 points.step/s, 28 var
   calls    total     self   % total   function
    7230    55.93    43.23     35.4%   foreach():/src/saint-venant.h:275
    7230    31.29    25.33     20.8%   foreach():/src/utils.h:266
    7230    17.92    17.87     14.6%   foreach():/src/saint-venant.h:321
    7230    15.25    15.20     12.4%   foreach():/src/saint-venant.h:129
   28920     6.43     6.35      5.2%   foreach():/src/grid/gpu/grid.h:967
    7230     6.33     6.32      5.2%   gpu_reduction():/src/saint-venant.h:207
   28920     5.24     5.17      4.2%   foreach():/src/grid/gpu/grid.h:970
    7230   106.47     1.32      1.1%   update_saint_venant():/src/saint-venant.h:331

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
