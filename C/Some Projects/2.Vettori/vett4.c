/*Scrivere un programma in grado di scrivere gli elementi di un vettore in ordine decrescente*/
#include <stdio.h>
#include <stdlib.h>
#define N 1024 //Dimensione dei vettori 

int main()
{
	int n, i, j, temp; 
	int vettore[N];
	char input[N];
	
	do
	{			
		printf("Quanti valori vuoi inserire?");
		scanf("%s",&input);
		n=atoi(input);	
	
	}while(n<=0);

	/*Inizio della costruzione del vettore*/
	for(i=0; i<n; i++)
	{
		printf("Inserisci valore:");
		scanf("%s", &input);
		vettore[i]=atoi(input);
	}
	/*Fine della costruzione del vettore*/
	
	/*Inizio della visualizzazione del vettore appena costruito*/
	printf("\n Il vettore costruito e': [");
	for(i=0; i<n; i++)
	{
		printf("%d ",vettore[i]);
	}
	printf("]\n");
	/*Fine della visualizzazione del vettore appena costruito */
	
	/*Inizio il BubbleSort: algoritmo di ordinamento*/
	for(i=0; i<(n-1); i++)
	{
		for(j=(i+1); j<n; j++) //Questo for mi serve per confrontare due elementi vicini dello stesso vettore: vedi exr: vett3.c 
		{
			if(vettore[i]<vettore[j])//mi serve per capire la condizione necessaria per ordinare in maniera decrescente
			{
				temp=vettore[i];
				vettore[i]=vettore[j];
				vettore[j]=temp;
			}
		}
	}
	printf("\n Il vettore di elementi in ordine decrescente: [");
	for(i=0; i<n; i++)
	{
		printf("%d ",vettore[i]);
	}
	printf("]\n");
	/*Fine BubbleSort*/
}
