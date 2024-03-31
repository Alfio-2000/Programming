#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define LS 1024              // Lunghezza stringhe
#define NP 401              //  Numero di punti all'interno dei 3 file.
#define FILE_X  "x.txt"
#define FILE_Y0 "y0.txt"
#define FILE_Y1 "y1.txt"

typedef FILE* pfile;    //Puntatore per aprire i file.
typedef float* pfloat; //Puntatore per gestire i dati.
typedef char* pchar;  //Puntatore per gestire i caratteri. (Vedi [1])

pfloat get_array_from_txt(pchar nf, unsigned n) // [1]
{
    pfile pf;
    pfloat parray; // Questo sarà il puntatore a float che mi la funzione dovrà restituire.
    char s[LS]; // Stringa per l'acquisizione.

    if(((pf=fopen(nf,"r"))==NULL)) return (pfloat)pf; //[2]
    printf("Leggo il file %s\n",nf);
    if((parray=(pfloat)malloc(sizeof(float)*n))!=NULL)//[3]
    {
        for(unsigned i=0; i<NP; i++){fscanf(pf,"%s",s); parray[i]=atof(s);}
    }
    printf("Primo valore=%.2f; Ultimo valore=%.2f\n",parray[0],parray[n-1]);
    return parray;
}

int main(void)
{
    pfloat px,py0,py1; //Puntatori per i relativi file che abbiamo.

    if ((px= get_array_from_txt(FILE_X ,NP))==NULL) goto get_array_from_txt_err;
    if ((py0=get_array_from_txt(FILE_Y0,NP))==NULL) goto get_array_from_txt_err;
    if ((py1=get_array_from_txt(FILE_Y1,NP))==NULL) goto get_array_from_txt_err;

    free(px);free(py0);free(py1);

    return EXIT_SUCCESS;
    get_array_from_txt_err: printf("ERRORE: non posso caricare uno degli array!\n"); return EXIT_FAILURE;

}
//[1]: Questa funzione mi dice i file letti e i rispettivi primo ed ultimo valore.
/* PARAMETRI: Ho messo tali parametri perché sono delle etichette per le variabili che effettivamente devo usare: infatti, nel        main, quando richiamo la funzione, come "argomento" passo il nome del file definito all'inizio del codice e la dimensione nota  che mi viene fornita dal testo. */

//[2]: Mi restituisce un vettore nullo, se non ci sono dati all'interno dei file. (Se è vuoto.)


//[3]: Non ho messo ==NULL perché gli errori sull'apertura dei file e sulla memoria li ho inseriti direttamente nell'errore sulla funzione.

