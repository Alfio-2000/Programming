#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define FILE_PUNTI        "dati.bin"
#define FILE_RETTANGOLI   "rettangoli.bin"
#define FILE_ELAB         "elab.txt"

typedef FILE* pfile;
typedef int*  pint;
typedef struct _rettangolo {int x1,y1,x2,y2;} rettangolo;
typedef rettangolo* prettangolo;

int main(void)
 {pfile       f;
  int         n_d,n_c,i,j,j1,v;
  pint        pdata;
  prettangolo prett;
  rettangolo  r;
 
  printf("Inizio elaborazione\nApro il file %s in lettura\n",FILE_PUNTI);
  if ((f=fopen(FILE_PUNTI,"rb"))==NULL) goto file_err;
  fread(&n_d,sizeof(int),1,f);
  if ((pdata=(pint)malloc(sizeof(int)*n_d*2))==NULL) goto no_mem;
  fread(pdata,sizeof(int),n_d*2,f);
  fclose(f);

  printf("Apro il file %s in lettura\n",FILE_RETTANGOLI);
  if ((f=fopen(FILE_RETTANGOLI,"rb"))==NULL) goto file_err;
  fread(&n_c,sizeof(int),1,f);
  if ((prett=(prettangolo)malloc(sizeof(rettangolo)*n_c))==NULL) goto no_mem;
  fread(prett,sizeof(rettangolo),n_c,f);
  fclose(f);

  printf("Apro il file %s in scrittura\n",FILE_ELAB);
  if ((f=fopen(FILE_ELAB,"w"))==NULL) goto file_err;
  for(i=0;i<n_c;i++)
   {v=0;   
	   r.x1=r.y1=INT_MAX;
	   r.x2=r.y2=INT_MIN;
   	 for(j=0,j1=n_d;j<n_d;j++,j1++)
     if ((pdata[j]>prett[i].x1)&&(pdata[j]<prett[i].x2)&&(pdata[j1]>prett[i].y1)&&(pdata[j1]<prett[i].y2))
      {v++;
       if (pdata[j]< r.x1) r.x1=pdata[j];
       if (pdata[j]> r.x2) r.x2=pdata[j];
       if (pdata[j1]<r.y1) r.y1=pdata[j1];
       if (pdata[j1]>r.y2) r.y2=pdata[j1];
      }      
    fprintf(f,"%d\n%d\n%d\n%d\n%d\n",v,r.x1,r.y1,r.x2,r.y2);
   }
  fclose(f);
  printf("Elaborazione terminata\n");
  return EXIT_SUCCESS;
  
  file_err:
  	 printf("Errore di apertura fil\n");
   return EXIT_FAILURE;
  no_mem:
  	 printf("Memoria insufficient\n");
   return EXIT_FAILURE;
 }
