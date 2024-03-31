#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define LS 1024    // Lunghezza delle stringhe
#define NFI 2    //  Numero di file input
#define NFD 3   //   Numero di file output
#define PERC 0.8 //80% dell'intervallo
#define nome_base "ciccio"

typedef FILE* pfile;
typedef pfile* ppfile;
typedef float* pfloat;

int main(void)
{
    ppfile ppfi,ppfo; // Puntatori di Puntatori a file per la creazione di array dinamici di tipo file.
    pfloat pf; // Puntatore a float per acquisire ogni dato dei file.
    char s[LS]; //Stringa per l'acquisizione.
    char sn[2*LS]; // Stringa che conterrà il nome dei file.
    unsigned n; //Numero di misure.
    unsigned nt=0; //Numero totale di misure.
    unsigned cont=0; // Mi serve per salvare i dati nell'array dinamico

    float mx=-FLT_MAX;
    float mn=FLT_MAX;  //Ho dichiarato massimo e minimo della serie di dati.
    float media=0.0; // media valori
    float dev_std=0.0;  // deviazione standard.
    float sommaquadrati=0.0;
    float somma=0.0;
    float ampiezza,ampiezza_ristretta,pt_medio; // ampiezza intervallo e quella ridotta dell'80%

    if((ppfi=(ppfile)malloc(sizeof(ppfile)*NFI))==NULL) goto mem_err;
    if((ppfo=(ppfile)malloc(sizeof(ppfile)*NFD))==NULL) goto mem_err; // Ho creato così vettori dinamici di file.

    printf("Il software di raccolta dati, salva quest'ultimi in file il cui nome è %s\n",nome_base);
    printf("Nome base file:");
    scanf("%s",s);

    for(unsigned i=0; i<NFI; i++) // Questo mi servirà a scrivere i file di input
    {
        sprintf(sn,"%s.%u.bin",s,i);
        if((ppfi[i]=fopen(sn,"rb"))==NULL) goto open_err; // Così apro l'i-esimo file.
        fread(&n,sizeof(unsigned),1,ppfi[i]); // Ho letto la prima riga dell'i-esimo file.
        nt+=n; // mi dà il numero totale di misure
        printf("File n.%u; dim=%u; tot=%u \n",i,n,nt);
    }

    for(unsigned i=0; i<NFI; i++) // Così ho acquisito ogni dato dei due file.
    {
        if((pf=(pfloat)malloc(sizeof(float)*nt))==NULL) goto mem_err;
        for(unsigned j=0; j<nt; j++)
        {
            fread(&pf[j],sizeof(float),1,ppfi[i]);
            printf("Letto %.1f dal file input n.%u\n",pf[j],i);
            somma+=pf[j];
            sommaquadrati+=pf[j]*pf[j];
            if(mx<pf[j]){mx=pf[j];}
            else if(mn>pf[j]){mn=pf[j];}
            i=(i+1)%NFI; //[1]
        }
    }
    media=somma/nt; dev_std= sqrt((sommaquadrati/nt)-(media*media)); // Calcolo media e deviazione standard
    ampiezza=(mx-mn); ampiezza_ristretta=0.8*ampiezza;
    pt_medio=(mx+mn)*0.5;
    printf("Media: %.5f, Std:%.5f\n",media,dev_std);
    printf("[%.2f,%.2f] ristretto ->[%.2f,%.2f]\n",mn,mx,pt_medio-(ampiezza_ristretta/2),pt_medio+(ampiezza_ristretta/2));

    for(unsigned i=0; i<NFI; i++) fclose(ppfi[i]); // Così ho chiuso tutti i file di input
    for(unsigned o=0; o<NFD; o++) fclose(ppfi[o]); // Così ho chiuso tutti i file di output
    free(pf);
    free(ppfi);free(ppfo);

    return EXIT_SUCCESS;
    open_err: printf("Errore nell'apertura dei file.\n");        return EXIT_FAILURE;
    mem_err:  printf("Errore di memoria: RAM insufficiente!\n"); return EXIT_FAILURE;
}
//[1]: In questo modo sto dicendo: i inizia da zero, quindi leggo i dati dal primo file, appena arriva i=NFI questa riparte da zero, perché tale operazione mi ritorna 0. In questo modo dovrei aver acquisito i dati dai file in modo alternato.
