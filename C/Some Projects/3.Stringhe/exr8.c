/*Exr7.c fatto in maniera diversa*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_LENGHT 1024 //dimensione generica dei vettori stringa

int main()
{
    char stringa[STR_LENGHT];
    int lunghezza; //la lunghezza della stringa acquisita
    unsigned i;
    int maiuscole=0, minuscole=0, cifre=0;
    /*Presentazione del programma */
    printf("Ciao, sono il programma in grado di contare le cifre contenute in una parola.\n");

    /* Chiedo all'utente di inserire una parola */
    printf("Inserisci una parola: ");
    fgets(stringa,sizeof(stringa),stdin); /* (1) Vedere exr6.c */
    lunghezza= strlen(stringa);

    for(i=0; i<lunghezza && stringa[i]!='\0'; i++ )
    {
        if(isupper(stringa[i]))
        {
            maiuscole++;
        }
        else if(islower(stringa[i]))
        {
            minuscole++;
        }
        else if(isdigit(stringa[i]))
        {
            cifre++;
        }
    }
    printf("La stringa inserita contiene %d maiuscole.\n",maiuscole);
    printf("La stringa inserita contiene %d minuscole.\n",minuscole);
    printf("La stringa inserita contiene %d cifre.\n",cifre);
    printf("La stringa inserita contiene %d altri termini.\n",lunghezza-maiuscole-cifre-minuscole);
}
