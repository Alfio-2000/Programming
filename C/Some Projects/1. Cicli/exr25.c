/* Scrivere un programma che classifichi la natura delle figura piane dopo aver inserito il numero di lati: 
calcolare area e perimetro delle figure piane conosciute*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main(void)
{
    int n; /*numero di lati che vogliamo inserire*/
    float perimetro, area;
    float a,b,c; /*Sono i lati del triangolo*/
    float quad_a,quad_b,quad_c; /*Sono i quadrati dei lati del triangolo*/
    float l_quadrato; /*Lato del quadrato*/
    float semi_perimetro;
    do
    {
        printf("Il numero di lati inseriti è:\n");
        scanf("%d",&n);
    }while(n<=2); /*Con questo ciclo sto controllando se il numero di lati ha senso*/
        if(n==3)
        {
        printf("Il poligono ha 3 lati: hai scelto un triangolo!\n");
        printf("Inserisci i valori dei tre lati\n");
        
        printf("Inserisci il primo valore:\n");
        scanf("%f",&a);
        
        printf("Inserisci il secondo valore:\n");
        scanf("%f",&b);
        
        printf("Inserisci il terzo valore:\n");
        scanf("%f",&c);
        quad_a=a*a;
        quad_b=b*b;
        quad_c=c*c;
            if((a==b) && (b==c)) /* Un triangolo è equilatero se tutti i lati sono uguali*/
            {
            printf("Il triangolo è equilatero\n");
            perimetro=a+b+c; 
            printf("Il perimetro del triangolo equilatero é: %.3f \n",perimetro);
            semi_perimetro=perimetro*0.5;
            area=sqrt(semi_perimetro*(semi_perimetro-a)*(semi_perimetro-b)*(semi_perimetro-c));/*Formula di Erone per il calcolo dell'area di un triangolo qualsiasi:*/
            printf("L'area del triangolo equilatero é: %.3f \n",area);
            }
            else if((a==b) || (a==c) || (c==b)) /* Un triangolo è isoscele se ha due lati uguali   */
            {
            printf("Il triangolo è  isoscele\n");
            perimetro=a+b+c; 
            printf("Il perimetro del triangolo isoscele é: %.3f \n",perimetro);
            semi_perimetro=perimetro*0.5;
            area=sqrt(semi_perimetro*(semi_perimetro-a)*(semi_perimetro-b)*(semi_perimetro-c));/* Formula di Erone per il calcolo dell'area di un triangolo qualsiasi:*/
            printf("L'area del triangolo isoscele é: %.3f \n",area);
            }
            else if((quad_a==quad_c+quad_b) || (quad_b==quad_a+quad_c) || (quad_c==quad_a+quad_b))
            {
                printf("Il triangolo è rettangolo\n");
                perimetro=a+b+c; 
                printf("Il perimetro del triangolo rettangolo é: %.3f \n",perimetro);
                semi_perimetro=perimetro*0.5;
                area=sqrt(semi_perimetro*(semi_perimetro-a)*(semi_perimetro-b)*(semi_perimetro-c));
                printf("L'area del triangolo rettangolo é: %.3f \n",area);
            }
            else 
                printf("Il triangolo è scaleno\n");
                perimetro=a+b+c;
                printf("Il perimetro del triangolo scaleno é: %.3f\n",perimetro);
                semi_perimetro=perimetro*0.5;
                area=sqrt(semi_perimetro*(semi_perimetro-a)*(semi_perimetro-b)*(semi_perimetro-c));
                printf("L'area del triangolo scaleno è. %.3f\n",area);
        }else if(n==4)
                {
                printf("Il poligono ha 4 lati: hai scelto un quadrato!\n");
                printf("Inserisci un lato del quadrato:\n"); /*Essendo il quadrato costituiti da 4 lati uguali, basta inserire un solo lato per poter calcolare area e perimetro*/ 
                scanf("%f",&l_quadrato);
                perimetro=3*l_quadrato;
                printf("Il perimetro è: %.3f \n",perimetro);
                area=l_quadrato*l_quadrato;
                printf("L'area é %.3f\n",area);
                }
        else
        printf("Hai scelto poligoni regolari.\n");
}
    
