#include <stdio.h>
#include <stdlib.h>

#define STRLEN      1024
#define C_SERIE     'D'
#define C_END_SERIE 'E'
#define C_FINE_FILE 'S'
#define VERO        1
#define FALSO       0
#define VMN         1
#define VMX         10

#define FILENAME    "mail.txt"
#define L_MX_SERIE 10

typedef FILE*  pfile;
typedef char*  pchar;
typedef float* pfloat;

int stringa_contiene_char(pchar pc,char c)
 {while ((*pc)!='\0') if ((*pc)==c) return VERO; else pc++;
  return FALSO;
 }
 
void save_buffer(pchar nomebase,unsigned n,pfloat pb,unsigned lb)
 {pfile    pf;
  char     s[STRLEN];
  pfloat   pbfin;
  
  sprintf(s,"%s.%u",nomebase,n);
  printf("Scrivo il file %s\n",s);
  pf=fopen(s,"w"); fprintf(pf,"%u\n",lb);
  for(pbfin=pb+lb;pb<pbfin;pb++) fprintf(pf,"%.2f\n",*pb);
  fclose(pf);
 }
 
int main(void)
 {char     s[STRLEN];
  pfile    pf;
  unsigned ns,nd,nr,nb,nvb;
  int      lb;
  pfloat   pb;
 
  do
   {printf("Lunghezza buffer (ammessi solo valori positivi in [%u,%u]): ",VMN,VMX);
    scanf("%s",s);
    lb=atoi(s);
   }
  while ((lb<VMN)||(lb>VMX));
 
  if ((pb=(pfloat)malloc(sizeof(float)*lb))==NULL) goto mem_err;
 
  if ((pf=fopen(FILENAME,"r"))==NULL) goto file_err;
  
  for(ns=nd=nr=nb=nvb=0;;)
   {fscanf(pf,"%s",s); 
    if (stringa_contiene_char(s,C_FINE_FILE)) break;
    nr++;
    if (stringa_contiene_char(s,C_SERIE))
     {ns++;
      for(;;)
       {fscanf(pf,"%s",s); nr++;
        if(stringa_contiene_char(s,C_END_SERIE)) break;
        nd++;
        printf("nr=%u ns=%u nd=%u -> Letto: %.2f\n",nr,ns,nd,pb[nvb++]=atof(s));
        if (nvb==lb) {save_buffer(FILENAME,nb,pb,lb); nvb=0; nb++;}
       }
     }   
   }
  if (nvb) save_buffer(FILENAME,nb,pb,nvb); 
  fclose(pf); free(pb);
  return EXIT_SUCCESS;
 
  file_err: printf("Errore file\n"); return  EXIT_FAILURE;
  mem_err:  printf("Errore mem\n");  return  EXIT_FAILURE; 
 }
