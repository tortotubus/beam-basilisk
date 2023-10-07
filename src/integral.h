/**
# Integral formulation for surface tension

See [Al Saud et al., 2018](alsaud2018) for details.

The surface tension field $\sigma$ will be associated to each levelset
tracer. This is done easily by adding the following [field
attributes](/Basilisk C#field-attributes). */

extern scalar * tracers;

attribute {
  scalar sigma;
}

/**
Surface tension is a source term in the right-hand-side of the
evolution equation for the velocity of the [centered Navier--Stokes
solver](navier-stokes/centered.h) i.e. it is an acceleration. If
necessary, we allocate a new vector field to store it. */

event defaults (i = 0) {
  if (is_constant(a.x)) {
    a = new face vector;
    foreach_face() {
      a.x[] = 0.;
      dimensional (a.x[] == Delta/sq(DT));
    }
  }
}

/**
## Stability condition

The surface tension scheme is time-explicit so the maximum timestep is
the oscillation period of the smallest capillary wave.
$$
T = \sqrt{\frac{\rho_{m}\Delta_{min}^3}{\pi\sigma}}
$$
with $\rho_m=(\rho_1+\rho_2)/2.$ and $\rho_1$, $\rho_2$ the densities
on either side of the interface. */

event stability (i++)
{
  double sigma = 0.;
  for (scalar d in tracers)
    if (is_constant (d.sigma))
      sigma += constant (d.sigma);
  double sigmamax = sigma;
  
  /**
  We first compute the minimum and maximum values of $\alpha/f_m =
  1/\rho$, as well as $\Delta_{min}$. */

  double amin = HUGE, amax = -HUGE, dmin = HUGE;
  foreach_face (reduction(min:amin) reduction(max:amax) reduction(min:dmin)
		reduction(max:sigmamax))
    if (fm.x[] > 0.) {
      if (alpha.x[]/fm.x[] > amax) amax = alpha.x[]/fm.x[];
      if (alpha.x[]/fm.x[] < amin) amin = alpha.x[]/fm.x[];
      if (Delta < dmin) dmin = Delta;

      /**
      The maximum timestep is set using the sum of surface tension
      coefficients. */

      double sigmai = sigma;
      for (scalar d in tracers)
	if (!is_constant (d.sigma) && fabs(d[]) < 2.*Delta) {
	  scalar sigmaf = d.sigma;
	  sigmai += sigmaf[];
	}
      if (sigmai > sigmamax)
	sigmamax = sigmai;
    }
  double rhom = (1./amin + 1./amax)/2.;

  if (sigmamax) {
    double dt = sqrt (rhom*cube(dmin)/(pi*sigmamax));
    if (dt < dtmax)
      dtmax = dt;
  }
}

#define CURVATURE 0 // set to 1 (resp. 2) to use curvature (resp. linear) interpolation of curvature

/**
## Curvature

This function computes the curvature from the levelset function *d* using:
$$
\kappa = \frac{d^2_xd_{yy} - 2d_xd_yd_{xy} + d^2_yd_{xx}}{|\nabla d|^3}
$$
*/

#if CURVATURE
static inline double distance_curvature (Point point, scalar d)
{
  double dx = (d[1] - d[-1])/2.;
  double dy = (d[0,1] - d[0,-1])/2.;
  double dxx = d[1] - 2.*d[] + d[-1];
  double dyy = d[0,1] - 2.*d[] + d[0,-1];
  double dxy = (d[1,1] - d[-1,1] - d[1,-1] + d[-1,-1])/4.;
  double dn = sqrt(sq(dx) + sq(dy)) + 1e-30;
  return (sq(dx)*dyy - 2.*dx*dy*dxy + sq(dy)*dxx)/cube(dn)/Delta;
}
#endif

/**
## Surface tension term

The calculation of the acceleration is done by this event, overloaded
from [its definition](navier-stokes/centered.h#acceleration-term) in
the centered Navier--Stokes solver. */

event acceleration (i++)
{
  
  /**
  We check whether surface tension is associated with any levelset
  function *d*. */

  for (scalar d in tracers)
    if (d.sigma.i) {
      (const) scalar sigma = d.sigma;
      
#if CURVATURE == 2
      /**
      We first compute the curvature. */

      scalar kappa[];
      foreach()
	kappa[] = distance_curvature (point, d);
#endif
      
      /**
      We allocate the surface tension stress tensor "manually",
      because the symmetries of the default tensor allocation in
      Basilisk are not what we want (this is messy). */

      scalar Sxx[], Sxy[], Syy[], Syx[];
      tensor S; S.x.x = Sxx, S.x.y = Sxy, S.y.y = Syy, S.y.x = Syx;

      /**
      We compute the diagonal components of the tensor. */
      
      foreach()
	foreach_dimension() {
	  S.y.y[] = 0.;
	  for (int i = -1; i <= 1; i += 2)
	    if (d[]*(d[] + d[i]) < 0.) {
	      double xi = d[]/(d[] - d[i]);
	      double nx = ((d[1] - d[-1])/2. +
			   xi*i*(d[-1] - 2.*d[] + d[1]))/Delta;
	      double sigmai = sigma[] + xi*(sigma[i] - sigma[]);
#if CURVATURE
#if CURVATURE == 2 // does not make much difference
              double ki = kappa[] + xi*(kappa[i] - kappa[]);
#else
	      double ki = distance_curvature (point, d);
#endif
	      S.y.y[] += sigmai*(fabs(nx)/Delta - sign(d[])*ki*(0.5 - xi));
#else
	      S.y.y[] += sigmai*fabs(nx)/Delta + (p[] - p[i])*(0.5 - xi);
#endif
	    }
        }

      /**
      We compute the off-diagonal components of the tensor.  */
      
      foreach_vertex()
	foreach_dimension()
	  if ((d[] + d[0,-1])*(d[-1] + d[-1,-1]) > 0.)
	    S.x.y[] = 0.;
	  else {
	    double xi = (d[-1] + d[-1,-1])/(d[-1] + d[-1,-1] - d[] - d[0,-1]);
	    double ny = (xi*(d[] - d[-1] + d[-1,-1] - d[0,-1]) +
			 d[-1] - d[-1,-1])/Delta;
	    double sigmai = (sigma[-1] + sigma[-1,-1] +
			     xi*(sigma[] + sigma[0,-1] - sigma[-1] -  sigma[-1,-1]))/2.;
	    S.x.y[] = - sigmai*sign(d[] + d[0,-1])*ny/Delta;
	  }

      /**
      Finally, we add the divergence of the surface tension tensor to
      the acceleration. */
      
      face vector av = a;
      foreach_face()
	av.x[] += alpha.x[]/(fm.x[] + SEPS)*(S.x.x[] - S.x.x[-1] + S.x.y[0,1] - S.x.y[])/Delta;      
    }
}

/**
## References

~~~bib
@hal{alsaud2018, hal-01706565}
~~~
*/

