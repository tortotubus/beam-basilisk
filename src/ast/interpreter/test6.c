/**
Check optional parameters in function calls. */

struct _bidule {
  float fc[3];
};

void bidule (struct _bidule p)
{
  p.fc[0];
  p.fc[1];
  p.fc[2];
}

int main()
{
  {
    interpreter_verbosity (4);
    bidule (fc = {1,2,3});
  }
}
