/* Scrivere un programma che chieda due numeri da registrare in due variabili A e B. Alla fine del programma si chieda di scambiare i valori delle due variabili. (Es: se A=12 e B=3, alla fine del programma si deve avere A=3 e B=12).*/
#include <stdio.h>
void main(void)
{
	float a, b, temp; /* temp è una variabile temporanea in cui conserviamo il valore che assegneremo ad una delle due variabili*/
	printf("Inserisci il primo numero: \n"); 
	scanf("%f",&a);
	printf("Inserisci il secondo numero: \n"); 
	scanf("%f",&b);
		/* Adesso conservo il valore di a in una variabile temporanea*/
		temp=a;
		a=b; 
		b=temp; 
			/* Adesso stampo i nuovi valori*/
				printf("Il nuovo valore del primo numero e' :  %1.2f \n",a);
				printf("Il nuovo valore del secondo numero e': %1.2f \n",b);
}

