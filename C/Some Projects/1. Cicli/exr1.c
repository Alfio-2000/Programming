//Inserire due numeri dall'esterno da stampare in ordine crescente
#include <stdio.h>
#define N 1024
int main()
{
  int a, b;
  char scelta;
  char input[N];  
  printf("Inserisci il primo numero:");
  scanf("%s",&input);
  a=atoi(input);
  printf("Inserisci il secondo numero:");
  scanf("%s",&input);
  b=atoi(input); //è la funzione che mi permette di convertire le stringhe in interi
	if  (a>b)
	 {
		printf("In ordine crescente i numeri sono: %d %d: \n", b, a);
	 }
	 else
		{
			printf("I numeri, in ordine crescente sono: %d %d\n",a,b);
		}
  printf("Vuoi arrestare il programma? Digita y per confermare, n per ripartire.\n");
  scanf(" %c",&scelta); //per acquisire un carattere è meglio lasciare uno spazio in "%c"
  while(scelta!='y')
  {
  	printf("Inserisci il primo numero:");
  	scanf("%s",&input);
	a=atoi(input);
	printf("Inserisci il secondo numero:");
	scanf("%s",&input);
	b=atoi(input);
  	
  	if(a>b)
	{
		printf("In ordine crescente i numeri sono: %d %d: \n", b, a);
	}
	else
		{
			printf("I numeri, in ordine crescente sono: %d %d \n",a,b);
		}
  printf("Vuoi arrestare il programma? Digita Y per confermare, n per ripartire.\n");
  scanf(" %c",&scelta);	
  }
  printf("Hai deciso di fermare il programma. Spero di averti aiutato, arrivederci.");			
}
