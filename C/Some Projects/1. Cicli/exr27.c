/*Il programma indovino: pensa ad un numero tra quelli proposti e io proverà ad indovinarlo. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10 /*Il numero di numeri tra cui scegliere.*/
void main(void)
    {
        unsigned int i, j; /*Variabile ciclica: sta dentro il ciclo*/
        int tentativi; 
        int min,max; /*Gli estremi dell'intervallo dentro al quale c'è il numero pensato.*/
        int pt_medio; /*Punto medio dell'intervallo*/
        char scelta; 
        printf("Quanti tentativi vuoi far fare al software per indovinare il tuo numero?\n");
        scanf("%d",&tentativi);
        printf("Pensa ad un numero tra questi:\n");    
    
            /*Adesso stampo i numeri che voglio mostrare all'utente in modo tale che quest'ultimo ne pensi uno*/
            i=1; /*Faccio partire i numeri che voglio mostrare dal valore 1.*/
            for(;;)
            {
                printf("%d\n",i);
                if(i<N)
                {
                i++; /*Incremento i numeri di 1 fino ad arrivare ad N*/
                
                }else 
                {
                    break; /*Serve per bloccare il ciclo appena i=11, perchè voglio mostrare i primi dieci numeri*/
                }
            }
        min=1;
        max=10;
        pt_medio=(max+min)*0.5;
        printf("Hai pensato al numero: %d? \n",pt_medio);
        printf("Digita s se ho indovinato, mentre n per il contrario.\n");
        scanf("%c",&scelta);
        scelta=getchar();
            
        if(scelta=='s')
        {
        printf("Woah! Ho indovinato il numero che hai pensato!\n");
        }
        for( j=1; j<tentativi; j++) /*Questo ciclo mi serve iterare il procedimento per un numero di volte pari a tentativi*/
        {
            if(scelta=='n')
            {
                printf("Peccato, non ci sono ruscito,ma dammi un'altra opportunita'.\n");
                printf("Il numero che hai pensato e' maggiore (>) o minore (<) di %d?:\n",pt_medio);
                scanf("%c",&scelta);
                scelta=getchar();
                if(scelta=='>')
                {
                    min=pt_medio;
                    pt_medio=(max+pt_medio)*0.5;
                    
                }
                if(scelta=='<')
                {
                    max=pt_medio;
                    pt_medio=(pt_medio+min)*0.5;
                }
                printf("Hai pensato al numero %d:\n",pt_medio);
                scanf("%c",&scelta);
                scelta=getchar();
                
            }
         
        }
        
    }
