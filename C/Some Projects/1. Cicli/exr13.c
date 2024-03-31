#include <stdio.h>
#include <string.h>
#define N 5
void main(void) 
{
	int v1[N], v2[N]; /* i due vettori presi in considerazione */
	int v3[N];        /* il vettore che conterrà gli elementi max */
	int i, max;
		
		//Lettura primo vettore
		for (i = 0; i<N; i++) 
		{
		printf("Inserire il %d valore del primo vettore: ", i + 1);
		scanf("%d", &v1[i]);
		}
		printf("\n");
		
			/*Lettura secondo vettore */
			for (i = 0; i<N; i++) 
			{
			printf("Inserire il %d valore del secondo vettore: ", i + 1);
			scanf("%d", &v2[i]);
			}
			printf("\n");
			
				/* Stampa del primo vettore */
				printf("Primo vettore: [ ");
				for (i = 0; i<N; i++) 
				printf("%d ", v1[i]);
				printf("]");
				printf("\n");
				
					/* Stampa del secondo vettore */
					printf("Secondo vettore: [ ");
					for (i = 0; i<N; i++)
					printf("%d ", v2[i]);
					printf("]");
						max = v3[0]; /*Inizializzo max = 0 */
						for(i=0; i<N; i++)
						{
							if (v1[i]>=v2[i])/*se l'elemento in posizione [i] del vettore v1 è maggiore 										   dell'elemento nella stessa posizione di v2 */
							{ 
							max=v1[i]; /* allora max è uguale all'elemento in posizione [i] del vettore v1 */
							v3[i]=v1[i]; /* quindi a v3 in posizione [i] assegno l'elemento in posizione [i] di 										 v1 */
							}
								if (v2[i]>v1[i])
								{
								max = v2[i];
								v3[i] = v2[i];
								}
						}
						printf("\n");
						
								/* Stampa del vettore max */ 
								printf("Vettore massimo: [ ");
									for (i = 0; i < N; i++)
									{
									printf("%d ", v3[i]);
									printf("]");
									}
}
