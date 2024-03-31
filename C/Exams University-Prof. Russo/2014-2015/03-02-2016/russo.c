#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STR_LENGTH  256
#define FILE_FASCIO "fasci.bin"
#define DISTANZA    10

typedef FILE* pfile;
typedef float* pfloat;
typedef struct _particella {float x,y;} particella;
typedef particella* pparticella;
typedef short* pshort;

float dist(float x1,float y1,float x2,float y2) {return sqrt(pow(x1-x2,2)+pow(y1-y2,2));}

int main(void)
 {pfile f;
  int nptot,np[]={0,0},i,j;
  pparticella pparts;
  float x,y,v,xb[]={0.0,0.0},yb[]={0.0,0.0},s[]={0.0,0.0},s2[]={0.0,0.0};
  pshort pset;

  if ((f=fopen(FILE_FASCIO,"rb"))==NULL) goto file_err;
  fread(&nptot,sizeof(int),1,f);
  if ((pparts=(pparticella)malloc(sizeof(particella)*nptot))==NULL) goto no_mem;
  if ((pset=(pshort)malloc(sizeof(short)*nptot))==NULL) goto no_mem;
  fread(pparts,sizeof(particella),nptot,f);
  for(i=0;i<nptot;i++)
   {pset[i]=j=(dist(x=pparts[i].x,y=pparts[i].y,0.0,0.0)<DISTANZA)?0:1;
    xb[j]+=x; yb[j]+=y; np[j]++;
   }
  for(j=0;j<2;j++) {xb[j]/=np[j]; yb[j]/=np[j];}
  for(i=0;i<nptot;i++) 
   {j=pset[i]; 
    s[j]+=v=dist(pparts[i].x,pparts[i].y,xb[j],yb[j]); 
    s2[j]+=v*v;
   }
  for(j=0;j<2;j++) 
   {s[j]/=np[j];
    printf("Baricentro n.%d: coordinate=(%.2f,%.2f) std=%.2f\n",j+1,xb[j],yb[j],sqrt(s2[j]/np[j]-s[j]*s[j]));
   }
  return EXIT_SUCCESS;

  file_err: printf("Errore di apertura del file %s\n",FILE_FASCIO); return EXIT_FAILURE;
  no_mem:   printf("Memoria insufficiente\n");   return EXIT_FAILURE;

 }


