#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define LS     1024   //Lunghezza delle stringhe.
#define SOGLIA 2.829 // Valore di soglia che deve essere usato.

#define PUNTI "hits.bin"   //Nome file punti
#define RETTE "rette.bin" // Nome file rette

typedef FILE* pfile;
typedef struct{int x,y;}dot; //Struttura di nome dot: x,y sono le coordinate del punto.
typedef dot* pdot;
typedef struct{float a,b,c;}retta; //Struttura di nome retta: a,b,c sono i parametri della retta.
typedef retta* pretta;

int main(void)
{
    unsigned np;    //Numero di punti all'interno del file omonimo
    int nr;        // Numero di rette all'interno del file omonimo
    pfile fp,fr;  //  Puntatori necessari all'apertura e alla chiusura dei file: fp per i punti, fr per le rette.
    pdot pd;
    pretta pr;
    float d; // La distanza che separa ogni singola retta dal singolo punto.
    float d_media; // La distanza media tra quelle calcolate prima.
    float dmin1=FLT_MAX, dmin2=FLT_MAX; //Distanti minori delle due rette che dobbiamo trovare.
    unsigned imin1,imin2; //Posizioni delle rette con distanze minori

    if((fp=fopen(PUNTI,"rb"))==NULL) goto file_err;
    fread(&np,sizeof(unsigned),1,fp); // Ho acquisito il numero di punti presenti nel file.
    if((fr=fopen(RETTE,"rb"))==NULL) goto file_err;
    fread(&nr,sizeof(unsigned),1,fr); // Ho acquisito il numero di rette presenti nel file.

    printf("File %s: %u punti,File %s: %d rette.\n",PUNTI,np,RETTE,nr);

    if((pd=(pdot)malloc(sizeof(dot)*np))==NULL)      goto mem_err;
    if((pr=(pretta)malloc(sizeof(retta)*nr))==NULL)  goto mem_err;
    printf("Questi sono i punti all'interno del file '%s'.\n",PUNTI);
    for(unsigned i=1; i<=np; i++) // Acquisisco le coordinate dei punti.
    {
        fread(&pd[i].x,sizeof(unsigned),1,fp); //[1]
        fread(&pd[i].y,sizeof(unsigned),1,fp);
        printf("Punto n°%u:(%d,%d).\n",i,pd[i].x,pd[i].y);
    }
    printf("\nQueste sono le rette all'interno del file '%s'.\n",RETTE);
    for(unsigned j=1; j<=nr; j++)
    {
        fread(&pr[j].a,sizeof(float),1,fr);
        fread(&pr[j].b,sizeof(float),1,fr);
        fread(&pr[j].c,sizeof(float),1,fr);
        printf("Retta n°%u:(%.2f)x+(%.2f)y+(%.2f)=0.\n",j,pr[j].a,pr[j].b,pr[j].c);
    }
    printf("\nEcco le rette che hanno una distanza <%.3f:\n",SOGLIA);
    for(unsigned j=1; j<=nr; j++) //Inizio il calcolo della distanza
    {
        if(pr[j].a==0 && pr[j].b==0){printf("Retta n°%u non valida!\n",j); return EXIT_FAILURE;}
        d=0.0; //[2]
        for(unsigned i=1; i<=np; i++)
        {
            d+=(fabs((pd[i].x*pr[j].a+pd[i].y*pr[j].b+pr[j].c))/sqrt((pr[j].a*pr[j].a)+(pr[j].b*pr[j].b)));
            d_media=d/np;
        }
        if(d_media<SOGLIA)
        {
            printf("Retta n°%u:(%f)x+(%f)y+(%f)=0 ha una distanza pari a %f.\n",j,pr[j].a,pr[j].b,pr[j].c,d_media);
            if(d_media<dmin1){dmin2=dmin1; imin2=imin1; dmin1=d; imin1=j;} //[3]
            else if(d_media<dmin2){dmin2=d_media; imin2=j;} //[4]
        }
    }
    fclose(fp);fclose(fr); // Ho chiuso i due file.
    printf("\nQuali sono le rette a distanza minore tra quelle selezionate?\n");
    if(dmin1<FLT_MAX){printf("Esse sono: retta n°%u",imin1);} //[5]
    if(dmin2<FLT_MAX){printf("; retta n°%u.\n",imin2);}
    free(pd); free(pr); // Ho liberato la memoria dai due vettori dinamici.
    return EXIT_SUCCESS;
    file_err: printf("Errore di apertura file.\n");              return EXIT_FAILURE;
    mem_err:  printf("Errore di memoria: RAM insufficiente.\n"); return EXIT_FAILURE;
}
//[1]: Non ho messo pd.x[] perché pd è un puntatore che puta all'intera struttura.Quindi, con questa scrittura punto direttamete alla variabile all'interno della struttura.

//[2]: Ho inizializzato qui perché in questo modo riporto a zero la distanza ad ogni iterazione conclusa. Altrimenti, tale distanza verrà incrementata ogni volta e avrò risultati diversi.

//[3]: Questa parte di codice controlla se d_media calcolare per la corrente j retta risulta essere minore della distanza minima dmin1 (inizializzata ad una valore arbitrario). Se è così viene aggiornato il secondo valore minimo dmin2, l'indice della retta corrispondente imin2 e di nuovo dmin1 e imin1 (quest'ultimo risulta essere l'indice corrispondente alla retta con distanza minima.)

//[4]: Questo controlla se d_media risulta compresa tra dmin1 e dmin2. Se risulta essere così viene aggiornato dmin2 e imin2.

//[5]: Fino alla riga 74 sto stampando le rette con distanza minima e la seconda tra quelle selezionate. dmin1 e dmin2 a questo punto sono le ultime che vengono calcolate alla fine del for a riga 70.

//[6]: IN conclusione, dalla riga 67 a riga 74 sto effettuando la ricerca del minimo secondo il metodo classico che ho usato negli esercizi sui vettori. RICORDA: USA LA VARIABILE TEMPORANEA. QUESTO METODO NON È LO STESSO DI QUELLO CHE USO: QUELLO CON I DUE IF.
