/**
# Zero reflection of a wave propagating across an interface between two fluids with impedance matching

In this test proposed [Denner et al (JCP, 2018)](https://www.sciencedirect.com/science/article/pii/S0021999118302535)
a linear wave propagating in an ideal gas is completely transmitted to another ideal gas with the same acoustic impedance
*/

#include "two-phase-compressible.h"

/** Parameters of the problem */
double tend = 0.6;
double cflac = 0.1;
double uper = 0.0001;
double freq = 15.;
double p0, rho20;

event stability (i++) {
  double dt = 100.;
  foreach ()
    dt = min(dt,Delta);
  dtmax = dt*cflac;
  DT = dt*cflac;
}


int main()
{  
  
  /** The EOS for an adiabatic perfect gas is defined by its polytropic coefficient $\Gamma = \gamma$ */
  gamma1 = 9.872;
  gamma2 = 2.468;
  rho20  = 1.0/0.25;

  p0 = 1./gamma1;
  
  /** We use an upwind method for the tracer advection associated to the VOF tracer f*/
  f.gradient = zero; 

  L0 = 1. [0]; // fixme: this should work with dimensions
  DT = HUGE [0];
  
  N = 512;
  run();

}

event init (i = 0)
{   
  mask( y > 0.01 ? top : none); 

  foreach() {
    double perturb = uper*exp(-pow((x-0.3)*freq,2));
    f[] = ( x < 0.5);
    p[] = p0 + perturb;
    frho1[] = f[]*(1. + perturb);
    frho2[] = (1. - f[])*rho20;
    q.x[] = (frho1[] + frho2[])*perturb;
    q.y[] = 0.;
    fE1[] = f[]*p[]/(gamma1 - 1.) + 0.5*pow(q.x[]/(frho1[] + frho2[]),2)*frho1[];
    fE2[] = (1.-f[])*p[]/(gamma2 - 1.) + 0.5*pow(q.x[]/(frho1[] + frho2[]),2)*frho2[];
  }
  boundary ((scalar *){q, frho1, frho2,p, fE1, fE2});
}

event endprint ( t = tend) {
  
  scalar perr[];
  foreach () {
    perr[] = fabs((p[] - p0)/uper - exp(-sq((x-0.6)*freq*sqrt(gamma1*rho20/gamma2))));
    if (y < Delta)
      fprintf (stderr, "%g %g %g \n", t, x, (p[]-p0));
  }
  
  assert (statsf(perr).sum < 3.e-5);
}

/**
~~~gnuplot Perfect transmission
set ylabel '{/Symbol D}p/{/Symbol D}p_0'
set xlabel 'x'
set samples 1000
set arrow from 0.5,0 to 0.5,1 nohead lc 0
set label 'fluid 1' at 0.4,0.8
set label 'fluid 2' at 0.51,0.8
p "log" u 2:($3/0.0001) t 'tend' w l lc 1, exp(-((x-0.3)*15)**2) t 't=0' w l, exp(-((x-0.6)*15*sqrt(9.872/2.468/0.25))**2) t 'tend (theory)' w l
~~~
*/
