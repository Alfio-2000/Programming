/*Scrivere un programma che chieda da tastiera di introdurre un numero intero corrispondente ad un voto e stampi a video "INSUFFICIENTE" se inferiore a 18, "APPENA SUFFICIENTE" se pari a 18, "BASSO" se compreso tra 19-20, "MEDIO" se compreso tra 21-23, "BUONO" se compreso tra 24-26, "ALTO" se compreso tra 27-29, "MASSIMO" se pari a 30 e "IMPOSSIBILE" per tutti gli altri. (Usare il costrutto switch) */
#include <stdio.h>
void main(void)
{
	int voto;
		do
		{
		printf("Inserire il voto dell'esame : \n");
		scanf("%d", &voto);
		if(voto<=0)
		printf("IMPOSSIBILE \n");
		}while(voto<=0);
			if(voto>0 && voto<18)
			{
			printf("INSUFFICIENTE \n");
			}
				switch(voto)
				{
				case 18:
				printf("APPENA SUFFICIENTE \n");
				break;
				case 19:
				case 20:
				printf("BASSO \n");
				break;
				case 21:
				case 22:
				case 23:
				printf("MEDIO \n");
				break;
				case 24:
				case 25:
				case 26:
				printf("BUONO \n");
				break;
				case 27:
				case 28:
				case 29:
				printf("ALTO \n");
				break;
				case 30:
				printf("MASSIMO \n");
				break;
				default:
				if(voto>30)
				printf("IMPOSSIBILE \n");
				break;
				}

}
