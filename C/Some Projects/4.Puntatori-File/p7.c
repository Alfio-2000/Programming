/*Codice in C in grado di:
1. Stampare la somma degli elementi.
2. Stampare la media degli elementi.
3. Trovi l'elemento massimo.
4. Stampi l'array invetito. */

#include <stdio.h>
#include <stdlib.h>

#define DIM 1024

void somma_media(int* array, int n)
{
    unsigned i;
    float somma = 0.0;
    float media = 0.0;

    // Costruisco il vettore.
    for (i = 0; i < n; i++)
    {
        printf("Inserisci elemento:");
        scanf("%d", array + i);
    }

    // Calcolo la somma.
    for (i = 0; i < n; i++)
    {
        somma += *(array + i);
    }

    media = somma / n;

    printf("La somma degli elementi dell'array è: %.2f\n", somma);
    printf("La media degli elementi è: %.2f\n", media);
}

void massimo(int* array, int n)
{
    int max = *array;
    unsigned i;
    for (i = 1; i < n; i++)
    {
        if (*(array + i) > max)
        {
            max = *(array + i);
        }
    }
    printf("L'elemento massimo è: %d\n", max);
}

void inverso(const int* array, int n)
{
    unsigned i;
    if (n <= 0)
    {
        printf("Impossibile invertire un array con dimensione non positiva.\n");
        return;
    }

    int array_invertito[DIM];

    // Costruisco l'array invertito.
    for (i = 0; i < n; i++)
    {
        array_invertito[i] = *(array + i);
    }

    printf("Il vettore invertito è: [");
    for (i = n - 1; i > 0; i--)
    {
        printf("%d ", array_invertito[i]);
    }
    printf("%d]\n", array_invertito[0]);
}

int main()
{
    int array[DIM];
    int n; // Sarà la nuova dimensione del vettore.
    do
    {
        printf("Inserisci un numero positivo di elementi:");
        scanf("%d", &n);

    } while (n <= 0); // Controllo che mi permette di verificare se l'utente ha inserito una dimensione valida.

    /* Ho risolto 1. e 2. */
    somma_media(array, n);

    /* Ho risolto 3. */
    massimo(array, n);

    /* Ho risolto 4. */
    inverso(array, n);
}

