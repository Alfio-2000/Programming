/*Scrivere un programma in grado di stampare un vettore in un file uscita.txt */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //libreria che mi permette di usare le stringhe

int main()
{
    int n; //dimensione del vettore
    int i; //contatore per i cicli
    FILE* uscita; //puntatore che mi permette di aprire un file. 
    char nome_file[31]; //Vettore stringa di 30 elementi: bisogna sempre considerare l'elemento terminatore \0 di una stringa. 
    
    printf("Ciao, sono il programma in grado di costruire un vettore. \n");
    printf("Quanti elementi deve contenere il vettore?");
    scanf("%d",&n);
    int vett[n]; //vettore che voglio costruire e stampare
    
    /* Adesso costruisco il vettore */
    for(i=0; i<n; i++)
    {
        printf("Inserisci elemento:\n");
        scanf("%d",&vett[i]);
    }
    
    printf("Inserisci il nome del file nel quale vuoi salvare e stampare il vettore:");
    scanf("%s",nome_file);
    uscita=fopen(nome_file, "w"); //così apro il file e posso scriverci dentro, anche sborrare sulle righe. 
    if(uscita==NULL)  goto file_err; // è un controllo per capire se il file viene aperto correttamente. La funzione goto mi permette di saltare interi blocchi di istruzioni
    
    for(i=0; i<n; i++)
    {
      fprintf(uscita, "%d\n", vett[i]); //stampo su file grazie alla funzione fprintf=file_stampa
    }
    
    fclose(uscita); //funzione che mi permette di chiudere il file. 

    file_err: printf("Errore con i files\n");  
    return EXIT_FAILURE;
}
