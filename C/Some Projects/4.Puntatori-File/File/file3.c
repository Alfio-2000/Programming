#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* input; // puntatore che permette di creare il file di input
    FILE* output; //puntatre che permette di creare il file di output
    char nome_file[31]; //stringa per il nome del file input che voglio creare
    char nome_file2[31]; //stringa per il nome del file output che voglio creare
    int n; //dimensione del vettore
    float elemento; //singolo elemento del vettore
    int riga=0;
    float somma=0.0, media;
    unsigned int i;
    printf("Quanti elementi vuoi inserire nel vettore?");
    scanf("%d",&n);
    float vettore[n]; //ho dichiarato il vettore dopo aver acquisito la sua dimensione

    /* Costruzione del vettore */
    for(i=0; i<n;i++)
    {
        printf("Inserisci elemento:");
        scanf("%f",&vettore[i]);
    }

    printf("Inserisci il nome del file in cui vuoi salvare il vettore:");
    scanf("%s",nome_file);

    input=fopen(nome_file,"w"); //apertura in scrittura.
    if(input==NULL) goto file_err;

    for(i=0; i<n; i++)
    {
        fprintf(input,"%.2f\n", vettore[i]);
    }
    fclose(input); //così ho chiuso il file di scrittura.

    /* Adesso apro il file input.txt creato prima e lo uso per crearne un altro che mi stampi i vari risultati */
    input=fopen(nome_file,"r"); //apro il file in lettura
    if(input==NULL) goto file_err;
    while(fscanf(input,"%f",&elemento)==1) // ho acquisito ogni valore
    {
        vettore[riga]=elemento;
        riga++;
    }
    for(i=0; i<riga; i++)
    {
        somma+=vettore[i];
        media=somma/n;
    }
    fclose(input);

    printf("Inserisci il nome del file output da creare:");
    scanf("%s",nome_file2);

    output=fopen(nome_file2,"w");
    fprintf(output, "La somma è %.2f, mentre la media è %.2f",somma,media);
    fclose(output);

    file_err: printf("ERRORE IN FASE DI APERTURA DEL FILE! \n");
    return EXIT_FAILURE;
}
