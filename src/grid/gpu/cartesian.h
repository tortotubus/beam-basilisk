#define _GPU 1
#define GRIDNAME "Cartesian (GPU)"
#define GRIDPARENT Cartesian
#define grid_size() sq(N + 2)
#define grid_data() (cartesian->d)
#define grid_offset(s) ((s).i*grid_size())
#define depth() 0
#define GPU_CODE()							\
  "#define POINT_VARIABLES VARIABLES\n"					\
  "#define valt(s,k,l,m) _data[(point.i + k + (s).i*(N + 2))*(N + 2) + point.j + l]\n" \
  "#define val_red_(s) _data[(s).i*sq(N + 2) + (point.i - 1)*NY + point.j - 1]\n"

#include "../cartesian.h"
#include "gpu.h"
#include "../cartesian-common.h"

static void gpu_cartesian_methods()
{
  cartesian_methods();
}

#include "grid.h"
