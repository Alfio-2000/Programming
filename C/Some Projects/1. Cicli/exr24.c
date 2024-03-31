/*Scrivere un programma che riesca a classificare un triangolo, ossia in grado di dire se un triangolo dato risulta scaleno,equilatero o rettangolo,calcolandone l'area e il perimetro*/
#include <stdio.h> 
#include <math.h>
#include <stdlib.h> 
void main(void)
{
	float a,b,c; /*sono i lati del triangolo che verranno chiesti nel corso del programma*/
	float quad_a,quad_b,quad_c; /*Sono i quadrati dei lati*/ 
	float area, perimetro, semi_perimetro; 
	do{
	printf("Imettere il primo lato: \n");
	scanf("%f",&a);
	printf("Imettere il secondo lato: \n");
	scanf("%f",&b);
	printf("Imettere il terzo lato: \n");
	scanf("%f",&c);
	}while(a<=0 && b<=0 && c<=0);
		if((a==b) && (b==c))
		{
		printf("Il triangolo è equilatero. \n");
		perimetro=a+b+c; 
		printf("Il perimetro del triangolo equilatero è: %.3f\n",perimetro);
		semi_perimetro=perimetro*0.5;
		area=sqrt(semi_perimetro*(semi_perimetro-a)*(semi_perimetro-b)*(semi_perimetro-c)); /*Sto usando la formual di Erone*/
		printf("L'area del triangolo equilatero è: %.3f\n",area);
		}else if((a==b) || (a==c) || (b==c))
		{
		printf("IL triangolo è isoscele.\n");
		perimetro=a+b+c; 
		printf("Il perimetro del triangolo isoscele è: %.3f\n",perimetro);
		semi_perimetro=perimetro*0.5;
		area=sqrt(semi_perimetro*(semi_perimetro-a)*(semi_perimetro-b)*(semi_perimetro-c)); /*Sto usando la formual di Erone*/
		printf("L'area del triangolo isoscele è: %.3f\n",area);
		}else if((quad_a==quad_b+quad_c) || (quad_b==quad_a+quad_c) || (quad_c==quad_a+quad_b))
		{
		printf("IL triangolo è rettangolo.\n");
		perimetro=a+b+c; 
		printf("Il perimetro del triangolo rettangolo è: %.3f\n",perimetro);
		semi_perimetro=perimetro*0.5;
		area=sqrt(semi_perimetro*(semi_perimetro-a)*(semi_perimetro-b)*(semi_perimetro-c)); /*Sto usando la formual di Erone*/
		printf("L'area del triangolo rettangolo è: %.3f\n",area);
		}
		else
		printf("Il triangolo è scaleno.\n");
		perimetro=a+b+c; 
		printf("Il perimetro del triangolo scaleno è: %.3f\n",perimetro);
		semi_perimetro=perimetro*0.5;
		area=sqrt(semi_perimetro*(semi_perimetro-a)*(semi_perimetro-b)*(semi_perimetro-c)); /*Sto usando la formula di Erone*/
		printf("L'area del triangolo scaleno è: %.3f\n",area);
}	
