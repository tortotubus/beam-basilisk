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

__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia bump2D-gpu/bump2D-gpu 10 2> /dev/null

# Cartesian (GPU), 3615 steps, 12.3778 CPU, 12.38 real, 3.06e+08 points.step/s, 30 var
   calls    total     self   % total   function
    7230     4.95     3.90     31.5%   foreach():/src/saint-venant.h:275
    7230     2.57     2.29     18.5%   foreach():/src/utils.h:266
    7230     2.26     1.99     16.1%   foreach():/src/saint-venant.h:321
    7230     2.01     1.68     13.6%   foreach():/src/saint-venant.h:129
    7230     0.70     0.70      5.7%   gpu_reduction():/src/saint-venant.h:207
   28923     0.56     0.56      4.5%   build_shader():/src/grid/gpu/cartesian.h:620
   28923     0.52     0.52      4.2%   foreach():/src/grid/gpu/cartesian.h:1593
    7230    10.27     0.49      4.0%   update_saint_venant():/src/saint-venant.h:331

glxinfo -B
...
Device: Mesa Intel(R) UHD Graphics (TGL GT1) (0x9a60)
...
Video memory: 3072MB

./bump2D-gpu 10 2> /dev/null

# Cartesian (GPU), 3615 steps, 20.5449 CPU, 135.3 real, 2.8e+07 points.step/s, 30 var
   calls    total     self   % total   function
    7230    65.54    64.28     47.5%   foreach():/src/utils.h:266
    7230    35.28    28.91     21.4%   foreach():/src/saint-venant.h:275
    7230    17.01    15.86     11.7%   foreach():/src/saint-venant.h:321
    7230    15.31    13.68     10.1%   foreach():/src/saint-venant.h:129
    7230     4.70     4.70      3.5%   gpu_reduction():/src/saint-venant.h:207
   28923     3.87     3.85      2.8%   build_shader():/src/grid/gpu/cartesian.h:620
    7230   119.54     1.71      1.3%   update_saint_venant():/src/saint-venant.h:331

With outer loops at src/utils.h:265

# Cartesian (GPU), 3615 steps, 17.3946 CPU, 94.46 real, 4.01e+07 points.step/s, 30 var
   calls    total     self   % total   function
   28920    30.08    28.40     30.1%   foreach():/src/utils.h:265
    7230    32.63    27.99     29.6%   foreach():/src/saint-venant.h:275
    7230    16.18    15.47     16.4%   foreach():/src/saint-venant.h:321
    7230    14.02    12.94     13.7%   foreach():/src/saint-venant.h:129
    7230     3.92     3.92      4.1%   gpu_reduction():/src/saint-venant.h:207
   50613     2.86     2.83      3.0%   build_shader():/src/grid/gpu/cartesian.h:620
    7230    80.13     1.24      1.3%   update_saint_venant():/src/saint-venant.h:331

cd ..
CFLAGS='-DTRACE=2 -grid=cartesian -fopenmp' make bump2D.tst
cd bump2D
OMP_NUM_THREADS=8 ./bump2D 10 2> /dev/null

# Cartesian, 3615 steps, 3220.14 CPU, 402.8 real, 9.41e+06 points.step/s, 28 var
   calls    total     self   % total   function
    7230   303.74   301.49     74.8%   update_saint_venant():/src/saint-venant.h:335
    7230    98.86    98.86     24.5%   advance_saint_venant():/src/saint-venant.h:133
   14460     2.24     2.24      0.6%   boundary_internal():/src/grid/cartesian-common.h:531
       1   402.81     0.20      0.1%   run():/src/predictor-corrector.h:75
~~~

with compute shaders

~~~bash
__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia ./bump2D-gpu 10 2> /dev/null

# Cartesian (GPU), 3615 steps, 12.5313 CPU, 12.55 real, 3.02e+08 points.step/s, 30 var
   calls    total     self   % total   function
    7230     5.11     4.06     32.3%   foreach():/src/saint-venant.h:275
    7230     2.63     2.41     19.2%   foreach():/src/utils.h:266
    7230     2.21     2.02     16.1%   foreach():/src/saint-venant.h:321
    7230     1.98     1.73     13.7%   foreach():/src/saint-venant.h:129
    7230     0.78     0.78      6.2%   gpu_reduction():/src/saint-venant.h:207
   28923     0.58     0.58      4.6%   build_shader():/src/grid/gpu/cartesian.h:630
    7230    10.43     0.49      3.9%   update_saint_venant():/src/saint-venant.h:331
      11     0.20     0.20      1.6%   load_shader():/src/grid/gpu/cartesian.h:667

./bump2D-gpu/bump2D-gpu 10 2> /dev/null

# Cartesian (GPU), 3615 steps, 21.4548 CPU, 150.5 real, 2.52e+07 points.step/s, 30 var
   calls    total     self   % total   function
    7230    73.04    71.50     47.5%   foreach():/src/utils.h:266
    7230    41.48    34.97     23.2%   foreach():/src/saint-venant.h:275
    7230    17.28    15.87     10.5%   foreach():/src/saint-venant.h:321
    7230    16.41    14.52      9.6%   foreach():/src/saint-venant.h:129
   28923     4.77     4.75      3.2%   build_shader():/src/grid/gpu/cartesian.h:630
    7230     4.62     4.62      3.1%   gpu_reduction():/src/saint-venant.h:207
    7230   133.57     1.78      1.2%   update_saint_venant():/src/saint-venant.h:331
~~~

with SSBO

~~~bash
__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia ./bump2D-gpu/bump2D-gpu 10

# Cartesian (GPU), 3615 steps, 15.398 CPU, 15.4 real, 2.46e+08 points.step/s, 28 var
   calls    total     self   % total   function
    7230     6.68     4.38     28.4%   foreach():/src/saint-venant.h:275
    7230     3.40     2.36     15.3%   foreach():/src/utils.h:266
    7230     2.35     2.18     14.2%   foreach():/src/saint-venant.h:129
    7230     2.24     2.12     13.8%   foreach():/src/saint-venant.h:321
    7230     0.94     0.87      5.7%   gpu_reduction():/src/saint-venant.h:207
   86763     0.83     0.83      5.4%   build_shader():/src/grid/gpu/cartesian.h:628
   28920     1.02     0.79      5.1%   foreach():/src/grid/gpu/cartesian.h:959
   28920     0.91     0.68      4.4%   foreach():/src/grid/gpu/cartesian.h:962
    7230    12.96     0.60      3.9%   update_saint_venant():/src/saint-venant.h:331
  101194     0.23     0.23      1.5%   load_shader():/src/grid/gpu/cartesian.h:638

./bump2D-gpu/bump2D-gpu 10 2> /dev/null

# Cartesian (GPU), 3615 steps, 6.84099 CPU, 88.07 real, 4.3e+07 points.step/s, 30 var
   calls    total     self   % total   function
    7230    37.45    30.70     34.9%   foreach():/src/saint-venant.h:275
    7230    22.98    20.93     23.8%   foreach():/src/utils.h:266
    7230    14.32    14.19     16.1%   foreach():/src/saint-venant.h:321
    7230    12.43    12.25     13.9%   foreach():/src/saint-venant.h:129
    7230     4.21     4.05      4.6%   gpu_reduction():/src/saint-venant.h:207
   28920     2.18     1.92      2.2%   foreach():/src/grid/gpu/cartesian.h:959
   28920     1.91     1.65      1.9%   foreach():/src/grid/gpu/cartesian.h:962
   86763     0.92     0.92      1.0%   build_shader():/src/grid/gpu/cartesian.h:628
~~~
*/
