@undef VARIABLES
@def VARIABLES
  double Delta = L0*_DELTA; /* cell size */
  double Delta_x = Delta; /* cell size (with mapping) */
#if dimension > 1
  double Delta_y = Delta; /* cell size (with mapping) */
#endif
#if dimension > 2
  double Delta_z = Delta; /* cell size (with mapping) */
#endif
  /* cell/face center coordinates */
  double x = (ig/2. + _I + 0.5)*Delta + X0; NOT_UNUSED(x);
#if dimension > 1
  double y = (jg/2. + _J + 0.5)*Delta + Y0;
#else
  double y = 0.;
#endif
 NOT_UNUSED(y);
#if dimension > 2
  double z = (kg/2. + _K + 0.5)*Delta + Z0;
#else
  double z = 0.;
#endif
  NOT_UNUSED(z);
  /* we need this to avoid compiler warnings */
  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);
#if dimension > 1
  NOT_UNUSED(Delta_y);
#endif
#if dimension > 2
  NOT_UNUSED(Delta_z);
#endif
  /* and this when catching FPEs */
  _CATCH;
@
