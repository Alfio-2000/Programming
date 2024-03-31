/*Questo programma è in grado di ordinare un vettore costruito da tastiera in ordine crescente, decrescente,mettendo gli elementi pari prima di quelli dispari */
#include <stdio.h>
#include <stdlib.h>
#define N 1024 //Dimensione del vettore

void ordine_crescente(int vett[N], int n) // Funzione che mi permette di visualizzare quali sono gli elementi pari e dispari del vettore
{
	int i, j, temp;
	/*Inizio l'algoritmo di ordinamento Bubble Sort*/
	
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
	} //Finisco l'algoritmo di ordinamento Bubble Sort
	
	/* Stampo il vettore ordinato */
	printf("Il vettore i cui elementi sono in ordine crescente e': [");
	for(i=0; i<n; i++)
	{
		printf("%d ",vett[i]);
	}
	printf("]\n");			
}

void ordine_decrescente(int vett[N], int n)
{
	int i, j, temp;
	
	for(i=0; i<(n-1); i++) //Inizio l'algoritmo di ordinamento Bubble Sort
	{
		for(j=(i+1); j<n; j++) //Questo for mi serve per confrontare due elementi vicini dello stesso vettore: vedi exr: vett3.c 
		{
			if(vett[i]<vett[j])//mi serve per capire la condizione necessaria per ordinare in maniera decrescente
			{
				temp=vett[i];
				vett[i]=vett[j];
				vett[j]=temp;
			}
		}
	} //Con questo riga termino l'algoritmo di ordinamento Bubble Sort
	
	/* Stampo il vettore ordinato */
	printf("\n Il vettore di elementi in ordine decrescente: [");
	for(i=0; i<n; i++)
	{
		printf("%d ",vett[i]);
	}
	printf("]\n");	
}

void elementi_pari_dispari(int vett[N], int n)
{
	int i; 
	printf("Ecco a te: \n");
	printf("\n Il vettore ordinato e': [");
	/* Inizio della ricerca degli elementi pari e dispari */
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

int main()
{
	int vett[N];
	char input[N]; //vettore che mi serve per migliorare l'acquisizione di valori da tastiera
	int n; //quanti valore l'utente vuole conservare in un vettore
	int i, j; //contatori usati nei cicli for  
	char scelta; //variabile che mi permette all'utente di selezionare l'operazione che desidera. 
		
	printf("Quanti valori vuoi inserire?");
	scanf("%s",&input);
	n=atoi(input);
	
	/*Costruisco il vettore*/
	for(i=0; i<n; i++)
	{
		printf("Inserisci valore:");
		scanf("%d",&vett[i]);
	}
	/*Stampo il vettore*/
	printf("\n Il vettore che costruito e': [");
	for(i=0; i<n; i++)
	{
		printf("%d ",vett[i]);
		
	}
	printf("]\n ");	
	
	/* Vengono presentate le varie funzioni del programma all'utente, il quale dovrà scegliere quale fare partire */
	printf("Se vuoi stampare il vettore i cui elementi sono in ordine crescente digita 'c'\n");
	printf("Se vuoi stampare il vettore i cui elementi sono in ordine decrescente digita 'd'\n");
	printf("Se vuoi stampare il vettore in modo tale da visualizzare prima gli elementi pari e poi quelli dispari digita 'h'\n");
	scanf(" %c",&scelta); //La scelta va acquisita prima di entrare nello swicht (Ricorda: i codici vengono letti dall'alto verso il basso)
	
	switch(scelta) //Ciclo selettivo che mi permette di poter effettuare diverse scelte. 
	{
		case 'c': 
		ordine_crescente(vett, n);
		break; 
		case 'd':
		ordine_decrescente(vett, n);
		break;
		case 'h':
		elementi_pari_dispari(vett, n);
		break;	
		default: 
			printf("La scelta da te fatta non e' valida: \n");
			break; 
	}
	return 0;
}
