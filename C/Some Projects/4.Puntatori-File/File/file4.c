#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordinecrescente(int* a, int* b, int* c)
{
    if(*a>*b && *a>*c && *b>*c)
    {
        printf("\nL'ordine dei valori inseriti e': %d, %d, %d", *a, *b, *c);
    }
    else if(*a>*b && *a>*c && *b<*c)
    {
        printf("\nL'ordine dei valori inseriti e': %d, %d, %d",*a, *c, *b);
    }
    else if(*a<*b && *a>*c && *b>*c)
    {
        printf("\nL'ordine dei valori inseriti e': %d, %d, %d",*b,*a,*c);
    }
    else if(*a<*b && *a<*c && *b>*c)
    {
        printf("\nL'ordine dei valori inseriti e': %d, %d, %d \n",*b,*c,*a);
    }
    else if(*a<*b && *a<*c && *b<*c)
    {
        printf("\nL'ordine dei valori inseriti e': %d, %d, %d \n",*c,*b,*a);
    }
    else if(*a>*b && *a<*c && *b<*c)
    {
        printf("\nL'ordine dei valori inseriti e': %d, %d, %d \n",*c,*a,*b);
    }
}

int main()
{
    int x,y,z; //valori da ordinare
    printf("Inserisci il primo valore:");
    scanf("%d",&x);
    printf("Inserisci il secondo valore:");
    scanf("%d",&y);
    printf("Inserisci il terzo valore:");
    scanf("%d",&z);
    ordinecrescente(&x,&y,&z);
}
