#define THERMAL 1
#include "compressible/two-phase.h"
#include "compressible/Mie-Gruneisen.h"

scalar T[], Ts[];
(const) scalar rhocp[], lambda2[], lambda4[];
(const) face vector kappaT[];


/** Variables of the NASG EOS */
double b1 = 0., b2 = 0.;
double qq1 = 0., qq2 = 0.;

double kappaT1 = 0., kappaT2 = 0.;
double cp1 = 0., cp2 = 0.;
double cv1 = 0., cv2 = 0.;

#ifndef kappaT
#define kappaT(f) (clamp(f,0.,1.)*(kappaT1 - kappaT2) + kappaT2) //Arithmetic mean
#endif

/**
Auxilliary fields need to be allocated. In particular the quantity $\rho c^2$ */

scalar rhocpv[];

scalar lambda2v[], lambda4v[];

/** Naive refinement method */
#if TREE
/** Different refine and prolongation functions are defined to respect equation of state
   when refining the cells, The energy is calculated from interpolated pressure to preserve smoothness.*/
void fE_refine_thermal(Point point, scalar s)
{
 foreach_child(){
   double Ek = 0.;
   foreach_dimension()
     Ek += sq(q.x[]);
   if (s.inverse)
      s[] = (p[] + gamma2*PI2)/(gamma2 - 1.)*(1. - f[] - frho2[]*b2) + frho2[]*qq2 + (0.5*Ek/(frho1[] + frho2[]))*(1. - f[]);
   else
      s[] = (p[] + gamma1*PI1)/(gamma1 - 1.)*(f[] - frho1[]*b1) + frho1[]*qq1 + (0.5*Ek/(frho1[] + frho2[]))*f[];
  }
}

#endif

/** We set the default values */



event defaults (i = 0)
{

  if (kappaT1 || kappaT2)
    kappaT = new face vector;

  rhocp = rhocpv;

  lambda2 = lambda2v;
  lambda4 = lambda4v;
  
#if TREE
    fE1.refine = fE1.prolongation = fE_refine_thermal;
    fE2.refine = fE2.prolongation = fE_refine_thermal; // The refine and prolongation functions for fE1 and fE2 are added as above
#endif

}

/** 
During the projection step we compute the provisional pressure from
the EOS using the values after advection */

event acceleration (i++)
{
  foreach() {
    double Ek = 0.;
    foreach_dimension()
      Ek += sq(q.x[]);

    double fc = clamp (f[],0.,1.);
    double invgammaavg = (fc - frho1[]*b1)/(gamma1 - 1.) +
      (1. - fc - frho2[]*b2)/(gamma2 - 1.);
    double PIGAMMAavg = PI1*gamma1*(fc - frho1[]*b1)/(gamma1 - 1.) + frho1[]*qq1 +
      PI2*gamma2*(1. - fc - frho2[]*b2)/(gamma2 - 1.) + frho2[]*qq2;
    
    ps[] = (fE1[] + fE2[] - Ek/(frho1[] + frho2[])/2. - PIGAMMAavg)/invgammaavg;
    
    /** We also compute $\rho c^2$ */
    //rhoc2v[] = (p[]*(invgammaavg + 1.) + PIGAMMAavg)/invgammaavg;
    //rhoc2v[] = 1./((fc - frho1[]*b1)/(gamma1*(p[] + PI1)) +
    //		   (1. - fc - frho2[]*b2)/(gamma2*(p[] + PI2)));
    double rhoc2v1 = fc ? gamma1*(p[] + PI1)/(1. - frho1[]*b1/fc) : 1.;
    double rhoc2v2 = (1. - fc) ? gamma2*(p[] + PI2)/(1. - frho2[]*b2/(1. - fc)) : 1.;
    /* // Harmonic mean of the mixture compressibility */
    /* rhoc2v[] = rhoc2v1*rhoc2v2/(rhoc2v1 + fc*(rhoc2v2 - rhoc2v1)); */
    // Arithmetic mean of the mixture compressibility
    rhoc2v[] = fc*rhoc2v1 + (1. - fc)*rhoc2v2;

    // Computation of a provisional temperature
    double rhocpmcvavg = (cp1 - cv1)*frho1[] + (cp2 - cv2)*frho2[];
    double const1 = (fc - frho1[]*b1) + (1. - fc - frho2[]*b2);
    double const2 = (fc - frho1[]*b1)*PI1 + (1. - fc - frho2[]*b2)*PI2;
    
    Ts[] = (const1*ps[] + const2)/rhocpmcvavg;

    rhocpv[] = cp1*frho1[] + cp2*frho2[];

    // Thermal dilation coefficient
    double betaT = /* fc*(gamma1 - 1.)*cv1/((gamma1 - 1.)*cv1*Ts[] + b1*(ps[] + PI1)) + */
      (1. - fc)*(gamma2 - 1.)*cv2/((gamma2 - 1.)*cv2*Ts[] + b2*(ps[] + PI2));
    lambda2v[] = cm[]*betaT*Ts[]/dt;
    lambda4v[] = betaT/rhocpv[]/dt;
  }
  
  /** If viscosity is present we obtain the averaged viscosity at the cell faces */
  foreach_face() {
    if (kappaT1 || kappaT2) {
      face vector kappaTv = kappaT;
      double ff = (f[] + f[-1])/2.;
      kappaTv.x[] = fm.x[]*kappaT(ff);
    }
  }

  boundary ((scalar *){kappaT,ps,rhoc2v,Ts,rhocpv,lambda2v,lambda4v});
  
}

/** 
After projection we update the values of the total energy adding the
term missing */

event end_timestep (i++)
{

  face vector gradTv[];
  foreach_face()
    gradTv.x[] = kappaT.x[]*face_gradient_x (T,0);
  /* boundary_flux ({gradTv}); */
  
  foreach () {
    double energy = 0.;
    foreach_dimension() {
      energy += gradTv.x[1] - gradTv.x[];
    }
    double fc = clamp(f[],0,1);
    fE1[] += fc*dt*energy/Delta/cm[];
    fE2[] += (1-fc)*dt*energy/Delta/cm[];
  }
  boundary ({fE1, fE2});

}

