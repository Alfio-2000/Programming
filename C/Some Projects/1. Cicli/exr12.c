/* Scrivere un programma che chieda tre numeri da tastieri e li visualizzi in ordine decrescente */
#include <stdio.h>
void main(void){
	int a, b, c;
	printf("Inserire il primo valore:");
	scanf("%d", &a);
	printf("Inserire il secondo valore:");
	scanf("%d", &b);
	printf("Inserire il terzo valore:");
	scanf("%d", &c);
		if(a>b && a>c && b>c)
		{
		printf("L'ordine dei valori inseriti e': %d, %d, %d", a, b, c);
		}
			else if(b>a && b>c && a>c)
			{
			printf("L'ordine dei valori inseriti e': %d, %d, %d", b, a, c);
			}
				else if(c>a && c>b && b>a)
				{
				printf("L'ordine dei valori inseriti e': %d, %d, %d", c, b, a);
				}
					else
					{
					printf("L'ordine dei valori inseriti e': %d, %d, %d \n", c, a, b); 
					}

}
