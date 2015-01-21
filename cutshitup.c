#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char **argv)
{
  char *vstr;
  long int vlen;
  long int avlen;
  char *butts;

  if(argc < 2)
  {
    printf("not enoguh args\n");
    return 1;
  }

  if(argc < 3)
  {
    butts = malloc(256);
    butts = fgets(butts, 256, stdin);
    avlen = strlen(butts);
    vlen = atoll(argv[1]);

    if(vlen > avlen)
    {
      printf("cut length is too long\n");
      return 1;
    }

    *(butts + vlen) = '\0';

    printf("%s\n", butts);
  }
  else
  {
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
  }
  free(butts);

  return 0;
}
