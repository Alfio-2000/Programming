/* Raddoppia gli elementi di un vettore. */

#include <stdio.h>
#include <stdlib.h>

#define DIM 1024

void raddoppia_elementi(int* array,int n)
{
    unsigned i; //contatore del ciclo.

    /* Costruisco il vettore. */
    for(i=0; i<n; i++)
    {
        printf("Inserisci elemento:");
        scanf("%d",&array[i]);
    }

    /* Effettuo il calcolo. */
    for(i=0; i<n; i++)
    {
        *array *= 2;
        array++;
    }
}

int main()
{
    int array[DIM];
    int n; //sarà la nuova dimensione del vettore.

    printf("Quanti elementi vuoi inserire:");
    scanf("%d",&n);

    raddoppia_elementi(array, n); // così ho effettuato il calcolo

    printf("Il nuovo vettore è: [");
    for(unsigned i=0; i<n; i++) // in questo modo ho stampato il risultato.
    {
        printf("%d,",array[i]);
    }
    printf("]\n");
}
