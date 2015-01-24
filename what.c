#include <stdio.h>

int main()
{
  int butt = 100;
  printf("%d ", butt);
  fflush(stdout);
  butt &= 0;
  printf("%d ", butt);
  fflush(stdout);
  butt |= 100;
  printf("%d ", butt);
  fflush(stdout);
  return 0;
}
