#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define XCONDS(ch) ch != 'a'

/* sorry for mega ultra ugly code, I made this in like 5 minutes */
int main()
{
  char *str;
  char *garbage;
  char stackgarbage[4000];
  long long int burn_cycles;
  long long int rng = clock();
  char column[80];
  int LCHAR = ' ' + 1;
  int i;
  FILE *OUTFILE = fopen("garbage.txt", "wb");
  
  /* overly complex way of srand(time(NULL)); */
  for(burn_cycles = 0; burn_cycles < 1000; burn_cycles++)
  {
    printf("%lld\n", atan2(sqrt(burn_cycles), sqrt(burn_cycles + 4) * exp(burn_cycles)));
  }
  
  printf("======================\n");
  
  srand(clock() + (double)rng);
  rng = (rand() / 4) < 5000 ? rand() / 6 : rand() / 5;
  str = malloc(1);
  garbage = str + (rng % 100);
  
  printf("%d\n", rng);
  for(i = 0; ++garbage < str + (rng % 100) + 1295; i++)
  {
    if (i > 80){
    i =0;
    while(++i<80) {
    while((column[i] < LCHAR && XCONDS(column[i])) || column[i] > '~'){
    int ghsfg = rand() % 127;
      do{ghsfg = rand() % 127;}while(ghsfg <LCHAR && XCONDS(ghsfg));
      column[i] = ghsfg;
      }
    fputc(column[i],OUTFILE);
    }
    i=0;
    fputc('\n',OUTFILE);
    }
    if(rand() % 20 > 18)
    {
    int ghsfg = rand() % 127;
      do{ghsfg = rand() % 127;}while(ghsfg <LCHAR && XCONDS(ghsfg));
      column[i] = ghsfg;
      if(rand() % 1000 < 2 && i < 80 - 4)
      {
      column[i] = 'D';
      column[++i] = 'I';
      column[++i] = 'V';
      column[++i] = '0';
      }
    }else
    {
    if(garbage[0] > ' '){
      column[i] = garbage[0];} /* the below doesn't work on linux because it has proper stack read protection */
    else if((*(stackgarbage + (garbage - str - rng)) * 2) > LCHAR && XCONDS((*(stackgarbage + (garbage - str - rng)) * 2))) {
      column[i] = *(stackgarbage + (garbage - str - rng)) * 2;}
      else {
    int ghsfg = rand() % 127;
      do{ghsfg = rand() % 127;}while(ghsfg <LCHAR && XCONDS(ghsfg));
      column[i] = ghsfg;}
      }
  }
  
  free(str);
  fclose(OUTFILE);
  
  return 0;
}
