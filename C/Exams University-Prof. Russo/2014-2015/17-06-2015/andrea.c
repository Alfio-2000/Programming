#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



#define NOMEFILE1  "dati.bin"
#define NOMEFILE2  "rettangoli.bin"
#define NOMEFILE3  "benitomussolini.txt"



typedef FILE* PuntatoreFile;
typedef int* PuntatoreInt;

typedef struct{int x1,y1,x2,y2;}Rettangolo;
typedef Rettangolo* PuntatoreRettangolo;

int main ()
{
 int nd,nr,np; // numero di dati nel file binario, è il primo valore di esso e numero di rettangoli da prendere dal secondo file.
 PuntatoreFile file1,file2,file3;
 PuntatoreInt pu1,pu2;
 PuntatoreRettangolo pr;

 file1=fopen(NOMEFILE1,"rb");
 if(file1==NULL){printf("ERRORE APERTURA FILE 1");}

 /*Apro in lettura i file dati.bin*/
 file2=fopen(NOMEFILE2,"rb");
 if(file2==NULL){printf("ERRORE APERTURA FILE 2");}
 fread(&nd,sizeof(int),1,file1);
 printf("Nel file binario fornito sono presenti %u dati\n",nd);

 pu1=(PuntatoreInt)malloc(sizeof(int)*nd); //Vettore dinamico che contiene le ascisse dei punti
 if(pu1==NULL){printf("ERRORE ALLOCAZIONE DINAMICA");}

 for(int i=0;i<nd;i++){fread(&pu1[i],sizeof(int),1,file1);printf("%u\n",pu1[i]);}

  pu2=(PuntatoreInt)malloc(sizeof(int)*nd); //Vettore dinamico che contiene le ordinate dei punti
 if(pu2==NULL){printf("ERRORE ALLOCAZIONE DINAMICA");}

 for(int i=0;i<nd;i++){fread(&pu2[i],sizeof(int),1,file1);printf("%u\n",pu2[i]);}

 fclose(file1);// Abbiamo acquisito i valori posso chiudere il file1
 fread(&nr,sizeof(int),1,file2); printf("Ci sono %d rettangoli\n",nr);

 pr=(PuntatoreRettangolo)malloc(sizeof(Rettangolo)*nr);

 if(pr==NULL){printf("Errore costruzione del vettore di rettangoli");} //in cui ogni componente è una struttura contenente un rettangolo

 for(int i=0;i<nr;i++)
 {
  fread(&pr[i].x1,sizeof(int),1,file2);fread(&pr[i].y1,sizeof(int),1,file2); //Ho letto (x1,y1)
  fread(&pr[i].x2,sizeof(int),1,file2);fread(&pr[i].y2,sizeof(int),1,file2);//Ho letto (x2,y2)
  printf("SI ha un un rettangolo con punti rilevanti %d,%d e %d,%d\n",pr[i].x1,pr[i].y1,pr[i].x2,pr[i].y2);
 }
 file3=fopen(NOMEFILE3,"w");
 if(file3==NULL){printf("ERRORE\n");}
 for(int i=0;i<nr;i++) //fissiamo il primo rettangolo e vediamo quante ce ne stanno.
  {
   np=0; // poniamo a 0 il numero di particelle dentro questo iesimo rettangolo.
   Rettangolo r = {INT_MAX, INT_MAX, INT_MIN, INT_MIN}; //Dentro questo rettangolo costruiamo un nuovo rettangolo che dovrà aggiornarsi
                                                         // In maniera tale che sia il più piccolo contenente tutte le particelle.
                                                         // Questa notazione mi permette di fissare le componenti della struct.
  for(int j=0;j<nd;j++)
   {
   if(pu1[j]>pr[i].x1 && pu1[j]<pr[i].x2 && pu2[j]>pr[i].y1 && pu2[j]<pr[i].y2)
    {
     np++;
     if(pu1[j]<r.x1) r.x1=pu1[j];
     if(pu2[j]<r.y1) r.y1=pu2[j];
     if(pu1[j]>r.x2) r.x2=pu1[j];
     if(pu2[j]>r.y2) r.y2=pu2[j];
   }
  }
   fprintf(file3,"%d\n",np);
   fprintf(file3,"%d\n",r.x1);
   fprintf(file3,"%d\n",r.y1);
   fprintf(file3,"%d\n",r.x2);
   fprintf(file3,"%d\n",r.y2);
  }
 fclose(file3);
 free(pu1);
 free(pu2);
 free(pr);
 }
