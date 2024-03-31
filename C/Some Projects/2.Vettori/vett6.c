/*Scrivere un programma che stampi e visualizzi due vettori e che crei un terzo vettore di uguale dimensione i cui elementi sono la somma degli elementi dei primi 
due vettori. Ad esempio, se A=[1,2,3,4] e B=[5,6,7,8,9] sono i vettori dati, allora, C=[6,8,10,13] deve essere il vettore creato alla fine del programma.*/
#include <stdio.h>
#define N 10
int main()
{
	int v[N], w[N], z[N]; 
	int n; //Numero di valori inseriti dall'utente. 
	int i, j; //Contatori per i cicli for, necessari per la costruzione dei vettori
	printf("Quanti valori vuoi inserire?");
	scanf("%d",&n);
	//Costruisco il primo vettore
	for(i=0; i<n; i++)
	{
		printf("Inserisci valore:");
		scanf("%d",&v[i]);
	}
	//Stampo il primo vettore
	printf("Primo vettore: [");
	for(i=0; i<n; i++)
	{
		printf("%d ", v[i]);
	}	
	printf("] \n");
	
	//Costruisco il secondo vettore
	for(j=0; j<n; j++)
	{
		printf("Inserisci valore:");
		scanf("%d",&w[j]);
	}
	//Stampo il secondo vettore
	printf("Secondo vettore: [");
	for(j=0; j<n; j++)
	{
	 	printf("%d ", w[j]);
	}	
	printf("] \n");
	//Stampa e cosruzione del vettore finale
	printf(" \n Il vettore finale e': [");
	for(i=0; i<n; i++)
	{
		z[i]=v[i]+w[i];
		printf("%d ", z[i]);
	}
	printf("]");
}
