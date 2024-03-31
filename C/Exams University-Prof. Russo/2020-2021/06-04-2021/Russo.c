#include <stdio.h>
#include <stdlib.h>


#define NFP    "punti.txt"
#define NFR    "rette.txt"
#define STRLEN 256

typedef FILE*                    pfile;
typedef struct _dot {float x,y;} dot;
typedef dot*                     pdot;


int main(void)
 {pfile    f,fpiu,fmeno,fd;
  unsigned np,nr,i,j,npiu,nmeno;
  char     s[STRLEN];
  pdot     pd;
  float    m,q,x,y;
  
  if ((f=fopen(NFP,"r"))==NULL) goto file_err;
  fscanf(f,"%s",s);
  np=atoi(s);
  if ((pd=(pdot)malloc(sizeof(dot)*np))==NULL) goto mem_err;
  for (i=0;i<np;i++) {fscanf(f,"%s",s); pd[i].x=atof(s); fscanf(f,"%s",s); pd[i].y=atof(s);}
  fclose(f);
  
  if ((f=fopen(NFR,"r"))==NULL) goto file_err;
  fscanf(f,"%s",s);
  nr=atoi(s);
  for(i=0;i<nr;i++)
   {npiu=nmeno=0;
    fscanf(f,"%s",s);
    m=atof(s);
    fscanf(f,"%s",s);
    q=atof(s);
    printf("Acquisita la retta r%u: y=%.2fx+%.2f\n",i,m,q);
    sprintf(s,"r%d_piu.txt",i);
    if ((fpiu= fopen(s,"w"))==NULL) goto file_err;
    printf("Divido i punti nel primo file denominato %s\n",s);
    sprintf(s,"r%d_meno.txt",i);
    if ((fmeno=fopen(s,"w"))==NULL) goto file_err;
    printf("E nel secondo file denominato %s\n",s);
    for(j=0;j<np;j++)
     {if ((y=pd[j].y)>(m*(x=pd[j].x)+q)) {fd=fpiu;  npiu++;}
      else                               {fd=fmeno; nmeno++;}
      fprintf(fd,"%.2f\n%.2f\n",x,y);
     }
    fclose(fmeno);fclose(fpiu);
    printf("%u punti nel primo file e %u punti nel secondo file\n\n",npiu,nmeno);
   }
  fclose(f);
  
  return EXIT_SUCCESS;
  
  file_err: printf("Problema coi files!\n");     return EXIT_FAILURE;
  mem_err:  printf("Problema colla memoria!\n"); return EXIT_FAILURE;
 }
