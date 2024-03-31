#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define STRLEN 256
#define NF_IN  2 
#define NF_OUT 3 
#define PERC   0.8

typedef FILE*    pfile;
typedef pfile*   ppfile;
typedef unsigned un;

int main(void)
 {unsigned i,ii,o,n,nt;
  float    v,me,si,mn,mx;
  char     s[STRLEN],ss[2*STRLEN];

  ppfile ppfi,ppfo;

  printf("Nome base file: ");
  scanf("%s",s);
   
  if ((ppfi=(ppfile)malloc(sizeof(pfile)*NF_IN)) ==NULL) goto mem_err;
  if ((ppfo=(ppfile)malloc(sizeof(pfile)*NF_OUT))==NULL) goto mem_err;

  for(i=nt=0;i<NF_IN; i++)
   {sprintf(ss,"%s.%u.bin",s,i);
    if ((ppfi[i]=fopen(ss,"rb"))==NULL) goto file_err;
    fread(&n,sizeof(unsigned),1,ppfi[i]); nt+=n;
    printf("File n.%u dim=%u tot=%u\n",i,n,nt);
   }
  for(o=0;o<NF_OUT;o++)
   {sprintf(ss,"%s.%u.out.txt",s,o);
    if ((ppfo[o]=fopen(ss,"w"))==NULL) goto file_err;
    fprintf(ppfo[o],"%u\n",nt/NF_OUT);
   }

  for(i=ii=o=0,me=si=0.0,mx=-(mn=FLT_MAX);i<nt;i++,ii=(ii+1)%NF_IN,o=(o+1)%NF_OUT)
   {fread(&v,sizeof(float),1,ppfi[ii]);
    fprintf(ppfo[o],"%.1f\n",v); me+=v; si+=v*v;
    if (v<mn) {mn=v;} if (v>mx) {mx=v;}
    printf("Letto %.1f dal file input n.%u , scritto su file out n.%u\n",v,ii,o);     
   }
  
  me/=nt;si=sqrt(si/nt-me*me);
  printf("Media:%.5f Std:%.5f\n",me,si);
  me=0.5*(mn+mx); si=(mx-mn)*(1.0-PERC)*0.5;
  printf("[%.2f,%.2f] ristretto-> [%.2f,%.2f]\n",mn,mx,mn+si,mx-si);  

  for(i=0;i<NF_IN; i++) fclose(ppfi[i]);
  for(o=0;o<NF_OUT;o++) fclose(ppfo[o]);

  return EXIT_SUCCESS;
  
  file_err: printf("Errore con i files\n"); return EXIT_FAILURE;
  mem_err:  printf("Errore di memoria\n");  return EXIT_FAILURE;
   
 }

