/*Scrivere un programma in grado di costruire un vettore e di ordinare gli elementi di tale vettore in ordine crescente.*/
#include <stdio.h>
#define N 1024 //Dimensione dei vettore 
int main()
{
	int n; //Numero di valori da inserire in un vettore. 
	int i, j; //Contatori usati nei for. 
	int temp; //Variabile temp che mi serve per conservare il valore dell'i-esimo valore.
	int vett[N]; //vettore da usare la cui dimensione è nota (se vuoi cambiarla, vai al define)
	char input[N];
	
	do
	{
		printf("Quanti valori vuoi inserire?");
		scanf("%s",&input);
		n=atoi(input);	
	}while(n<=0);
	
	for(i=0; i<n; i++)//Questo for mi serve per costriire il vettore
	{
		printf("Inserisci valore:");
		scanf("%s", &input);
		vett[i]=atoi(input);	
	}
	
	//Adesso, scrivo un pezzo di codice in grado di visualizzare il vettore appena costruito
	
	printf("\n Il vettore che hai costruito e': [");
	for(i=0; i<n; i++)
	{
		printf("%d ",vett[i]);
	}
	printf("]\n"); //Con questa riga ho finito la visualizzazione del vettore costruito.
	
	for(i=0; i<n-1; i++)//Ho messo n-1 per riuscire a prendere tutti gli elementi da tastiera: se ho 5 elementi, partendo da i=0, avrei: 0,1,2,3,4 (cioè i 5 elementi)
	{
		for(j=i+1; j<n; j++)//Ho bisogno di j=i+1 perché così prendo il primo elemento e arrivo all'ultimo j<n
		{
			if(vett[i]>vett[j]) //Esempio: vett[0]>vett[1] (perché i=0 e j=0+1=1 all'inizio): se questa condizione avviene l'elemento più grande viene spostato a dx, mentre quello più piccolo a sx
			{
				temp=vett[i];
				vett[i]=vett[j];
				vett[j]=temp; //Questo mi serve per scambiare gli elementi in pratica
			}
		}
	}
	printf("Il vettore i cui elementi sono in ordine crescente e': [");
	for(i=0; i<n; i++)
	{
		printf("%d ",vett[i]);
	}
	printf("]\n");		
}
