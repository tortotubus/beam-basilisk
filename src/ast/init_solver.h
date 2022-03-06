# 2 "ast/init_solver.h"

static void _init_solver (void)
{
  void init_solver();
  init_solver();
  Events = (Event *) pmalloc (sizeof (Event), __func__, __FILE__, __LINE__);
  Events[0].last = 1;
  {

    /**
    Placeholder for event registrations and field allocations. Must be
    empty. */

  }
}
