#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int i;
  srand(time(NULL));
  printf("static const unsigned char rng[256] = {\n\t");
  for(i = 0; i < 255; i++)
  {
    if(!(i % 10))
      printf("\n\t");
    printf("%d, ", rand() % 255);
  }
  printf("};");
  return 0;
}
