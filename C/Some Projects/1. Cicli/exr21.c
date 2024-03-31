/* Benvenuti ad Hogwarts! Io sono il cappello parlante ed oggi ha inizio lo smistamento delle case. Esse sono GRIFONDORO, SERPEVERDE, TASSOROSSO E CORVONERO. Esse sono rappresentate dai numeri, rispettivamente 1, 2, 3, 4, ma anche 5, 6, 7, 8 e così via. Dimmi il numero che ti è stato assegnato nella lettera di ammissione e io ti dirò qual è il tuo destino (Usare il costrutto if) */

#include <stdio.h>
void main(void)
{
	int n;
		do
		{
		printf("Inserire il numero assegnato nella lettera : \n");
		scanf("%d", &n);
		if(n<=0)
		printf("Il numero inserito non e' valido \n");
		}while(n<=0);
			if(n % 4==1)
			{
			printf("La tua casa e': GRIFONDORO! \n");
			}
				else if(n % 4==2)
				{
				printf("La tua casa e': SERPERVERDE! \n");
				}
					else if(n % 4==3)
					{
					printf("La tua casa e' : TASSOROSSO! \n");
					}
						else
						{
						printf("La tua casa e': CORVONERO \n ");
						}
}
