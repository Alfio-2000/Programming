#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define FI "valori.bin" // FIle input
#define FO "valori.txt" // FIle ouput
#define LS 1024 // Lunghezza stringa

typedef FILE*   pfile;
typedef double* pdouble;

int main(void)
 {pfile    pfi,pfo;
  float    alpha,beta;
  unsigned i,j,k,nm,nv;
  double   v; // Valore
  char     s[LS];
  pdouble  pmax;
 
  printf("Numero di valori a partire dal massimo incluso: ");
  scanf("%s",s); nm=atoi(s);
  if ((pmax=(pdouble)malloc(sizeof(double)*nm))==NULL) goto mem_err;
  for(i=0;i<nm;pmax[i++]=-DBL_MAX);
  if ((pfi=fopen(FI,"rb"))==NULL) goto file_err;
  if ((pfo=fopen(FO,"w")) ==NULL) goto file_err;
  fread(&alpha,sizeof(float),1,pfi); fread(&beta,sizeof(float),1,pfi);
  printf("Funzione di trasformazione y=f(x) => y=%.2fx^2+%.2f\n",alpha,beta);
  fread(&nv,sizeof(unsigned),1,pfi); fprintf(pfo,"%u\n",nv);
  for(i=0;i<nv;i++)
   {fread(&v,sizeof(double),1,pfi); printf("Acquisito valore n.%u: %.2f, trasformato in ",i,v);
    fprintf(pfo,"%f\n",v=alpha*v*v+beta); printf("%.2f\n",v);

    for(j=0;j<nm;j++)
     if (pmax[j]<v) 
      {for(k=nm-1;k>j;k--) pmax[k]=pmax[k-1];
       pmax[j]=v;
       break;
      }
   }

  fclose(pfi);fclose(pfo);
  printf("I valori a partire dal massimo incluso sono: \n");
  for(i=0;i<nm;printf("%.2f ",pmax[i++])); printf("\n");
  return EXIT_SUCCESS;
  
  file_err: printf("Errore di apertura file!\n"); return EXIT_FAILURE;
  mem_err:  printf("Errore di memoria!\n");       return EXIT_FAILURE;

 }
 
