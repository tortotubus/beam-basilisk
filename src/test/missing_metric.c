/**
# Bug in vof advection equation with embed + metric
 */

#define SHOW_ERROR 1

#if SHOW_ERROR
#include "embed.h"
#endif
#include "axi.h"
#define ro 1.2
#define veloc(r) (1./r)
#define fpos(t) sqrt(sq(ro) +2.*t)

#include "advection.h"
#include "vof.h"
#include "curvature.h"

scalar f[];
scalar * tracers = NULL;
scalar * interfaces = {f};

/**
 */

int main()
{
  X0 = -0.5;
  Y0 = 1.0;
  L0 = 1.0 [0];
  DT = 1.0 [0];
  N = 64;
  run();
}

event init (i = 0) {

  fraction(f, ro-y);

  /**
  The embed geometry is out of the computational domain. Therefore, no
  update is needed for *cm* and *fm*. */
  
#if SHOW_ERROR
  foreach()
    cs[] = 1.0;
  foreach_face()
    fs.x[] = 1.0;
#endif  

  foreach_face(y)
    u.y[] = veloc(y)*fm.y[];

  dt = dtnext (timestep (u, DT));
}

/**
## Results

We just compare analytical with numerical results... */


event prof_pos (i += 5; t <= 0.8) {
  scalar pos[];
  position (f, pos, {0,1.});
  fprintf (stdout, "%g %g %g \n", t, statsf(pos).max, fpos(t));
  
}

/**
~~~gnuplot Interface position
set terminal @PNG enhanced size 640,640 font ",12"
set xlabel 't'
set ylabel 'interface position'
plot 'out' u 1:2  t 'Numerical', 'out' u 1:3 w line t 'Theoretical'
~~~
*/
