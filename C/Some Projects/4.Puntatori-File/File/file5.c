/*Scrivi un programma in linguaggio C che legge un numero intero n da tastiera (n > 0) e quindi chiede all'utente di inserire n valori interi. Il programma deve successivamente raddoppiare il valore di ogni elemento nell'array e stampare il risultato in un file stampa.txt */
#include <stdio.h>
#include <stdlib.h>

#define N 1024 //dimensione standard (casuale) del vettore
int main()
{
    int n; //numero positivo richiesto dall'utente.
    unsigned int i; //contatore
    int vettore[N];
    char nome_file[31]; //vettore stringa che serve per dare il nome al file.
    FILE* output; //puntatore che mi serve per stampare sul file creato
    do{
        printf("Inserisci un numero positivo:");
        scanf("%d",&n);
    }while(n<=0); //ho effettuato un controllo: l'utente potrebbe essere idiiota

    /* Adesso chiedo all'utente di inserire n elementi in un vettore */
    for(i=0;i<n;i++)
    {
        printf("Inserisci elemento:");
        scanf("%d",&vettore[i]);
    }
    /* Adesso raddoppiamo gli elementi del vettore */
    for(i=0; i<n; i++) //Per me usare i puntatori qui non ha senso.
    {
        vettore[i] *=2; //raddoppia il valore puntato da *array
    }

    printf("Inserisci il nome del file da creare:");
    scanf("%s",nome_file);

    output=fopen(nome_file, "w"); //apertura in scrittura
    if(output==NULL) goto file_err;
    for(i=0; i<n; i++)
    {
        fprintf(output,"%d\n",vettore[i]); //non dovrei mettere ,*array? No, perché per me vale commento riga 26.
    }

    fclose(output);

    file_err: printf("\n ERRORE NELL'APERTURA!\n");
    return EXIT_FAILURE;
}
