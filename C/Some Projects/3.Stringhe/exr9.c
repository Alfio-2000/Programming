/* Scrivere un programma che verifichi se la stringa data in input è palindroma o no (“kayak”, “otto”, “elle”, “anilina”).*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_LENGHT 1024 //dimensione generica dei vettori stringa

int main()
{
    char stringa[STR_LENGHT];
    int lunghezza; //la lunghezza della stringa acquisita
    unsigned i,j;

    /*Presentazione del programma */
    printf("Ciao, sono il programma in grado di contare le cifre contenute in una parola.\n");

    /* Chiedo all'utente di inserire una parola */
    printf("Inserisci una parola: ");
    fgets(stringa,sizeof(stringa),stdin); /* (1) Vedere exr6.c */
    lunghezza= strlen(stringa);

    if (lunghezza > 0 && stringa[lunghezza - 1] == '\n')//Questo serve per rimuovere \n e \0 altrimenti non sarà mai palindroma.
    {
        stringa[lunghezza - 1] = '\0';
    }

    lunghezza= strlen(stringa); //così viene acquisita la nuova lunghezza della stringa dopo la rimozione di \0 e \n.

    for(i=0,j=(lunghezza-1); i<j; j--,i++)
    {
        if(stringa[i]!=stringa[j])
        {
            printf("La stringa non è palindroma.\n");
            return 0; //valore che conferma la NON palindromia della stringa
        }
    }
    printf("La stringa è palindroma.\n");
    return 1; //valore che conferma la palindromia della stringa
}
