/*Scrivere un programma in grado di restituire la frequenza di un carattere c in una stringa acquisita da tastiera. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_LENGHT 1024 //dimensione generica dei vettori stringa

int main()
{
    char stringa[STR_LENGHT];
    int lunghezza; //la lunghezza della stringa acquisita
    int frequenza=0;
    unsigned i;

    /*Presentazione del programma */
    printf("Ciao, sono il programma in grado di dirti quante -c- sono contenute nella tua parola.\n");

    /* Chiedo all'utente di inserire una parola */
    printf("Inserisci una parola: ");
    fgets(stringa,sizeof(stringa),stdin); /* (1) Vedere exr6.c */
    lunghezza= strlen(stringa);

    for(i=0; i<lunghezza && stringa[i]!='\0'; i++)
    {
        if(stringa[i]=='c')
        {
            frequenza++;
        }
    }
    printf("La lettera -c- compare %d volte.\n",frequenza);
}
