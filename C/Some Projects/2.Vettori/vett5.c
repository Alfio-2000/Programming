/*Scrivere un programma in grado di ordinare un vettore come segue: [1,2,3,4] che diventa [2,4,1,3], cioè prima i pari e poi i dispari*/
#include <stdio.h>
#define N 10 //Dimensione del vettore

int main()
{
	int vett[N];
	int n; //Numero di valori che l'utente vuole introdurre da tastiera
	int i;
	/*Inizio costruzione e visualizzazione del vettore*/
	printf("Quanti valori vuoi inserire?");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("Inserisci valore:");
		scanf("%d", &vett[i]);
	}
	printf("\n Il vettore che hai costruito e': [");
	for(i=0; i<n; i++)
	{
		printf("%d ", vett[i]);
	}
	printf("]\n");
	/*Fine costruzione e visualizzazione del vettore*/
	
	/*Inizio della ricerca degli elementi pari e dispari*/
	printf("Adesso scrivo il vettore in modo tale da visualizzare prima i numeri pari e poi quelli dispari. \n");
	printf("\n Il vettore ordinato e': [");
	
	for(i=0; i<n; i++)
	{
		if(vett[i]%2==0) //Non viene usato l'else, perché mi servono solo i numeri pari e non quelli dispari (*)
		{
			printf("%d ", vett[i]); //Numeri pari
		}
	}
	for(i=n-1; i>=0; i--) //Con questo for sto portando tutti i numeri dispari a dx del vettore. 
	{
		if(vett[i]%2!=0) //Stesso motivo (*): sono interessato solo ai numeri dispari e non a quelli pari.
		{
			printf("%d ",vett[i]); //Numeri dispari
		}
	}
	printf("]");
	/*Fine della ricerca degli elementi pari e dispari */		
}
