#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DT "dati.bin"
#define RT "rettangoli.bin"
#define FO "elab.txt" //File di output.

typedef FILE* pfile;
typedef struct {int x,y;}dot; //Struttura punto
typedef dot* pdot;
typedef struct {int x1,y1,x2,y2;}rettangolo; // Struttura rettangolo.
typedef rettangolo* prettangolo;

int main(void)
{
    pfile f1,f2,fout;
    pdot pd;
    prettangolo pr;
    int nd, nr; //numero di dati e rettangoli.
    unsigned i,j,k;
    rettangolo r;

    if((f1=fopen(DT,"rb"))==NULL) goto file_err;
    if((f2=fopen(RT,"rb"))==NULL) goto file_err;
    fread(&nd,sizeof(int),1,f1);fread(&nr,sizeof(int),1,f2);

    printf("\nInizio elaborazione dei dati.\n\n");

    if((pd=(pdot)malloc(sizeof(dot)*2*nd))==NULL)             goto mem_err;
    if((pr=(prettangolo)malloc(sizeof(rettangolo)*nr))==NULL) goto mem_err;
    printf("%u Punti acquisiti:\n",nd);
    for(i=0,j=nd; i<nd,j<2*nd; i++,j++)//[1].
    {
        fread(&pd[i].x,sizeof(int),1,f1);fread(&pd[j].y,sizeof(int),1,f1); //Ho acquisito i punti (x,y)
        printf("%u° Punto: (%d,%d)\n",i+1,pd[i].x,pd[j].y);
    }
    printf("\n%u Rettangoli acquisiti:\n",nr);
    for(k=0;k<nr;k++) //[2]
    {
        fread(&pr[k].x1,sizeof(int),1,f2); fread(&pr[k].y1,sizeof(int),1,f2); //Leggo il punto (x1,y1)
        fread(&pr[k].x2,sizeof(int),1,f2); fread(&pr[k].y2,sizeof(int),1,f2);//Leggo il punto (x2,y2)
        printf("%u° diagonale: (%d,%d),(%d,%d)\n",k+1,pr[k].x1,pr[k].y1,pr[k].x2,pr[k].y2);
    }
    printf("\n");

    if((fout=fopen(FO,"w"))==NULL) goto file_err;
    int v; //Numero di particelle incidenti.
    for(k=0;k<nr;k++)
    {
        v=0;
        r.x1=r.y1=INT_MAX;
        r.x2=r.y2=INT_MIN;//[3]
        for(i=0,j=nd; i<nd,j<2*nd; i++,j++)
        {
            if((pd[i].x>pr[k].x1)&&(pd[i].x<pr[k].x2)&&(pd[j].y>pr[k].y1)&&(pd[j].y<pr[k].y2))
            {
                v++;
                if(pd[i].x<r.x1) r.x1=pd[i].x;
                if(pd[i].x>r.x2) r.x2=pd[i].x;
                if(pd[j].y<r.y1) r.y1=pd[j].y;
                if(pd[j].y>r.y2) r.y2=pd[j].y;
            }
        }
        printf("Nel %u° rettangolo incidono %d particelle.\n",k+1,v);
        fprintf(fout,"%d\n%d\n%d\n%d\n%d\n",v,r.x1,r.y1,r.x2,r.y2);
    }
    printf("\nTroverai i risultati nel file '%s'.\n",FO);
    printf("\nFine elaborazione dei dati.\n");

    fclose(fout);
    fclose(f1); fclose(f2);
    free(pd);free(pr); //LIbero la memoria.
    return EXIT_SUCCESS;
    file_err: printf("Errore apertura file.\n");  return EXIT_FAILURE;
    mem_err:  printf("RAM insufficiente!\n");     return EXIT_FAILURE;
}

/*[1]:Sto acquisendo i dati.bin
Ho messo 2*nr perché per ogni punto ci sono 2 coordinate: quindi, 5 punti->10 valori */

/*[2]:Ho moltiplicato per 2 perché ogni rettangolo è caratterizzato da una diagonale identificata da due punti.Quindi, in totale ho 6 punti.*/

/*//[3]:Sto fissando le variabili della struct r a dei valori dati. perché sto facendo questo? Perché voglio costruire un rettangolo più piccolo all'i-esimo rettangolo e questo rettangolo piccolo dovrà aggiornarsi ad ogni ciclo (perché deve essere interno ad ogni i-esimo rettangolo)*/
