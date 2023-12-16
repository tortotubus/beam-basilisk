/**
# Oscillation of a compressible gas bubble due to surface tension in a nearly incompressible liquid

*/



#include "axi.h"
#include "compressible/two-phase.h"
#include "compressible/Mie-Gruneisen.h"
#include "tension.h"
#include "compressible/tension.h"
#include "rayleigh-plesset.h"

int MINLEVEL = 5;
int MAXLEVEL;

double rhoL = 1., rhoG = 0.001;
double pg0=100.;
double pinf;
double tend = 0.4;

double Rbub = 1.;
double lambda = 40.;

scalar keliq[];

uf.n[right] = neumann(0.);
p[right]    = dirichlet(pinf);
q.n[right]  = neumann(0.);
f[right]    = dirichlet(1);
fE1[right]  = neumann(0.);

uf.n[top] = neumann(0.);
p[top]    = dirichlet(pinf);
q.n[top]  = neumann(0.);
f[top]    = dirichlet(1.);
fE1[top]  = neumann(0.);

uf.n[bottom] = 0.;
uf.t[bottom] = dirichlet(0.);


int main()
{
  
  pinf = pg0;

  mu1 = mu2 = 0;

  f.sigma = 1.;
    
  gamma2 = 1.4;
  gamma1 = 7.14;
  PI1 = 30000*pg0;
  double cliq = sqrt(gamma1*(pinf + PI1)/rhoL);

  struct RPdata RPd;
  RPd.rhol  = rhoL;
  RPd.pliq = pinf;
  RPd.p0 = pg0;

  RPd.sigma = f.sigma;
  RPd.gamma = gamma2;
  RPd.R0 = Rbub;
  RPd.visc = mu1;
  RPd.cson = cliq;
 
  FILE * fp = fopen("RP.dat", "w"); 
  Integrate_RP (fp, 0., tend, &RPd);
  fclose(fp);
  
  L0 = lambda;

  for (MAXLEVEL=9; MAXLEVEL <= 12; MAXLEVEL++) {
  	N = 1 << MINLEVEL;
  	run();
	free_grid();
  }

}

event init (i = 0)
{
  for (int l = MINLEVEL ; l <= MAXLEVEL; l++)
    refine (level < l && sqrt(sq(x) + sq(y)) < (2.5*Rbub + 4.*sqrt(2.)*lambda/(1<<(l-1))));

  fraction (f, sq(x) + sq(y) - sq(Rbub));
  
  foreach() {
    frho1[] = f[]*rhoL;
    frho2[] = (1. - f[])*rhoG;

    /** The initial liquid pressure field is approximated from the solution in the incompressible limit */
    double r = sqrt(sq(x) + sq(y));
    double pL = pinf*(1. - Rbub/r) + (pg0 - 2*f.sigma/Rbub)*Rbub/r;
	
    fE1[] = f[]*(pL/(gamma1 - 1.) + PI1*gamma1/(gamma1 - 1.));
    fE2[] = (1. - f[])*pg0/(gamma2 - 1.);
	
    double invgammaavg = f[]/(gamma1 - 1.) + (1. - f[])/(gamma2 - 1.);
    double PIGAMMAavg = (f[]*PI1*gamma1/(gamma1 - 1.) +
			 (1. - f[])*PI2*gamma2/(gamma2 - 1.));
	
    p[] = (fE1[] + fE2[] - PIGAMMAavg)/invgammaavg;

  }
}

event logfile (i++)
{
  scalar pgas[];
  double volume = 0.;
  double ekmax = 1e-20;
  
  foreach (reduction(+:volume) reduction(max:ekmax)) {
   
    double Ek = 0.;
    foreach_dimension()
      Ek += sq(q.x[]);
  
   /**
    * The gas pressure is recovered from the energy */ 
    pgas[] = (fE2[]- 0.5*Ek/(frho1[] + frho2[])*(1.-f[]))*(gamma2-1.);

    keliq[] = 0.5*(Ek/(frho1[] + frho2[]))*f[];
   
    ekmax = max(ekmax, keliq[]);
    volume += dv()*(1. - f[]);
  }

  if (i == 0)
    fprintf (stderr,"# t volume statsf(keliq).sum statsf(pgas).sum/volume\n");
  fprintf (stderr,"%10.9f %10.9f %10.9f %10.9f %i\n",
	   t, volume, statsf(keliq).sum, statsf(pgas).sum/volume, grid->n);

}

event end ( t = tend) {
	fprintf(stderr, "\n");
}


/**
Comparison with the Rayleigh-Plesset solution
~~~gnuplot Bubble radius as a function of time
set xlabel 't'
set ylabel 'R/R_0'
set cblabel 'N'
set key bottom
plot "log" u 1:($2*3.)**(1./3.):(sqrt($5)) w lp palette t "Basilisk",\
"RP.dat" u 1:3 w l lw 2 t 'Keller-Miksis'
~~~

For adiabatic gas transformations $P_b V_b^{\gamma}$ should remain constant inside the bubble
~~~gnuplot Entropy errors
set ylabel 'p V^{/Symbol g}'
plot "log" u 1:(($2*3.)**(1.4)*$4):(sqrt($5)) not w l palette
~~~

*/
