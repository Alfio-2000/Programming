/* Scrivere un programma che richieda N numeri da tastiera e ne calcoli il max, il min, la somma e la media */ 
#include <stdio.h>
void main(main)
{
	int i, n; /* n è il numero di valori che vogliamo inserire */ 
	float somma,max,min,v; /* v è il valore che inseriamo */
  	double media;
		do
		{
		printf("Quanti numeri vuoi inserire? \n");
		scanf("%d",&n);
		}while(n<=0);
printf("Inserisci il 1° valore: \n");
scanf("%f", &v);
max=v;
min=v;
somma=v; /* La somma non va inizializzata a 0, altrimenti essa inizia a sommare i tre valori inseriti dentro al for.Quindi, dobbiamo 		    inizianizzarla a v, perché la somma deve partire da v */
			for(i=1; i<n; i++)
			{
			printf("Inserisci il %d° valore: \n", i+1);
			scanf("%f", &v);
			somma+=v;
				if(v>max)
				{
				max=v;
				}
					if(v<min)
					{
					min=v;
					}
			}
media=(somma/n);
printf("Il max e': %.3f \n", max);
printf("Il min e': %.3f \n", min);
printf("La somma e': %.3f \n", somma);
printf("La media e': %.3f \n", media); 
}
