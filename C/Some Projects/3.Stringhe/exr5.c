/*Scrivere un programma che data una stringa in input verifichi se essa contiene almeno una ‘A’ tra i primi 10 caratteri.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LENGHT 1024

int main()
{
    char stringa[STR_LENGHT];
    unsigned i;
    int lunghezza; //lunghezza della stringa
    int trovato=0; //contatore che mi permette di contare le A

    /* Presentazione del programma */
    printf("Ciao, inserisci una parola di 10 lettere e ti dico quante -A- contiene. \n");

    /* Chiedo all'utente di inserire la stringha */
    do{
        printf("Inserisci la parola:");
        scanf("%s",stringa);
        lunghezza=strlen(stringa); //in questo modo ho salvato la lunghezza della parola inserita dall'utente.

    }while(lunghezza>10); //Ho effettuato un controllo per verificare se l'utente è idiota.

    for(i=0; i<lunghezza && stringa[i]!='\0'; i++) //devo mettere stringa[i]!='\0' per lavorare con gli elementi di interesse
    {
        if(stringa[i]=='A')
        {
            trovato++; // così conto le 'A',incrementando la variabile opportuna.
        }
    }

    /* Stampo il numero di 'A' */

    if(trovato>0) // verifico se ho trovato almeno una 'A'
    {
        printf("Ci sono %d -A-\n",trovato);
    }
    else
    {
        printf("Non ci sono -A-\n");
    }
    printf("Abbiamo finito, a presto :).\n");
}
