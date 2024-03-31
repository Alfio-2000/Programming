#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define NF "misure.bin"
#define LS 1024 //Lunghezza delle stringhe.

typedef FILE* pfile;
typedef struct {float v,c;}misura; //tensione, corrente che vengono dati dal testo
typedef misura* pmisura;
typedef float* pfloat;

int main(void)
{
    pfile f;
    pmisura pm;
    pfloat pr;     // Vettore dinamico che conterrà tutte le resistenze
    int n_m,n_r;  //Numero di misure e di resistenze.
    char s[LS];
    float r_min,r_max; //Valore minimo e massimo delle resistenze.
    float r,dr;
    float d,d_best=FLT_MAX,r_best; //[2]
    unsigned i,j;

    printf("Inizio eleborazione dati.\n"); printf("\nApertura file %s --> ",NF);
    if((f=fopen(NF,"rb"))==NULL) goto file_err;
    fread(&n_m,sizeof(int),1,f); printf("%d coppie di misure acquisite.\n\n",n_m);
    printf("Di seguito le coppie misurate.\n");
    if((pm=(pmisura)malloc(sizeof(misura)*n_m))==NULL) goto mem_err;
    if((pr=(pfloat)malloc(sizeof(float)*n_m))==NULL) goto mem_err;
    for(i=0,j=0; i<n_m,j<n_m; i++,j++)
    {
        fread(&pm[i].v,sizeof(float),1,f);fread(&pm[i].c,sizeof(float),1,f);//Ho acquisito i dati.
        pr[j]=pm[i].v*pm[i].c; //Calcolo la j-esima resistenza.
        printf("%u° coppia (%f, %f) ---> R= %f\n",i+1,pm[i].v,pm[i].c,pr[j]);
    }

    printf("\nRichiesta parametri per l'analisi dati:\n");
    printf("-Resistenza minima:");  scanf("%s",s); r_min=atof(s);
    printf("-Resistenza massima:"); scanf("%s",s); r_max=atof(s);
    if(r_min>r_max) goto dati_err;
    printf("-Inserisci il numero di resistenze:"); scanf("%s",s); n_r=atof(s);
    if(n_r<0) goto dati_err;

    dr=(r_max-r_min)/(n_r-1);
    for(r=r_min;r<=r_max;r+=dr) //[1]
    {
        for(d=0.0,i=0; i<n_m; i++){d+=fabs((pm[i].v-r*pm[i].c))/sqrt((1+r*r));}
        if(d<d_best){d_best=d; r_best=r;}
    }
    printf("\nParametri finali: R_best=%f, d_mean=%f\n",r_best,d_best/n_m);
    fclose(f);//Chiusura dei file.
    free(pm);free(pr);//LIberazione della memoria dalle misure.
    printf("\nFine eleborazione dati.\n");
    return EXIT_SUCCESS;
    file_err: printf("Errore apertura file.\n");        return EXIT_FAILURE;
    mem_err:  printf("RAM insufficiente!\n");           return EXIT_FAILURE;
    dati_err: printf("Dati inseriti non validi.\n");    return EXIT_FAILURE;

}
/*[1]: Questo for mi serve per generare n_r valori di resistenze uniformemente (altrimenti avrei dovuto usare time.h). Questo spiega anche perché ho calcolato dr, ossia la larghezza dell'intervallo che sarà l'incremento di r a partire da r_min fino a raggiungere il valore r_max. */

/*[2]: La r_best sarebbe la migliore approssimazione delle resistenza che corrisponde alla minore distanza media tra le misure sperimentali e le rette determinate da ciascuna resistenza. La logica sarebbe questa: sono state generate n_r resistenze. Prendiamone una detta r. Allora, dovremmo calcolare la retta v=ri->pm[].v=r*pm[].c (nel caso specifico del codice).

d=0.0 è un contatore che mi permette di sommare ogni singola distanza per poter calcolare poi la media.Questo l'ho inizializzato a zero per poter confrontare ogni singolo valore della distanza con il valore d_best. Se lo inizializzassi al di fuori del ciclo for confronterei solo l'ultimo valore acquisito della distanza misurata.

d_best=FLT_MAX è la distanza fissata al valore massimo per poter confrontarla con il valore corrente della distanza.*/
