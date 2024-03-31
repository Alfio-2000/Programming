#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STRLENGTH 1024
/* Definisco gli estremi dell'intervallo. */
#define XL -2.0
#define XR 2.0
#define NR 10000 // Numero di rettangoli.

#define POL "polinomi.txt"

typedef FILE *pfile;
typedef float *pfloat;

float integrale(pfloat pc, int g, float xl, float xr, int nr) // Funzione che mi calcola gli integrali con i rettangoli.
{
    float x,dx;
    float risultato=0.0; // Ho scritto così perché bisogna incrementare tale valore per ogni suddivisione fatta
    dx=(xr-xl)/nr;  // Larghezza dei singoli rettangoli.
    for(x=xl; x<xr; x+=dx)
    {
        for(unsigned i=0; i<=g; i++)
        {
            risultato+=pc[i]*pow(x,i);
        }
    }
    return risultato*dx;
}

int main()
{
    char stringa[STRLENGTH];

    /* Variabili per i polinomi. */
    int g; // Grado del polinomio
    float q, c1, c2; // termine noto, coeff. di x, coeff. di x2

    pfile f;
    pfloat pc; // pct è un puntatore temporaneo.

    unsigned np = 0; // Numero di polinomi.

    if ((f = fopen(POL, "r")) == NULL) goto open_err; /* Apertura con controllo del file. */
    fscanf(f, "%s", stringa);
    printf("Hai acquisito %u polinomi\n\n", np = atoi(stringa));

    for (unsigned ip = 0; ip < np; ip++)
    {
        fscanf(f, "%s", stringa);
        g = atoi(stringa);
        if ((pc = (pfloat)malloc(sizeof(float) * (g + 1))) == NULL) goto mem_err;
        printf("Polinomio n.%u: ", ip + 1);

        pfloat pct = pc; // Inizializzazione corretta di pct (puntatore temp di pc)

        for (unsigned ig = 0; ig <= g; ig++, pct++)
        {
            fscanf(f, "%s", stringa);
            if (!ig)
                printf("(%.2f)", (*pct) = atof(stringa));
            else
                printf("+(%.2f)x^%u", (*pct) = atof(stringa), ig);
        }
        printf("\nL'integrale in [%.2f,%.2f] vale:%.2f\n\n", XL, XR, integrale(pc,g, XL, XR, NR));
        free(pc);
    }
    fclose(f); /* Chiusura del file.*/
    return EXIT_SUCCESS;

    open_err: perror("Errore nell'apertura del file.\n"); return EXIT_FAILURE;
    mem_err:  perror("Errore di memoria: RAM insufficiente.\n"); return EXIT_FAILURE;
}
