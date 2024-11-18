extern double omr, Cm;
extern double * hmin, * hmax;

extern scalar * hl;
extern double dt, dry;

#define wmin(h,hmin) (h >= hmin ? 0. : sq((hmin - h)/hmin))
#define wmax(h,hmax) (h <= hmax ? 0. : sq((h - hmax)/hmax))

static double * vhi = NULL;

event cleanup (t = end)
{
  if (vhi)
    free (vhi), vhi = NULL;
}

event viscous_term (i++)
{
  if (omr <= 0.)
    return 0;

  // Initial volume of each layer
  
  if (vhi == NULL) {
    vhi = malloc (sizeof(double)*nl);
    foreach_layer()
      vhi[_layer] = statsf(h).sum;
  }
 
  double oma[nl], wa[nl];
  for (int l = 0; l < nl; l++)
    oma[l] = wa[l] = 0.;
  foreach(reduction(+:oma[:nl]) reduction(+:wa[:nl]))
    for (int l = nl - 1; l >= 1; l--) {
      double om = omr*(wmin((h[0,0,l]), hmin[l]) - wmax((h[0,0,l]), hmax[l]));
      if (h[0,0,l] + dt*om > dry && h[0,0,l-1] - dt*om > dry)
	oma[l] += dv()*om, wa[l] += dv();
    }
  
  foreach() {
    double hn[nl];
    coord un[nl];
    foreach_layer() {
      hn[point.l] = h[];
      foreach_dimension()
	un[point.l].x = h[]*u.x[];
    }
    for (int l = nl - 1; l >= 1; l--) {
      double om = omr*(wmin((h[0,0,l]), hmin[l]) - wmax((h[0,0,l]), hmax[l]));
      if (h[0,0,l] + dt*om > dry && h[0,0,l-1] - dt*om > dry) {
	om -= oma[l]/wa[l];
	hn[l] += dt*om;
	hn[l - 1] -= dt*om;
	int lum = om >= 0 ? l - 1 : l;
	foreach_dimension() {
	  double flux = dt*om*(u.x[0,0,lum]*(1. + Cm) - Cm*u.x[0,0,l]);
	  un[l].x     += flux;
	  un[l - 1].x -= flux;
	}
      }
    }
    foreach_layer() {
      h[] = hn[point.l];
#if 1
      foreach_dimension()
	u.x[] = h[] > dry ? un[point.l].x/h[] : 0.;
#endif
    }
  }

  // Conservation of the volume of each layer

  double eh[nl];
  foreach_layer()
    eh[_layer] = vhi[_layer]/statsf(h).sum;

  foreach() {
    double hnew[nl];
    coord hu[nl];
    foreach_layer() {
      hnew[point.l] = h[]*eh[point.l];
      foreach_dimension()
	hu[point.l].x = h[]*u.x[];
    }
    for (int l = nl - 1; l >= 1; l--) {
      double dh = hnew[l] - h[0,0,l];
      if ((dh < 0. && h[0,0,l] + dh > dry && h[0,0,l-1] > dry) ||
	  (dh > 0. && h[0,0,l-1] - dh > dry)) {
	h[0,0,l] += dh;
	h[0,0,l-1] -= dh;
	int ul = dh > 0. ? l - 1 : l;
	foreach_dimension() {
	  hu[l].x += dh*u.x[0,0,ul];
	  hu[l - 1].x -= dh*u.x[0,0,ul];
	}
      }
    }
#if 0
    foreach_layer()
      foreach_dimension()
	u.x[] = h[] > dry ? hu[point.l].x/h[] : 0.;
#endif
  }
}
