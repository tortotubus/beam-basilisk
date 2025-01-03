/**
# Macros */

macro myothermacro()
{
  for (int j = 1; j < 3; j++) {
    fprintf (stderr, "other %d ", j);
    {...}
  }
}

macro mymacro (int len = 0, int end = 0)
{
  int i;
  for (i = len; i < end; i++)
    myothermacro()
      {...}
  {...}
}

macro mymacro2 (coord * view, float color[3])
{
  view->x = 1;
  view->y = 2;
  color[0] = 2;
  {...}
}

macro mymacro3 (double field, scalar s1, double expr)
{
  foreach() {
    field = expr;
    s1[] = expr;
    fprintf (stderr, "%g %g %g\n", x, y, expr);
  }
}

macro mymacro4 (break = (i = j = 2))
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      {...}
}

int main()
{  
  mymacro (end = 2)
    fprintf (stderr, "%d\n", i);
  coord p;
  float machin[3];
  mymacro2 (&p, machin)
    machin[1] = 3;
  fprintf (stderr, "%g %g %g %g\n", p.x, p.y, machin[0], machin[1]);

  init_grid (2);
  scalar s[], s1[];
  mymacro3 (s[], s1, x*x + y*y);
  foreach()
    fprintf (stderr, "%g %g %g %g\n", x, y, s[], s1[]);
  
  mymacro4() {
    for (int k = 0; k < 2; k++) {
      fprintf (stderr, "%d %d %d\n", i, j, k);
      break;
    }
    if (j == 1)
      break;
  }
}
