#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LS 1024     //Lunghezza delle stringhe
#define NPUNTI    10000000
#define VMIN      0.0
#define VMAX      100
#define NF "dati.txt" //Nome del file
#define DXCHAR 'd'

typedef FILE* pfile;
typedef struct {float x,y,l;}quadrato; //Struttura del quadrato (destro).
typedef quadrato* pquadrato;
typedef float* pfloat; //Questo mi serve per acquisire i dati del quadrato centrato.

int main(void)
{
    pfile f; //Puntatore per la gestione del file di testo.
    pquadrato pq; //Puntatore alla struttura quadrato (questa rappresenterà il quadrato destro.).
    pfloat pf; //Questo puntatore mi serve per acquisire i dati del quadrato centrato.
    unsigned nq; //Numero di quadrati misurati.
    unsigned i; //Contatore per i cicli.
    float area; //Area dei quadrati.
    char s[LS];

    printf("Inizio elaborazione dati.\n");
    if((f=fopen(NF,"r"))==NULL) goto file_err;
    fscanf(f,"%s",s); nq=atoi(s);
    printf("\n%u misure acquisite.\n\n",nq); //Ho acquisito il numero totale delle misure effettuate.

    if((pq=(pquadrato)malloc(sizeof(quadrato)*nq))==NULL) goto mem_err;

    for(i=0; i<nq; i++)
    {
        fscanf(f,"%s",s); pq[i].x=atof(s);
        fscanf(f,"%s",s); pq[i].y=atof(s);
        fscanf(f,"%s",s); pq[i].l=atof(s);
        fscanf(f,"%s",s);
        printf("Acquisiti x=%.2f, y=%.2f, l=%.2f di un quadrato ",pq[i].x,pq[i].y,pq[i].l);
        if(s[0]==DXCHAR){printf("destro ");}
        else{printf("centrato ");pq[i].x=pq[i].x-pq[i].l;pq[i].y=pq[i].y-pq[i].l;pq[i].l*=2;}
        printf("As=%.2f.\n",pq[i].l*pq[i].l);
    }
    fclose(f); //Ho chiuso il file txt.
    printf("\nFine elaborazione dati.\n");

    return EXIT_SUCCESS;
    file_err: printf("Errore con i file!\n"); return EXIT_FAILURE;
    mem_err:  printf("Errore di memoria.\n"); return EXIT_FAILURE;

}
