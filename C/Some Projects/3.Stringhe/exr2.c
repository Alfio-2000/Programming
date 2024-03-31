/*Scrivere un programma che date due stringhe in input stampi la maggiore.*/
/*Qua abbiamo usato la funzione strcmp che serve a confrontare le due stringhe: questo exr si può fare come exr1.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LENGHT 1024
int main()
{
    char stringa1[STR_LENGHT];
    char stringa2[STR_LENGHT];
    unsigned i,j; //contatori usati nei Cicli

    /* Presentazione del programma */
    printf("Ciao, inserisci due parole e io ti dico qual è la più lunga. \n");

    /* Chiedo all'utente di inserire le due stringhe */
    printf("Inserisci la prima parola:");
    scanf("%s",stringa1);
    printf("Inserisci la seconda parola:");
    scanf("%s",stringa2);

    /* Confronto le due stringhe */
    if(strcmp(stringa1,stringa2)>=0) // la funzione strcmp serve a confrontare due stringhe.
    {
        printf("La stringa più lunga è: %s",stringa1);
    }
    else
        printf("La stringa più lunga è: %s",stringa2);
}
