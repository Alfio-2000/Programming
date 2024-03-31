/* Si vogliono dividere gli allievi di un corso in tre squadre denominate ROSSA, VERDE e BLU secondo il loro numero di matricola. L'assegnazione avviene con il seguente criterio: l'allievo con matricola 1 va nella squadra ROSSA, quello con matricola 2 nella VERDE, quello con matricola 3 nella BLU, quello con matricola 4 nella ROSSA e così via. Scrivere un programma che chieda il numero di matricola all'allievo e che indichi a quale squadra appartenga. (Usare il costrutto Switch) */

#include <stdio.h>

void main(void)

{
	int matricola,scelta;
	
		do
		{
		printf("Inserire il numero di matricola: \n");
		scanf("%d", &matricola);
		if(matricola<=0)
		printf("Il numero di matricola non e' valido \n");
		}while(matricola<=0);
			
			switch(matricola % 3)
			{
			case 1:
			printf("Lo studente appartiene alla squadra ROSSA \n");
			break;
			case 2: 
			printf("Lo studente appartiene alla squadra VERDE \n");
			break;
			default:
			printf("Lo studente appartiene alla squadra BLU \n");
			break;
			}
			
	printf("Fai la tua scelta: digita 1 per continuare, 0 per fermare il programma \n");
	scanf("%d", &scelta);
	
				while(scelta!=0)
				{
					switch(scelta)
					{
					case 1:
						do
						{
						printf("Inserire il numero di matricola: \n");
						scanf("%d", &matricola);
						if(matricola<=0)
						printf("Il numero di matricola non e' valido \n");
						}while(matricola<=0);
							switch(matricola % 3)
							{
							case 1:
							printf("Lo studente appartiene alla squadra ROSSA \n");
							break;
							case 2: 
							printf("Lo studente appartiene alla squadra VERDE \n");
							break;
							default:
							printf("Lo studente appartiene alla squadra BLU \n");
							break;
							}
					default: 
					printf("La scelta non e' valida \n");
					break;
					}
				printf("Fai la tua scelta: digita 1 per continuare, 0 per fermare il programma \n");
				scanf("%d", &scelta);
				}

}
