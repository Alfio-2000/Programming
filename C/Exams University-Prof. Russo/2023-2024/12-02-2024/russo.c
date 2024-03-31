#include <stdio.h>
#include <stdlib.h>

#define SL 1024

typedef FILE*    pfile;
typedef pfile*   ppfile;
typedef unsigned un;
typedef un*      pun;

int main(void)
 {char   s[SL+5],b[SL];
  un     nf,nvm,nvt,jf,jb,n;
  ppfile ppf;
  pfile  pfo;
  pun    nv;
  float  v;
  
  for (;;)
   {printf("Nome base file (attenzione il primo carattere non puo' essere un numero): ");
    scanf("%s",b);
    if ((b[0]<'0')||(b[0]>'9')) break;
    else printf("Errore!!\n");
   }

  sprintf(s,"%s.out",b);
  if ((pfo=fopen(s,"w"))==NULL) goto fil_err;

  printf("Num files: ");
  scanf("%s",s);
  nf=atoi(s);
  
  if ((ppf=(ppfile)malloc(sizeof(pfile)*nf))==NULL) goto mem_err;
  if ((nv =(pun)   malloc(sizeof(un)   *nf))==NULL) goto mem_err;
  for(nvt=nvm=jf=0;jf<nf;jf++) 
   {sprintf(s,"%s%u.bin",b,jf+1);
    if ((ppf[jf]=fopen(s,"rb"))==NULL) goto fil_err;
    if (fread(&n,sizeof(un),1,ppf[jf])!=1) goto fil_err;
    nvt+=nv[jf]=n;
    if (n>=nvm) nvm=n;
   }
  fprintf(pfo,"%u\n",nvt);
  for(jb=0;jb<nvm;jb++)
   for(jf=0;jf<nf;jf++)
    if (jb<nv[jf]) 
     {if (fread(&v,sizeof(float),1,ppf[jf])!=1) goto fil_err;
      fprintf(pfo,"%.3f\n",v);
     }
  return EXIT_SUCCESS;
  mem_err: printf("Errore di memoria!"); return EXIT_FAILURE;
  fil_err: printf("Errore di file!");    return EXIT_FAILURE;
 }
