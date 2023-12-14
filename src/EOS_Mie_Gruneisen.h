/**
# The Mie--Gruneisen Equation of State

This EOS is typically used in combination with the
[two-phase compressible solver](/src/two-phase-compressible.h).

The general form of the
[Mie--Gruneisen](https://en.wikipedia.org/wiki/Mie%E2%80%93Gr%C3%BCneisen_equation_of_state)
EOS can be written
$$
\rho_i e_i = \frac{p_i + \Gamma_i \Pi_i}{\Gamma_i - 1}
$$

The coefficients of the Mie-Gruneisen EOS for each phase. */

double gamma1 = 1.4 [0], gamma2 = 1.4 [0], PI1 = 0., PI2 = 0.;

/**
The speed of sound: in mixture cells, this function returns the
maximum between the speeds in both phases. */

double sound_speed (double f, double frho1, double frho2, double fe1, double fe2)
{
  double fc = clamp (f,0.,1.);
  double c2speed1 = 0., c2speed2 = 0.;

  if (fc > 0.00001) {
    double p  = fe1/fc*(gamma1 - 1.) - gamma1*PI1;
    c2speed1 = gamma1*(p + PI1)/frho1;
  }
  
  if (fc < 0.99999) {
    double p  = fe2/(1. - fc)*(gamma2 - 1.) - gamma2*PI2;
    c2speed2 = gamma2*(p + PI2)/frho2;
  }

  return sqrt (max (c2speed1, c2speed2));
}

/**
Average pressure: */

double average_pressure (double fc, double frho1, double frho2, double fe1, double fe2)
{
  double invgammaavg = fc/(gamma1 - 1.) + (1. - fc)/(gamma2 - 1.);
  double PIGAMMAavg = fc*PI1*gamma1/(gamma1 - 1.) + (1. - fc)*PI2*gamma2/(gamma2 - 1.); 
  return (fe1 + fe2 - PIGAMMAavg)/invgammaavg;
}

/**
Bulk compressibility of the mixture: */

double bulk_compressibility (double fc, double p)
{
  double invgammaavg = fc/(gamma1 - 1.) + (1. - fc)/(gamma2 - 1.);
  double PIGAMMAavg = fc*PI1*gamma1/(gamma1 - 1.) + (1. - fc)*PI2*gamma2/(gamma2 - 1.);
  return (p*(invgammaavg + 1.) + PIGAMMAavg)/invgammaavg;
}

/**
Internal energy: */

double internal_energy (double fc, double p)
{
  double invgammaavg = fc/(gamma1 - 1.) + (1. - fc)/(gamma2 - 1.);
  double PIGAMMAavg = fc*PI1*gamma1/(gamma1 - 1.) + (1. - fc)*PI2*gamma2/(gamma2 - 1.);
  return p*invgammaavg + PIGAMMAavg;
}
