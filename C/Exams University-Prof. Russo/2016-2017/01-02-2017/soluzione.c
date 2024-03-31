#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATI  "dati.bin"
#define NOISE "noise.txt"
#define CLEAN "clean.txt"

typedef FILE* pfile; //Puntatore apertura file.
typedef float* pfloat;
typedef double* pdouble;
int main(void)
{
    pfile fdati,fnoise,fclean; //File dati, noise,clean
    int nc; //Numero coppie valori.
    pfloat x; //Puntatore a float che mi serve per contenere i valori delle ascisse.
    pdouble y; //Puntatore a double che mi serve per contenere i valori delle ordinate
    unsigned i,j; //Contatori per i cicli.
    float  x_g=0.0, std_x=0.0, xbar, x_numeratore=0.0; //Baricentro e dev.std delle x
    double y_g=0.0, std_y=0.0, ybar, y_numeratore=0.0;// Baricentro e dev.std delle y

    printf("Inizio elaborazione dati.\n");printf("\nApertura file '%s' ---> ",DATI);

    if((fdati=fopen(DATI,"rb"))==NULL) goto file_err;
    fread(&nc,sizeof(int),1,fdati); printf("%d coppie acquisite --->",nc);
    if((x=(pfloat)malloc(sizeof(float)*2*nc))==NULL)   goto mem_err;
    if((y=(pdouble)malloc(sizeof(double)*2*nc))==NULL) goto mem_err;
    for(i=0; i<nc;i++){fread(&x[i],sizeof(float),1,fdati);}
    for(j=nc; j<2*nc; j++){fread(&y[j],sizeof(double),1,fdati);}
    printf("Chiusura file.\n");
    for(i=0; i<nc;i++){x_g+=x[i];}
    for(j=nc; j<2*nc; j++){y_g+=y[j];}
    printf("Baricentro delle coppie: (%.2f, %.2f)\n",xbar=x_g/nc,ybar=y_g/nc);
    for(i=0; i<nc;i++){x_numeratore+=(x[i]-xbar)*(x[i]-xbar);}
    for(j=nc; j<2*nc; j++){y_numeratore+=(y[j]-ybar)*(y[j]-ybar);}
    std_x=sqrt(x_numeratore/nc);std_y=sqrt(y_numeratore/nc);
    printf("Le due deviazioni standard sono: stdx=%.2f, stdy=%.2f.\n",std_x,std_y);

    if((fnoise=fopen(NOISE,"w"))==NULL) goto file_err;
    if((fclean=fopen(CLEAN,"w"))==NULL) goto file_err;
    for(i=0,j=2*nc-1;i<nc,j>=nc;i++,j--)
    {
        if((((pow((x[i]-xbar),2))/(std_x*std_x))+((pow((y[j]-ybar),2))/(std_y*std_y)))<1)
        {
            fprintf(fclean,"%.2f %.2f\n",x[i],y[j]);

        }
        else if((((pow((x[i]-xbar),2))/(std_x*std_x))+((pow((y[j]-ybar),2))/(std_y*std_y)))>1)
        {
            fprintf(fnoise,"%.2f %.2f\n",x[i],y[j]);
        }
    }
    printf("Punti interni all'ellisse nel file '%s'.\n",CLEAN);
    printf("Punti esterni all'ellisse nel file '%s'.\n",NOISE);
    printf("\nChiusura dei files.\n"); printf("\nFine elaborazione dati.\n");
    fclose(fnoise);fclose(fclean);
    free(x);free(y); //Libero la memoria dai due vettori dinamici.
    return EXIT_SUCCESS;
    file_err: printf("Errore apertura file.\n"); return EXIT_FAILURE;
    mem_err:  printf("RAM insufficiente!\n");    return EXIT_FAILURE;
}
/*[1]:Non ho capito perché ha messo 2nc-1.*/
