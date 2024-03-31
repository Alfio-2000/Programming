/* Scrivere un programma che chieda in input una stringa e calcoli da quanti caratteri è composta (senza usare la funzione strlen, ma cercando il carattere '\0') */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LENGHT 1024

int main()
{
    char stringa[STR_LENGHT];
    unsigned i;
    /* Presentazione del programma */
    printf("Ciao, inserisci una parola e io ti dico da quante lettere è composta. \n");

    /* Chiedo all'utente di inserire la stringha */
    printf("Inserisci la parola:");
    scanf("%s",stringa);

    /* Inizio ad analizzare ogni singolo carattere */
    for(i=0; i<STR_LENGHT; i++)//questo ciclo che mi serve per analizzare ogni singolo carattere
    {
        if(stringa[i]=='\0')
        {
            printf("La parola -%s- è composta da %d caratteri.\n",stringa,i);
            break;
        }
    }
}
/* L'esercizio può essere risolto anche così:
 * int num_caratteri=0; questo è il contatore che mi permette di contare il numero di caratteri
 * while(stringa[num_caratteri]!='\0')
 * {
 *      num_caratteri++;
 * }
 *
 * printf("La parola %s contiene %d caratteri",stringa,num_caratteri);
 */
