/*Scrivere un programma che data una stringa in input, la converta tutta in maiuscolo */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h> /*questa libreria mi serve per usare le funzioni per il trattamento dei caratteri: una di queste è la funzione toupper() che mi permette di convertire un carattere minuscolo al maiuscolo.*/

#define STR_LENGHT 1024

int main()
{
    char stringa[STR_LENGHT];
    unsigned i;
    int lunghezza; //lunghezza della stringa

    /* Presentazione del programma */
    printf("Ciao, inserisci una parola e io la scrivo con tutti caratteri maiuscoli. \n");

    /* Chiedo all'utente di inserire la stringha */
    printf("Inserisci la parola:");
    scanf("%s",stringa);
    lunghezza=strlen(stringa); //in questo modo ho salvato la lunghezza della parola inserita dall'utente.

    for(i=0; i<lunghezza; i++)
    {
        stringa[i]=toupper(stringa[i]);
    }
    printf("La nuova parola è: %s\n",stringa);
}
