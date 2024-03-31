/* Calcola la lunghezza di una stringa usando i puntatori. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LENGHT 1024 //dimensione generica di una stringa

void lunghezza_parola(char* stringa)
{
    int lunghezza=0; //lunghezza della stringa acquisita
    while(*stringa!='\0')
    {
        lunghezza++;
        stringa++;
    }
    printf("La lunghezza della parola inserita è: %d\n",lunghezza-1);
}

int main()
{
    char stringa[STR_LENGHT]; //ho dichiarato la stringa da inserire.
    printf("Inserisci una parola:");
    fgets(stringa, sizeof(stringa),stdin);

    lunghezza_parola(stringa);
}
