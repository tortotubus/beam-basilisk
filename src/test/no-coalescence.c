#include "grid/multigrid.h"
#include "navier-stokes/centered.h"
#include "vof.h"
#include "tension.h"
#include "view.h"
#include "two-phase.h"
#include "no-coalescence.h"

int main()
{
  size (4.);
  origin (-L0/2., -L0/2.);
  const face vector muc[] = {0.01,0.01};
  mu = muc;
  f.sigma = 1.;
  run();
}

event init (t = 0)
{
  fraction (f, max (- (sq(x + 1.) + sq(y) - sq(0.4)),
		    - (sq(x - 1.) + sq(y) - sq(0.5))));
  foreach()
    u.x[] = - 2* sign(x)*f[];
}

event movie (t += 0.08; t <= 3.)
{
  scalar inter[];
  foreach() 
    inter[] = 0;
  for(scalar s in interfaces)
    foreach()
      inter[] += s.i * s[];
  box();
  for (scalar s in interfaces){
    draw_vof(s.name, fc = {0.13,0.47,0.77}, min = 0, max = 3, lw = 2.);
  }
  squares("inter");
  save("movie.mp4");
  clear();

  box();
  for (scalar s in interfaces){
    draw_vof(s.name, fc = {0.13,0.47,0.77}, min = 0, max = 3, lw = 2.);
  }
  squares("u.x");
  save("velocity.mp4");
  clear();

  fprintf(qerr,"%g %d\n",t,list_len(interfaces));
}