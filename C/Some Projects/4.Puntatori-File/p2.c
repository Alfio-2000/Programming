/* Mediante l'uso dei puntatori, effettua lo scambio tra due numeri. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

int main()
{
    int a,b;
    int temp; // variabile temporanea.
    char input[N];

    /* Presentazione del programma. */
    printf("Ciao, sono il programma in grado di scambiare due numeri inseriti da tastiera.\n");

    /* Acquisizione dei due numeri. */
    printf("Inserisci il primo numero:");
    scanf("%s",input);
    a=atoi(input);

    int* ptr_a= &a; //puntatore di a.

    printf("Inserisci il secondo numero:");
    scanf("%s",input);
    b=atoi(input);

    int* ptr_b= &b; //puntatore di b.

    printf("Hai inserito a=%d e b=%d\n",a,b);

    /* Effettuo lo scambio dei due numeri. */

    temp=*ptr_a;
    *ptr_a=*ptr_b;
    *ptr_b=temp;

    printf("Alla fine ottenuto a=%d e b=%d\n",*ptr_a,*ptr_b);

}
