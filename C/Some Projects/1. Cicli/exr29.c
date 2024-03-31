/*Scrivere un programma in grado di calcolare il determinante di una matrice 2x2*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
	{
		/*Dichiarazione delle variabili*/
		int a11,a12; /*Sono gli elementi della prima riga*/
		int a21,a22; /*Sono gli elementi della seconda riga*/
		float determinante; 
		
		printf("Inserisci gli elementi della prima riga:\n");
		scanf("%d%d",&a11, &a12);
		
		printf("Inserisci gli elementi della seconda riga:\n");
		scanf("%d%d",&a21, &a22);
		
		/*Iniziamo il calcolo del determinante*/
		determinante=((a11*a22)-(a21*a22));
		printf("Il determinante cercato è: %.2f\n",determinante);
		if(determinante==0)
		{
			printf("La matrice data non è invertibile.\n");
		}
		else if(determinante!=0)
		{
			printf("La matrice è invertibile.\n");
		}
	}
