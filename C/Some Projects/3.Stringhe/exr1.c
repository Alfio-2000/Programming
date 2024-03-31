/*Scrivere un programma che date due stringhe in input stampi la più lunga. Qualora risultino di uguale lunghezza, stampare la prima. */
/*Qua abbiamo usato la funzione strlen che serve a contare i caratteri all'interno delle stringhe: questo exr si può fare come exr2.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LENGHT 1024
int main()
{
    char stringa1[STR_LENGHT];
    char stringa2[STR_LENGHT];

    /* Presentazione del programma */
    printf("Ciao, inserisci due parole e io ti dico qual è la più lunga. \n");

    /* Chiedo all'utente di inserire le due stringhe */
    printf("Inserisci la prima parola:");
    scanf("%s",stringa1);
    printf("Inserisci la seconda parola:");
    scanf("%s",stringa2);

    if(strlen(stringa1)>=strlen(stringa2)) //la funzione strlen serve per contare i caratteri che formano le stringhe
    {
        printf("La parola più lunga è: %s\n",stringa1);
    }
    else
        printf("\n La parola più lunga è: %s\n",stringa2);
}
