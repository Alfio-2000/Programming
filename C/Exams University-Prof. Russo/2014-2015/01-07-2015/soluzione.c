#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define FX "x.bin"
#define FY "y.txt"
#define DELTA_T 1 //Differenza tra i tempi di misura.
#define LS 1024

typedef FILE* pfile;
typedef float* pfloat;
typedef struct {float v,t;}coppia; //Struttura che rappresenta (valore,tempo). Il valore sono le due possibili coordinate
typedef coppia* pcoppia;
typedef struct {float x,y,t;}particella;
typedef particella* pparticella;

int main(void)
{
    pfile fx,fy; //Puntatori che mi permettono di aprire i due file.
    pcoppia px,py;
    pparticella pp;
    char s[LS]; //Stringa per l'acquisizione.
    int n_m; //Numero misure files
    float x_g=0.0,y_g=0.0,t_g=0.0; //Coordiante baricentro.
    float x,y,t; //Queste mi servono per il calcolo delle dev_std
    float x_num=0.0,y_num=0.0,t_num=0.0;
    float std_x,std_y,std_t;
    unsigned i,k,j; //Contatori per i cicli

    printf("Inizio elaborazione dati.\n");printf("\nApertura file:\n");
    printf("%s ---> ",FX);
    if((fx=fopen(FX,"rb"))==NULL) goto file_err; fread(&n_m,sizeof(int),1,fx);
    printf("%d Coppie (ascissa, tempo) acquisite.\n",n_m);
    printf("%s ---> ",FY);
    if((fy=fopen(FY,"r"))==NULL)  goto file_err; fscanf(fy,"%s",s); n_m=atoi(s);
    printf("%d Coppie (ordinata, tempo) acquisite.\n",n_m);

    if((px=(pcoppia)malloc(sizeof(coppia)*n_m))==NULL) goto mem_err;
    if((py=(pcoppia)malloc(sizeof(coppia)*n_m))==NULL) goto mem_err;
    if((pp=(pparticella)malloc(sizeof(particella)*n_m))==NULL) goto mem_err;
    printf("Questo coppie (x,t), (y,t) sono:\n");
    for(i=0;i<n_m;i++)
    {
        fread(&px[i].v,sizeof(float),1,fx);fread(&px[i].t,sizeof(float),1,fx);  //Ho letto la coppia (x,t)
        fscanf(fy,"%s",s); py[i].v=atof(s);fscanf(fy,"%s",s); py[i].t=atof(s); // Ho letto la coppia (y,t)
        printf("(%.1f,%.1f),(%.1f,%.1f)\n",px[i].v,px[i].t, py[i].v,py[i].t);
    }
    printf("\n");
    for(i=k=0; i<n_m; i++) //[1]
    {
        for(j=0;j<n_m;j++)
        {
            if(fabs(px[i].t-py[j].t)<DELTA_T) //[2]
            {
                x_g+=x=pp[k].x=px[i].v;
                y_g+=y=pp[k].y=py[i].v;
                t_g+=t=pp[k].t=(px[i].t+py[j].t)*0.5; //(ALPHA)
                x_num+=x*x; y_num+=y*y; t_num+=t*t;
                k++;
            }
        }
    }
    printf("Il baricentro delle particelle rivelate è: x_g=%f, y_g=%f, t_g=%f \n",x_g/n_m, y_g/n_m, t_g/n_m);
    std_x=sqrt((x_num/n_m)-(x_g/n_m)*(x_g/n_m));
    std_y=sqrt((y_num/n_m)-(y_g/n_m)*(y_g/n_m));
    std_t=sqrt((t_num/n_m)-(t_g/n_m)*(t_g/n_m));
    printf("\nLe deviazioni standard sono pari a: std_x=%f, std_y=%f, std_t=%f\n",std_x,std_y,std_t);
    printf("\nChiusura dei file.\n"); printf("\nFine elaborazione dati.\n");
    fclose(fx);fclose(fy); //Chiudo i due files.
    free(px);free(py);free(pp);//Libero la memoria.
    return EXIT_SUCCESS;
    file_err: printf("Errore apertura file!\n"); return EXIT_FAILURE;
    mem_err:  printf("RAM insufficiente!\n"); return EXIT_FAILURE;
}
/*[1]: Il contatore i mi serve per gestire il vettore px (cioè gestire le ascisse), il contatore j per py (cioè gestire le ordinate). Infine il contatore k mi serve per gestire il vettore pp che conterrà (x,y,t) particella, dove t è la media dei due tempi tx,ty (guarda (ALPHA)) */

/*[2]: Questa condizione è necessaria perché i due sistemi possono rivelare la medesima particella purché si abbia un tempo inferiore a DELTA_T. */
