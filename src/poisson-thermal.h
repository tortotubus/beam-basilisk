struct Thermal {
  scalar a1, a2, b1, b2;
  (const) face vector kappa, alpha;
  (const) scalar lambda1, lambda2, lambda3, lambda4;
  double tolerance;
  int nrelax, minlevel;
  scalar * res;
};

static void relax_thermal (scalar * al, scalar * bl, int l, void * data)
{
  scalar Tv = al[0], pv = al[1], rhsTv = bl[0], rhspv = bl[1];
  struct Thermal * p = (struct Thermal *) data;
  (const) face vector kappa = p->kappa, alpha = p->alpha;
  (const) scalar lambda1 = p->lambda1, lambda2 = p->lambda2,
    lambda3 = p->lambda3, lambda4 = p->lambda4;

#if JACOBI
  scalar cT[], cp[];
#else
  scalar cT = Tv, cp = pv;
#endif

  foreach_level_or_leaf (l) {
    double numT = sq(Delta)*(lambda2[]*pv[] - rhsTv[]), denT = -lambda1[]*sq(Delta);
    double nump = - sq(Delta)*rhspv[], denp = -lambda3[]*sq(Delta);
    foreach_dimension() {
      numT += kappa.x[1]*Tv[1] + kappa.x[]*Tv[-1];
      denT += kappa.x[1] + kappa.x[];
      nump += alpha.x[1]*pv[1] + alpha.x[]*pv[-1];
      nump += lambda4[]*(kappa.x[1]*(Tv[1] - Tv[]) - kappa.x[]*(Tv[] - Tv[-1]));
      denp += alpha.x[1] + alpha.x[];
    }
    cT[] = numT/denT;
    cp[] = nump/denp;
  }

#if JACOBI
  foreach_level_or_leaf (l) {
    Tv[] = (Tv[] + 2.*cT[])/3.;
    pv[] = (pv[] + 2.*cp[])/3.;
  }
#endif
}

static double residual_thermal (scalar * al, scalar * bl, scalar * resl, void * data)
{
  scalar Tv = al[0], pv = al[1], rhsTv = bl[0], rhspv = bl[1], resTv = resl[0], respv = resl[1];
  struct Thermal * p = (struct Thermal *) data;
  (const) face vector kappa = p->kappa, alpha = p->alpha;
  (const) scalar lambda1 = p->lambda1, lambda2 = p->lambda2,
    lambda3 = p->lambda3, lambda4 = p->lambda4;
  double maxres = 0.;
#if TREE
  /* conservative coarse/fine discretisation (2nd order) */
  face vector gradT[], gradp[];
  foreach_face() {
    gradT.x[] = kappa.x[]*face_gradient_x (Tv, 0);
    gradp.x[] = alpha.x[]*face_gradient_x (pv, 0);
  }
  foreach (reduction(max:maxres)) {
    resTv[] = rhsTv[] - lambda1[]*Tv[] - lambda2[]*pv[];
    respv[] = rhspv[] - lambda3[]*pv[];
    foreach_dimension() {
      resTv[] -= (gradT.x[1] - gradT.x[])/Delta;
      respv[] -= (gradp.x[1] - gradp.x[])/Delta;
      respv[] -= lambda4[]*(gradT.x[1] - gradT.x[])/Delta;
    }
#else // !TREE
  /* "naive" discretisation (only 1st order on trees) */
  foreach (reduction(max:maxres)) {
    resTv[] = rhsTv[] - lambda1[]*Tv[] - lambda2[]*pv[];
    respv[] = rhspv[] - lambda3[]*pv[];
    foreach_dimension() {
      resTv[] += (kappa.x[0]*face_gradient_x (Tv, 0) -
		 kappa.x[1]*face_gradient_x (Tv, 1))/Delta;
      respv[] += (alpha.x[0]*face_gradient_x (pv, 0) -
		 alpha.x[1]*face_gradient_x (pv, 1))/Delta;
      respv[] += lambda4[]*(kappa.x[0]*face_gradient_x (Tv, 0) -
		 kappa.x[1]*face_gradient_x (Tv, 1))/Delta;
    }
#endif // !TREE
    if (max(fabs(resTv[]),fabs(respv[])) > maxres)
      maxres = max(fabs(resTv[]),fabs(respv[]));
  }
  return maxres;
}

mgstats poisson_thermal (struct Thermal p)
{
  if (!p.alpha.x.i)
    p.alpha = unityf;
  if (!p.lambda3.i)
    p.lambda3 = zeroc;

  face vector kappa = p.kappa, alpha = p.alpha;
  scalar lambda1 = p.lambda1, lambda2 = p.lambda2, lambda3 = p.lambda3, lambda4 = p.lambda4;

  double defaultol = TOLERANCE;
  if (p.tolerance)
    TOLERANCE = p.tolerance;

  scalar a1 = p.a1, a2 = p.a2, b1 = p.b1, b2 = p.b2;

  restriction({kappa,alpha,lambda1,lambda2,lambda3,lambda4});

  mgstats s = mg_solve ({a1,a2}, {b1,b2}, residual_thermal, relax_thermal,
			&p, p.nrelax, p.res, minlevel = max(1, p.minlevel));

  if (p.tolerance)
    TOLERANCE = defaultol;

  return s;
}
