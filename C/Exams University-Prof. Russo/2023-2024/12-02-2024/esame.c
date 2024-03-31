#include <stdio.h>
#include <stdlib.h>

#define STR_LENGHT 256

typedef FILE* pfile;
typedef pfile* ppfile; //Questo lo uso quando devo acquisire il nome di tanti file da tastiera.
typedef float* pfloat;
typedef unsigned un;
typedef unsigned* punsigned;

int main(void)
{
    ppfile finput; //Questo sarà il vettore dinamico che conterrà l'i-esimo file.
    pfile fout;   // Puntatore per il file di output.
    punsigned misure;

    char s[STR_LENGHT];     //Questa stringa mi serve per acquisire.
    char ss[STR_LENGHT*2]; //[1] RICONTROLLARE!!!!!

    un n_f; //Numero di file.
    un i,j; //Contatori per i cicli.
    un m_tot=0; //numero misure totali.

    float v; //Valore di ogni misura nei file.

    printf("Inizio elaborazione dei dati.\n\n");
    for(;;) //[2]
    {
        printf("Inserisci il basename (Attenzione: il 1° carattere non può essere un numero!): ");scanf("%s",s);
        if((s[0]<'0') || (s[0]>'9')) break;
        else{printf("Errore: nome non valido!\n");}
    }

    sprintf(ss,"%s.out",s); printf("\nIl file di output sarà: %s ---> ",ss);
    if((fout=fopen(ss,"w"))==NULL) goto file_err;
    printf("Apertura del file.\n\n");

    printf("Quanti sono i file di input? ");
    scanf("%s",ss);
    n_f=atoi(ss); //[3]

    if((finput=(ppfile)malloc(sizeof(ppfile)*n_f))==NULL) goto mem_err;
    if((misure=(punsigned)malloc(sizeof(un)*n_f))==NULL)  goto mem_err;

    un maxmis=misure[0]; //[4]
    printf("\nApertura dei file di input.\n\n");
    for(i=0; i<n_f; i++)
    {
        sprintf(ss,"%s%u.bin",s,i+1); //[5]
        if((finput[i]=fopen(ss,"rb"))==NULL) goto file_err;
        fread(&misure[i],sizeof(un),1,finput[i]);
        printf("%u° file: %s e contiene %u misure.\n",i+1,ss,misure[i]);
        m_tot+=misure[i];
        if(maxmis<misure[i]){maxmis=misure[i];}
    }

    printf("\nI %u rivelatori hanno acquisito %u misure totali.\n",n_f,m_tot);
    printf("Numero massimo di misure acquisite: %u.\n",maxmis);
    fprintf(fout,"%u\n",m_tot); //Ho stampato m_tot sul file di output.

    for(j=0; j<maxmis; j++) //[6]
    {
        for(i=0; i<n_f; i++)
        {
            if(j<misure[i]) //[7]
            {
                if((fread(&v,sizeof(float),1,finput[i]))!=1) goto file_err; //[8]
                fprintf(fout,"%.3f\n",v); //Così ho stampato sul file il singolo valore.
            }
        }
    }
    for(i=0; i<n_f; i++){fclose(finput[i]);} printf("\nChiusura dei file di input.\n");
    printf("Chiusura file output.\n"); fclose(fout); //Ho chiuso il file di output.
    printf("\nFine elaborazione dei dati.\n");

    return EXIT_SUCCESS;
    file_err: printf("Errore di file!\n");    return EXIT_FAILURE;
    mem_err:  printf("Errore di memoria!\n"); return EXIT_FAILURE;
}
/*[1]: Questa stringa sarà quella che darà il nome ai files. Tuttavia non ho ben capito perché non raddoppia la lunghezza, visto che lo fa in tanti compiti...(vedi compito 19/06/2023) */

/*[2]:Questo è un controllo per vedere se il nome inserito dall'utente risulta valido: La logica dietro questo ciclo è geniale:
il for(;;) è un ciclo infinito: all'interno di esso chiedo il nome e uso l'if((s[0]<'0') || (s[0]>'9')) per dire che se il primo carattere della stringa risulta essere <0 o >9 allora, dobbiamo fermarci (queste disuguaglianze significano che se il primo carattere NON risulta essere un numero (come vogliamo noi) allora, dobbiao fermarci. PERCHÉ È GENIALE? PERCHÉ IN QUESTO MODO I FORMATI .1bw, /2bg, *b2, (cioè con caratteri speciali prima del numero) saranno esclusi.
Si può fare anche con while((s[0]>='0') || (s[0]<='9')) oppure con il do-while. Tuttavia, non quest'ultimi cicli i formati con i caratteri speciali non verranno esclusi, ma considerati e questo non va bene, come si potrebbe fare? IO L'HO FATTO CON IL WHILE(), MA, ONESTAMENTE, IL CONTROLLO DEL PROFESSORE È DAVVERO GENIALE. */

/*[3]: La logica dietro l'utilizzo  della ss[] è la seguente: Siccome sto acquisendo un numero, qualunque sia la stringa che uso per l'acquisizione essa sarà lo stesso convertita in un numero tramite la funzione atoi.*/

/*[4]: Ho inizializzato qui perché alla riga precedente ho acquisito il vettore in questione. Inoltre, questa inizializzazione mi serve per poter cercare il massimo numero di misure che vengono acquisite: quindi, se vengono, nel caso in questione, acquisite 3,5,4 misure, in output dovremmo ottenere: "Il massimo numero di misure acquisite da un singolo rivelatore è 5" */

/*[5]: La nota precedente potrebbe portarti a chiederti: "Come faccio a beccare il nome giusto dei file nel for?". La risposta è banale: la funzione sprintf converte la stringa di input (nel caso specifico è ss[]) in ciò che viene scritto tra le "" che seguono. (gli oggetti dopo le "" sono gli elementi che vengono richiamate all'interno delle "" ).*/

/*[6]: Ho usato la condizione j<maxmis perchè in questo modo posso acquisire tutte le misure di ogni file, poiché maxmis è il massimo numero di misure che un rivelatore è stato in grado di acquisire. */

/*[7]: Questo controllo è FONDAMENTALE PER L'ACQUISIZIONE DEI DATI DAI FILE: in pratica, ci dice che se il numero di misure è minore di quello corrente (misure[i]=vettore dinamico che ha per elementi il numero di misure acquisite nel singolo file.) allora posso acquisire, altrimenti no! */

/*[8]: Questo è geniale: Sto acquisendo un singolo valore dal file i-esimo in modo tale da non creare un vettore in grado di contenere tutti questi valori (I FILE POSSONO AVERE DIMENSIONE DEL TERABYTE.) Infatti, ho messo un controllo: se viene acquisito più di un valore c'è un errore. */
