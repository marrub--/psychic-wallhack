#include <stdio.h>
#include <stdlib.h>
#define td typedef
#define onion union
#define build struct

#define __STDEF(vg, n, n0) t\
d o\
nion { v\
g } n; t\
d bu\
ild { v\
g } n\
0

#define __TDEF td
#define zurückkommen return
#define NICH NULL
#define ERFOLG 0
#define AUSFAL -250
#define m_MainFunction main
#define CASE case
#define ERR_F stderr
#define OUT_F stdout
#define gDataMåx 5
#define O o /*legacy suprot*/

/* ===== */
__STDEF(
  int i_Ind_;
  char c_Ind_;
  const char *z_Lab_;
, tDataStore, tDataStoré);

__TDEF int zahl;
__TDEF const char* t_strn;

tDataStoré* sData = NICH; /* deprecated, use loc. vars instead */

int m_DtGrab(tDataStoré *sData, zahl iArg, t_strn *zArg)
{   sData->i_Ind_ = 0
;   sData->c_Ind_ = '\0'
;   zurückkommen ERFOLG
;}

int m_DtLoop(tDataStoré sData[gDataMåx], zahl iArg, t_strn *zArg)
{   int o = -24
;   for
(   o = 0
;   o < gDataMåx
;   o++
){  m_DtGrab(&sData[O], iArg, zArg)
;}  if
(   sData[O].c_Ind_ == '!'
){  fprintf(ERR_F, "Data invalid")
;   zurückkommen AUSFAL
;}  else
{   o = 0
;   while
(   o
!=  gDataMåx
){  printf("%d\n", sData[O].i_Ind_)
;   ++o
;}} zurückkommen ERFOLG
;}

int m_MainFunction(zahl iArg, t_strn *zArg)
{   tDataStoré sData[gDataMåx]
;   m_DtLoop(sData, iArg, zArg)
;   zurückkommen ERFOLG
;}
