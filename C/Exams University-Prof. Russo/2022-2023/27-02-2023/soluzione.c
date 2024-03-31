#include <stdio.h>
#include <stdlib.h>

#define LS 1024 // Lunghezza della stringa che serve per l'acquisizione da tastiera.
#define FI "mail.txt" // File Input: mail.txt
#define INIZIO_SERIE 'D' // Carattere che segna l'inizio di una serie di dati.
#define FINE_SERIE 'E' // Carattere che segna la fine di una serie di dati.
#define FINE_FILE 'S' // Carattere che segna la fine delle email.
#define VMIN 1 // Valore minimo
#define VMAX 10 // Valore massimo

#define VERO 1
#define FALSO 0 // Questi due parametri mi servono per la funzione stringa_contiene_char.

typedef FILE* pfile;   // Puntatore a file necessario per aprire i file.
typedef float* pfloat; // Puntatore che mi serve per gestire i valori del file.
typedef char* pchar;   // Puntatore che mi serve per gestire i caratteri.

int stringa_contiene_char(pchar pc, char c ) //[1]: ho bisogno di c per esaminare i caratteri.
{
    while((*pc)!='\0')
    {
        if((*pc)==c) return VERO;
        else
        {
          pc++;
        }
    }
    return FALSO;
}

void save_buffer(pchar nomebase,pfloat pv, unsigned lb, unsigned n) // Funzione che mi serve per stampare i file di output.
{
    pfile fo; // Puntatore per il salvataggio per il file output
    pfloat pvfinale; // Vettore dinamico che mi permetterà di scrivere i dati nel file di output.
    char s[LS];

    sprintf(s,"%s.%u",nomebase,n); // Scrivo il nome del file
    printf("Scrivo il file:%s\n",s);
    fo=fopen(s,"w");
    fprintf(fo,"%u\n",lb); // Stampo il numero di valori presenti nel buffer.
    for(pvfinale=pv+lb;pv<pvfinale;pv++) // Devo capire meglio il perché ho bisogno di un puntatore pvfinale.
    {
        fprintf(fo,"%.2f\n",*pv); // Stampo gli elementi.

    }
    fclose(fo); // Chiudo il file che sto scrivendo.
}

int main(void)
{

    pfile fi; // Puntatore per l'apertura del file di input.
    pchar pc; // Puntatore per i char.
    pfloat pv; // Puntatore che mi servirà per creare un array dinamico che conterrà i valori.
    char s[LS];
    int lb; // Lunghezza massima de file.
    unsigned nr=0; // Numero di righe.
    unsigned ns=0; // Numero di serie attuale.
    unsigned nd=0; // Contatore di dati.
    unsigned ndb=0; // Numero di dati presenti nel buffer esso sarà il nostro contatore per i for.
    unsigned nb=0; // Numero di buffer: insieme di dati che sono stati salvati nel file output.

    do
    {
        printf("Lunghezza del buffer (ammessi solo valori positivi in [%d,%d]):",VMIN, VMAX);
        scanf("%s",s);
        lb=atoi(s);

    }while((lb<VMIN) || (lb>VMAX)); // Controllo che l'utente abbia inserito un valore adeguato.

    if((pv=(pfloat)malloc(sizeof(float)*lb))==NULL) goto mem_err; // Creazione array dinamico che conterrà i valori.

    if((fi=fopen(FI,"r"))==NULL) goto open_err;

    for(ndb=0;;) // Inizio ad acquisire i dati del file.
    {
        fscanf(fi,"%s",s);
        if(stringa_contiene_char(s,FINE_FILE)) // Se il programma incontra una parola con S si blocca ed esce dal for.
        {
            printf("L'email è terminata: non ci sono altri dati da acquisire.\n");
            break;
        }
        nr++; // Incremento del numero di riga
        if(stringa_contiene_char(s,INIZIO_SERIE)) // Se becco 'D' inizio ad acquisire i dati
        {
            ns++; // Sto incrementando il numero di serie: 1° serie, 2° serie ecc...
            for(;;) // Ciclo infinito: si interrompe quando becca 'S'
            {
                fscanf(fi,"%s",s);
                nr++;
                if(stringa_contiene_char(s,FINE_SERIE)) break; // Non considero le stringhe con 'E'.
                nd++; // Incremento il numero di dati acquisiti.
                printf("nr=%u, ns=%u, nd=%u -> Letto: %.2f \n",nr,ns,nd,pv[ndb++]=atof(s));
                if(ndb==lb) // Devo capire meglio questa scrittura.
                {
                    save_buffer(FI,pv,lb,nb); // Salvo nel buffer i dati
                    ndb=0; // Azzerro il contatore che mi conta il numero di dati nel buffer
                    nb++; // Inserisco i dati nel buffer.
                }
            }
        }
    }
    free(pv);
    fclose(fi);
    return EXIT_SUCCESS;

    open_err: printf("Errore nell'apertura del file.\n"); return EXIT_FAILURE;
    mem_err:  printf("Errore di memoria: RAM INSUFFICIENTE.\n"); return EXIT_FAILURE;

}
//[1] Funzione che mi serve per capire quale carattere è contenuto nelle stringhe. La logica che sta dietro a questa funzione è la seguente: come parametri le passo un puntatore a carattere che salva i caratteri di nostro interesse (E,S,D) e una variabile carattere c. Nella riga (*pc==c) sto dicendo che l'i-esimo elemento puntato da pc è uguale al carattere c. In questo modo, nel main, quando la richiamo, come parametri gli passo la stringa (perché pc punta alla stringa) e le variabili del define citate prima.



