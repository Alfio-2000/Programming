/*Scrivere un programma in grado di stampare un vettore i cui elementi sono in ordine crescente a partire da
due vettori: A[1,2,3,4], B[5,6,7,8] dati da input, si deve ottenere: C[1,2,3,4,5,6,7,8]. Il testo dice di inserire al massimo 20 elementi */
/*DA COMPLETARE*/

#include <stdio.h>
#include <stdlib.h>

#define N 1024 

int main()
{
	int a[N], b[N]; //vettori costruiti dall'input
	int c[2*N]; //vettore fusione (quello finale)
	int n; //numero di elementi dei vettori
	char input[N]; //vettore che mi serve per migliiorare la gestione dell'input
	int i, j; //contatori che mi servono per i cicli  
	/* Chiedo all'utente il numero di elementi dei vettori'*/
	do
	{
		printf("Inserisci un numero di elementi inferiore o pari a 20.");
		scanf("%s",input);
		n=atoi(input);	
	
	}while(n>20 || n<=0);	//controllo se il numero di elementi sia lecito
	printf("Costruisci il primo vettore \n");
	/* Costruisco il vettore a[] */
	for(i=0; i<n; i++)
	{
		printf("Inserisci valore:");
		scanf("%s",input);
		a[i]=atoi(input);
	}
	printf("Costruisci il secondo vettore\n");
	/* Costruisco il vettore b[] */
	for(i=0; i<n; i++)
	{
		printf("Inserisci valore:");
		scanf("%s",input);
		b[i]=atoi(input);
	}
	for(i=0; i<2*n; i++)
	{
		c[i]=a[i];
		c[i+1]=b[i]; //Credo che il problema sia qui: in output, infatti, riesco a visualizzare solo gli elementi del primo vettore. 
	}
	printf("\n Il vettore costruito e':[ %d");
	for(i=0; i<2*n; i++)
	{
		printf("%d ",c[i]);
	}
	printf("]\n");
}
