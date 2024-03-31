#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PUNTI "punti.bin"
#define SFERE "sfere.txt"
#define STR_LENGTH 256

typedef FILE* pfile;
typedef struct {float x,y,z,r;}sfera;
typedef sfera* psfera;
typedef struct {float x,y,z;}dot;
typedef dot* pdot;

int main(void)
{
    pfile fpunti,fsfere;
    psfera ps;
    pdot pd;
    int n_p,n_s; //Numero di punti e di sfere.
    int i,j;
    char s[STR_LENGTH];
    float x_bar,y_bar,z_bar,x_g=0.0,y_g=0.0,z_g=0.0;
    int count; //Contatore di punti interni alla i-esima sfera.
    float d;

    printf("Inizio elaborazione dati.\n");
    if((fpunti=fopen(PUNTI,"rb"))==NULL) goto file_err;
    fread(&n_p,sizeof(int),1,fpunti);
    printf("\nApertura file '%s' --> %d punti acquisiti:\n\n",PUNTI,n_p);
    if((pd=(pdot)malloc(sizeof(dot)*n_p))==NULL)     goto mem_err;
    for(i=0; i<n_p; i++) //Prendo i punti dal file omonimo.
    {
        fread(&pd[i].x,sizeof(float),1,fpunti);
        fread(&pd[i].y,sizeof(float),1,fpunti);
        fread(&pd[i].z,sizeof(float),1,fpunti);
        printf("%u° punto:(%.1f, %.1f, %.1f)\n",i+1,pd[i].x,pd[i].y,pd[i].z);
        x_g+=pd[i].x; y_g+=pd[i].y; z_g+=pd[i].z;
    }
    printf("\nChiusura file '%s'\n",PUNTI);
    fclose(fpunti);
    printf("\nIl baricentro dei punti é: (%.2f, %.2f, %.2f)\n",x_bar=(x_g/n_p),y_bar=(y_g/n_p),z_bar=(z_g/n_p));
    if((fsfere=fopen(SFERE,"r"))==NULL) goto file_err;
    fscanf(fsfere,"%s",s); n_s=atoi(s);
    printf("\nApertura file '%s' --> %d Sfere acquisite:\n\n",SFERE,n_s);
    if((ps=(psfera)malloc(sizeof(sfera)*n_s))==NULL) goto mem_err;
    for(j=0; j<n_s; j++) //Prendo le sfere dal file omonimo.
    {
        fscanf(fsfere,"%s",s); ps[j].x=atof(s);
        fscanf(fsfere,"%s",s); ps[j].y=atof(s);
        fscanf(fsfere,"%s",s); ps[j].z=atof(s);
        fscanf(fsfere,"%s",s); ps[j].r=atof(s);
        printf("%d° sfera:[x-(%.1f)]^2 +[y-(%.1f)]^2 + [y-(%.1f)]^2=(%.1f)^2 \n",j+1,ps[j].x,ps[j].y,ps[j].z,ps[j].r);
    }
    printf("\nChiusura file '%s'\n\n",SFERE);
    for(j=0; j<n_s; j++)
    {
        count=0;
        for(i=0; i<n_p; i++)
        {
            if((pow((pd[i].x-ps[j].x),2)+pow((pd[i].y-ps[j].y),2)+pow((pd[i].z-ps[j].z),2))<(ps[j].r*ps[j].r))
            {
                d=sqrt(pow((x_bar-ps[j].x),2)+pow((y_bar-ps[j].y),2)+pow((z_bar-ps[j].z),2));
                count++;
            }
        }
        printf("Alla %d° sfera appartengono %d punti e la distanza è pari a %f.\n",j+1,count,d);
    }
    printf("\nFine elaborazione dati.\n");
    free(pd);free(ps); //Libero la memoria.
    return EXIT_SUCCESS;
    file_err: printf("Errore apertura file.\n"); return EXIT_FAILURE;
    mem_err:  printf("Errore memoria.\n");       return EXIT_FAILURE;
}
