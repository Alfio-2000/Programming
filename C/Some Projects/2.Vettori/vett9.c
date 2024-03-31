/*Scrivere un programma in grado d calcolare la media, la somma, il massimo e il minimo  degli elementi di un vettore */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024
void somma_media(int vett[N], int n) //Funzione che mi calcola la somma e la media degli elementi di un vettore. 
{
	int i; 
	float media, somma=0.0;
	for(i=0; i<n; i++)
	{
		somma+=vett[i];	
	}
	printf("La somma degli elementi e': %.2f  ", somma);
	media=(somma/n);
	printf("\n La media cercata e': %.2f", media);
}

void massimo_minimo(int vett[N], int n) //Guarda dopo: si puoò fare in un altro modo
{
	int i, max=vett[0], min=vett[0]; // Ho inizializzato: il primo elemento coincide con il massimo e con il minimo
	
	for(i=1; i<(n-1); i++) // parto da i=1, perché il caso i=0 l'ho considerato nell'inizializzazione
	{
		if(vett[i]>=max)
		{	
			max=vett[i];
		}
		else if(vett[i]<min) // Tolgo <=0 perché altrimenti i due casi (<= e >=) potrebbero coincidere
		{
			min=vett[i];
		}
	} 
	printf("\n L'elemento piu' grande e': %d", max);
	printf("\n L'elemento piu' piccolo e': %d", min);
}

/*
void massimo_minimo(int vett[N], int n)  
{
	int i, j, max=vett[0], min=vett[0]; //Vanno inizializzati perché se ho un vettore di un solo elemento max e min coincidono e questo caso va considerato
	
	for(i=0; i<n; i++)
	{
		for(j=1; j<(n-1); j++ ) 
		{
			if(vett[i]>=vett[j])
			{
				max=vett[i];
			}
			if(vett[i]<vett[j])
			{
				min=vett[i];
			}
		}
	} 
	printf("\n L'elemento piu' grande e': %d ", max);
	printf("\n L'elemento piu' piccolo e': %d ", min);
}
*/

int main()
{
	int vett[N];
	char input[N];
	char scelta; //Variabile che mi serve per chiedere all'utente se vuole riutilizzare il programma 
	int n; //Numero di elementi che si vuole inserire
	int i;  
	do
	{
		printf("Quanti elementi vuoi inserire?");
		scanf("%s",&input);
		n=atoi(input);
		
	}while(n<=0);
	
	/* Acquisizione e visualizzazione del vettore */
	
	for(i=0; i<n; i++) //Sto costruendo il vettore
	{
		printf("Inserisci valore:");
		scanf("%s",&input);
		vett[i]=atoi(input);
	}
	
	/* Adesso, stampo il vettore */
	
	printf("\n Il vettore che hai costruito e': [");
	for(i=0; i<n; i++) 
	{
		printf("%d ", vett[i]);
	}
	printf("]\n ");
	
	somma_media(vett, i); // Ho calcolato la somma e la media degli elementi.
	massimo_minimo(vett, i); //Ho calcolato il minimo e il massimo.
	
	printf("\n Se vuoi far ripartire il programma digita y oppure digita n se vuoi fermarlo:");
	scanf(" %c",&scelta);
	while(scelta=='y')
	{
		do
		{
			printf("Quanti elementi vuoi inserire?");
			scanf("%s",&input);
			n=atoi(input);
		}while(n<=0);
	
		/* Acquisizione e visualizzazione del vettore */
	
		for(i=0; i<n; i++) //Sto costruendo il vettore
		{
			printf("Inserisci valore:");
			scanf("%s",&input);
			vett[i]=atoi(input);
		}
		/* Adesso, stampo il vettore */
		
		printf("\n Il vettore che hai costruito e': [");
		for(i=0; i<n; i++) 
		{
			printf("%d ", vett[i]);
		}
		printf("]\n ");
	
		somma_media(vett, i); // Ho calcolato la somma e la media degli elementi.
		massimo_minimo(vett, i); //Ho calcolato il minimo e il massimo.
		printf("\n Se vuoi far ripartire il programma digita y oppure digita n se vuoi fermarlo:");
		scanf(" %c",&scelta);
	}
	return 0; 
}
