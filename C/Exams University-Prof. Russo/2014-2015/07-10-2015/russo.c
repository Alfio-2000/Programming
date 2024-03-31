#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define STR_LENGTH 256
#define FILE_MISURE "misure.bin"

typedef FILE*   pfile;
typedef struct  _misura {float v,i;} misura;
typedef misura* pmisura;

int get_int_from_kbd(char* msg)
 {char s[STR_LENGTH];
  printf("%s",msg); 
  scanf("%s",s);
  return atoi(s);
 }

float get_float_from_kbd(char* msg)
 {char s[STR_LENGTH];
  printf("%s",msg); 
  scanf("%s",s);
  return atof(s);
 }

int main(void)
 {pfile  f;
  int n_m,n_r,i;
  float r_min,r_max,r,dr,r_best,e,e_best=FLT_MAX;
  pmisura misure;

  if ((f=fopen(FILE_MISURE,"rb"))==NULL) goto file_err;
  fread(&n_m,sizeof(int),1,f);
  if ((misure=(pmisura)malloc(sizeof(misura)*n_m))==NULL) goto mem_err;
  fread(misure,sizeof(misura),n_m,f);
  fclose(f);

  r_min=get_float_from_kbd("Dammi il valore minimo  di resistenza: ");
  r_max=get_float_from_kbd("Dammi il valore massimo di resistenza: ");
  if (r_max<r_min) goto dati_err;
  n_r=    get_int_from_kbd("Dammi il numero di resistenze: ");
  if (n_r<0) goto dati_err;

  dr=(r_max-r_min)/(n_r-1);
  for(r=r_min;r<=r_max;r+=dr)
   {for(e=0.0,i=0;i<n_m;i++) e+=fabs(misure[i].v-r*misure[i].i)/sqrt(1+r*r);
    if (e<e_best) {e_best=e; r_best=r;}
   }

  printf("R=%f, d_mean=%f\n",r_best,e_best/n_m); 
  free(misure);
  return EXIT_SUCCESS;

  file_err: printf("Errore di apertura fil\n");  return EXIT_FAILURE;
  mem_err:  printf("Memoria insufficient\n");    return EXIT_FAILURE;
  dati_err: printf("Dati immessi non validi\n"); return EXIT_FAILURE;
 }
