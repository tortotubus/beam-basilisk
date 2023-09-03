/**
Check that (all) the zeros of structures have dimensions of the
zeros in the calling function. */

struct Func {
  double a;
  double b;
};

void func (struct Func p)
{
  display_value (p.a);
  display_value (p.b);
}

int main()
{
  { interpreter_verbosity (2);
#if 0
    struct Func p = {1};
    display_value (p.a);
    display_value (p.b);
#else
    func();
#endif
  }
}
