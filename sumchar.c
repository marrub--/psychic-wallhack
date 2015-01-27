#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
  unsigned long int butt = 0, i;
  for(i = 0; i < strlen(argv[1]); i++)
  {
    butt += argv[1][i];
  }
  printf("%s: %lX\n", argv[1], butt);
  return 0;
}
