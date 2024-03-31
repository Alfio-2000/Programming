#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

#define LS 1024 //Lunghezza delle stringhe
#define NF "fasci.txt"
#define NP 1000000 // Numero di punti da generare.

typedef FILE* pfile;
typedef struct {float x,y,r;}cerchio; //Ascissa,ordinata e raggio del cerchio.
typedef cerchio* pcerchio; //Puntatore alla struttura cerchio

int main(void)
{
    pfile pf; //Puntatore per l'apertura dei file.
    pcerchio pc; //Ho dichiarato un Puntatore di tipo cerchio (struttura)
    char s[LS]; //Stringa per l'acquisizione.
    int nc; //Numero di cerchi all'interno del file.
    unsigned npunti=0; //Contatore che conta il numero di punti interni al rettangolo.
    unsigned i,j; //Contatori per i cicli. Il prof pretende che li dichiariamo prima..

    float min_x=FLT_MAX,min_y=FLT_MAX,max_x=-FLT_MAX,max_y=-FLT_MAX; // Rettangolo_MASSIMO [1]
    float b1,b2,h1,h2,area; //Rettangolo_minimo [2]
    float area_stimata; //É l'area derivante dall'unione dei fasci.
    float xp,yp; //Coordinate punti da generare

    printf("Ciao, io, usando il Metodo Montecarlo, sono in grado di calcolare l'area di un rettangolo");
    printf("\nche contiene i cerchi del tuo file e l'area stimata dell'unione di questi cerchi.\n\n");

    if((pf=fopen(NF,"r"))==NULL) goto file_err;
    fscanf(pf,"%s",s); nc=atoi(s); //Ho acquisito la prima riga del file-> ho il numero di cerchi all'interno del file.

    if((pc=(pcerchio)malloc(sizeof(cerchio)*nc))==NULL) goto mem_err;

    for(i=0; i<nc; i++)
    {
        fscanf(pf,"%f",&pc[i].x);
        fscanf(pf,"%f",&pc[i].y);
        fscanf(pf,"%f",&pc[i].r); //Ho acquisito x,y ed r del cerchio

        //Adesso costruisco il rettangolo minimo:
        b1=(pc[i].x-pc[i].r); b2=(pc[i].x+pc[i].r); //Ho costruito le basi.
        h1=(pc[i].y-pc[i].r); h2=(pc[i].y+pc[i].r); //Ho costruito le altezze.

        //Adesso devo aggiornare questi lati (cioè devo fare una ricerca di minimo e massimo.)
        if(b1<min_x) min_x=b1;     //Ho aggiornato la base minima del rettangolo.
        if(b2>max_x) max_x=b2;    //Ho aggiornato la base massima del rettangolo.
        if(h1<min_y) min_y=h1;   //Ho aggiornato l'altezza minima del rettangolo.
        if(h2>max_y) max_y=h2;  //Ho aggiornato l'altezza massima del rettangolo.
    }
    fclose(pf); //Ho chiuso il file dei cerchi.
    printf("Rettangolo trovato:\nbase:%.2f, altezza:%.2f.\n",(max_x-min_x),(max_y-min_y));
    printf("L'area del rettangolo è pari a %.2f.\n",area=((max_x-min_x)*(max_y-min_y))); //[3]

    srand(time(NULL)); //Ho inizializzato il 'seme' (non so cosa significhi.)

    for(i=0; i<NP; i++) //Adesso genero i punti.
    {
        xp= ((((float)rand())/RAND_MAX)*(max_x-min_x))+min_x; //Guarda appunti pag 38
        yp= ((((float)rand())/RAND_MAX)*(max_y-min_y))+min_y;
        for(j=0; j<nc; j++) //Adesso conto tutti quei punti interni al rettangolo.
        {
            if(pow((xp-pc[j].x),2)+pow((yp-pc[j].y),2)<=pow(pc[j].r,2)){npunti++; break;} //[4]
        }
    }
    printf("L'area stimata dell'unione dei fasci è pari: %f.\n",((npunti*area)/NP)); //[5]

    free(pc);//Ho liberato la memoria.

    return EXIT_SUCCESS;
    file_err: printf("Errore di apertura file.\n");              return EXIT_FAILURE;
    mem_err:  printf("Errore di memoria: RAM insufficiente.\n"); return EXIT_FAILURE;
}
//[1]: Uso questa dichiarazione perché ho fatto il seguente ragionamento: costruisco il rettangolo più grande possibile (così sono sicuro che contenga i cerchi; successivamente inizio a rimpicciolirlo in modo tale da beccare il rettangolo più piccolo in grado di contenere i cerchi)

//[2]: Sarà quello giusto perché dobbiamo trovare il rettangolo che contiene "strettamente i cerchi", quindi, è chiaro che se avessimo un rettangolo enorme questo li contenga, ma così sarebbe scontato e l'area non sarebbe quella richiesta (unione dei due cerchi.)

//[3]: Ho scritto così perché devi immaginare un rettangolo grande in grado di contenere i due cerchi e quello più piccolo in grado di contenerlo. Questi due rettangoli, chiaramente, avranno una base che dista dal centro del cerchio differente. Allora, tale differenza si esprime esatttamente come ho fatto io.

//[4]: HO usato questa condizione per l'if per il seguente ragionamento: se ho trovato un rettangolo che contiene i due cerchi basta che considero tutti i punti all'interno di uno de due cerchi avrò che tali punti apparterrano anche al rettangolo. Inoltre, ho messo il break in questo modo esce appena ha preso tutti quei punti appartenenti al cerchio.

//[5]: Questa è la formula per calcolare l'area usando il metodo Montecarlo


