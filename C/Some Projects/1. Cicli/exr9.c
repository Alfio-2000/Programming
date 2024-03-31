#include <stdio.h> 
#include <stdlib.h>

void main (void)
 {
 
  		float h,b,a_s; /* fase di dichiarazione delle variabili: il prof vuole variabili scrite per esteso (es:h=altezza) */
 			      /* Non bisogna dichiarare variabili in maiuscolo */ 		
  		
  		/* Qui chiedo l'altezza */ 
		printf("Mi dai l'altezza: \n");
		scanf("%f",&h); /* andando avanti la funzione scanf non si dovrà usare" */
		printf("Hai digitato %f \n", h); /* Sto dicendo al programma di stampare h per vedere se sta acquisendo il valore giusto */
		
		/* Qui chiedo la base */ 
		printf("Mi dai la base: \n");
		scanf("%f",&b); 
		printf("Hai digitato %f \n", b); /* Sto dicendo al programma di stampare b per vedere se sta acquisendo il valore giusto */
		
		/* Qui faccio il calcolo dell'area */ 
		
		a_s=b*h*0.5; /* in programmazione conviene usare più moltiplicazioni,perché la macchina le legge più facilmente e risparmia 				       tempo */
		
		printf("L'area risultante e' pari a: %f \n", a_s); 
				
 }
