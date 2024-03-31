/* Scrivere un codice in grado di aprire il file input.txt contenente una serie di numeri interi uno per riga, sommarli e scrivere il risultato in un nuovo file. */

/* Per questo tipo di esercizio è necessario avere i due file già a disposizione. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5 // è la dimensione del vettore riga, perché, in questo caso, il file contiene solo 5 righe occupate alle quali siamo interessati

int main()
{
    FILE* miofile, *uscita; //puntatori che mi servono per aprire e chiudere i file
    int numero; //numero contenuto all'interno del file
    int riga=0; //contatore che mi permette di considerare ogni riga-> così prendo ogni numero di ogni riga
    int vettore[N];
    int somma=0; //somma dei valori all'interno del file
    unsigned int i;
    miofile=fopen("input.txt","r"); //sto aprendo il file in lettura
    if(miofile==NULL) goto file_err;
    /* Adesso visualizzo e leggo ogni riga del file */
    while(fscanf(miofile, "%d",&numero)==1) //la funzione fscanf serve per acquisire i dati dal file
    {
        vettore[riga]=numero;
        riga++;
    }
    for(i=0; i<riga; i++) //ho sommato i valori all'interno del file
    {
        somma+=vettore [i];
    }
    fclose(miofile); //ho chiuso il file.

    /* Adesso apro il file output.txt per scriverci dentro il risultato */
    miofile=fopen("output.txt","w"); //l'ho aperto in scrittura)
    if(miofile==NULL) goto file_err;
    fprintf(miofile,"%d",somma);
    fclose(miofile);

    file_err: printf("ERRORE NELL'APERTURA DEL FILE\n");
    return EXIT_FAILURE;
}
