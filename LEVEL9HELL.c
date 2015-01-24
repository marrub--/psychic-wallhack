#include <stdio.h>
#define _T typedef
#define r return
  _T int i;_T char c;_T i z;_T const c* s;_T struct{i í;c á;}tÐ;
i mD(tÐ *sD,z iA,s *zA){sD->í=0;sD->á=0;r 0;}i md(tÐ sD[5],z iA,s *zA)
{for(i o=0;    o<5;              o++){mD(&sD[o],iA,zA); }
for(i o=0;o<5;o++)               printf("%d\n",sD[o].í);
r 0;}i main
(z iA,s *zA)
{tÐ sD[5];
md(sD,iA,zA);
r 0;}
