/*Scrivere un programma in cui, preso un numero, stampi il suo successivo e il suo precedente */
#include <stdio.h>
#include <stdlib.h>
void main (void)
{
	int a,precedente, successivo; 
	printf("Inserisci un numero: \n");  /* il computer chiede di inserire un numero */
	scanf("%d", &a); /* il computer registra in memoria il numero inserito */

	/* Iniziamo il calcolo */
	precedente=a-1; 
	successivo=a+1; 
	
	//Stampiamo i due numeri
	printf("Il precedente e': %d \n", precedente); 
	printf("Il successivo e': %d \n", successivo); 
	
}
