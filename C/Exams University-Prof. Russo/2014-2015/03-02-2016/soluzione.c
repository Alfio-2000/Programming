#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LS 1024
#define NOME_FILE "fasci.bin"
#define DISTANZA 10 //Distanza tra i due centri.

typedef FILE* pfile;
typedef struct {float x,y;}particella;
typedef particella* pparticella;
typedef float* pfloat;

float dist(float x1,float y1,float x2,float y2){return sqrt((pow((x2-x1),2)+pow((y2-y1),2)));}

int main(void)
{
    pfile f;
    pparticella pp;
    pfloat pd1,pd2; //Vettore dinamico che conterrà tutte le distanze.
    int nptot;
    int np=0; //Numero di punti con distanza<10
    int npout=0; //Numero di punti con distanza>10
    unsigned i;
    float distanza;

    /* ***BARICENTRO*** */
    float xb1=0.0,yb1=0.0,xb2=0.0,yb2=0.0;
    float xbar1,ybar1,xbar2,ybar2;//Baricentro.
    /* ******* */

    /* ***Deviazioni standard*** */
    float std1=0.0,std2=0.0; //Deviazioni standard finali
    float d1,d2; //Deviazioni standard medie
    float somma1=0.0,somma2=0.0,numeratore1=0.0,numeratore2=0.0;
    /* ******* */

    printf("Inizio elaborazione dati.\n");
    printf("\nApertura del file '%s':\n",NOME_FILE);
    if((f=fopen(NOME_FILE,"rb"))==NULL) goto file_err;
    fread(&nptot,sizeof(int),1,f);
    printf("\n%d punti acquisiti:\n",nptot);
    if((pp=(pparticella)malloc(sizeof(particella)*nptot))==NULL) goto mem_err;
    if((pd1=(pfloat)malloc(sizeof(float)*nptot))==NULL) goto mem_err;
    if((pd2=(pfloat)malloc(sizeof(float)*nptot))==NULL) goto mem_err;
    for(i=0;i<nptot;i++)
    {
        fread(&pp[i].x,sizeof(float),1,f);fread(&pp[i].y,sizeof(float),1,f);
        printf("%u° coppia di punti: (%.2f,%.2f)\n",i+1,pp[i].x,pp[i].y);
        if((distanza=dist(pp[i].x,pp[i].y,0.0,0.0))<DISTANZA){np++;}
    }
    printf("\nTra questi, %d punti hanno distanza<10:\n",np);
    for(i=0;i<nptot;i++)
    {
        if((distanza=dist(pp[i].x,pp[i].y,0.0,0.0))<DISTANZA)
        {
            printf("(%.2f,%.2f)\n",pp[i].x,pp[i].y);
            xb1+=pp[i].x;yb1+=pp[i].y;
        }
    }
    xbar1=(xb1/np); ybar1=(yb1/np); //1° Baricentro
    for(i=0;i<nptot;i++)
    {
        if((distanza=dist(pp[i].x,pp[i].y,0.0,0.0))<DISTANZA)
        {
            pd1[i]=dist(pp[i].x,pp[i].y,xbar1,ybar1);
            somma1+=pd1[i];
            numeratore1+=pd1[i]*pd1[i];
        }
    }
    d1=somma1/np; //Misura media delle distanze del 1° Fascio
    std1=sqrt(((numeratore1)/np)-(d1*d1));
    for(i=0;i<nptot;i++){if((distanza=dist(pp[i].x,pp[i].y,0.0,0.0))>DISTANZA){npout++;}}
    printf("\nMentre %d con distanza>10:\n",npout);
    for(i=0;i<nptot;i++)
    {
        if((distanza=dist(pp[i].x,pp[i].y,0.0,0.0))>DISTANZA)
        {
            printf("(%.2f,%.2f)\n",pp[i].x,pp[i].y);
            xb2+=pp[i].x;yb2+=pp[i].y;
        }
    }
    xbar2=(xb2/npout);ybar2=(yb2/npout); //2° Baricentro
    for(i=0;i<nptot;i++)
    {
        if((distanza=dist(pp[i].x,pp[i].y,0.0,0.0))>DISTANZA)
        {
            pd2[i]=dist(pp[i].x,pp[i].y,xbar2,ybar2);
            somma2+=pd2[i];
            numeratore2+=pd2[i]*pd2[i];
        }
    }
    d2=somma2/npout; //Misura media delle distanze del 2° Fascio
    std2=sqrt(((numeratore2)/npout)-(d2*d2));
    printf("\n");
    printf("1° Baricentro: (%.2f,%.2f), std: %.2f\n",xbar1,ybar1,std1);
    printf("2° Baricentro: (%.2f,%.2f), std: %.2f\n",xbar2,ybar2,std2);
    fclose(f);
    free(pp); free(pd1); free(pd2);
    printf("\nChiusura file '%s':\n",NOME_FILE);
    printf("\nFine elaborazione dati.\n");
    return EXIT_SUCCESS;
    file_err: printf("Errore apertura file!\n");return EXIT_FAILURE;
    mem_err:  printf("RAM insufficiente!\n");   return EXIT_FAILURE;
}
//[1]: Questo if mi serve a calcolare quei punti che hanno una distanza<10 e quindi le coppie interessate per il calcolo del baricentro.
