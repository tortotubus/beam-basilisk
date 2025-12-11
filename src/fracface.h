/**
# Face fraction

We wish to calculate the fraction of face surface occupied by a phase defined
by a volume fraction field. This operation can be useful in different contexts,
for example the solution of the diffusion equation in a specific phase. */

#include "geometry.h"

/**
The surface fraction is computed as the intersection between the face of the
cell under investigation and the PLIC interface fragment. The problem boils down
to the calculation of the intersection between the interfacial plane and the
coordinate of the cell face ($x = x_o$). In 2D:

$$
  y = \frac{\alpha - m_x x_o}{m_y}
$$

after shifting the reference frame and handling degenerate cases ($m_y = 0$).
In 3D, this concept is extended by computing the area occupied by the phase.
The plane is considered either on the left or on the right side of the face, as
controlled using the boolean `right`. */

foreach_dimension()
static double interface_fraction_x (coord m, double alpha, bool right) {
#if dimension == 1
  return 1;
#elif dimension == 2
  if (fabs (m.y) < 1e-4) // degenerate case
    return right ? (m.x < 0. ? 1. : 0.)
                 : (m.x > 0. ? 1. : 0.);

  alpha += 0.5*(m.x + m.y);
  if (m.y < 0.) {
    alpha -= m.y;
    m.y *= -1;
  }
  double xo = right ? 1. : 0.;
  return clamp ((alpha - m.x*xo)/m.y, 0., 1.);
#elif dimension == 3
  if (fabs (m.y) < 1e-4 && fabs (m.z) < 1e-4) // degenerate case
    return right ? (m.x < 0. ? 1. : 0.)
                 : (m.x > 0. ? 1. : 0.);

  double n1 = m.y/(fabs (m.y) + fabs (m.z));
  double n2 = m.z/(fabs (m.y) + fabs (m.z));
  double j = right ? 0.5 : -0.5;
  alpha -= j*m.x;
  alpha /= (fabs(m.y) + fabs(m.z));
  return clamp (line_area (n1, n2, alpha), 0., 1.);
#endif
}

/**
This function calculates a single surface fraction value in a given face. The
PLIC interface representation cannot guarantee the continuity of the planar
segments across the faces. Therefore, we obtain a single value using a geometric
mean between the left and right sides. The tolerance defines the interfacial
cells and it can be modified.

Note that adaptation of the face fraction `s` is currently not performed through
a dedicated refinement procedure. Consequently, `s` must be recalculated after
each grid adaptation and update of the volume fraction. */

trace
void face_fraction (scalar f, face vector s, double tol = 1.e-6) {

  /**
  We calculate the interface normal field. */

  vector n[];
  foreach() {
    coord m = mycs (point, f);
    foreach_dimension()
      n.x[] = m.x;
  }

  foreach_face() {

    /**
    Case 1: the face is shared between a full and an empty cell. The surface
    fraction is null. */

    if (f[-1] < tol || f[] < tol)
      s.x[] = 0.;

    /**
    Case 2: if both cells are full, the surface fraction is unitary. */

    else if (f[-1] > 1. - tol && f[] > 1. - tol)
      s.x[] = 1.;

    /**
    Case 3: if both cells are interfacial, the face contains the interface, and
    we proceed with the calculation of the surface fraction. */

    else {
      double vleft = 1., vright = 1.;
      if (f[] < 1. - tol) {
        coord m = {0};
        m.x = n.x[];
#if dimension > 1
        m.y = n.y[];
#endif
#if dimension > 2
        m.z = n.z[];
#endif
        double alpha = plane_alpha (f[], m);
        vleft = interface_fraction_x (m, alpha, false);
      }
      if (f[-1] < 1. - tol) {
        coord m = {0};
        m.x = n.x[-1];
#if dimension > 1
        m.y = n.y[-1];
#endif
#if dimension > 2
        m.z = n.z[-1];
#endif
        double alpha = plane_alpha (f[-1], m);
        vright = interface_fraction_x (m, alpha, true);
      }
      s.x[] = sqrt (vleft*vright);
    }
  }
}

