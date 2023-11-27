/**
# Advection of two fluids at two different pressures

This problem proposed by [Johnsen and Colonius (JCP, 2006)](https://www.sciencedirect.com/science/article/pii/S0021999106002014) 
tests the solver for the 
advection of an interface between two different ideal gases
at uniform velocity and pressure
quantifying the amplitude of spurious pressure and velocity oscillations 
induced by the method when advecting an interface with different material properties.

$$(\rho,u,p,\gamma)^T_L = (1, 0.5, 1/1.4, 1.2)^T$$
$$(\rho,u,p,\gamma)^T_R = (10, 0.5, 1/1.4, 1.4)^T$$

By construction the method should keep the pressure and velocity uniform. During the advection step the energy is advected avoiding any diffusion and therefore 
both the provisional pressure and velocity are uniform and do not need to be corrected during the projection step.
*/

#include "grid/multigrid.h"
#include "two-phase-compressible.h"

/** We set the problem parameters, size domain and boundary conditions */
double rhoL = 1., rhoR = 10.;
double pL, pR;
double tend = 8;

int main() {

  L0 = 2. [1];
  X0 = Y0 = -L0/2.;
  
  TOLERANCE = 1e-6 [*];

  periodic (right); 
  
  pL = pR = 1./1.4;
  gamma1 = 1.2;
  gamma2 = 1.4;
  
  /**We use 1st order upwind method for advection*/
  f.gradient = zero;
 
  N = 128;
  run();

}

/** The initial conditions are: */
event init (i = 0) {
  
  double u0 = 0.5;
  foreach() {
    f[] = (x < 0.);
    p[] = f[]*pL + (1. - f[])*pR;
    frho1[] = f[]*rhoL;
    frho2[] = (1. - f[])*rhoR;
    fE1[] = f[]*pL/(gamma1 - 1.) +  0.5*frho1[]*pow(u0,2);
    fE2[] = (1.-f[])*pR/(gamma2 - 1.) +  0.5*frho2[]*pow(u0,2);
    q.x[] = (frho1[] + frho2[])*u0;
    q.y[] = 0.;
  }

  foreach_face(x) 
    uf.x[] = u0;

  foreach_face(y)
    uf.x[] = 0.;
}

/** We output the field variables at the end of the simulation */
event outputdata ( t = tend )
{  
  scalar perr[], uerr[];
  
  foreach () {
    
    perr[] = fabs(p[] - 1./1.4);
    uerr[] = fabs(q.x[]/rho[] - 0.5);

    double Ek = 0.;
    foreach_dimension ()
     Ek += pow(q.x[],2);
    
    fprintf (stderr, "%g %g %g %g %g %g %g \n", x, t, p[], rho[], q.x[]/(rho[]),f[],
	     (fE1[] + fE2[] - 0.5*Ek/rhov[])/(f[]/(gamma1-1.) + (1. - f[])/(gamma2 - 1.)));  
  }

  assert ( (statsf(perr).sum/pow(L0,2) < 1.e-3) && (statsf(uerr).sum/pow(L0,2) < 1.e-3) );
}

/**
*
Results shown in Figure 4 in [Fuster and Popinet (JCP, 2018)](https://hal.sorbonne-universite.fr/hal-01845218)

~~~gnuplot Pressure profile
set xlabel 'x'
set ylabel 'p'
set cblabel 't'
p "log" u 1:3 t 'Sim' w lp pt 6 
~~~ 
 
~~~gnuplot Density profile
reset
set xlabel 'x'
set ylabel '{/Symbol r}'
set cblabel 't'
p "log" u 1:4 t 'Sim' w lp pt 6
~~~ 

~~~gnuplot Velocity profile
reset
set xlabel 'x'
set ylabel 'u'
set cblabel 't'
p "log" u 1:5 t 'Sim' w lp pt 6
~~~ 

~~~gnuplot VOF comp
reset
set xlabel 'x'
set ylabel 'VOF function'
set cblabel 't'
p "log" u 1:6 t 'f' w l
~~~ 
*/
