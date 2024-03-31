#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define FILENAME1 "hits.bin"
#define FILENAME2 "rette.bin"



typedef FILE* PuntatoreFile;
typedef float* PuntatoreFloat;
typedef struct
 {
  int x,y;
 }Punto;
typedef struct
 {
  float a,b,c;
 }Retta;

typedef Punto* PuntatorePunto;
typedef Retta* PuntatoreRetta;
float calcoladistanza(PuntatoreRetta pr, PuntatorePunto pp, int i,int j);


float calcoladistanza(PuntatoreRetta pr,PuntatorePunto pp, int i,int j)
 {
  float numeratore=fabs(pr[i].a*pp[j].x+pr[i].b*pp[j].y+pr[i].c);
  float denominatore=sqrt(pow(pr[i].a,2)+pow(pr[i].b,2));
  float d=numeratore/denominatore;
  return d;
  }

int main ()
{
 int k,h;
 float somma;
 float media=0;
 float rettamigliore,secondarettamigliore;
 int np,nr,numerorettebuone=0; // Numero punti
 PuntatoreFile file1,file2;
 PuntatoreRetta pr;
 PuntatorePunto pp;
 PuntatoreFloat distanze;
 file1=fopen(FILENAME1,"rb");
 if(file1==NULL)
  {
   printf("Errore apertura del file\n");
  }
 fread(&np,sizeof(int),1,file1); //Leggiamo il numero di punti.
 pp=(PuntatorePunto)malloc(sizeof(Punto)*np); //vettore malloc di strutture
 if(pp==NULL)
  {
   printf("Errore costruzione del vettore di strutture"); //in cui ogni componente è una struttura cioè un punto
  }
 for(int i=0;i<np;i++)
 {
  fread(&pp[i].x,sizeof(int),1,file1);  //Stiamo leggendo le coordinate dal file bin e le sto inserendo nelvettore di strutture.
  fread(&pp[i].y,sizeof(int),1,file1);
 }
file2=fopen(FILENAME2,"rb");
if(file2==NULL)
 {
  printf("Errore apertura file2\n");
 }
fread(&nr,sizeof(int),1,file2);
pr=(PuntatoreRetta)malloc(sizeof(Retta)*nr); //Vettore di strutture dove ogni struttura è una retta determinata da tre parametri.
if(pr==NULL)
 {
  printf("ERRORE\n");
 }
distanze=(PuntatoreFloat)malloc(sizeof(float)*numerorettebuone);
if(distanze==NULL)
 {
  printf("ERRORE\n");
 }
for(int i=0;i<nr;i++)
 {
  fread(&pr[i].a,sizeof(float),1,file2);
  fread(&pr[i].b,sizeof(float),1,file2);
  fread(&pr[i].c,sizeof(float),1,file2);
 }
for(int i=0;i<nr;i++)    //Fissiamo adesso una retta e calcoliamo la distanza media da tutti i punti,dobbiamo fissare un elemento della struct di rette
 {
  somma=0;
  for(int j=0;j<np;j++)
   {

    float d=calcoladistanza(pr,pp,i,j);
    somma+=d;
   }
   media=somma/np;
   if(media<2.829)
    {
     numerorettebuone++;
     printf("Retta n%d %fx+%fy+%f=0 e distanza media pari a %f\n",i,pr[i].a,pr[i].b,pr[i].c,media);
     distanze[k]=media;
     k++;
     numerorettebuone=k;
    }
  }

 rettamigliore = distanze[0];
 for(int i=1;i<numerorettebuone;i++)
 {
   if(distanze[i]<rettamigliore)
    {
     rettamigliore=distanze[i];
     h=i;
    }
  }

 printf("La retta migliore è quella di distanza pari a %f\n",rettamigliore);
 secondarettamigliore=FLT_MAX;
 for(int i=0;i<numerorettebuone;i++)
  {
   if(i!=h && distanze[i]<secondarettamigliore)
    {
     secondarettamigliore=distanze[i];
    }
  }
 printf("La retta migliore è quella di distanza pari a %f\n",secondarettamigliore);


 free(pp);
 free(pr);
 free(distanze);
 fclose(file1);
 fclose(file2);
 fclose(file3);
}
