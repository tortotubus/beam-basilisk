/**
# Propagation of an acoustic disturbance in a tube

This test is the axisymmetric variant of the results presented in Section 4.1 in [Fuster and Popinet (JCP, 2018)](https://hal.sorbonne-universite.fr/hal-01845218).
We quantify the dissipation properties of the all-Mach solver in the acoustic limit
by simulating the propagation of a gaussian pulse of small amplitude.
The results can be compared with the results obtained with a classical
[Riemann solver](http://basilisk.fr/sandbox/fuster/RiemannSolverExamples/gaussian.c)
*/

#include "grid/multigrid.h"
/** We use the two-phase flow formulation */

#include "axi.h"
#include "two-phase-compressible.h"

/** Parameters of the problem */
double tend = 3.;
double cflac = 0.1;

event stability (i++) {
  double dt = 100.;
  foreach ()
    dt = min(dt,Delta/sqrt(gamma1));
  dtmax = dt*cflac;
  DT = dt*cflac;
}


int main()
{  
  
  /** Size of the domain: */

  size (20. [0]); // fixme: this should work with dimensions
  DT = HUGE [0];
  
  X0 = -L0/2.;

  /** The EOS for an adiabatic perfect gas is defined by its polytropic coefficient $\Gamma = \gamma = 1.4$ */
  gamma1 = 1.4;
  
  /** We use an upwind method for the tracer advection associated to the VOF tracer f*/
  f.gradient = zero; 

  /** We perform a convergence study */
  N = 128;
  for (cflac = 0.01; cflac <= 100; cflac *= 5)
    run();
}

event init (i = 0)
{   
  double cson = sqrt(gamma1);

  foreach() {
    f[] = 1.;
    p[] = (1.+ 1.e-3*exp(-x*x));
    frho1[] = (1. + (p[] - 1.)/sq(cson));
    q.x[] = 0.;
    q.y[] = 0.;
    fE1[] = p[]/(gamma1 - 1.) + 0.5*pow(q.x[],2)/frho1[];
  }
}

event endprint (t = tend)
{  
  foreach () {
    double xref = fabs(x) - tend*sqrt(gamma1);
    fprintf(stderr, "%g %g %g \n", cflac, xref, (p[]-1.)/1.e-3);
  }
  fprintf(stderr, "\n");
}

/**

~~~gnuplot Pressure profile
set xrange[-3:3]
set cblabel 'log10(CFL)'
p "log" u 2:3:(log10($1)) not w lp pt 7 palette, 0.5*exp(-x*x) not w l lw 2 lc 0
~~~ 

*/
