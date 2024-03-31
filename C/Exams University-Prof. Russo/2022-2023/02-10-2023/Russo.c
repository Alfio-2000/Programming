#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SL 1024
#define FI "polinomi.txt"
#define XL -2.0
#define XR +2.0
#define NI 10000

typedef  FILE*  pfile;
typedef float* pfloat;  

float integrale(pfloat pc,unsigned g,float xl,float xr,unsigned nr)
 {unsigned i;
  float    x,dx,res;
 
  for(res=0.0,x=xl,dx=(xr-xl)/nr;x<xr;x+=dx) 
   for (i=0;i<=g;i++) res+=pc[i]*pow(x,i); 
  return res*dx;
 }

int main(void)
 {pfile    f;
  char     s[SL];
  unsigned np,ip,ig,g;
  pfloat   pc,pct;
  
  if ((f=fopen(FI,"r"))==NULL) goto file_err;
  fscanf(f,"%s",s);
  printf("Numero polinomi da integrare pari a %u\n",np=atoi(s));
  for (ip=0;ip<np;ip++)
   {fscanf(f,"%s",s);
    g=atoi(s);
    printf("Polinomio n.%u: ",ip+1);
    if ((pc=(pfloat)malloc(sizeof(float)*(g+1)))==NULL) goto mem_err;
    for(ig=0,pct=pc;ig<=g;ig++,pct++)
     {fscanf(f,"%s",s);
      if(!ig) printf("%.2f",(*pct)=atof(s));
      else    printf("+%.2fx^%u",(*pct)=atof(s),ig);
     }
    printf("\nIntegrale in [%.2f,%.2f] pari a %.2f",XL,XR,integrale(pc,g,XL,XR,NI));
    free(pc); printf("\n");
   }
  
  return EXIT_SUCCESS; 
  
  file_err: printf("Non ho potuto aprire il file %s!\n",FI); return EXIT_FAILURE;
  mem_err:  printf("Problemi di memoria!\n");                return EXIT_FAILURE;
 }
