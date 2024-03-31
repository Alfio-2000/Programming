#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define STRLEN           256
#define EXT_FILE_IN_RIF  "inrif" 
#define EXT_FILE_IN_MIS  "inmis"
#define EXT_FILE_OUT_RIF "outrif" 
#define EXT_FILE_OUT_MIS "outmis"

typedef FILE*    pfile;
typedef float*   pfloat;
typedef unsigned un;
typedef un*      pun;

int main(void)
 {char   s[2*STRLEN],nf[STRLEN];
  pfile  pf;
  float  v,d,vmin;
  pfloat prif,pmis,piniz,pfine,p;
  un     nrif,nmis,i,ib;
  pun    pidxmis;
  
  printf("Nomefile: ");
  scanf("%s",nf);
  sprintf(s,"%s.%s",nf,EXT_FILE_IN_RIF);
  if ((pf=fopen(s,"r"))==NULL) goto file_err;
  fscanf(pf,"%s",s);
  printf("Numero riferimenti=%u\nValori:",nrif=atoi(s));
  if ((prif=(pfloat)malloc(sizeof(float)*nrif))==NULL) goto mem_err;
  for(pfine=(piniz=prif)+nrif;piniz<pfine;piniz++)
   {fscanf(pf,"%s",s); printf("(%.2f) ",(*piniz)=atof(s));}
  fclose(pf);
    
  sprintf(s,"%s.%s",nf,EXT_FILE_IN_MIS);
  if ((pf=fopen(s,"rb"))==NULL) goto file_err;
  fread(&nmis,sizeof(un),1,pf);
  printf("\nNumero misure=%u\n",nmis);
  if ((pidxmis=(pun)    malloc(sizeof(un)   *nmis))==NULL) goto mem_err;
  if ((pmis   =(pfloat) malloc(sizeof(float)*nmis))==NULL) goto mem_err;
  fread(pidxmis,sizeof(un),nmis,pf); fclose(pf); 
  for(i=0;i<nmis;i++) {ib=pidxmis[i]; printf("Acqisito idx (%u) -> Convertito in (%.2f)\n",ib,pmis[i]=prif[ib]);};  
  free(pidxmis);
  
  printf("\nNumero nuovi riferimenti=%u\nValori:",nrif/=2);
  sprintf(s,"%s.%s",nf,EXT_FILE_OUT_RIF);
  if ((pf=fopen(s,"w"))==NULL) goto file_err;
  fprintf(pf,"%u\n",nrif);
  for(pfine=(p=piniz=prif)+2*nrif;piniz<pfine;piniz+=2,p++)
   {printf("(%.2f) ",(*p)=v=0.5*(piniz[0]+piniz[1])); fprintf(pf,"%.3f\n",v);}
  fclose(pf); 

  printf("\nLe %d misure definitive:",nmis);
  sprintf(s,"%s.%s",nf,EXT_FILE_OUT_MIS);
  if ((pf=fopen(s,"w"))==NULL) goto file_err;
  fprintf(pf,"%u\n",nmis);
  for(pfine=(piniz=pmis)+nmis;piniz<pfine;piniz++)
   {for(v=(*piniz),vmin=FLT_MAX,i=0;i<nrif;i++)
     if ((d=(fabs(v-prif[i])))<vmin) {vmin=d; ib=i;}
    fprintf(pf,"%u\n",ib); printf("(%.2f) ",prif[ib]);
   }
  fclose(pf); printf("\n");
  
  return EXIT_SUCCESS;
  
  file_err: printf("Errore con i files\n"); return EXIT_FAILURE;
  mem_err:  printf("Errore di memoria\n");  return EXIT_FAILURE;
  
 }
