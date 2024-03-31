/* Indovino: l'utente pensa ad un numero e il programma cerca di indovinarlo */
#include <stdio.h>
#define N 1024 //dimensione del vettore stringa 

int main()
{
	int i; // contatori che mi servono per i cicli 	
	int tentativi; // Numero di tentativi che il programma ha a disposizione per poter indovinare il numero pensato dall'utente
	int tentativo=0; // contatore che conta i tentativi (mi serve per poter uscire dal ciclo uno volta terminati i cicli.)
	int pt_medio; // il punto medio dell'intervallo all'interno del quale si trova il numero pensato dall'utente
	int min=1, max=10; // Estremi dell'intervallo all'interno del quale si trova il numero pensato dall'utente
	char input[N];	
	char a; // variabile che mi permette di dire se il programma ha indovinato o meno.
	
	printf("Pensa ad un numero tra %d e %d",min, max);
	do 
	{
		printf("\n Quanti tentativi ho a disposizione per indovinare il tuo numero?");
		scanf("%s",&input);
		tentativi=atoi(input);
				
	}while(tentativi<=0); //Questo ciclo mi permette per controllare se il numero di tentativi abbia senso
	
	pt_medio=(max+min)*0.5; 
	printf("\n Il numero che hai pensato e' %d?",pt_medio);
	
	printf("\n Se ho indovinato digita y, oppure n:");
	scanf(" %c",&a);
	
	for(i=0; i<(tentativi-1); i++) //devo inizializzare ad 1 per prendere il min e il max. 
	{
		if(a=='y')
		{
			printf("\n Perfetto! Ho indovinato il tuo numero! \n");
			break;
		}
		if(a=='n')	
		{	

			printf("Non ho indovinato il tuo numero, ma dammi un'altra possibilita'\n");
			printf("Il numero che hai pensato e' (>) oppure (<) di %d ?", pt_medio);
			scanf(" %c",&a);
			if(a=='>')
			{
				min=pt_medio;
				pt_medio=(max+pt_medio)*0.5; // Se ho pensato al 10, questa scrittura non va bene, perché?	
			}
			if(a=='<')
			{
				max=pt_medio;
				pt_medio=(pt_medio+min)*0.5;
			}
			printf("Il numero che hai pensato e' %d ?",pt_medio);
			scanf(" %c",&a);
		}
	}
	printf("\n Non sono riuscito ad indovinare, che peccato! :( \n");	
	return 0;
}

