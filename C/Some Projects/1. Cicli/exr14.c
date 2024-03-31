#include <stdio.h>
#include <math.h>
void main (void) 
{ 
	int a, b, c; 
	float delta, radice,x1,x2;
	printf("Introduci il primo valore:");
	scanf("%d",&a);
	printf("Introduci il secondo valore:");
	scanf("%d",&b);
	printf("Introduci il terzo valore:");
	scanf("%d",&c);
	delta= ((b*b)-(4*a*c));
	radice=sqrt(delta);
	x1=((-b-radice))/(2*a);
	x2=((-b+radice))/(2*a);
		if(delta>=0)
		{
		printf("La prima soluzione e': %2.5f \n", x1);
		printf("La seconda soluzione e': %2.5f \n", x2);
		printf("Le due soluzioni sono: %2.5f %f \n ", x1, x2);
		}
			else
			{
			printf("Non ci sono soluzioni reali \n");
			}
}
