#include <stdio.h>
#include <stdlib.h>

#define NP "punti.txt"   // Ho dichiarato costante il nome del file: NP = numero punti.
#define NR "rette.txt"  // Ho dichiarato costante il nome del file: NR = numero rette.
#define LS 1024        // Lunghezza delle stringhe.

typedef FILE* pfile;
typedef struct {float x,y;}dot;
typedef dot* pdot;

int main(void)
{
    char stringa[LS];
    pfile f, fpiu, fmeno, ftemp;
    pdot pd;
    unsigned np; // Numero di punti all'interno del relativo file.
    unsigned nr; // Numero di rette all'interno del relativo file.

    unsigned npiu; // Numero di punti sopra le rette.
    unsigned nmeno; // Numero di punti sotto le rette.

    /* Variabili per le rette. */
    float m,q; // Coeffiiciente angolare e termine noto.

    /* File punti.txt */
    f=fopen(NP,"r");
    if(f==NULL)
    {
        perror("Errore nell'apertura del file.\n");
        return EXIT_FAILURE;
    }
    fscanf(f,"%s",stringa);
    np=atoi(stringa);
    pd=(pdot)malloc(np*sizeof(dot));
    if(pd==NULL)
    {
        perror("Errore di memoria: RAM insufficiente! \n");
        return EXIT_FAILURE;
    }
    for(unsigned i=0; i<np; i++)
    {
        fscanf(f,"%s",stringa);
        pd[i].x=atof(stringa);

        fscanf(f,"%s",stringa);
        pd[i].y=atof(stringa);
    }
    fclose(f);

    /* File rette.txt */
    f=fopen(NR,"r");
    if(f==NULL)
    {
        perror("Errore nell'apertura del file.\n");
        return EXIT_FAILURE;
    }
    fscanf(f,"%s",stringa);
    nr=atoi(stringa);
    for(unsigned i=0; i<nr; i++)
    {
        npiu=0;
        nmeno=0; // Ho inizializzato qui le variabili così tornano a 0 ad ogni ciclo e come numero max prende np vedi for [91]
        fscanf(f,"%s",stringa);
        m=atof(stringa);

        fscanf(f,"%s",stringa);
        q=atof(stringa);
        printf("È stata acquisita la retta r%u: y=x*(%.2f)+(%.2f)\n",i,m,q);
        sprintf(stringa,"r%u_piu.txt",i); // Considero la stringa r%u_piu.txt che ho creato.
        printf("Divido i punti: nel 1° file denominato r%u_piu.txt\n",i);
        fpiu=fopen(stringa,"w");
        if(fpiu==NULL)
        {
            perror("Errore nell'apertura del file.\n");
            free(pd);
            fclose(f);
            return EXIT_FAILURE;
        }
        printf("E nel secondo file denominato r%u_meno.txt\n",i);
        sprintf(stringa,"r%u_meno.txt",i);
        fmeno=fopen(stringa,"w");
        if(fmeno==NULL)
        {
            perror("Errore nell'apertura del file.\n");
            fclose(fpiu);
            free(pd);
            fclose(f);
            return EXIT_FAILURE;
        }
        for(unsigned j=0; j<np; j++)
        {
            if(pd[j].y>(m*pd[j].x +q))
            {
                fprintf(fpiu, "%.2f\n%.2f\n", pd[j].x, pd[j].y);
                npiu++;
            }
            else if(pd[j].y<(m*pd[j].x +q))
            {
                fprintf(fmeno, "%.2f\n%.2f\n", pd[j].x, pd[j].y);
                nmeno++;
            }
        }
        fclose(fmeno);
        fclose(fpiu);
        printf("%u punti nel primo file e %u punti nel secondo file\n\n",npiu,nmeno);
    }
    fclose(f);
    free(pd);
    return EXIT_SUCCESS;
}
