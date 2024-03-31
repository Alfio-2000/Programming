/* Scrivere un programma che chieda 4 numeri double e ne calcoli la media (double) con 2 decimali. */
#include <stdio.h> 
#include <math.h>
#define n 4
void main(void)
{
	int scelta, i=0;
	double somma, media, v; 
		for(i=1; i<=n; i++)
		{
		somma=0;
		printf("Inserisci %d° valore: \n",i);
		scanf("%lf", &v);
		somma+=v;
		} 
		media=(somma/n);
		printf("La media tra i 4 numeri inseriti e': %1.2f \n", media);
		printf("Fai la tua scelta: digita 1 per continuare, 0 per fermare il programma \n");
		scanf("%d", &scelta);
			while(scelta!=0)
			{
				switch(scelta)
				{
				case 1:
					for(i=1; i<=n; i++)
					{
					printf("Inserisci %d° valore: \n",i);
					scanf("%lf", &v);
					somma+=v;
					} 
				media=(somma/n);
				printf("La media tra i 4 numeri inseriti e': %1.2f \n", media);
				break;
				default: 
				printf("La scelta non e' valida \n");
				break;
				}
			printf("Fai la tua scelta: digita 1 per continuare, 0 per fermare il programma \n");
			scanf("%d", &scelta);
			}
	printf("Hai scelto di fermare il programma \n");
	
}
