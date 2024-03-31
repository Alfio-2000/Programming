/* Scrivere un programma in grado di stampare gli elementi di POSTO pari e dispari di un vettore. 
Esempio: Se costruiamo [1,2,3,4,5,10,9,6], in output dobbiamo visualizzare: Elementi posto pari: (1,3,5,9) e (2,4,10,6). */

#include <stdio.h>
#include <stdlib.h>

#define N 1024

int main()
{
	char input[N]; //Vettore che mi serve per migliorare l'acquisizione di valori da tastiera
	int n; //Numero di elementi del vettore
	int vett[N]; //vettore che vogliamo costruire
	int pari[N],dispari[N]; //Questi vettori li uso per conservare gli elementi di posto pari e dispari presenti all'interno del vettore costruito.
	int cont_pari=0, cont_dispari=0; //Contatori in grado di dirci QUANTI elemnti pari ci sono
	int i,j; //Contatore del for
	char scelta; 
	printf("Ciao, sono in grado di stampare separatamente gli elementi di posto pari e di posto dispari di un vettore.\n");
	do
	{
		printf("Quanti elementi vuoi che possieda il tuo vettore?");
		scanf("%s",&input);
		n=atoi(input);
	
	}while(n<=0);
	
	for(i=0; i<n; i++)
	{
		printf("Inserisci elemento:");
		scanf("%s",&input);
		vett[i]=atoi(input);	
	}
	
	printf("Il vettore che hai costruito e': [");
	for(i=0; i<n; i++)
	{
		printf("%d ",vett[i]);
	}
	printf("]\n");	
	for(i=0; i<n; i++) //Questo mi serve per contare quanti elementi di posto pari e dispari ci sono all'interno del vettore.
	{
		if(i%2==0)
		{
			pari[cont_pari]=vett[i];
			cont_pari++;//così aumentiamo sempre la dimensione del vettore pari[] ogni qualvolta che prendiamo l'elemento di posto pari, salvando nel vettore stesso
		}
		if(i%2!=0)
		{
			dispari[cont_dispari]=vett [i];
			cont_dispari++; //così aumentiamo sempre la dimensione del vettore dispari[] ogni qualvolta che prendiamo l'elemento di posto dispari, salvando nel vettore stesso
		}	
	}
	printf("Elementi di posto pari: ");
	for(i=0; i<cont_pari; i++)
	{
		printf("%d, ",pari[i]);	
	}
	printf("\n Elementi di posto dispari: ");
	for(i=0; i<cont_dispari; i++)
	{
		printf("%d, ",dispari[i]);	
	}
	printf("Vuoi arrestare il programma? y/n?");
	scanf(" %c", &scelta);
	while(scelta!='y')
	{
		do{
			
			printf("Quanti elementi vuoi che possieda il tuo vettore?");
			scanf("%s",&input);
			n=atoi(input);
		
		}while(n<=0);
	
		for(i=0; i<n; i++)
		{
			printf("Inserisci elemento:");
			scanf("%s",&input);
			vett[i]=atoi(input);	
		}
	
		printf("Il vettore che hai costruito e': [");
		for(i=0; i<n; i++)
		{
			printf("%d ",vett[i]);
		}
		printf("]\n");	
		for(i=0; i<n; i++) //Questo mi serve per contare quanti elementi di posto pari e dispari ci sono all'interno del vettore.
		{
			if(i%2==0)
			{
				pari[cont_pari]=vett[i];
				cont_pari++;//così aumentiamo sempre la dimensione del vettore pari[] ogni qualvolta che prendiamo l'elemento di posto pari, salvando nel vettore stesso
			}
			if(i%2!=0)
			{
				dispari[cont_dispari]=vett [i];
				cont_dispari++; //così aumentiamo sempre la dimensione del vettore dispari[] ogni qualvolta che prendiamo l'elemento di posto dispari, salvando nel vettore stesso
			}		
		}
		printf("Elementi di posto pari: ");
		for(i=0; i<cont_pari; i++)
		{
			printf("%d, ",pari[i]);	
		}
		printf("\n Elementi di posto disppari: ");
		for(i=0; i<cont_dispari; i++)
		{
			printf("%d, ",dispari[i]);	
		}
		printf("\n Vuoi arrestare il programma? y/n?");
		scanf(" %c", &scelta);
	
	}
	
}
