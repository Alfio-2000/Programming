/* Scrivere un programma che chieda un programma che chieda quanti valori verranno introdotti dalla tastiera, li chieda tutti e ne stampi la somma e la media */ 
#include <stdio.h>
void main(void)
{
	int somma;
	int v, n ; /* v è il valore che inseriamo dalla tastiera; n è il numero di valoriche vogliamo inserire */
	double media;
	somma=0;
		do
		{
		printf("Quanti numeri vuoi inserire? \n");
		scanf("%d", &n);
		}while(n<=0);
			for(int i=1; i<=n; i++)
			{
			printf("Inserisci il %d° numero: \n", i);
			scanf("%d", &v);
			somma+=v;
			}
	media=(somma/n);
	printf("La media dei numeri inseriti e': %.2f \n", media);
	printf("La Somma e': %d \n", somma);

}
