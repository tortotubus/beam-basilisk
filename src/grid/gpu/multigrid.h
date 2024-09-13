#define _GPU 1
#define GRIDNAME "Multigrid (GPU)"
#define GRIDPARENT Multigrid
#define grid_size() (multigrid->size)
#define grid_data() (multigrid->d)
#define grid_offset(s) (_shift (depth()) + (s).i*grid_size())
 
// ghost cell coordinates for each direction
static int _ig[] = {1,-1,0,0}, _jg[] = {0,0,1,-1};
#define GPU_CODE()							\
  "#define POINT_VARIABLES VARIABLES "					\
  " int level = point.level;"						\
  " struct { int x, y; } child = {"					\
  "   2*((point.i+GHOSTS)%2)-1, 2*((point.j+GHOSTS)%2)-1"		\
  " };"									\
  " Point parent = point;"						\
  " parent.level--;"							\
  " parent.i = (point.i + GHOSTS)/2; parent.j = (point.j + GHOSTS)/2;\n" \
  "#define _shift(l) ((sq(1 << (l)) - 1)/3 + 4*GHOSTS*((1 << (l)) - 1 + GHOSTS*(l)))\n"	\
  "#define valt(s,k,l,m)"						\
  "  _data[point.j + l + (point.i + k)*((1 << point.level) + 2*GHOSTS) +" \
  " _shift (point.level) + (s).i*_shift (_depth + 1)]\n"		\
  "#define val_red_(s) _data[point.j - GHOSTS + (point.i - GHOSTS)*NY + _shift (point.level) + (s).i*_shift (_depth + 1)]\n" \
  "#define foreach_child() {"						\
  "  int _i = 2*point.i - GHOSTS, _j = 2*point.j - GHOSTS;"		\
  "  point.level++;"							\
  "  for (int _k = 0; _k < 2; _k++)"					\
  "    for (int _l = 0; _l < 2; _l++) {"				\
  "      point.i = _i + _k; point.j = _j + _l;"				\
  "      POINT_VARIABLES;\n"						\
  "#define end_foreach_child()"						\
  "  }"									\
  "  point.i = (_i + GHOSTS)/2; point.j = (_j + GHOSTS)/2;"		\
  "  point.level--;"							\
  "}\n"									\
  "#define coarse(a,k,l,m)"						\
  "  _data[(point.j + GHOSTS)/2 + l + ((point.i + GHOSTS)/2 + k)*((1 << point.level)/2 + 2*GHOSTS)" \
  "  + _shift (point.level - 1) + (s).i*_shift (_depth + 1)]\n"

#include "../multigrid.h"
#include "gpu.h"
#include "../multigrid-common.h"

static void gpu_multigrid_methods()
{
  multigrid_methods();
}

#include "grid.h"
