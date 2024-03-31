/*Somma di elementi di un array usando i puntatori. */

#include <stdio.h>
#include <stdlib.h>

#define dim 1024

void somma_elementi(int* array, int n)
{
    int somma=0;
    unsigned i; //contatore del ciclo.

    /* Costruisco il vettore. */
    for( i=0; i<n; i++)
    {
        printf("Inserisci elemento:");
        scanf("%d",&array[i]);
    }

    /* Calcolo la somma. */
    for(i=0; i<n; i++)
    {
        somma+=*array;
        array++; //sto incrementando il puntatore: dico al puntatore di puntare il 1, il 2 e l'i-esimo valore.
    }
    printf("La somma degli elementi dell'array è:%d\n",somma);
}

int main()
{
    int array[dim];
    int n;
    printf("Quanti elementi vuoi inserire:");
    scanf("%d",&n);

    somma_elementi(array,n);
}
