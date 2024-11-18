/**
# The Gulf Stream
*/

#include "grid/multigrid.h"
#include "spherical.h"
#include "layered/hydro.h"
#include "layered/implicit.h"

scalar zbs[];

#define Omega 7.292205e-5
#define F0() (2.*Omega*sin(y*pi/180.))
#define Cb 2e-3 // 2e-3 in Hurlburt & Hogan, 2000, Table 2
// see Metzger & Hurlburt, 1996, Appendix A for the cube(zb/zbs) expression
#if 1 // COMPRESSED
#define K0() (point.l > 0 && h[0,0,-1] > dry ? 0. : h[] < dry ? HUGE :	\
	      Cb*cube(zb[]/zbs[])*norm(u)/h[])
#elif 1
#define K0() (y > 50 ? (y - 50)/3600. :					\
	      y < 9.5 ? 1./3600. :					\
	      point.l > 0 && h[0,0,-1] > 10. ? 0. : h[] < dry ? HUGE :	\
	      Cb*norm(u)/h[])
#else
#define K0() (point.l > 0 && h[0,0,-1] > 10. ? 0. : h[] < dry ? HUGE :	\
	      Cb*norm(u)/h[])
#endif
#define alpha_H 1.
#include "layered/coriolis.h"

#define rho0 1000.
#include "layered/isopycnal.h"
#include "layered/entrainment.h"
// see Table 2 of Hurlburt & Hogan, 2000
#define NL 5
double * dh   = (double [NL]){ 0., 250, 250, 250, 250 };
double * drho = (double [NL]){ 2.13/rho0, 1.72/rho0, 1.41/rho0, 1.01/rho0, 0. };
double * hmin = (double [NL]){ 0, 40, 40, 40, 50 };
double * hmax = (double [NL]){ HUGE, HUGE, HUGE, HUGE, HUGE };
double omr = 0.07e-2, Cm = 0.;

#include "terrain.h"
#include "input.h"
#include "layered/perfs.h"

double nu_H = 10;

/**
Time averages. */

#define hour 3600.
#define day 86400.
#define month (day*30.)
#define year (day*365.)

vector ua, ud;
scalar Ha, etam[], eta2[];
vector uga[], ugd[];

double t0 = 5.*year; // start averaging after that time

// compile: qcc -source -nolineno -D_MPI=1 -DDISPLAY=1 gulf-stream.c
// np: 8, 32, 128, 512

int main (int argc, char * argv[])
{
  if (npe() > 1) {
    dimensions (ny = sqrt(npe()/2));
    size (42*2.);
  }
  else
    size (42);
  Radius = 6371220.;
  origin (-98, 9);
  G = 9.8;
  if (argc > 1)
    N = atoi(argv[1]);
  else
    N = 512; // lower resolution will not work when including bflux.h (not sure)
  DT = 600;
  if (argc > 2)
    DT = atof(argv[2]);
  if (argc > 3)
    t0 = atof(argv[3]);
  nl = NL;
  TOLERANCE = 1e-4;
  theta_H = 0.55; // damps the barotropic mode: 0.55 necessary for N = 512, 0.51 OK for N >= 1024
  run();
}

#if 1
#include "bflux.h"
#endif

void laplacian_smoothing()
{
  // Laplacian smoothing as in H & H, 2000, 2008
  for (int i = 0; i < 2; i++) {
    foreach() {
      if (zb[] < 0.)
	zbs[] = (zb[1] + zb[-1] + zb[0,1] + zb[0,-1] +
		 zb[1,1] + zb[-1,-1] + zb[-1,1] + zb[1,-1])/8.;
      else
	zbs[] = zb[];
    }
    foreach()
      zb[] = zbs[];
  }  
}

event init (i = 0)
{
  if (restore ("restart"))
    event ("metric");
  else {
    terrain (zb, "~/terrain/etopo2", NULL);
    laplacian_smoothing();

    foreach_dimension() {
      u.t[right] = dirichlet(0);
      u.t[left] = dirichlet(0);
      zb[right] = 1000;
      zb[left] = 1000;
      h[right] = 0;
      h[left] = 0;
    }
      
#if !COMPRESSED
    foreach()
      if (zb[] > - 10)
	zb[] = 100.;
#else // COMPRESSED
    foreach() {
      double zbmin = - 6500.;
      if (zb[] > - 200)
	zb[] = 1000.;
      else
	// "topography compression" as in Hurlburt & Hogan, 2000, 2008
	// see Note c for Table 1 in Hurlburt & Hogan, 2000	
	zb[] = zbmin + 0.82*(zb[] - zbmin);
    }
#endif // COMPRESSED
  
    foreach() {
      double z = 0.;
      for (point.l = nl - 1; point.l >= 0; point.l--) {
	// fixme: this should be done in a generic way by isopycnal.h
	if (point.l > 0 && z - dh[point.l] > zb[])
	  h[] = dh[point.l];
	else
	  h[] = max(z - zb[], 0.);
	z -= h[];
      }
    }

    reset ({etam, eta2, ua, ud, Ha, uga, ugd}, 0.);
  }
}

/**
# Wind stress
*/

double Cw = 1.5e-3; // as in Hurlburt & Hogan, 2000, page 293
double rho_air = 1.2;

void load_wind (vector wind, int index)
{
  char name[80];
#if COADS  
  sprintf (name, "coads-%d_5.asc", index + 1);
  input_grd (wind.x, file = name, linear = true, periodic = true, zero = true);
  sprintf (name, "coads-%d_6.asc", index + 1);
  input_grd (wind.y, file = name, linear = true, periodic = true, zero = true);
#else // HR
  sprintf (name, "wind/hr-%d-x.asc", index + 1);
  input_grd (wind.x, file = name, linear = true, periodic = true, zero = true,
	     smooth = 1);
  sprintf (name, "wind/hr-%d-y.asc", index + 1);
  input_grd (wind.y, file = name, linear = true, periodic = true, zero = true,
	     smooth = 1);
#endif // HR
}

event init (i = 0)
{

  /**
  Needs gdal_translate from Debian package gdal-bin */
  
#if COADS
  system ("if ! test -f coads-1_1.asc; then "
	  "  wget https://github.com/NOAA-PMEL/FerretDatasets/raw/master/data/coads_climatology.cdf -O coads_climatology.cdf; "
	  "  for i in `seq 1 1 12`; do "
	  "    gdal_translate -of AAIGrid -ot float32 -b $i -sds -q "
	  "    coads_climatology.cdf coads-$i.asc; "
	  "  done "
	  "fi "
	  );
#else // HR
  system ("if ! test -f wind/hr-1-x.asc; then "
	  " mkdir wind; cd wind; "
	  " wget https://iridl.ldeo.columbia.edu/SOURCES/.HELLERMAN/.taux/data.nc -O data.nc; "
	  "  for i in `seq 1 1 12`; do "
	  "    gdal_translate -of AAIGrid -ot float32 -b $i -sds -q "
	  "    data.nc hr-$i-x.asc; "
	  "  done; "
	  " wget https://iridl.ldeo.columbia.edu/SOURCES/.HELLERMAN/.tauy/data.nc -O data.nc; "
	  "  for i in `seq 1 1 12`; do "
	  "    gdal_translate -of AAIGrid -ot float32 -b $i -sds -q "
	  "    data.nc hr-$i-y.asc; "
	  "  done; "
	  "fi "
	  );
#endif // HR
}

vector wind1[], wind2[];

event acceleration (i++)
{
  int i = t/month;
  double deltaw = (t - i*month - month/2.)/month;
  while (i > 11) i -= 12;
  int i1 = deltaw > 0 ? i : i - 1;
  int i2 = deltaw > 0 ? i + 1: i;
  if (deltaw < 0.) deltaw += 1.;
  if (i1 < 0) i1 = 11;
  if (i2 > 11) i2 = 0;
  static int t1 = -1, t2 = -1;
  if (i1 != t1)
    load_wind (wind1, i1), t1 = i1;
  if (i2 != t2)
    load_wind (wind2, i2), t2 = i2;

  // wind stress
  foreach_face() {
    point.l = nl - 1;
    if (hf.x[] > 10.) {
      double tauw = ((1. - deltaw)*(wind1.x[] + wind1.x[-1]) +
		     deltaw*(wind2.x[] + wind2.x[-1]))/2.;
#if COADS // fixme
      double n = Cw*rho_air*sqrt(sq(tauw.x) + sq(tauw.y));
#else // HR
      double n = 0.1; // conversion from dynes/cm^2 to kg/m/s^2
#endif
      ha.x[] += n*tauw/rho0;
    }
  }
}

event viscous_term (i++)
{
  if (nu_H > 0.) {
    vector d2u[];
    foreach_layer() {
      double dry = 1.;
      foreach()
	foreach_dimension()
	d2u.x[] = 2.*(sq(fm.x[1])/(cm[1] + cm[])*u.x[1]*(h[1] > dry) +
		      sq(fm.x[])/(cm[-1] + cm[])*u.x[-1]*(h[-1] > dry) +
		      sq(fm.y[0,1])/(cm[0,1] + cm[])*u.x[0,1]*(h[0,1] > dry) +
		      sq(fm.y[0,-1])/(cm[0,-1] + cm[])*u.x[0,-1]*(h[0,-1] > dry))
	/(sq(Delta)*cm[]);
      foreach()
	foreach_dimension() {
	double n = 2.*(sq(fm.x[1])/(cm[1] + cm[])*(1. + (h[1] <= dry)) +
		       sq(fm.x[])/(cm[-1] + cm[])*(1. + (h[-1] <= dry)) +
		       sq(fm.y[0,1])/(cm[0,1] + cm[])*(1. + (h[0,1] <= dry)) +
		       sq(fm.y[0,-1])/(cm[0,-1] + cm[])*(1. + (h[0,-1] <= dry)))
	  /(sq(Delta)*cm[]);
	u.x[] = (u.x[] + dt*nu_H*d2u.x[])/(1. + dt*nu_H*n);
      }
    }
  }
}

event outputs (t += day)
{
  double ke = 0., keb = 0., vol = 0., volb = 0.;
  scalar etad[], m[], nu[];
  
  foreach(reduction(+:ke) reduction(+:vol) reduction(+:keb) reduction(+:volb)) {
    point.l = 0; // fixme
    keb += dv()*h[]*(sq(u.x[]) + sq(u.y[]));
    volb += dv()*h[];
    foreach_layer() {
      ke += dv()*h[]*(sq(u.x[]) + sq(u.y[]));
      vol += dv()*h[];
    }
    point.l = nl - 1; // fixme
    etad[] = h[] > dry ? eta[] : 0.;
    nu[] = h[] > dry ? norm(u) : 0.;
    m[] = etad[] - zbs[];
  }
  if (i == 0) {
    fprintf (stderr, "t ke/vol keb/vol dt "
	     "mgH.i mgH.nrelax etad.stddev nu.stddev");
    for (int l = 0; l < nl; l++)
      fprintf (stderr, " d%s%d.sum/dt", h.name, l);
    fputc ('\n', stderr);
  }
  fprintf (stderr, "%g %g %g %g %d %d %g %g", t/day, ke/vol/2., keb/volb/2., dt,
	   mgH.i, mgH.nrelax,
	   statsf (etad).stddev, statsf(nu).stddev);

  static double s0[NL], t0 = 0.;
  foreach_layer() {
    double s = statsf(h).sum;
    if (i == 0)
      fprintf (stderr, " 0");
    else
      fprintf (stderr, " %g", (s - s0[_layer])/(t - t0));
    s0[_layer] = s;
  }
  fputc ('\n', stderr);
  t0 = t;

  output_ppm (etad, mask = m, file = "eta.mp4", n = clamp(N,1024,2048),
	      min = -0.8, max = 0.6,
	      box = {{X0,Y0},{X0+L0,Y0+L0/2.}},
	      map = cool_warm);
  output_ppm (nu, mask = m, file = "nu.mp4", n = clamp(N,1024,2048),
	      min = 0, max = 1.5,
	      box = {{X0,Y0},{X0+L0,Y0+L0/2.}},
	      map = cool_warm);

  char name[80];
  sprintf (name, "u%d", nl - 1);
  vorticity (lookup_vector (name), nu);

  output_ppm (nu, mask = m, file = "omega.mp4", n = clamp(N,1024,2048),
	      linear = false,
	      //	      spread = 5,
	      min = -0.5e-4, max = 0.5e-4,
	      box = {{X0,Y0},{X0+L0,Y0+L0/2.}},
	      map = blue_white_red);
}

// see Figure 2a and Table 6 of Hurlburt & Hogan, 2000
Flux fluxes[] = {
  { "florida", {{- 80.25, 27.}, {- 78.75, 27.}},
    "Florida Straits at 27N" },
  { "abaco",   {{- 77.2, 26.5}, {- 74.13, 26.5}},
    "East of Abaco Island at 26.5N" },
  { "hatteras",   {{- 76.15, 34.25}, {- 74.5, 34.25}},
    "Gulf Stream at Cape Hatteras" },
  { "38N",   {{- 74.2, 38}, {- 72.8, 38}},
    "Western boundary current at 38N" },
  { "NACwest",   {{- 52.5, 44}, {- 53.9, 43}},
    "N. Atlantic Current, west of Grand Banks" },
  { "NACeast",   {{- 49, 44}, {- 46, 44}},
    "N. Atlantic Current, east of Grand Banks at 44N" },
  { "south",   {{- 50, 42.8}, {- 50, 36}},
    "S. of Grand Banks to 36N" },
  { "68W",   {{- 68, 38.34}, {- 68, 33.48}},
    "Gulf Stream at 68W" },
  {NULL}
};

event fluxes1 (t += day)
  output_fluxes (fluxes, h, u);

event snapshots (t += month)
{
  char name[80];
  sprintf (name, "u%d", nl - 1);
  scalar omega[];
  vorticity (lookup_vector (name), omega);
  dump();
}

/**
Time averages
*/

event init (i = 0)
{
  ua = new vector[nl];
  ud = new vector[nl];
  Ha = new scalar[nl];
}

event average (t = t0; t <= 60.*year; i++)
{
  double Dt = t - t0;
  foreach() {
    foreach_layer() {
      Ha[] = (Dt*Ha[] + dt*h[])/(Dt + dt);
      foreach_dimension() {
        ua.x[] = (Dt*ua.x[] + dt*u.x[])/(Dt + dt);
	ud.x[] = (Dt*ud.x[] + dt*sq(u.x[]))/(Dt + dt);
      }
    }

    coord ug = geostrophic_velocity (point);
    foreach_dimension() {
      uga.x[] = (Dt*uga.x[] + dt*ug.x)/(Dt + dt);
      ugd.x[] = (Dt*ugd.x[] + dt*sq(ug.x))/(Dt + dt);      
    }
      
    etam[] = (Dt*etam[] + dt*eta[])/(Dt + dt);
    eta2[] = (Dt*eta2[] + dt*sq(eta[]))/(Dt + dt);
  }
}

event average_outputs (t = t0; t += 30*day)
{
  scalar etad[], m[];
  foreach() {
    point.l = nl - 1;
    etad[] = eta2[] - sq(etam[]) > 0. ? sqrt(eta2[] - sq(etam[])) : 0.;
    m[] = (h[] > dry ? eta[] : 0.) - zbs[];
  }
  output_ppm (etad, mask = m, file = "etad.mp4", n = clamp(N,1024,2048),
	      linear = false,
	      min = 0, max = 0.4,
	      box = {{X0,Y0},{X0+L0,Y0+L0/2.}},
	      map = cool_warm);
  output_ppm (etam, mask = m, file = "etam.mp4", n = clamp(N,1024,2048),
	      linear = false,
	      min = -0.6, max = 0.6,
	      box = {{X0,Y0},{X0+L0,Y0+L0/2.}},
	      map = cool_warm);
}

/**
# Running on karman

~~~bash
../qcc -source -D_MPI=1 -DCOMPRESSED -DDISPLAY=1 gulf-stream.c
scp _gulf-stream.c basilisk@karman.lmm.jussieu.fr:gulf-stream/restart/
scp ../gl/*.a basilisk@karman.lmm.jussieu.fr:lib/
scp ../wsServer/libws.a basilisk@karman.lmm.jussieu.fr:lib/
mpicc -Wall -O2 _gulf-stream.c -o gulf-stream -L$HOME/lib -lglutils -lfb_tiny -lkdt -lws -lm
nohup mpirun -np 8 ./gulf-stream 2> log
~~~

# Running on navier

~~~bash
../qcc -source -D_MPI=1 -DCOMPRESSED -DDISPLAY gulf-stream.c
scp _gulf-stream.c navier.lmm.jussieu.fr:gulf-stream/
mpicc -Wall -std=c99 -D_XOPEN_SOURCE=700 -O2 _gulf-stream.c -o gulf-stream -I$HOME/include -L$HOME/lib -lglutils -lfb_tiny -lkdt -lws -lm
~~~

# References

~~~bib
@article{hurlburt2008,
  title={The {G}ulf {S}tream pathway and the impacts of the eddy-driven 
         abyssal circulation and the {D}eep {W}estern {B}oundary {C}urrent},
  author={Hurlburt, Harley E and Hogan, Patrick J},
  journal={Dynamics of Atmospheres and Oceans},
  volume={45},
  number={3-4},
  pages={71--101},
  year={2008},
  publisher={Elsevier}
}

@article{hurlburt2000,
  title={Impact of 1/8 to 1/64 resolution on {G}ulf {S}tream model--data 
         comparisons in basin-scale subtropical {A}tlantic {O}cean models},
  author={Hurlburt, Harley E and Hogan, Patrick J},
  journal={Dynamics of Atmospheres and Oceans},
  volume={32},
  number={3-4},
  pages={283--329},
  year={2000},
  publisher={Elsevier}
}

@article{hellerman1983,
  title={Normal monthly wind stress over the world ocean with error estimates},
  author={Hellerman, Sol and Rosenstein, Mel},
  journal={Journal of Physical Oceanography},
  volume={13},
  number={7},
  pages={1093--1104},
  year={1983},
  url={https://iridl.ldeo.columbia.edu/SOURCES/.HELLERMAN/}
}
~~~
*/
