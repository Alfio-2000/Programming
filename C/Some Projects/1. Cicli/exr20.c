/* Scrivere un programma che calcoli la media (con parte frazionaria) di 100 valori interi introdotti dalla tastiera */
#include <stdio.h>
#include <math.h>
#define n 5
void main(void)
{
	double media;
	int i, v, somma,scelta;
	somma=0; 
		for(i=0; i<=n; i++)
		{
		printf("Inserire il valore:\n");
		scanf("%d", &v);
		somma+=v;
		}
		media=somma/n;
		printf("La media dei 10 numeri e': %1.3f \n", media);
		printf("Fai la tua scelta: digita 1 per continuare, 0 per fermare il programma \n");
		scanf("%d", &scelta);
			while(scelta!=0)
			{
				switch(scelta)
				{
					case 1:
					somma=0; 
					for(i=0; i<=n; i++)
					{
						printf("Inserire il valore:\n");
						scanf("%d", &v);
						somma+=v;
					}
					media=somma/n;
					printf("La media dei 10 numeri e': %1.3f \n", media);
					break;
					default: 
					printf("La scelta non e' valida \n");
					break;
				}
				printf("Fai la tua scelta: digita 1 per continuare, 0 per fermare il programma \n");
				scanf("%d", &scelta);
			}

}

