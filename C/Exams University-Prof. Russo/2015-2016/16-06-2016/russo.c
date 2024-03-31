#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define NOME_FILE "fasci.bin"
#define N_PUNTI   1000000

typedef struct _rettangolo {double x1,y1,x2,y2;} rettangolo;
typedef rettangolo* prettangolo;
typedef FILE* pfile;

int main(void)
 {int n_r,i_r,i_p,count=0;
  pfile f;
  prettangolo pr;
  double xmin=DBL_MAX,ymin=DBL_MAX,xmax=-DBL_MAX,ymax=-DBL_MAX,x,y,dx,dy,area;

  if ((f=fopen(NOME_FILE,"rb"))==NULL) goto file_err;
  if (fread(&n_r,sizeof(int),1,f)!=1)  goto file_err;
  if ((pr=(prettangolo)malloc(sizeof(rettangolo)*n_r))==NULL) goto mem_err;
  if (fread(pr,sizeof(rettangolo),n_r,f)!=n_r) goto file_err;
  fclose(f);
  for(i_r=0;i_r<n_r;i_r++)
   {if (pr[i_r].x1<xmin) xmin=pr[i_r].x1;
    if (pr[i_r].y1<ymin) ymin=pr[i_r].y1;
    if (pr[i_r].x2>xmax) xmax=pr[i_r].x2;
    if (pr[i_r].y2>ymax) ymax=pr[i_r].y2;
   }
  printf("\nL'area del rettangolo R_min e' pari a: %f",area=(dy=(ymax-ymin))*(dx=(xmax-xmin)));
  for(i_p=0;i_p<N_PUNTI;i_p++)
   {x=dx*rand()/RAND_MAX+xmin; y=dy*rand()/RAND_MAX+ymin;
    for(i_r=0;i_r<n_r;i_r++)
     if ((x>=pr[i_r].x1)&&(x<=pr[i_r].x2)&&(y>=pr[i_r].y1)&&(y<=pr[i_r].y2))
      {count++; break;}
   }
  printf("\nL'area stimata dell'unione dei rettangoli e' pari a: %f\n",count*area/N_PUNTI);
  return EXIT_SUCCESS;

  file_err: printf("\nERRORE:  problemi col file \"%s\"\n",NOME_FILE); return EXIT_FAILURE;
  mem_err:  printf("\nERRORE: Mememoria insufficiente\n"); return EXIT_FAILURE;
  
  
 }
