#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char **argv)
{
  char *vstr;
  long int vlen;
  long int avlen;

  if(argc < 3)
  {
    printf("not enoguh args\n");
    return 1;
  }

  avlen = strlen(argv[1]);
  vlen = atoll(argv[2]);

  if(vlen > avlen)
  {
    printf("cut length is too lnog\n");
    return 1;
  }

  vstr = malloc(avlen + 1);
  memcpy(vstr, argv[1], avlen + 1);

  *(vstr + vlen) = '\0';

  printf("%s\n", vstr);

  free(vstr);
  return 0;
}
