/**
# A range of GPU tests */

#include "utils.h"

scalar s[], s1[];
vector v[];

void variable_list (scalar * list)
{
  foreach() {
    int i = 0;
    for (scalar s in list)
      s[] = 13 + i++;
  }
}

double myfunc2 (double x)
{
  return x;
}

double myfunc (double x)
{
  return myfunc2 (x);
}

void myfunc3 (double * a)
{
  *a += 2;
}

int main (int argc, char * argv[])
{
  init_grid (1);

#if 0  
  gpu_limits (stderr);
#endif

  /**
  ## Check input/output for vector fields */

  foreach()
    v.x[] = 1., v.y[] = 2.;
  foreach (serial)
    fprintf (stderr, "v.x: %g v.y: %g\n", v.x[], v.y[]);
  foreach()
    v.x[] += 1., v.y[] += 2.;
  foreach (serial)
    fprintf (stderr, "v.x: %g v.y: %g\n", v.x[], v.y[]);

  /**
  ## Check consistent writes to individual texture components */
  
  foreach()
    v.y[] = 3; // v.x[] should not be modified
  foreach (serial)
    fprintf (stderr, "v.x: %g v.y: %g\n", v.x[], v.y[]);

  /**
  ## Check consistent CPU copies of individual texture components */
  
  foreach (cpu)
    v.x[] = 4.;
  foreach()
    v.x[] += v.y[];
  foreach (serial)
    fprintf (stderr, "v.x: %g v.y: %g\n", v.x[], v.y[]);

  /**
  ## Check for "no inputs" */

  {
    scalar a[], b[];
    foreach() {
      a[] = 1.;
      b[] = 3. - a[];
    }
    foreach (serial)
      fprintf (stderr, "%g %g\n", a[], b[]);
  }
  
  /**
  ## A simple array */
  
  {
    double array[2] = {1.,2.};
    foreach() {
      s[] = array[0];
      s1[] = array[1];
    }
    foreach (serial)
      fprintf (stderr, "%g %g\n", s[], s1[]);
  }

  /**
  ## A "variable-size" array */

  {
    int nl = 2;
    double array[nl];
    array[0] = 3.; array[1] = 4.;
    foreach() {
      s[] = array[0];
      s1[] = array[1];
    }
    foreach (serial)
      fprintf (stderr, "%g %g\n", s[], s1[]);
  }

  /**
  ## List of scalars */

  scalar * list = {s, s1};
  foreach() {
    scalar a = list[0], b = list[1];
    a[] = 5., b[] = 6.;
  }
  foreach (serial)
    fprintf (stderr, "%g %g\n", s[], s1[]);
  
  foreach()
    s1[] = 7;
  
  foreach() {
    scalar a = list[0], b = list[1];
    a[] = b[];
  }
  foreach (serial)
    fprintf (stderr, "%g %g\n", s[], s1[]);

  /**
  ## List of vectors */

  {
    vector v[], v1[];
    vector * list = {v, v1};
    foreach() {
      vector a = list[0], b = list[1];
      foreach_dimension()
	a.x[] = 5., b.x[] = 6.;
    }
    foreach (serial)
      fprintf (stderr, "%g %g %g %g\n", v.x[], v.y[], v1.x[], v1.y[]);
  }

  /**
  ## For (scalar in ...) */

  foreach()
    for (scalar s in list)
      s[] = 12;
  foreach (serial)
    fprintf (stderr, "%g %g\n", s[], s1[]);

  /**
  ## A list with a single element */

  scalar * single = {s};
  foreach()
    for (scalar s in single)
      s[] = 12;
  
  /**
  ## An empty list */

  scalar * empty = NULL;
  foreach() {
    s1[] = 1.;
    for (scalar s in empty)
      s[] = 12;
  }
  
  /**
  ## For (s,v in list1,list2) */

  {
    vector v[], v1[];
    vector * list = {v, v1};
    scalar * list1 = {s, s1};
    foreach() {
      scalar s;
      vector v;
      for (s, v in list1, list) {
	s[] = 1;
	v.x[] = 2, v.y[] = 3;
      }
    }
    foreach (serial)
      fprintf (stderr, "%g %g %g %g %g %g\n", v.x[], v.y[], v1.x[], v1.y[], s[], s1[]);
  }

  /**
  ## Lists of variable length 

  This is not trivial to handle on GPUs since they do not allow for
  dynamic memory allocation. The solution is to use a different
  (compiled) static function for each list length... */

  variable_list ({s, s1});
  foreach (serial)
    fprintf (stderr, "%g %g\n", s[], s1[]);

  variable_list ({s1, s});
  foreach (serial)
    fprintf (stderr, "%g %g\n", s[], s1[]);

  scalar s2[];
  variable_list ({s, s1, s2});
  foreach (serial)
    fprintf (stderr, "%g %g %g\n", s[], s1[], s2[]);

  /**
  ## Functions with "inout" parameters */
  
  foreach() {
    double b = 0;
    myfunc3 (&b);
    myfunc3 (&b);
    s[] = b;
  }
  foreach (serial)
    fprintf (stderr, "%g\n", s[]);
  
  /**
  ## Functions */

  init_grid (16);
  foreach()
    s[] = myfunc (x);
  stats sf = statsf (s);
  fprintf (stderr, "%g %g %g\n", sf.min, sf.sum, sf.max);

  /**
  ## foreach_point() */

  init_grid (2);
  origin (-0.5, -0.5);
  foreach()
    s[] = 0.;
  for (double xp = - 0.24; xp < 0.5; xp += 0.5)
    for (double yp = - 0.24; yp < 0.5; yp += 0.5)
      foreach_point (xp, yp)
	s[] = (x + y) - (xp + yp);
  foreach (serial)
    fprintf (stderr, "%g %g %g\n", x, y, s[]);
  origin (0, 0);

  /**
  ## Interpolation
  
  This also tests foreach_point() and reductions. */
  
  foreach()
    s[] = x*y;
  fprintf (stderr, "%g %g\n",
	   interpolate (s, 0.5, 0.5, linear = false),
	   interpolate (s, 0.5, 0.5, linear = true));

  /**
  ## Other tests */
  
  init_grid (argc > 1 ? atoi(argv[1]) : 64);
  
  //  periodic (right);
  //  periodic (top);
  
  size (2.*pi);

  double a = 1., b = 1.;
  foreach()
    s1[] = s[] = cos(a*x)*cos(b*y);
  
  scalar p[], tmp[];
  reset ({p}, 0.);

  timer t = timer_start();
  int iter;
  for (iter = 0; iter < 40000*64/N; iter++) {

    /**
    There are two versions: the first one (commented out) used an
    explicit temporary field to avoid concurrent read/write accesses
    to 'p'. 
    
    The second one will use concurrent read/write accesses on the CPU
    but will automatically use a temporary texture on the GPU (because
    concurrent read/writes accesses are not possible on the GPU). The
    GPU version is then exactly identical to the first version. */
    
#if 0    
    foreach()
      tmp[] = (p[1] + p[-1] + p[0,1] + p[0,-1] - s[]*sq(Delta))/4.;
    swap (scalar, tmp, p);
#elif 1
    foreach()
      p[] = (p[1] + p[-1] + p[0,1] + p[0,-1] - s[]*sq(Delta))/4.;
#else
    scalar * list = {p};
    foreach()
      for (int i = 0; i < 1; i++) { scalar p = list[i];
	p[] = (p[1] + p[-1] + p[0,1] + p[0,-1] - s[]*sq(Delta))/4.; }
#endif
  }

#if GPU
  glFinish(); // make sure rendering is done on the GPU
#endif
  
  double elapsed = timer_elapsed (t);
  fprintf (stdout, "N: %d elapsed: %g speed: %g\n",
	   N, elapsed, grid->tn*iter/elapsed);

  stats sp = statsf (p);
  fprintf (stderr, "sp: %g %g %g\n", sp.min, sp.sum, sp.max);
  
#if 0
  foreach (serial)
    printf ("%g %g %g %g\n", x, y, p[], s1[]);
#else
  output_ppm (p, file = "p.png", n = 512, spread = -1);
  output_ppm (s1, file = "s1.png", n = 512, spread = -1);
#endif
}
