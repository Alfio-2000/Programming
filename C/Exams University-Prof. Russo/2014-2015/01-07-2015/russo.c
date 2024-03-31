#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STR_LENGTH 256
#define DELTA_T    1
#define FILEX      "x.bin"
#define FILEY      "y.txt"

typedef FILE* pfile;
typedef float* pfloat;
typedef struct _coppia {float v,t;} coppia;
typedef coppia* pcoppia;
typedef struct _particella {float x,y,t;} particella;
typedef particella* pparticella;

int get_int_from_file(pfile f)
 {char s[STR_LENGTH]; 
  fscanf(f,"%s",s);
  return atoi(s);
 }

float get_float_from_file(pfile f)
 {char s[STR_LENGTH]; 
  fscanf(f,"%s",s);
  return atof(s);
 }

int main(void)
 {int n_m,i,j,k;
  pcoppia px,py;  
  pparticella pparticelle;
  pfile f;
  float x_g=0.0,y_g=0.0,t_g=0.0,sx=0.0,sy=0.0,st=0.0,x,y,t;
 
 	 printf("Inizio elaborazione\nApro il file %s in lettura\n",FILEX); 
	 if ((f=fopen(FILEX,"rb"))==NULL) goto file_err;
	 fread(&n_m,sizeof(int),1,f);
  	if ((px=(pcoppia)malloc(sizeof(coppia)*n_m))==NULL) goto no_mem;
  fread(px,sizeof(coppia),n_m,f);
  fclose(f); 

 	 printf("Adesso apro il file %s in lettura\n",FILEY); 
	 if ((f=fopen(FILEY,"r"))==NULL) goto file_err;
  if (get_int_from_file(f)!=n_m)  {printf("\nErrore di consistenza dei files!!\n"); return EXIT_FAILURE;}
  	if ((py=(pcoppia)malloc(sizeof(coppia)*n_m))==NULL) goto no_mem;
  for(i=0;i<n_m;i++) {py[i].v=get_float_from_file(f); py[i].t=get_float_from_file(f);}
  fclose(f); 

  	if ((pparticelle=(pparticella)malloc(sizeof(particella)*n_m))==NULL) goto no_mem;

  for(i=k=0;i<n_m;i++)
   for(j=0;j<n_m;j++)
    if (fabs(px[i].t-py[j].t)<DELTA_T)
     {x_g+=x=pparticelle[k].x=px[i].v;
      y_g+=y=pparticelle[k].y=py[j].v;
      t_g+=t=pparticelle[k].t=0.5*(px[i].t+py[j].t);
      sx+=x*x;
      sy+=y*y;
      st+=t*t;
      k++;
     }

  printf("Il baricentro delle particelle rivelate e': x_g=%f y_g=%f t_g=%f\n",x_g/=n_m,y_g/=n_m,t_g/=n_m);
  printf("Le deviazioni standard sono pari a:         sx= %f sy= %f st= %f\n",sqrt(sx/n_m-x_g*x_g),sqrt(sy/n_m-y_g*y_g),sqrt(st/n_m-t_g*t_g));
  printf("Elaborazione terminata\n");
  return EXIT_SUCCESS;
  
  file_err:
  	 printf("Errore di apertura file\n");
   return EXIT_FAILURE;
  no_mem:
  	 printf("Memoria insufficiente\n");
   return EXIT_FAILURE;
 }



