/* Scrivere un programma che chieda N numeri da tastiera e ne calcoli il valore massimo. */
#include <stdio.h>
void main(main)
{
	int v, max,i,n; /* v è il valore che inseriamo,n è il numero di numeri che vogliamo inserire */
		do
		{
		printf("Quanti numeri vuoi inserire? \n");
		scanf("%d", &n);
		}while(n<=0);
	printf("Inserisci il 1° numero:\n");
	scanf("%d", &v);
	max=v;
			for(i=1; i<n; i++)
			{
			printf("Inserisci il %d° numero: \n", i+1);
			scanf("%d", &v);
			if(v>max)
			max=v;
			}
	printf("Il massimo valore inserito e': %d \n", max);
}
