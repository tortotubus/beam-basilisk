#define northern_flux() (x > -50 && x < - 40 && y > 50.5 && val(zbs,0,0,0) < -4000)
#define southern_flux() (x > -60 && x < - 50 && y < 9.5 && val(zbs,0,0,0) < - 4000)

event viscous_term (i++)
{
  double sht[nl], shb[nl];
  for (int l = 0; l < nl; l++)
    sht[l] = shb[l] = 0.;
  foreach(reduction(+:sht[:nl]) reduction(+:shb[:nl]))
    foreach_layer() {
      sht[point.l] += northern_flux()*fmax(h[] - hmin[point.l]/10., 0.)*dv();
      shb[point.l] += southern_flux()*fmax(h[] - hmin[point.l]/10., 0.)*dv();
    }
  // see Table 2 of Hurlburt & Hogan, 2000
#if NODWBC
  static const double northern[] =
    { 0., - 0.33e6, - 2.33e6, - 4.84e6, - 6.5e6 };
  static const double southern[] =
    { 0.,   0.33e6,   2.33e6,   4.84e6,   6.5e6 };
#else
  static const double factor = 0.9;
  static const double northern[] =
    { + 14e6, - 0.33e6, - 2e6*factor - 0.33e6, - 4.5e6*factor - 0.34e6, - 6.5e6*factor };
  static const double southern[] =
    { - 13e6, 0., 2e6*factor, 4.5e6*factor, 6.5e6*factor };
#endif
  assert (nl == 5);
  foreach()
    foreach_layer() {
      h[] += dt*northern_flux()*fmax(h[] - hmin[point.l]/10., 0.)*
	northern[point.l]/max(sht[point.l], dry);
      h[] += dt*southern_flux()*fmax(h[] - hmin[point.l]/10., 0.)*
	southern[point.l]/max(shb[point.l], dry);
      if (h[] < 0.)
	h[] = 0.;
    }
}
