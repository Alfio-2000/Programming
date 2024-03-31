/* Esercizio p2.c effettuato con l'uso delle funzioni. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

void scambio_variabili(int* ptr_a,int* ptr_b)
{
    int temp; //variabile temporanea.

    temp=*ptr_a;
    *ptr_a=*ptr_b;
    *ptr_b=temp;

    printf("Alla fine ottenuto a=%d e b=%d\n",*ptr_a,*ptr_b);

}

int main()
{
    int a,b; //numeri inseriti dall'utente.
    char input[N];

    /* Presentazione del programma. */
    printf("Ciao, sono il programma in grado di scambiare due numeri inseriti da tastiera.\n");

    /* Acquisizione dei due numeri. */
    printf("Inserisci il primo numero:");
    scanf("%s",input);
    a=atoi(input);

    printf("Inserisci il secondo numero:");
    scanf("%s",input);
    b=atoi(input);

    printf("Hai inserito a=%d e b=%d\n",a,b);

    scambio_variabili(&a,&b);
}
