#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STRLEN    256
#define NPUNTI    10000000
#define NOME_FILE "dati.txt"
#define VMIN      0.0
#define VMAX      100.0
#define DXCHAR    'd'
#define NCOORD    2

typedef struct _quadrato {float x[NCOORD],l;} quadrato;
typedef quadrato*                        pquadrato;
typedef FILE*                            pfile;
typedef float*                           pfloat;

float get_float_from_txtfile(pfile pf)
 {char s[STRLEN];
  fscanf(pf,"%s",s);
  return atof(s);
 }

int get_int_from_txtfile(pfile pf)
 {char s[STRLEN];
  fscanf(pf,"%s",s);
  return atoi(s);
 }

void get_stampa_quadrato(pfile pf, pquadrato pq)
 {char s[STRLEN];
  float x,y,l;
  x=get_float_from_txtfile(pf);
  y=get_float_from_txtfile(pf);
  l=get_float_from_txtfile(pf);
  fscanf(pf,"%s",s);
  printf("\nAquisiti valori x0=%.2f y0=%.2f l=%.2f di un quadrato ",x,y,l);
  if (s[0]==DXCHAR){printf("destro  "); pq->x[0]=x;   pq->x[1]=y;   pq->l=l;}
  else             {printf("centrato"); pq->x[0]=x-l; pq->x[1]=y-l; pq->l=(l*=2);}
  printf(" As= %.2f",l*l);
 }
 
int main(void)
 {pfile     pf;
  unsigned  nq,ip,iq,ic,np;
  pquadrato pq,pq2;
  float     v[NCOORD],left,right,l;
  pfloat    px,pv;
  
  srand(time(NULL));
  if ((pf=fopen(NOME_FILE,"r"))==NULL) goto file_err;
  nq=get_int_from_txtfile(pf);
  if ((pq=(pquadrato)malloc(sizeof(quadrato)*nq))==NULL) goto mem_err;
  for(iq=0,pq2=pq;iq<nq;iq++,pq2++) {get_stampa_quadrato(pf,pq2);}
  fclose(pf); 
  for(ip=np=0;ip<NPUNTI;ip++)
   {for (ic=0,pv=v;ic<NCOORD;ic++,pv++) (*pv)=(((VMAX-VMIN)*rand())/RAND_MAX)+VMIN;
    for (iq=0,pq2=pq;iq<nq;iq++,pq2++)
     {for (ic=0,px=pq2->x,l=pq2->l,pv=v;ic<NCOORD;ic++,px++,pv++)
       {right=(left=(*px))+l;
        if (((*pv)<left)||((*pv)>right)) break;   
       }
      if (ic==NCOORD) break;       
     }
    if (iq<nq) np++;
   }
  free(pq);  
  printf("\nL'area stimata e' pari a %.2f\n",((VMAX-VMIN)*(VMAX-VMIN)*np)/NPUNTI);
  return EXIT_SUCCESS;
  
  file_err: printf("Errore di apertura file\n"); return EXIT_FAILURE;
  mem_err:  printf("Memoria insufficiente\n");   return EXIT_FAILURE;
 }
