#include <stdio.h>
#include <math.h>
#define n 1000
//Funzione integranda
float funzione_integranda(float x)
{
	float funzione=x*x; 
	return funzione;	
}
//Funzione che mi serve per il calcolo dell'integrale metodo dei trapezo
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
	//Itervallo
	float estremo1, estremo2,risultato;
	float funzione, x; 
	printf("Inserisci il primo estremo:");
	scanf("%f",&estremo1);
	printf("Inserisci il secondo estremo:");
	scanf("%f",&estremo2);
	//Prendo la funzione integranda
	funzione=funzione_integranda(x);
	//Effettuo il calcolo dell'integrale
	risultato=calcolo_int_trapezi(estremo1,estremo2);
	printf("Il risultato dell'integrale e': %.3f",risultato);
		
}
