/**
# Boundary fluxes for the Gulf-Stream simulation

This implements the "ports" described in [Hurlburt & Hogan,
2000](#hulrburt2000), section 3, page 289:

*"The nonlinear simulations also include effects of the global
thermohaline circulation via ports in the northern and southern model
boundaries, including a southward DWBC and a northward upper ocean
return flow."*

~~~bib
@article{hurlburt2000,
  title={Impact of 1/8 to 1/64 resolution on {G}ulf {S}tream model--data 
         comparisons in basin-scale subtropical {A}tlantic {O}cean models},
  author={Hurlburt, Harley E and Hogan, Patrick J},
  journal={Dynamics of Atmospheres and Oceans},
  volume={32},
  number={3-4},
  pages={283--329},
  year={2000},
  publisher={Elsevier},
  DOI={10.1016/S0377-0265(00)00050-6},
  PDF={https://apps.dtic.mil/sti/tr/pdf/ADA531039.pdf}
}
~~~

These functions are non-zero at the locations (lon/lat) of the
southern and northern ports. These locations are not precisely
specified in H&H, 2000 (see Note b of Table 2 in H&H, 2000). */

#define northern_flux() (x > -50 && x < - 40 && y > 50.5 && val(zbs,0,0,0) < -4000)
#define southern_flux() (x > -60 && x < - 50 && y < 9.5 && val(zbs,0,0,0) < - 4000)

/**
The AMOC (see below) is balanced using (vertical) fluxes between layers. */

#include "layered/conservation.h"

event viscous_term (i++)
{

  /**
  In order to distribute the fluxes within each layer, we first
  compute the volume of the northern and southern ports, for each
  layer. */
  
  double sht[nl], shb[nl];
  for (int l = 0; l < nl; l++)
    sht[l] = shb[l] = 0.;
  foreach_layer() {
    double t = 0., b = 0.;
    foreach(reduction(+:t) reduction(+:b)) {
      t += northern_flux()*fmax(h[] - hmin[_layer]/10., 0.)*dv();
      b += southern_flux()*fmax(h[] - hmin[_layer]/10., 0.)*dv();
    }
    sht[_layer] = t, shb[_layer] = b;
  }

  /**
  The fluxes (in m^3^/s i.e. Sverdrups/10^6^) are given in Table 2 of
  H&H, 2000. 

  See also the 2nd paragraph page 295 which discusses in more detail
  the chosen fluxes and their control of the northward, southward
  (Deep Western Boundary Current) and upward (Atlantic Meridional
  Overturning Circulation, AMOC) currents. */

  static const double factor = 0.9;
  static const double AMOC = 1e6;
  static const double southern[] = {
    - 13e6,        // bottom layer
    0.,
    2e6*factor,
    4.5e6*factor,
    6.5e6*factor   // top layer
  };
  static const double northern[] = {
    + AMOC    - southern[0], // bottom layer
    - AMOC/3. - southern[1],
    - AMOC/3. - southern[2],
    - AMOC/3. - southern[3],
    - southern[4]            // top layer
  };

  assert (nl == 5);
  foreach()
    foreach_layer() {

      /**
      The fluxes are imposed using a thickness-weighted sum over the
      northern and southern ports. */
  
      double hn = h[];
      hn += dt*northern_flux()*fmax(h[] - hmin[point.l]/10., 0.)*
	northern[point.l]/fmax(sht[point.l], dry);
      hn += dt*southern_flux()*fmax(h[] - hmin[point.l]/10., 0.)*
	southern[point.l]/fmax(shb[point.l], dry);
      h[] = fmax(hn, 0.);
    }
}
