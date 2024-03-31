/* Scrivere un programma che richieda in input una stringa e conti di quante lettere maiuscole, minuscole,cifre e altri caratteri è composta. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_LENGHT 1024 //dimensione generica dei vettori stringa

void cifre(char stringa[STR_LENGHT],int lunghezza) //funzione che calcola il numero di cifre
{
    int cifre=0;
    unsigned i; //contatore per il ciclo
    for(i=0; i<lunghezza && stringa[i]!='\0'; i++ )
    {
        if(isdigit(stringa[i]))
        {
            cifre++;
        }
    }
    printf("La stringa inserita contiene %d cifre\n",cifre);
}

void maiuscole(char stringa[STR_LENGHT],int lunghezza) //funzione che calcola il numero di maiuscole
{

    int maiuscole=0;
    unsigned i;
    for(i=0; i<lunghezza && stringa[i]!='\0'; i++ )
    {
        if(isupper(stringa[i])) //la funzione isupper serve per capire se un carattere è maiuscolo
        {
            maiuscole++;
        }
    }
    printf("La stringa inserita contiene %d maiuscole\n",maiuscole);
}

void minuscole(char stringa[STR_LENGHT],int lunghezza)//funzione che calcola il numero di minuscole
{
    int minuscole=0;
    unsigned i;
    for(i=0; i<lunghezza && stringa[i]!='\0'; i++ )
    {
        if(islower(stringa[i])) //la funzione islower serve per cercare i carattere minuscoli
        {
            minuscole++;
        }
    }
    printf("La stringa inserita contiene %d minuscole\n",minuscole);
}

void speciali(char stringa[STR_LENGHT],int lunghezza)//funzione che calcola i caratteri speciali
{
    int speciali=0;
    unsigned i;
    for(i=0; i<lunghezza && stringa[i]!='\0'; i++ )
    {
        if(!isalnum(stringa[i]))//la funzione isalnum verifica se un carattere è alfanumerico. L'inversione ! permette di contare i             caratteri che non sono alfanumerici, cioè i caratteri speciali.
        {
            speciali++;
        }
    }
    printf("La stringa inserita contiene %d caratteri speciali\n",speciali);
}

int main()
{
    char stringa[STR_LENGHT];
    int lunghezza; //la lunghezza della stringa acquisita

    /*Presentazione del programma */
    printf("Ciao, sono il programma in grado di contare le cifre contenute in una parola.\n");

    /* Chiedo all'utente di inserire una parola */
    printf("Inserisci una parola: ");
    fgets(stringa,sizeof(stringa),stdin); /* (1) Vedere exr6.c */
    lunghezza= strlen(stringa);

    /* Stampo il numero di cifre della stringa */
    cifre(stringa,lunghezza);

    /* Stampo il numero di caratteri MAIUSCOLI*/
    maiuscole(stringa,lunghezza);

    /* Stampo il numero di caratteri minuscoli */
    minuscole(stringa,lunghezza);

    speciali(stringa,lunghezza);
}
