/*Scrivere un programma che riesca a stampare un vettore. */
#include <stdio.h>
#define N 5 //questa è la dimensione del mio vettore

void StampaVettore(int vett[N], int i) //Funzione: Stampo i valori di un vettore nell'ordine di inserimento
{
	for(i=0; i<N; i++) //Sono partito da i=0 per prendere tutti i valori del vettore
	{
		printf("Inserisci valore:");
		scanf("%d",&vett[i]); 
	}
	printf("Il vettore che hai costruito e': [");
	for(i=0; i<N; i++) //Sono partito da i=0 per prendere tutti i valori del vettore
	{
		printf("%d ",vett[i]);	 
	}	
	printf("]\n");
}

void OrdineInverso(int vett[N], int i) //Funzione: Stampo i valori di un vettore nell'ordine inverso a quello inserito
{
	printf("[");
	for(i=N-1; i>=0; i--) //Sono partito da i=0 per prendere tutti i valori del vettore
	{
		printf("%d ",vett[i]);	 
	}
	printf("]\n");	
}

int main()
{
	int vett[N]; //Ho scelto un vettore fatto da valori interi
	int i;
	printf("Ciao, costruisci il vettore che vuoi.\n");
	StampaVettore(vett, i);//Ho scritto (vett,i) perché per usare le funzioni mi servono gli "ingredienti" giusti, ossia un vettore intero e una costante
	printf("\n In ordine inverso, il vettore e':\n");
	OrdineInverso(vett,i);	
}

