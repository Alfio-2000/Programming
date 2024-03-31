/* Scrivere un programma in grado di copaire una stringa inserita da tastiera in un'altra. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_LENGHT 1024

int main()
{
    char input[STR_LENGHT]; //stringa inserita dall'utente.
    char output[STR_LENGHT]; // stringa di output.
    int lunghezza;

    printf("Inserisci una parola:");
    fgets(input, sizeof(input),stdin);
    lunghezza=strlen(input);

    strncpy(output, input, sizeof(output)); // Bisogna usare il sizeof all'interno perché bisogna assicurarsi che la stringa di destinazione abbia memoria sufficiente.
    output[sizeof(output) - 1] = '\0'; // Controllo che la stringa di output sia terminata correttamente

    printf("Ecco la parola iniziale: %s.",output);
}
