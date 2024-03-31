#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define LS 1024                      // Lunghezza delle stringhe
#define PA "pari.txt"               //  File input
#define PD "dispari.bin"           //   File input
#define RE "res.txt"              //    File output
#define ST "serie_temporale.txt" //     File che rappresenterà la serie temporale.

typedef FILE* pfile;
typedef float* pfloat;

int main(void)
{
    char s[LS];
    pfloat pv;
    pfile fp, fd, fst, fo; // Puntatori per: pari.txt, dispari.txt, serie.txt, res.txt
    unsigned i;
    unsigned n;   // numero di dati.
    float media,somma=0.0; //  media dei valori, somma mi serve per il calcolo della media.
    unsigned imn; // Indice del minimo assoluto
    unsigned i_f; //Contatore che mi serve per poter stabilire un intervallo opportuno: vedi riga 74
    unsigned l; //Ampiezza del semi intervallo
    int percentuale_media; //Percentuale media
    float pm; /*valore della media dopo il calcolo della percentuale */

    if((fp=fopen(PA,"r"))==NULL) goto open_err;
    if((fd=fopen(PD,"r"))==NULL) goto open_err;
    fscanf(fp,"%s",s);
    n=atoi(s);
    printf("N° Dati:%u\n",2*n);

    if((pv=(pfloat)malloc(sizeof(float)*2*n))==NULL) goto mem_err;

    if((fst=fopen(ST,"w"))==NULL) goto open_err;
    for(i=0; i<n; i++)
    {
        fscanf(fp,"%s",s);
        pv[i]=atof(s); fprintf(fst,"%.2f\n",pv[i]);
        fread(&pv[i],sizeof(float),1,fd); fprintf(fst,"%.2f\n",pv[i]); // [1]
    }
    fclose(fd);fclose(fp);
    fclose(fst);
    if((fst=fopen(ST,"r"))==NULL) goto open_err; // [2]
    for(i=0; i<2*n; i++)
    {
        fscanf(fst,"%s",s); pv[i]=atof(s);
        somma+=pv[i];
    }
    fclose(fst);

    printf("La media delle misure acquisite è: %.3f\n",media=somma/(2*n));
    do
    {
        printf("Percentuale media di taglio (positiva):");
        scanf("%s",s);
        percentuale_media=atof(s);

    }while(percentuale_media<=0); // In questo modo controllo se l'utente inserisce un adeguato valore.

    pm=(media*percentuale_media)/100;
    printf("Valore di troncamento: %.3f\n",pm);
    printf("Larghezza semintervallo:");
    scanf("%s",s);
    l=atof(s);

    if((fo=fopen(RE,"w"))==NULL) goto open_err;
    float mn=pv[0]; // Minimo assoluto
    for(i=1; i<(2*n); i++)
    {
        if(pv[i]<mn)
        {
            mn=pv[i];
            imn=i;
        }
    }
    printf("Il minimo della serie temporale è %.3f in posizione %u.\n",mn,imn);
    for(i=imn-l,i_f=imn+l; i<i_f; i++)
    {
        if((i<0) || (i>=(2*n)))
        {
            fprintf(fo,"MISS.\n");
        }
        else
        {
            fprintf(fo,"%.3f\n",pv[i]);
        }
    }
    fclose(fo);
    free(pv); //Libero la memoria

    return EXIT_SUCCESS;

    open_err: printf("Errore nell'apertura del file.\n");         return EXIT_FAILURE;
    mem_err:  printf("Errore di memoria: RAM INSUFFICIENTE!.\n"); return EXIT_FAILURE;
}
/* [1]: In questo modo ho costruito un vettore con i seguenti elementi: il primo elemento è il primo valore del file pari.txt
il secondo elemento è il primo valore del file dispari.bin, il terzo elemento è il 2 valore del file pari.txt e così via.
Faccio un esempio: se pari.txt contiene i valori 2,4,6 e dispari.bin contiene 1,3,5, allora il vettore sarà:
pv[]={2,1,4,3,6,5} */

/* [2]: Ho riaperto il file che ho creato in modalità lettura per poter usare il vettore pv in modo efficiente. Ma questo cosa significa? Se guardi bene il fstr a riga 31 sono stati acquisiti i dati come richiesto dal prof e nel frattempo sono stati stampati (per mia scelta) su un file. Ora, all'interno di tale fstr non potevo procedere come riga 42, perché altrimenti la scrittura somma+=pv[i] prenderebbe solo i valori dello fread, perché i codici vanno letti dall'alto verso il basso.*/
