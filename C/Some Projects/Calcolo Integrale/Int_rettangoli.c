#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 1000 //questo è il numero di rettangoli(suddivisioni) 

//Scrivo la funzione integranda
float funzione_integranda(float x) //questa è la funzione integranda
{
	float funzione= x*x; 
	return funzione; 
	
}
//Funzione che mi serve per il calcolo dell'integrale metodo dei rettangoli
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

int main()
{
	float estremo1, estremo2; //Estremi dell'intervallo.
	float risultato, funzione, x; //risultato dell'integrale
	printf("Inserisci il primo estremo:");
	scanf("%f",&estremo1);
	printf("Inserisci il secondo estremo:");
	scanf("%f",&estremo2);

	funzione=funzione_integranda(x); //Ho richiamato la funzione.
	risultato=calcolo_int_rettangoli(estremo1,estremo2);
	printf("L'integrale proposto è pari a %.3f:",risultato);	
}


