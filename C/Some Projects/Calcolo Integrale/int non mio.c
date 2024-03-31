/*Integrazione numerica: il  programma è in grado di risolvere integrali definiti con il METODO DEI RETTANGOLI
  Questo programma NON È¨ stato fatto da me: l'ho preso da Ludovica Conti nel gruppo Facebook di Informatica anno 2022-2023
*/

#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define N 1024
 
void main(void)
   {
      char input[N];
      float min_intervallo,max_intervallo,N_suddivisioni,delta_x,x,integrale,funzione,base_trapezio_1,base_trapezio_2;
      
      printf("Sono il programma che esegue l'integrazione definita della funzione x^2 all'interno di un generico intervallo [a,b] a scelta 			dell'utente.\n");
      
      printf("Inserire l'estremo minimo a:   ");
      scanf("%s",input);
      min_intervallo = atof(input);
      
      printf("Inserire l'estremo massimo b:  ");
      scanf("%s",input);
      max_intervallo = atof(input);
      
      printf("Inserisci il numero di intervalli di suddivisione: ");
      scanf("%s",input);
      N_suddivisioni = atof(input);
      
      /*Suddivisione dell'intervallo [a,b] in parti di uguale ampiezza*/
      delta_x = (max_intervallo - min_intervallo) / N_suddivisioni;
      
      printf("Specificare la modalita' di integrazione:\nDigita a per utilizzare il metodo dei rettangoli\nDigita b per utilizzare il metodo dei trapezi\n");
      scanf("%s",input);
      
      /*Integrazione*/
      
      if(input[0]=='a')
         {
            /*Integrazione secondo il metodo dei rettangoli*/
            for(x = min_intervallo, integrale = 0.0; x < max_intervallo; x += delta_x)
               {
                  /*Si valuta il valore della funzione all'inizio di ogni step'*/
                  funzione = x*x;
                  /*Si fa la somma infinitesimale*/
                  integrale = integrale + (funzione*delta_x);
               }
         }
      else
         {
            /*Integrazione secondo il metodo dei trapezi*/
            for(x = min_intervallo, integrale = 0.0; x < max_intervallo; x += delta_x)
               {
                  /*Si valutano le 2 basi del trapezio che si costruisce ad ogni step*/
                  base_trapezio_1 = x*x;
                  base_trapezio_2 = (x + delta_x)*(x + delta_x);
                  /*Si fa la somma infinitesimale*/
                  integrale += + (delta_x*((base_trapezio_1 + base_trapezio_2)/2.0));
               }
         }
      printf("L'integrale della funzione vale %f\n", integrale);
   }	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


