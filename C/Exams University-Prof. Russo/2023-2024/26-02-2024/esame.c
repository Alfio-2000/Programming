#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define LS 256
#define FILE_PUNTI  "punti.bin"
#define FILE_CERCHI "cerchi.bin"
#define FILE_RES "res.out"

typedef FILE* pfile;
typedef struct dot_{float x,y;}dot;
typedef dot* pdot;
typedef struct cerchio_{float xc,yc,r;}cerchio;

int main(void)
{
    pfile fpunti,fcerchi,fres; //Puntatore per la gestione dei file
    char s[LS];
    pdot pd;
    cerchio c; //Variabile cerchio: c rappresenta un cerchio con parametri xc,yc,r
    unsigned nd,nc; //Numero di punti e di cerchi in ogni file.
    unsigned i,j;
    unsigned count;
    float dx,dy;

    if((fpunti=fopen(FILE_PUNTI,"rb"))==NULL)   goto file_err;    //Apertura file punti.bin
    fread(&nd,sizeof(unsigned),1,fpunti); printf("Acquisito %u punti:\n",nd);
    if((pd=(pdot)malloc(sizeof(dot)*nd))==NULL) goto mem_err;
    if((fcerchi=fopen(FILE_CERCHI,"rb"))==NULL) goto file_err;   // Apertura file cerchi.bin
    fread(&nc,sizeof(unsigned),1,fcerchi);

    for(i=0; i<nd; i++)
    {
        fread(&pd[i].x,sizeof(float),1,fpunti);fread(&pd[i].y,sizeof(float),1,fpunti);
        printf("Acquisito %u° punto: x=%.2f, y=%.2f\n",i+1,pd[i].x,pd[i].y);
    }
    printf("\nAcquisiti %u cerchi:\n",nc);
    for(j=0;j<nc;j++)
    {
        if((fread(&c.xc,sizeof(float),1,fcerchi))!=1) goto file_err;
        if((fread(&c.yc,sizeof(float),1,fcerchi))!=1) goto file_err;
        if((fread(&c.r, sizeof(float),1,fcerchi))!=1) goto file_err;
        printf("Cerchio n.%u ---> xc=%.2f, yc=%.2f, r=%.2f\n",j+1,c.xc, c.yc, c.r);
        count=0;
        for(i=0; i<nd; i++)
        {
            dx=(pd[i].x-c.xc); dy=(pd[i].y-c.yc);
            if((dx*dx)+(dy*dy)<(c.r*c.r))
            {
                count++;
                printf("Trovato punto interno: (%.2f, %.2f)\n",pd[i].x,pd[i].y);
            }
            if(count==0){printf("Nessun punto interno!!\n");break;}
        }
    }

    return EXIT_SUCCESS;
    fclose(fpunti);fclose(fcerchi); //Chiusura dei files.
    free(pd); //Libero la memoria
    file_err: printf("Errore file!\n");    return EXIT_FAILURE;
    mem_err:  printf("Errore memoria!\n"); return EXIT_FAILURE;
    zero_dot: printf("Nessun punto interno!!\n");
}
