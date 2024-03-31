#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

#define NF "fasci.bin"
#define LS 1024 // Lunghezza stringhe
#define NP 1000000 //Numero di punti da generare.

typedef FILE* pfile;
typedef struct {double x1,y1,x2,y2;}rett;//Coordinate dei punti che identificano la diagonale del rettangolo corrente.
typedef rett* prett; //Puntatore alla struttura rett.

int main(void)
{
    pfile pf; //Puntatore apertura file.
    prett pr;//Puntatore di tipo rett (struttura)
    int nr; //Numero di rettangoli (È richiesto dal testo che sia un intero.)
    int npunti=0; //Numero di punti interni al rettangolo.
    unsigned i,j; //Contatori per i cicli
    float min_x=DBL_MAX,min_y=DBL_MAX,max_x=-DBL_MAX,max_y=-DBL_MAX; //[1]
    float b,c; // Parametri diagonale
    float dx,dy; //Base ed Altezza del nuovo rettangolo.
    float xp,yp; //Coordinate dei punti da generare.

    if((pf=fopen(NF,"rb"))==NULL) goto file_err;
    fread(&nr,sizeof(int),1,pf); //Ho letto il numero di rettangoli.
    printf("Abbiamo %d rettangoli.\n",nr);
    printf("Le diagonali di questi rettangoli sono:\n");
    if((pr=(prett)malloc(sizeof(rett)*nr))==NULL) goto mem_err; //Ho creato il vettore dinamico di struttura
    for(i=0; i<nr; i++)
    {
        fread(&pr[i].x1,sizeof(double),1,pf);
        fread(&pr[i].y1,sizeof(double),1,pf);//Ho acquisito le coordinate del 1°punto che rappresentano le diagonali.

        fread(&pr[i].x2,sizeof(double),1,pf);
        fread(&pr[i].y2,sizeof(double),1,pf);//Ho acquisito le coordinate del 2°punto che rappresentano le diagonali.
        b=((pr[i].y2-pr[i].y1)/(pr[i].x2-pr[i].x1));c=(((((pr[i].x1)*(pr[i].y2-pr[i].y1))/(pr[i].x2-pr[i].x1)))-pr[i].y1);
        printf("%u° diagonale: y+(%.2f)x+(%.2f)=0\n",i+1,b,c);

        if(pr[i].x1<min_x) min_x=pr[i].x1; //[2]
        if(pr[i].x2>max_x) max_x=pr[i].x2;
        if(pr[i].y1<min_y) min_y=pr[i].y1;
        if(pr[i].y2>min_y) max_y=pr[i].y2;
    }
    dx=(max_x-min_x); dy=(max_y-min_y);
    printf("\nL'area del rettangolo R_min è pari a: %f.\n",dx*dy);
    fclose(pf); //Ho chiuso il file.
    srand(time(NULL)); //Ho inizializzato il 'seme' (non so cosa significhi.)
    for(i=0; i<NP; i++)
    {
        xp=(dx*(rand()/RAND_MAX))+min_x;
        yp=(dy*(rand()/RAND_MAX))+min_y;
        for(j=0; j<nr; j++) //Faccio entrare i punti casuali all'interno dei rettangoli.
        {
            if((xp>=min_x) && (xp<=max_x) && (yp>=min_y) && (yp<=max_y)){npunti++;break;}
        }
    }
    printf("L'area stimata dell'unione dei rettangoli è pari a: %f.\n",((npunti*dx*dy)/NP));
    free(pr);//Libero la memoria dagli array dinamico.
    return EXIT_SUCCESS;
    file_err: printf("Errore di apertura file.\n");              return EXIT_FAILURE;
    mem_err:  printf("Errore di memoria: RAM insufficiente.\n"); return EXIT_FAILURE;
}
//[1]: Vedi compito 23/09/2015.

//[2]: Ho ragionato così: ho i punti che identificano la diagonale, allora, tra questi punti prendo la xmin, xmax, la ymin e la ymax. Così trovo le coordinate minime e quelle massime. Allora, otterrò la diagonale che passa per i punti (xmin,ymin) e (xmax,ymax).Inoltre, posso trovare le basi e le altezze: base=xmax-xmin, altezza=ymax-ymin
