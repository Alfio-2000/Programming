/* gcc nomefile.c -o nome eseguibile -lm (se c'è la libreria math.h) */
/*./nome eseguibile | more (questo comando serve per fare lo scroll con il le freccette o il mouse)*/
/*I due commenti servono per compilare dal terminale ubuntu */
/* Questo programma conta i primi N numeri*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 1000
void main(void)
{unsigned int i; /*Che cosa significa?*/
		
	i=0;
	for(;;)
	{
		printf("%d\n",i);
		if(i<N)
		{
		i+=1;
		} 
		else
		{
		break; 
		}
	}	

	printf("Ciao, ho finito il programma.\n");







}
