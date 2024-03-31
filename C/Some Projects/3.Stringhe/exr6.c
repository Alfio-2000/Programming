/*Scrivere un programma che richieda in input una stringa e conti quante cifre essa contiene.
 Esempio: input: "Ciao2004!C6?" in output bisogna ottenere 5 */

/*In questo codice viene usata la funzione isdigit(). Essa serve per determinare se ogni carattere è una cifra numerica. La funzione in questione restituisce un valore diverso da zero se il carattere è una cifra numerica, altrimenti restituisce zero. */

/*(1)Ho usato la funzione per fgets per gestire anche gli spazi,qualore l'utente ne inserisca.
 Per usarla correttamente bisogna passarle tre parametri: la variabile dichiarata, la dimensione di essa (sizeof), e la scrittura stdin.
 sizeof: restituisce la dimensione in byte di un tipo di dato o espressione al fine di capire quante byte sono necessari per il loro salvataggio in memoria. Nel caso in questione viene usata per specificare la dimensione massima che fgets può leggere dalla tastiera senza superare il buffer stringa.

 stdin:  uno dei tre file di stream standard forniti dal C standard library.Gli altri due sono stdout (standard output) e stderr (standard error). In altre parole, è usata per dire a fgets deve leggere l'input dalla tastiera. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> //libreria necessaria per l'uso di specifiche funzioni.

#define STR_LENGHT 1024 //dimensione generica dei vettori stringa

int main()
{
    char stringa[STR_LENGHT];
    int lunghezza; //la lunghezza della stringa acquisita
    unsigned i; //contatore per il ciclo
    int cifre=0; //contatore utile per la ricerca delle cifre

    /*Presentazione del programma */
    printf("Ciao, sono il programma in grado di contare le cifre contenute in una parola.\n");

    /* Chiedo all'utente di inserire una parola */
    printf("Inserisci una parola: ");
    fgets(stringa,sizeof(stringa),stdin); /* (1) */
    lunghezza= strlen(stringa);

    for(i=0; i<lunghezza && stringa[i]!='\0'; i++)
    {
        if(isdigit(stringa[i]))
        {
            cifre++;
        }
    }
    printf("La parola contiene %d cifre\n",cifre);
    printf("Abbiamo finito, a presto :)\n");
}
