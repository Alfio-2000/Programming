/* Scrivere un programma che chieda due numeri da tastiera e dei due visualizzi il maggiore */ 
/* Ho usato il while per non far fermare il programma, ma farlo ripartire */

#include <stdio.h>
void main(void)
{
	int a,b,scelta;
	printf("Inserire il primo numero: \n");
	scanf("%d",&a);
	printf("Inserire il secondo numero: \n");
	scanf("%d", &b);
		if(a>=b)
		{
		printf("Il maggiore tra i due numeri e': %d \n",a);
		}
			else
			{
			printf("Il maggiore tra i due numeri e': %d \n",b);
			}
	printf("Fai la tua scelta: digita 1 per continuare, 0 per fermare il programma \n");
	scanf("%d", &scelta);
			
				while(scelta!=0) /* Infatti, appena e' 0 si esce dal ciclo */
				{ 
					switch(scelta) /* E' lo switch che ci fa scegliere (1 or 0) */ 
					{ 
						case 1:
						printf("Inserire il primo numero: \n");
						scanf("%d",&a);
						printf("Inserire il secondo numero: \n");
						scanf("%d", &b);
							if(a>=b)
							{
							printf("Il maggiore tra i due numeri e': %d \n",a);
							}
								else
								{
								printf("Il maggiore tra i due numeri e': %d \n",b);
							}
							break;
							default: 
							printf("La scelta non e' valida \n");
							break;
					}
				printf("Fai la tua scelta: digita 1 per continuare, 0 per fermare il programma \n");
				scanf("%d", &scelta);
				}

}


