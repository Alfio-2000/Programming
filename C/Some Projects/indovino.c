//Scrivere il programma dell'indovino. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // libreria che serve per generare numeri casuali

#define MIN 1 
#define MAX 100 

int main()
{	
	int tentativo; //il numero introdotto dall'utente. 
	int tentativi=1; //Numeri di tentativi dell'utente per indovinare il numero.
	int a; //numero (casuale) pensato dal computer. 
	char scelta; 
	srand(time(NULL)); //sto dicendo al generatore di numeri con il tempo corrente. 
	a=MIN+rand()% (MAX-MIN+1); //così ho generato casualmente un numero tra 1 e 100 inclusi. 
	printf("Ciao, ho pensato ad un numero nell'intervallo [%d,%d]:\t prova ad indovinarlo. \n",MIN, MAX);
	while(tentativi<=10)
	{
		do //Questo lo uso per controllare il numero inserito: se negativo o nullo, va inserito nuovamente. 
		{
			printf("Inserisci numero:");
			scanf("%d",&tentativo);
		}while(tentativo<=0);
		
		if(tentativo<a)
		{
			printf("Il numero pensato e' piu' alto \n");
		}
		else if(tentativo>a)
			{
				printf("Il numero pensato e' piu' basso \n");
			}
		else
		{
			printf("Bravo!Hai indovinato il numero %d \n",tentativo);
			break; //lo uso per dire al programma di uscire una volta indovinato il numero
		}	
	
		tentativi++;
		if(tentativi>10)
		{
			printf("Hai perso!\n");
			break;
		}	
	
	}
	
	printf("Vuoi giocare ancora? Digita y per rigiocare, digita n se vuoi smettere.\n");
	scanf(" %c", &scelta);
	while(scelta =='y')
	{
	srand(time(NULL)); //sto dicendo al generatore di numeri con il tempo corrente. 
	a=MIN+rand()% (MAX-MIN+1); //così ho generato casualmente un numero tra 1 e 100 inclusi. 
	printf("Ciao, ho pensato ad un numero nell'intervallo [%d,%d]:\t prova ad indovinarlo. \n",MIN, MAX);
	while(tentativi<=10)
	{
		do //Questo lo uso per controllare il numero inserito: se negativo o nullo, va inserito nuovamente. 
		{
			printf("Inserisci numero:");
			scanf("%d",&tentativo);
		}while(tentativo<=0);
		
		if(tentativo<a)
		{
			printf("Il numero pensato e' piu' alto \n");
		}
		else if(tentativo>a)
			{
				printf("Il numero pensato e' piu' basso \n");
			}
		else
		{
			printf("Bravo!Hai indovinato il numero %d \n",tentativo);
			break; //lo uso per dire al programma di uscire una volta indovinato il numero
		}	
	
		tentativi++;
		if(tentativi>10)
		{
			printf("Hai perso!\n");
			break;
		}	
	
	}
	printf("Vuoi giocare ancora? Digita y per rigiocare, digita n se vuoi smettere.\n");
	scanf("%c",&scelta);
		
	}
	return 0; 
	
}
