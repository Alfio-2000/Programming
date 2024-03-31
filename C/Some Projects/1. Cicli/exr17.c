/*Scrivere un programma che chieda da tastiera di introdurre un numero intero corrispondente ad un voto e stampi a video "INSUFFICIENTE" se inferiore a 18, "APPENA SUFFICIENTE" se pari a 18, "BASSO" se compreso tra 19-20, "MEDIO" se compreso tra 21-23, "BUONO" se compreso tra 24-26, "ALTO" se compreso tra 27-29, "MASSIMO" se pari a 30 e "IMPOSSIBILE" per tutti gli altri. (Usare il costrutto if) */
#include <stdio.h>
void main(void)
{
	int voto;
		do
		{
		printf("Inserire il voto dell'esame : \n");
		scanf("%d", &voto);
		if(voto<=0)
		printf("Il voto inserito non e' valido \n");
		}while(voto<=0);
			if(voto<18)
			{
			printf("Il voto e' INSUFFICIENTE \n");
			}
				else if(voto==18)
				{
				printf("Il voto inserito e' APPENA SUFFICIENTE \n");
				}
					else if(voto>=19 && voto<=20)
					{
					printf("Il voto inserito e' BASSO \n");
					}
						else if(voto>=21 && voto<=23)
						{
						printf("Il voto inserito e' MEDIO \n");
						}
							else if(voto>=24 && voto<=26)
							{
							printf("Il voto inserito e' BUONO \n");
							}
								else if(voto>=27 && voto<=29)
								{
								printf("Il voto inserito e' ALTO \n");
								}
									else if(voto==30)
									{
									printf("Il voto inserito e' MASSIMO \n");
									}
										else
										{
										printf("IMPOSSIBILE \n");
										}
	
}
