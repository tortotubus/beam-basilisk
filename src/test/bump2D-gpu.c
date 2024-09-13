#include "grid/gpu/multigrid.h"
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
CFLAGS='-DBENCHMARK -DTRACE=2' make bump2D-gpu.tst
# Ignore diff error since the log has not been generated
cd bump2D-gpu

OpenGL renderer string: NVIDIA GeForce RTX 3050 Ti Laptop GPU/PCIe/SSE2
Dedicated video memory: 4096 MB

__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia bump2D-gpu/bump2D-gpu 10 2> /dev/null

# Cartesian (GPU), 3615 steps, 15.9482 CPU, 15.95 real, 2.38e+08 points.step/s, 28 var
   calls    total     self   % total   function
    7230     6.48     4.34     27.2%   foreach():/src/saint-venant.h:275
    7230     2.62     2.47     15.5%   foreach():/src/saint-venant.h:321
    7230     2.58     2.38     14.9%   foreach():/src/saint-venant.h:129
    7230     3.54     2.37     14.8%   foreach():/src/utils.h:266
   86763     0.95     0.95      6.0%   build_shader():/src/grid/gpu/cartesian.h:647
   28920     1.11     0.83      5.2%   foreach():/src/grid/gpu/cartesian.h:962
   28920     0.99     0.72      4.5%   foreach():/src/grid/gpu/cartesian.h:965
    7230     0.63     0.61      3.9%   gpu_reduction():/src/saint-venant.h:207
    7230    13.26     0.59      3.7%   update_saint_venant():/src/saint-venant.h:331
   93965     0.25     0.25      1.6%   load_shader():/src/grid/gpu/cartesian.h:657
      28     0.15     0.15      1.0%   load_shader():/src/grid/gpu/cartesian.h:684

glxinfo -B
...
Device: Mesa Intel(R) UHD Graphics (TGL GT1) (0x9a60)
...
Video memory: 3072MB

./bump2D-gpu/bump2D-gpu 10 2> /dev/null

# Cartesian (GPU), 3615 steps, 26.7441 CPU, 136 real, 2.79e+07 points.step/s, 28 var
   calls    total     self   % total   function
    7230    61.44    44.76     32.9%   foreach():/src/saint-venant.h:275
    7230    36.19    26.53     19.5%   foreach():/src/utils.h:266
    7230    19.35    18.61     13.7%   foreach():/src/saint-venant.h:321
    7230    17.09    16.06     11.8%   foreach():/src/saint-venant.h:129
   28920     9.30     7.74      5.7%   foreach():/src/grid/gpu/cartesian.h:962
    7230     6.84     6.77      5.0%   gpu_reduction():/src/saint-venant.h:207
   28920     7.93     6.58      4.8%   foreach():/src/grid/gpu/cartesian.h:965
   86763     5.24     5.24      3.9%   build_shader():/src/grid/gpu/cartesian.h:647
    7230   118.45     1.46      1.1%   update_saint_venant():/src/saint-venant.h:331

cd ..
CFLAGS='-DTRACE=2 -grid=cartesian -fopenmp' make bump2D.tst
cd bump2D
OMP_NUM_THREADS=8 ./bump2D 10 2> /dev/null

# Cartesian, 3615 steps, 2115.91 CPU, 264.5 real, 1.43e+07 points.step/s, 27 var
   calls    total     self   % total   function
    7230   223.97   222.45     84.1%   update_saint_venant():/src/saint-venant.h:331
    7230    40.40    40.40     15.3%   advance_saint_venant():/src/saint-venant.h:130
   14460     1.52     1.52      0.6%   boundary_internal():/src/grid/cartesian-common.h:530
       1   264.52     0.14      0.1%   run():/src/predictor-corrector.h:75
~~~
*/
