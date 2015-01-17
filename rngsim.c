#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int arbse;
  int i = 0;
  int ii = 0;
  char chr;
  int iarr[500];
  char chbuf[20];
  char chbuf2[20];
  char chbuf3[20];
  int iarr2[100];
  int iarr3[100];char next=0; int iii=0;int iiii=0;
  FILE *rng = fopen("rngnum.txt", "r");
  while((chr = fgetc(rng)) != '\n')
  {
    if(chr == ',')
    {
      chbuf[ii] = '\0';
      iarr[i++] = atoll(chbuf);
      ii = 0;
      continue;
    }
    chbuf[ii] = chr;
    ii++;
  }
  i=ii=0;
  while((chr = fgetc(rng))!='\n')
  {
    if(chr == ':')
    {
      chbuf2[ii] = '\0';
      iarr3[iii++] = atoll(chbuf2);
      ii = 0;
      continue;
    }
    
    if(chr == ',')
    {
      chbuf2[ii] = '\0';
      iarr2[i++] = atoll(chbuf2);
      ii = 0;
      continue;
    }
    chbuf2[ii] = chr;
    ii++;
  }
  
  for(ii = 0; ii < i; ii++)
  {
    int butt1;
    printf("::: %d:%d :::\n", iarr3[ii], iarr2[ii]);
    for(butt1 = 0; butt1 < iarr2[ii]; butt1++)
    {
      printf("%d\n", iarr[iiii++] % iarr3[ii] + 1);
    }
  }
  
  fclose(rng);
  return 0;
}

