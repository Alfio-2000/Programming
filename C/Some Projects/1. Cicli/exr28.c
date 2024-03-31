/*Scrivere un programma capace di calcolare il prodotto scalare e il prodotto vettoriale tra due vettori di R^3.*/
/*ab=a11b11+a22b22+a33b33; questo è il prodotto scalare*/
/*axb=regola di Sarrus.*/
#include <stdio.h>
#include <math.h>

#define N 3 /*Numero di componenti del vettore*/

void main(void)
	{
		
		int a1,a2,a3; /*Componenti del primo vettore*/
		int b1,b2,b3; /*Componenti del secondo vettore*/
		int scalare;  /*Prodotto scalare*/
		int vettoriale_1,vettoriale_2,vettoriale_3; /*Componenti del prodotto vettoriale:sapiamo che il prodotto vettoriale è ancora 									un vettore (NON RESTITUISCE UN NUMERO!)*/ 
		char scelta;
		
		/*Scrivo le componenti del primo vettore:*/
		
		printf("Inserisci le componenti del primo vettore:\n");
		scanf("%d%d%d",&a1, &a2, &a3);
	
		printf("\n");
	
		/*Scrivo le componenti del secondo vettore:*/
		
		printf("Inserisci le componenti del secondo vettore\n");
		scanf("%d%d%d",&b1, &b2, &b3);
		
		printf("Vuoi calcolare il prodotto scalare o quello vettoriale? Digita s per il primo e v per il secondo.\n");
		scanf("%c",&scelta);
		scelta=getchar();
		if(scelta=='s') /*s significa scalare */
		{
			scalare=((a1*b1)+(a2*b2)+(a3*b3));
			printf("Il prodotto scalare è: %d\n",scalare);	
			if(scalare==0)
			{
				printf("I due vettori sono ortogonali tra loro.\n");
			}
		}
		if(scelta=='v') /*v significa vettoriale*/
		{
			printf("Il prodotto vettoriale restituisce un vettore.Quindi, diamo il valore numerico delle singole componenti.\n");
			vettoriale_1=((a2*b3)-(a3*b2));
			vettoriale_2=((a3*b1)-(a1*b3));
			vettoriale_3=((a1*b2)-(a2*b1));
			printf("Il prodotto vettoriale ha componenti: %d,%d,%d\n",vettoriale_1,vettoriale_2,vettoriale_3);
			if((vettoriale_1==0) && (vettoriale_2==0) && (vettoriale_3==0))
			{
				printf("I due vettori sono paralleli tra loro.\n");
			}
					
		}
		
	}

