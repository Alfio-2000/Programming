/*Scrivere un programma che riesca a visualizzare gli elementi pari e dispari di un vettore.*/
#include <stdio.h>
#include <stdlib.h>
#define N 1024 //Dimensione del vettore 
int main()
{
	int n, i; //Numero di valori che si vogliano inserire. 
	int cont_pari=0, cont_dispari=0;
	char input[N];
	int vett[N], pari[N], dispari[N];  

	printf("Quandi valori vuoi inserire?");
	scanf("%s",&input);
	n=atoi(input);
	
	for(i=0; i<n; i++) //Riesco ad inserire tutti i valori che voglio.
	{
		printf("Inserisci valore:");
		scanf("%s", &input);
		vett[i]=atoi(input);
	}
	for(i=0; i<n; i++)
	{
		/*Adesso, devo visualizzare prima i valori pari e poi quelli dispari*/
		if(vett[i]%2==0)
		{
			pari[cont_pari]=vett[i];
			cont_pari++;
		}
		else if (vett[i]%2!=0)
		{
			dispari[cont_dispari]=vett[i];
			cont_dispari++;
		}
		
	}
	
	for(i=0; i<cont_pari; i++)
	{
		printf("\n Elemento pari: %d",pari[i]);	
	}
	
	for(i=0; i<cont_dispari; i++)
	{
		printf("\n Elemento dispari: %d",dispari[i]);
	}
		
}





















