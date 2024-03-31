/*  Scrivere un programma che chieda un valore double di temperatura in gradi Fahrenheit e calcoli i valori delle corrispondenti temperature in gradi Celsius e Kelvin */
#include <stdio.h>
#include <math.h>
void main(void)
{
	double f, k, c; 
	printf("Inserire la temperatura in Fahrenheit:");
	scanf("%lf", &f);
	c=((5*(f-32))/9);
	k=(c+273.15);
	printf("La temperatura in gradi Celsius e': %1.3f \n", c);
	printf("La temperatura in gradi Kelvin e': %1.3f \n", k);
 }
