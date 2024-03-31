/* Scrivere un programma in grado di sommare gli elementi di un vettore */
#include <stdio.h>
#include <stdlib.h>

#define N1 10 //Dimensione del vettore che vogliamo costruire
#define N 1024 //Dimensione del vettore input (stringa) 

void somma_elementi(int vett[N1], int n) //Funzione che mi permette di poter sommare gli elmenti del vettore
{
	int i; 
	int somma=0; //Contatore della somma in grado di aumentare ogni volta che aggiungo un elemento 
	for(i=0; i<n; i++)
	{
		somma+=vett[i];
	}
	printf("La somma degli elementi del vettore costruito e': %d", somma); 	
}

int main()
{
	int vett[N1];
	char input[N];
	char scelta;
	int n; //Numero di elementi che l'utente vuole salvare in un vettore
	int i; //Contatore del ciclo for
	
	printf("Quanti valori vuoi inserire?");
	scanf("%s",&input);
	n=atoi(input);
	
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
	
	/* Adesso, inizia la parte centrale del codice: sommare gli elementi del vettore appena stampato */
	somma_elementi(vett,n);
	printf("\n Vuoi terminare il programma? y/n?");
	scanf(" %c",&scelta);
	while(scelta=='n') // Questo mi serve per far ripartire il programma. 
	{
		printf("Quanti valori vuoi inserire?");
		scanf("%s",&input);
		n=atoi(input);
	
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
	
	/* Adesso, inizia la parte centrale del codice: sommare gli elementi del vettore appena stampato */
	somma_elementi(vett,n);
	printf("\n Vuoi terminare il programma? y/n?");
	scanf(" %c",&scelta);
	}
	return 0;
}

