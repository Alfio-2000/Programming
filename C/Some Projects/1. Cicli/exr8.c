/* Scrivere un programma che stampa un vettore le cui componenti vengono inserite da tastiera */
#include <stdio.h>
#include <string.h>
#define n 4
void main(void)
{
	int vettore[n],v[n]; /* v[n] sarà il vettore che conterrà le componenti inserite da tastiera */
	printf("La dimensione del vettore e' pari a 4. \n");
	printf("\n");
		for(int i=0; i<n; i++)
		{
		printf("Inserisci il valore della %d componente: ", i+1);
		scanf("%d", &vettore[i]);
		}
	printf("Il vettore finale e': [");
			for(int i=0; i<n; i++) /* Stampa del vettore finale */
			{ 
			printf("%ls", &v[i]);
			printf("]");
			}
printf("\n");
}
