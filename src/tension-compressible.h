/**
# Surface tension effects for the compressible solver 

<div class="message">
The documentation is missing.</div> */

#include "tension.h"

event end_timestep (i++)
{
  if (f.sigma > 0.) {
    scalar skappa[];
    curvature (f, skappa, f.sigma, add = false);

    face vector pf[];
    foreach_face() {
      if (f[1] + f[] > 0. && f[1] + f[] < 2.) {
	if (f[1] > f[])
	  pf.x[] = (1. - f[1])*skappa[1];
	else
	  pf.x[] = (1. - f[])*skappa[];
      }
      else
	pf.x[] = 0.;
    }

    foreach() {
      double div = 0.;
      foreach_dimension()
      div += pf.x[1]*uf.x[1] - pf.x[]*uf.x[];
      fE1[] -= f[]*div/Delta*dt/cm[];
    }

    foreach_face() {
      if (f[1] + f[] > 0. && f[1] + f[] < 2.) {
	if (f[1] > f[])
	  pf.x[] = - f[]*skappa[];
	else
	  pf.x[] = - f[1]*skappa[1];
      }
      else
	pf.x[] = 0.;
    }
    
    foreach() {
      double div = 0.;
      foreach_dimension()
	div += pf.x[1]*uf.x[1] - pf.x[]*uf.x[];
      fE2[] -= (1. - f[])*div/Delta*dt/cm[];
    }
  }
}
