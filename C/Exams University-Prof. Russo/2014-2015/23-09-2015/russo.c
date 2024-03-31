#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define STR_LENGTH  256
#define FILE_FASCIO "fasci.txt"
#define N           10000000 

typedef FILE* pfile;
typedef float* pfloat;
typedef struct _fascio {float xc,yc,r;} fascio;
typedef fascio* pfascio;

int get_int_from_file(pfile f)
 {char s[STR_LENGTH]; 
  fscanf(f,"%s",s);
  return atoi(s);
 }

float get_float_from_file(pfile f)
 {char s[STR_LENGTH]; 
  fscanf(f,"%s",s);
  return atof(s);
 }

int main(void)
 {long int i,j,nc,count;
  pfile f;
  pfascio pf;
  float x,y,xc,yc,r,dx,dy,a,mnx,mny,mxx,mxy,mnxtot=FLT_MAX,mnytot=FLT_MAX,mxxtot=-FLT_MAX,mxytot=-FLT_MAX;

  if ((f=fopen(FILE_FASCIO,"r"))==NULL) goto file_err;
  nc=get_int_from_file(f);
  if ((pf=(pfascio)malloc(sizeof(fascio)*nc))==NULL) goto no_mem;
  for(i=0;i<nc;i++)
   {xc=pf[i].xc=get_float_from_file(f);
    yc=pf[i].yc=get_float_from_file(f);
    r=pf[i].r  =get_float_from_file(f);
    mnx=xc-r;mxx=xc+r;
    mny=yc-r;mxy=yc+r;
    if (mnx<mnxtot) mnxtot=mnx;
    if (mny<mnytot) mnytot=mny;
    if (mxx>mxxtot) mxxtot=mxx;
    if (mxy>mxytot) mxytot=mxy;
   }
  fclose(f);
  printf("L'area del rettangolo e' pari a: %f\n",a=(dx=(mxxtot-mnxtot))*(dy=(mxytot-mnytot)));
  for(count=i=0;i<N;i++)
   {x=dx*rand()/RAND_MAX+mnxtot;
    y=dy*rand()/RAND_MAX+mnytot;
    for(j=0;j<nc;j++)
     if(pow(x-pf[j].xc,2)+pow(y-pf[j].yc,2)<=pow(pf[j].r,2)) {count++; break;}
   }
  printf("L'area stimata dell'unione dei fasci e' pari a: %f\nElaborazione terminata\n",(a*count)/N);
  return EXIT_SUCCESS;

  file_err: printf("Errore di apertura file\n"); return EXIT_FAILURE;
  no_mem:   printf("Memoria insufficiente\n");   return EXIT_FAILURE;
 }
