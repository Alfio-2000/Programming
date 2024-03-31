#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 10000 //questo è il numero di rettangoli(suddivisioni) 
#define N 1024

//Dichiarazione della funzione integranda (funzione dentro l'integrale considerato)
float funzione_integranda(float x) 
{
	float funzione= x*x; 
	return funzione; 	
}

//Calcolo mediante il metodo dei rettangoli
float calcolo_int_rettangoli(float estremo1, float estremo2) //Va messo anche int n, ma non l'ho fatto, perchè ho usato il define
{
	float x; 
	float dx;
	float  integrale=0.0; //Ho scritto così perchè bisogna incrementare tale valore per ogni suddivisione fatta
	dx=(estremo2-estremo1)/n; //Questa è la larghezza di ogni suddivisione
	for(x=estremo1; x<=estremo2; x+=dx)
	{
		integrale += funzione_integranda(x)*dx;
	}
	return integrale; 
}

//Calcolo mediante il metodo dei trapezi
float calcolo_int_trapezi(float estremo1, float estremo2) //Va messo anche int n, ma non l'ho fatto, perchè ho usato il define
{
	float base_trapezio_1, base_trapezio_2;
	float x; 
	float dx;
	float  integrale=0.0; //Ho scritto così perchè bisogna incrementare tale valore per ogni suddivisione fatta
	dx=(estremo2-estremo1)/n; //Questa è la larghezza di ogni suddivisione
	for(x=estremo1; x<=estremo2; x+=dx)
	{
		base_trapezio_1=x*x;
		base_trapezio_2= (x+dx)*(x+dx);
		integrale+=+(dx*(base_trapezio_1+base_trapezio_2)/2.0);	//Area_trapezio=altezza*[(base1+base2)/2], dx=altezza	
	}
	return integrale; 
}

int main()
{
	float estremo1, estremo2; //Estremi dell'intervallo.
	float x; //variabile delle funzione
	float risultato, funzione; //risultato dell'integrale e funzione integranda
	char r,t; //r se vuoi usare il metodo dei rettangoli, t se vuoi usare quello dei trapezi
	char scelta, choice; //la scelta che vuole effettuare l'utente. 
	char input[N];
	
	printf("Ciao, sono in grado di calcolare gli integrali definiti:Digita r per i rettangoli oppure t per i trapezi:");
	scanf("%c",&scelta);	
	
	if(scelta =='r')
	{
		printf("Hai scelto di usare il metodo dei rettangoli.\n");
		printf("Inserisci il primo estremo:");	scanf("%s",&input); estremo1=atof(input);
		printf("Inserisci il secondo estremo:");scanf("%s",&input); estremo2=atof(input);

		funzione=funzione_integranda(x); //Ho richiamato la funzione.
		risultato=calcolo_int_rettangoli(estremo1,estremo2);
		printf("L'integrale e' %.3f:",risultato);	
	}

	if(scelta =='t')
	{
		printf("\n Hai scelto di usare il metodo dei trapezi.\n");
		
		printf("Inserisci il primo estremo:");   scanf("%s",&input); estremo1=atof(input);
		printf("Inserisci il secondo estremo:"); scanf("%s",&input); estremo2=atof(input);
		
		funzione=funzione_integranda(x); //Ho richiamato la funzione.
		risultato=calcolo_int_trapezi(estremo1,estremo2);
		printf("L'integrale e' %.3f",risultato);	
	}
	
	printf("\n Vuoi continuare con il programma? y/n? "); scanf(" %c",&choice);

	while(choice=='y')
	{
			
		printf("\n Ciao, sono in grado di calcolare gli integrali definiti:Digita r per i rettangoli oppure t per i trapezi:");
		scanf(" %c",&scelta);
	
		if(scelta =='r')
		{
			printf("Hai scelto di usare il metodo dei rettangoli.\n");
			printf("Inserisci il primo estremo:"); scanf("%s",&input); estremo1=atof(input);
			printf("Inserisci il secondo estremo:"); scanf("%s",&input); estremo2=atof(input);

			funzione=funzione_integranda(x); //Ho richiamato la funzione.
			risultato=calcolo_int_rettangoli(estremo1,estremo2);
			printf("L'integrale e' %.3f",risultato);
			
		}
		if(scelta =='t')
		{	
			printf("Hai scelto di usare il metodo dei trapezi.\n");
			printf("Inserisci il primo estremo:"); scanf("%s",&input);  estremo1=atof(input);
			printf("Inserisci il secondo estremo:");scanf("%s",&input); estremo2=atof(input);

			funzione=funzione_integranda(x); //Ho richiamato la funzione.
			risultato=calcolo_int_trapezi(estremo1,estremo2);
			printf("L'integrale e' %.3f",risultato);
		
		}
		printf("\n Vuoi continuare con il programma? y/n? "); scanf(" %c",&choice);
	}
	return 0; 
}
