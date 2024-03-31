/* Scrivere un programma che chieda un numero da tastiera e indichi se e' pari o dispari */
#include <stdio.h>
#include <math.h>
void main(void)
{
	float a,resto;
	printf("Inserire un valore: \n");
	scanf("%f", &a);
	resto=a/2;
		if(resto==0)
		{
		printf("Il numero inserito e' PARI %f \n", a);
		}
			else
			{
			printf("Il numero inserito e' DISPARI %f \n", a);
			}

} 
