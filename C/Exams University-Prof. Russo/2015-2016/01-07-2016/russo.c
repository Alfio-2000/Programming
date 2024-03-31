#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define FILE_PUNTI "punti.bin"
#define FILE_SFERE "sfere.txt"
#define STR_LENGTH 256

typedef struct _dot {float x,y,z;} dot;
typedef dot*   pdot;
typedef char*  pchar;
typedef FILE*  pfile;
typedef float* pfloat;

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

float d2(pdot pd1,pdot pd2)
 {return pow(pd1->x-pd2->x,2)+pow(pd1->y-pd2->y,2)+pow(pd1->z-pd2->z,2);}

int main(void)
 {char nomefile[STR_LENGTH];
  int n_p,n_s,i,j,c; 
  pfile f;
  pdot pd;
  dot  cs,b;
  float rs;
 
  if ((f=fopen(strcpy(nomefile,FILE_PUNTI),"rb"))==NULL) goto file_err;
  if (fread(&n_p,sizeof(int),1,f)!=1)                    goto file_err;
  if ((pd=(pdot)malloc(sizeof(dot)*n_p))==NULL)          goto mem_err;
  if (fread(pd,sizeof(dot),n_p,f)!=n_p)                  goto file_err;  
  fclose(f);
     
  if ((f=fopen(strcpy(nomefile,FILE_SFERE),"r"))==NULL)  goto file_err;
  n_s=get_int_from_file(f);
  for(i=0;i<n_s;i++)
   {cs.x=get_float_from_file(f);cs.y=get_float_from_file(f);cs.z=get_float_from_file(f);rs=get_float_from_file(f);
    for(b.x=b.y=b.z=0.0,c=j=0;j<n_p;j++)
     if (d2(&cs,pd+j)<(rs*rs)) {c++; b.x+=pd[j].x; b.y+=pd[j].y; b.z+=pd[j].z;}
    printf("\nAlla sfera n.%d appartengono %d punti",i+1,c);
    if (c) 
     {b.x/=c;b.y/=c;b.z/=c;
      printf(" e la distanza e' pari a: %f",sqrt(d2(&cs,&b)));
     }
   }
  printf("\n"); fclose(f); free(pd);
  return EXIT_SUCCESS;

  file_err: printf("\nERRORE: problemi col file \"%s\"\n",nomefile); return EXIT_FAILURE;
  mem_err:  printf("\nERRORE: Mememoria insufficiente\n"); return EXIT_FAILURE;
 }
