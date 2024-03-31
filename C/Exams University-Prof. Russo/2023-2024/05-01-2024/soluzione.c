#include <stdio.h> /* NON RIESCO A STAMPARE L'ULTIMA RIGA DI OUTPUT DATA DAL PROFESSORE. */
#include <stdlib.h>
#include <float.h>

#define LS 1024          // Lunghezza stringa.
#define FI "valori.bin" // File di input: valori.bin
#define FO "valori.txt" // File di output: valori.txt

typedef FILE* pfile;
typedef double* pdouble;

int main(void)
{
    char s[LS];
    pfile fi,fo; // Puntatori a file: il primo per il file di input, il secondo per quello di output.
    pdouble pv;  // Puntatore che mi serve per costruire un array dinamico i cui elementi sono i valori dopo il 10 nel fle bin
    unsigned nm; // Numero di massimi che si vogliono stampare.
    unsigned nd; // Numero di misure all'interno del file binario.
    double v;    //  Valore della misura.
    float alpha, beta; // Variabili per la conversione.

    printf("Numero di valori a partire dal massimo incluso:");
    nm=atoi(s);
    scanf("%u",&nm);
    if((fi=fopen(FI,"rb"))==NULL) goto open_err; // Apro il file BINARIO.
    if((fo=fopen(FO,"w"))==NULL)  goto open_err; // Apro in scrittura il file TXT
    fread(&alpha,sizeof(float),1,fi); // Leggo il primo valore: alpha.
    fread(&beta,sizeof(float),1,fi); // Leggo il secondo valore: beta.
    printf("Funzione di trasformazione y=f(x) => y=(%.2f)x^2+(%.2f)\n",alpha,beta);
    fread(&nd,sizeof(unsigned),1,fi); // Leggo il terzo valore: nd (numero dei dati).
    fprintf(fo,"%u\n",nd); // Scrivo sul file TXT il numero di misure.
    if((pv=(pdouble)malloc(nd*sizeof(double)))==NULL) goto mem_err;
    for(unsigned i=0; i<nd; pv[i++]=-DBL_MAX) /* [NOTA VEDI SOTTO] */
    {
        fread(&v, sizeof(double),1,fi); // Acquisisco il valore v della misura  del file BIN
        printf("Acquisito il valore n.%u: %.2f, trasformato in: ",i,v); // Stampo in output il valore.
        fprintf(fo,"%f\n",alpha*(v*v)+beta); // Scrivo sul file TXT
        printf("%.2f\n",alpha*(v*v)+beta);  // Stampo su video
        for(unsigned j=0; j<nm; j++) // Inizio della ricerca dei valori massimi:
        {
            if(pv[j]<v)
            {
                for(unsigned k=nm; k>j; k--)
                {
                    pv[k]=pv[k-1];
                }
                pv[j]=v;
                break;
            }
        }
    }
    fclose(fo);
    fclose(fi);
    printf("I valori a partire dal massimo incluso sono:\n");
    for(unsigned i=0; i<nm;printf("%.2f\n ",pv[i++])); printf("\n");
    return EXIT_SUCCESS;

    open_err: perror("Errore nell'apertura del file.\n"); return EXIT_FAILURE;
    mem_err:  perror("Errore di memoria: RAM insufficiente.\n"); return EXIT_FAILURE;
}
  // [NOTA]:
 // Ho inizializzato pv[j++]=-DBL_MAX in modo tale da avere ogni elemento di pv posto al valore più piccolo:infatti, se pv[0]       assumerà tale valore, grazie a j++ (cioè l'incremento), anche gli altri elementi di posto successivo assumeranno tale valore  minimo. In questo modo ogni valore reale sarà sempre più grande di tale pv[j++]

