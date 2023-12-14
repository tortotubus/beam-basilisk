/**
# Surface tension effects for the compressible solver 

This module incorporates surface tension effects in the compressible
solver. Unlike momentum, which is defined for the averaged mixture,
the energy is defined separately for both phases. For that reason, we
need to reconstruct the pressure of each phase from the averaged
pressure obtained from the Helmholtz--Poisson equation.

To reconstruct $p_1$ and $p_2$ from the averaged pressure $p$,
we interpret the averaged pressure as
$$p = f p_1 + (1-f) p_2$$
Using the Laplace equation
$$p_2 - p_1 = -\sigma \kappa + [[\mu n \cdot \tau \cdot n]]$$
we can solve the system of the two equations for $p_1$ and $p_2$
$$  p_1  = p + (1 - f) \sigma \kappa - (1-f) [[\mu n \cdot \tau \cdot n]]$$
$$  p_2  = p - f \sigma \kappa + f [[\mu n \cdot \tau \cdot n]]$$
The flux terms depending on pressure entering into the conservative total energy equation are
$$\nabla \cdot (u p_1) = \nabla \cdot (u p) + \nabla \cdot (u (1-f) \sigma \kappa) - 
                         \nabla \cdot (u (1-f) [[\mu n \cdot \tau \cdot n]])$$
$$\nabla \cdot (u p_2) = \nabla \cdot (u p) - \nabla \cdot (u f \sigma \kappa) + 
                         \nabla \cdot (u f [[\mu n \cdot \tau \cdot n]])$$

In this module we only introduce the correction due to surface tension. */

#include "tension.h"

event end_timestep (i++)
{
  if (f.sigma > 0.) {
    scalar skappa[];
    curvature (f, skappa, f.sigma);

    /** 
    Here we just introduce the correction due to the surface tension
    contribution to the pressure jump. */
    
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
      fE1[] += f[]*div/Delta*dt/cm[];
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
