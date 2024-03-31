/* Alcuni dipendenti di una ditta effettua una richiesta di rimborso spese di un vaggio di lavoro, inserire dall'esterno il nominativo del dipendete, la spesa e il tipo (1,2,3). Per ogni dipendente dare un output il nominativo e il rimborso definitivo. Il rimborso definitivo si ottiene dalla spesa effettuata aumentata del 20% se il tipo è 1, 40% se il tipo è 2 e del 60% se il tipo è 3.*/

#include <stdio.h> // EXR 6 DA COMPLETARE DOPO AVER STUDIATO IL CHAR
void main(main)
{
	char N; 
	float r1, r2, r3;
	float spesa; 
	printf("Inserisci il nominativo: \n");
	scanf(%c, &N);
	printf("Inserisci la spesa di N: \n");
	scanf("%f", &spesa);
		switch(N)
		{
		case 1: 
		r1=(spesa+((spesa*20)/100));
		printf("Il rimborso per N e': %.2f \n", r1);
		break;
		case 2: 
		r2=(spesa+((spesa*40)/100));
		printf("Il rimborso per N e': %.2f \n", r2);
		break;
		case 3: 
		r3=(spesa+((spesa*60)/100));
		printf("Il rimborso per N e': %.2f \n", r3);
		break;
		}

}
