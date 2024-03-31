#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define STRLEN       1024
#define INV100       0.01
#define FILE_PARI    "pari.txt"
#define FILE_DISPARI "dispari.bin"
#define FILE_RES     "res.txt"

typedef FILE*  pfile;
typedef float* pfloat;

int main(void)
 {char     s[STRLEN];
  pfile    pf0,pf1;
  int      n,i,l,imn,i_f;
  pfloat   pv,pvtmp;
  float    m,v,mn;
  
  if ((pf0=fopen(FILE_PARI,"r"))    ==NULL) goto file_err;
  if ((pf1=fopen(FILE_DISPARI,"rb"))==NULL) goto file_err;

  fscanf(pf0,"%s",s);
  n=atoi(s);

  if ((pv=(pfloat)malloc(sizeof(float)*2*n))==NULL) goto mem_err;
  for(i=0,m=0,pvtmp=pv;i<n;i++)
   {fscanf(pf0,"%s",s);
    m+=*pvtmp=atof(s); pvtmp++;
    fread(pvtmp,sizeof(float),1,pf1); m+=*pvtmp; pvtmp++;
   }
  fclose(pf0);fclose(pf1);
  
  n*=2;
  printf("La media di %u valori e' pari a %.3f\nPercentuale media valore di taglio: ",n,m/=n);
  scanf("%s",s);
  m*=INV100*atof(s); printf("Valore di troncamento=%.3f\n",m);
  printf("Larghezza semintervallo: ");
  scanf("%s",s);
  l=atoi(s);
  
  for(i=0,mn=FLT_MAX,pvtmp=pv;i<n;i++,pvtmp++)
   {if ((*pvtmp)<mn) {mn=*pvtmp; imn=i;}}
  
  if ((pf0=fopen(FILE_RES,"w"))==NULL) goto file_err;
  for(i=imn-l,i_f=imn+l;i<=i_f;i++)
   {if ((i<0)||(i>=n)) fprintf(pf0,"MISS\n");
    else               {v=pv[i]; fprintf(pf0,"%.3f\n",(v<m)?v:m);}
   }
  fclose(pf0); free(pv);
  return EXIT_SUCCESS;
  
  file_err: printf("Errore con i files\n"); return EXIT_FAILURE;
  mem_err:  printf("Errore di memoria\n");  return EXIT_FAILURE;
  
 }
