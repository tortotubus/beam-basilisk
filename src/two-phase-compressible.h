/**
# A compressible two-phase flow solver

This solves the two-phase compressible Navier-Stokes equations
including the total energy equation.
$$
\frac{\partial (f \rho_i)}{\partial t } + 
\nabla \cdot (f \rho_i \mathbf{u}) = 0 
$$
$$
\frac{\partial (\rho_i \mathbf{u})}{\partial t } + 
\nabla \cdot ( \rho_i  \mathbf{u} \mathbf{u}) = 
-\nabla p + \nabla \cdot \tau_i' 
$$
$$
\frac{\partial [\rho_i (e_i + \mathbf{u}^2/2)]}{\partial t } 
+ \nabla \cdot [ \rho_i \mathbf{u} (e_i  + \mathbf{u}^2/2)] =
-\nabla \cdot (\mathbf{u} p_i) + 
\nabla \cdot \left( \tau'_i \mathbf{u} \right)
$$
an advection equation for the volume fraction $f$
$$
\frac{\partial f}{\partial t} + \mathbf{u} \cdot \nabla f = 0
$$
and an Equation Of State (EOS). Here we use the general EOS written in
the
[Mie--Gruneisen](https://en.wikipedia.org/wiki/Mie%E2%80%93Gr%C3%BCneisen_equation_of_state)
form
$$
\rho_i e_i = \frac{p_i + \Gamma_i \Pi_i}{\Gamma_i - 1}
$$

The method is described in detail in [Fuster & Popinet,
2018](#fuster2018) and relies on a time splitting technique were we
first solve the advection step using the VOF method for $f$, $f_i
\rho_i$, $f_i \rho_i \mathbf{u}$ $f_i \rho_i e_{tot,i}$ and then
perform the projection step using the all-Mach solver. */

#include "all-mach.h"

/**
We transport VOF tracers without the one-dimensional compressive term. */

#define NO_1D_COMPRESSION 1
#include "vof.h"

/**
The primary fields are:
$$
\begin{aligned}
\text{frho1} & = f \rho_1, \\
\text{frho2} & = (1-f) \rho_2, \\
\text{fE1} & = f \rho_1 e_1 + f \rho_1 \mathbf{u}^2, \\
\text{fE2} & = (1-f) \rho_2 e_2 + (1-f) \rho_2 \mathbf{u}^2 
\end{aligned}
$$
*/

scalar f[], * interfaces = {f};
scalar frho1[], frho2[], fE1[], fE2[];

/**
The coefficients of the Mie-Gruneisen EOS for each phase. */

double gamma1 = 1.4 [0], gamma2 = 1.4 [0], PI1 = 0., PI2 = 0.;

/**
The dynamic viscosities for each phase, as well as the volumetric
viscosity coefficients. */

double mu1 = 0., mu2 = 0.;
double lambdav1 = 0., lambdav2 = 0. ;

/**
By default the Harmonic mean is used to compute the phase-averaged
dynamic viscosity. */

#ifndef mu
# define mu(f) (mu1*mu2/(clamp(f,0,1)*(mu2 - mu1) + mu1))
#endif

/**
The volumetric viscosity uses arithmetic average by default. */

#ifndef lambdav
# define lambdav(f)  (clamp(f,0,1)*(lambdav1 - lambdav2) + lambdav2)
// # define lambdav(f)  (clamp(f,0.,1.)*(lambdav1 - lambdav2 - 2./3*(mu1 - mu2)) + lambdav2 - 2./3*mu2)
#endif

/**
## Auxilliary fields

Auxilliary fields need to be allocated. In particular the momentum of 
the second phase $\text{q2} = \rho_2 u$  and the quantity $\rho c^2$. */

vector q2[];
scalar rhoc2v[];

/**
We need to allocate fields to store the average density `rhov` and its
inverse `alphav`. */

face vector alphav[];
scalar rhov[];
const face vector lambdav0[] = {0,0,0};
(const) face vector lambdav = lambdav0;

/** 
## Refinement functions

Naive refinement method */
#if TREE
void conservative_refine (Point point, scalar s)
{
  double cc = f[];
  double scc = s[];
  if (cc <= 0. || cc >= 1.)
    refine_bilinear(point,s);
  else {

    /**
    Otherwise, we reconstruct the interface in the parent cell. */

    coord n = mycs (point, f);
    double alpha = plane_alpha (cc, n);

    /**
    And compute the volume fraction in the quadrant of the coarse cell
    matching the fine cells. We use symmetries to simplify the
    combinations. */

    coord a, b;
    foreach_dimension() {
      a.x = 0.; b.x = 0.5;
    }   
        
    foreach_child() {
      coord nc; 
      foreach_dimension()
        nc.x = child.x*n.x;
      double crefine = rectangle_fraction (nc, alpha, a, b); 
      if (s.inverse)
        s[] = scc/(1. - cc)*(1. - crefine);
      else
        s[] = scc/cc*crefine;
    }   
  }   
}

/** 
The energy is refined from the refined pressures and densities,
using the equation of state. */

void fE_refine (Point point, scalar s)
{
  foreach_child() {
    double Ek = 0.;
    foreach_dimension()
      Ek += sq(q.x[]);
    Ek /= 2.*(frho1[] + frho2[]);
    if (s.inverse)
      s[] = ((p[] + gamma2*PI2)/(gamma2 - 1.) + Ek)*(1. - f[]);
    else
      s[] = ((p[] + gamma1*PI1)/(gamma1 - 1.) + Ek)*f[];
  }
}
#endif // TREE

/**
## Initialisation

We set the default values. */

event defaults (i = 0)
{
  alpha = alphav;
  rho = rhov;

  /**
  If the viscosity is non-zero, we need to allocate the face-centered
  viscosity field. */
  
  if (mu1 || mu2) {
    mu = new face vector;
    lambdav = new face vector;
  }

  rhoc2 = rhoc2v;  
  foreach () {
    frho1[] = 1., fE1[] = 1.;
    frho2[] = 0., fE2[] = 0.;
    p[] = 1.;
    f[] = 1.;
  }

#if TREE
  p.refine = p.prolongation = refine_bilinear;
  for (scalar s in {frho1, frho2, q})
    s.refine = s.prolongation = conservative_refine;
  fE1.refine = fE1.prolongation = fE_refine;
  fE2.refine = fE2.prolongation = fE_refine;
#endif // TREE
  
  /** 
  We also initialize the list of tracers to be advected with the VOF
  function $f$ (or its complementary function). */
  
  f.tracers = list_copy ({frho1, frho2, fE1, fE2, q, q2});
  for (scalar s in {frho2, fE2, q2})
    s.inverse = true;

  /**
  We add the interface and the density to the default display. */

  display ("draw_vof (c = 'f');");
  display ("squares (color = 'rhov', spread = -1);");
}

event init (i = 0)
{
  trash ({uf});
  foreach_face()
    uf.x[] = fm.x[]*(q.x[]/(frho1[] + frho2[]) + q.x[-1]/(frho1[-1] + frho2[-1]))/2.;

  /**
  We update fluid properties. */

  event ("properties");

  /**
  We set the initial timestep (this is useful only when restoring from
  a previous run). */

  dtmax = DT;
  event ("stability");

  /** 
  For the associated tracers we use the advection scheme provided in
  f.gradient. */
  
  for (scalar s in {frho1, frho2, fE1, fE2, q, q2})
    s.gradient = f.gradient;  
}

/**
## VOF advection of momentum

Before the VOF advection step we recover the momentum of each phase
from the total momentum $\mathbf{q}$. */

event vof (i++)
{
  foreach()
    foreach_dimension() {
      double u = q.x[]/(frho1[] + frho2[]);
      q.x[]  = frho1[]*u;
      q2.x[] = frho2[]*u;
    }
}

/**
After advection we compute the total momentum $\mathbf{q}$. */

event tracer_advection (i++)
{
  foreach(){
    foreach_dimension()
      q.x[] += q2.x[];

    /**
    We avoid negative densities and energies which may have been
    caused by round-off during VOF advection. */
    
    if (f[] <= 0.){
      frho1[] = 0.;
      fE1[] = 0.;
    }
    if (f[] >= 1.){
      frho2[] = 0.;
      fE2[] = 0.;
    }
  }
}

/**
## Pressure and density

During the projection step we compute the provisional pressure from
the EOS using the values after advection. */

event properties (i++)
{
  foreach() {
    rhov[] = frho1[] + frho2[];
    
    double Ek = 0.;
    foreach_dimension()
      Ek += sq(q.x[]);

    double fc = clamp (f[],0,1);
    double invgammaavg = fc/(gamma1 - 1.) + (1. - fc)/(gamma2 - 1.);
    double PIGAMMAavg = (fc*PI1*gamma1/(gamma1 - 1.) +
			 (1. - fc)*PI2*gamma2/(gamma2 - 1.));
    ps[] = (fE1[] + fE2[] - Ek/(frho1[] + frho2[])/2. - PIGAMMAavg)/invgammaavg;
    
    /** 
    We also compute $\rho c^2$. */
    
    rhoc2v[] = (p[]*(invgammaavg + 1.) + PIGAMMAavg)/invgammaavg;
  }
  
  foreach_face() {
    
    /** 
    If viscosity is present we obtain the averaged viscosity at the cell faces. */
  
    if (mu1 || mu2) {
      face vector muv = mu, lambdavv = lambdav;
      double ff = (f[] + f[-1])/2.;
      muv.x[] = fm.x[]*mu(ff);
      lambdavv.x[] = lambdav(ff);
    }
    
    /** 
    We also compute the averaged density at the cell faces. */
    
    alphav.x[] = 2.*fm.x[]/(rhov[] + rhov[-1]);
  }

  /**
  The all-Mach solver needs rho*cm. */
  
  foreach()
    rhov[] *= cm[];
  
  /* I still miss a source term in the divergence related to viscous
   * dissipation. Usually it is small and a little bit complicated to
   * calculate. In the current form of allmach it cannot be added
   * because it does not allow user-defined divergence sources. */
}

/**
## Update of the total energy

After projection we update the values of the total energy adding the
term missing from the projection step.

For a Newtonian fluid, the stress tensor comprises the pressure term,
the viscous uncompressible term and the viscous compressible term,

$$ \tau = -p \mathbf{I} + \mu (\nabla \mathbf{u} + \nabla \mathbf{u}^T)
+ \lambda_v  (\nabla \cdot \mathbf{u}) \mathbf{I}
$$

where $\mathbf{I}$ is the unity tensor and $\lambda_v = \mu_v - 2/3
\mu$. The volumetric viscosity $\mu_v$ is negligible in most cases. */

event end_timestep (i++)
{

  /**
  We first compute the divergence of the velocity at cell centers
  using the cell face velocity. Note that the face vector *uf*
  incorporates the metric factor. */

  scalar divU[];
  foreach () {
    divU[] = 0.;
    foreach_dimension ()
      divU[] += (uf.x[1] - uf.x[])/(Delta*cm[]);
  }

  /**
  We compute explicitly the contribution of the compressible viscous
  term to the momentum equation and the total energy equation,
  $$
  \partial_t \mathbf{q} = \nabla \cdot [\lambda_v(\nabla \cdot \mathbf{u}) \mathbf{I}] 
  $$
  $$
  \partial_t [\rho (e + \mathbf{u}^2/2)] = 
  \nabla \cdot [\lambda_v (\nabla \cdot \mathbf{u}) \mathbf{u}] 
  $$

  The axysimmetric case allows some simplifications. Since
  $$
  \mathbf{S} = \lambda_v(\nabla \cdot \mathbf{u}) \mathbf{I} =
  \left( 
  \begin{array}{ccc}
  S_{xx} & 0 &  0 \				\
  0 &  S_{yy} &  0 \				\
  0 & 0 & S_{\theta \theta}  
  \end{array}
  \right)
  $$
  with $S = S_{xx} = S_{yy} = S_{\theta \theta}= \lambda_v \nabla
  \cdot \mathbf{u}$. Hence, the radial component of $\nabla \cdot
  \mathbf{S}$ is simply
  $$
  (\nabla \cdot \mathbf{S}) \cdot \mathbf{e}_y  = 
  \frac{1}{y} \frac{\partial(y S_{yy}) }{\partial y} 
  - \frac{S_{\theta \theta}}{y} 
  = \frac{\partial S }{\partial y}
  $$
  Also $u_\theta = 0$. */ 

  foreach () {
    double momentum = 0., energy = 0.;
    foreach_dimension() {
      double right = lambdav.x[1]*(divU[1]  + divU[])/2.;
      double left = lambdav.x[] *(divU[-1] + divU[])/2.;
      momentum += right - left;
      energy += uf.x[1]*right - uf.x[]*left;
    }
    foreach_dimension ()
      q.x[] += dt*momentum/Delta;

    double fc = clamp(f[],0,1);
    energy *= dt/Delta/cm[];
    fE1[] +=        fc*energy;
    fE2[] += (1. - fc)*energy;
  }

  /**
  The velocity $\mathbf{u}$ is obtained from the updated momentum
  $\mathbf{q}$.*/
  
  vector u = q;
  foreach() 
    foreach_dimension() 
      u.x[] = q.x[]/(frho1[] + frho2[]);

  /**
  The contribution of the pressure and incompressible viscous term to
  the total energy is lacking. Since the face velocity has already the
  metric factor those in $\mu$ have been removed.*/

  face vector tmpf[], pf = tmpf;
  foreach_face()
    pf.x[] = - (p[] + p[-1])/2.;
 
  foreach () {
    double energy = 0.; 
    foreach_dimension()
      energy += uf.x[1]*pf.x[1] - uf.x[]*pf.x[];

    double fc = clamp(f[],0,1);
    fE1[] += fc*dt*energy/Delta/cm[];
    fE2[] += (1-fc)*dt*energy/Delta/cm[];
  }   

  //alphav is now the deformation tensor 2e_ijk: fixme
  
  face vector eijk = tmpf;
  foreach_dimension() {
    foreach_face(x)
      eijk.x[] = 2.*(u.x[] - u.x[-1])/Delta;
    #if dimension > 1
      foreach_face(y)
        eijk.y[] = (u.x[] - u.x[0,-1] + 
		    (u.y[1,-1] + u.y[1,0])/4. -
		    (u.y[-1,-1] + u.y[-1,0])/4.)/Delta;
    #endif
    #if dimension > 2
      foreach_face(z)
        eijk.z[] = (u.x[] - u.x[0,0,-1] + 
		    (u.z[1,0,-1] + u.z[1,0,0])/4. -
		    (u.z[-1,0,-1] + u.z[-1,0,0])/4.)/Delta;
    #endif

    foreach () {
      double energy = 0.; 
      foreach_dimension()
        energy += uf.x[1]*eijk.x[1] - uf.x[]*eijk.x[];

      double fc = clamp(f[],0,1);
      energy *= dt/Delta/cm[];
      fE1[] += fc*mu1*energy;
      fE2[] += (1. - fc)*mu2*energy;
    }   
  }

  /**
  Finally we recover momentum.*/

  foreach() 
    foreach_dimension() 
      q.x[] *= frho1[] + frho2[];
}

/**
At the end of the simulation we clean the tracer list. */

event cleanup (i = end) {
  free (f.tracers);
  f.tracers = NULL;
}

/**
## References

~~~bib
@hal{fuster2018, hal-01845218}
~~~
*/
