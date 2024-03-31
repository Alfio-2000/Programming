#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILE_IN  "dati.bin"
#define FILE_OUT1  "clean.txt"
#define FILE_OUT2  "noise.txt"

typedef FILE*   pfile;
typedef float*  pfloat;
typedef double* pdouble;

int main(void)
 {pfile   f,f1,f2;
  pfloat  x;
  pdouble y;
  int     nc,i,j;
  float   xg=0.0,sx=0.0,vx;
  double  yg=0.0,sy=0.0,vy;
 
  if ((f=fopen(FILE_IN,"rb"))==NULL)                goto file_err;
  if (fread(&nc,sizeof(int),1,f)!=1)                goto file_err;
  if ((x=(pfloat)malloc(sizeof(float)*nc))==NULL)   goto mem_err;
  if (fread(x,sizeof(float),nc,f)!=nc)              goto file_err;
  if ((y=(pdouble)malloc(sizeof(double)*nc))==NULL) goto mem_err;
  if (fread(y,sizeof(double),nc,f)!=nc)             goto file_err;
  fclose(f);
  for(i=0;i<nc;i++)
   {xg+=vx=x[i];sx+=vx*vx;
    yg+=vy=y[i];sy+=vy*vy;
   }
  xg/=nc;yg/=nc;sx=sx/nc-xg*xg;sy=sy/nc-yg*yg;
  if ((f1=fopen(FILE_OUT1,"w"))==NULL)              goto file_err;
  if ((f2=fopen(FILE_OUT2,"w"))==NULL)              goto file_err;
  for(i=0,j=nc-1;i<nc;i++,j--)
   {f=((pow((vx=x[i])-xg,2)/sx+pow((vy=y[j])-yg,2)/sy)<1)?f1:f2;
    fprintf(f,"%.2f %.2lf\n",vx,vy);
   }
  fclose(f1); fclose(f2); free(x); free(y); 
  return EXIT_SUCCESS;

  file_err: printf("Problema con i files!\n");   return EXIT_FAILURE;
  mem_err:  printf("Problema con la memoria\n"); return EXIT_FAILURE;
 }
