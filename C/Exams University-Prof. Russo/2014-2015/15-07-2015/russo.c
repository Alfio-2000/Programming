#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define FILE_PUNTI "hits.bin"
#define FILE_RETTE "rette.bin"
#define D_SOGLIA   2.829

typedef FILE*  pfile;
typedef struct _punto {int x,y;} punto;
typedef punto* ppunto;
typedef struct _retta {float a,b,c;} retta;
typedef retta* pretta;

int main(void)
 {pfile  f;
  int    n_p,n_r,i_p,i_r,i1,i2;
  ppunto ppunti;
  retta  r;
  float  d,d1=FLT_MAX,d2=FLT_MAX;

  if ((f=fopen(FILE_PUNTI,"rb"))==NULL) goto file_err;
  fread(&n_p,sizeof(int),1,f);
  if ((ppunti=(ppunto)malloc(sizeof(punto)*n_p))==NULL) 
   {printf("Memoria insufficient\n"); return EXIT_FAILURE;}
  fread(ppunti,sizeof(punto),n_p,f);
  fclose(f);
  if ((f=fopen(FILE_RETTE,"rb"))==NULL) goto file_err;
  fread(&n_r,sizeof(int),1,f);
  for(i_r=0;i_r<n_r;i_r++)
   {fread(&r,sizeof(retta),1,f);
    if ((r.a==0.0)&&(r.b==0.0)) {printf("Errore nella retta n.%d\n",i_r); return EXIT_FAILURE;}
    d=0.0;
    for(i_p=0;i_p<n_p;i_p++)
     d+=fabs(r.a*ppunti[i_p].x+r.b*ppunti[i_p].y+r.c)/sqrt(r.a*r.a+r.b*r.b);
    if ((d/=n_p)<D_SOGLIA) 
     {printf("La retta n.%d: %fx+%fy+%f=0 ha una distanza pari a %f\n",i_r,r.a,r.b,r.c,d);
      if (d<d1) {d2=d1; i2=i1; d1=d; i1=i_r;}
      else if (d<d2) {d2=d; i2=i_r;}
     }
   }
  fclose(f);
  if (d1<FLT_MAX) 
   {printf("La migliore approx e' data dalla retta n.%d",i1);
    if (d2<FLT_MAX) printf(", seguita dalla n.%d",i2);
   }
  printf("\n");
  free(ppunti);
  return EXIT_SUCCESS;

  file_err: printf("Errore di apertura fil\n"); return EXIT_FAILURE;
 }
