/* Dichiarazione di un puntatore e stampa del valore puntato. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

int main()
{
    int x;
    char input[N];

    printf("Inserisci un numero:");
    scanf("%s",input);
    x=atoi(input);

    int* puntatore=&x; // così ho puntato il valore della variabile.

    printf("Il numero che hai inserito è: %d\n", *puntatore);
}
