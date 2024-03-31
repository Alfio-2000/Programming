/*Calcolo della perdita d'energia delle particelle alpha su un foglio d'alluminio 16 micron*/
#include <stdio.h>
#include <math.h>
#define c 1 /* e' la velcoita' della luce. Quando si lavora in MeV essa ha modulo unitario.*/
#define K 0.31 /* e' una costante espressa in (MeV*(cm^2))/g. */
#define m 0.51099828 /* massa dell'elettrone espressa in MeV. */
#define E0 5 /* E e' l'energia di 5MeV fornita dal testo. */
#define I 166 /* e' il potenziale di ionizzazione medio espresso in eV. */
void main(main)
{
	int n; 
	printf("In quanti spessorini vuoi suddividere il target d'alluminio?");
	scanf("%d", &n);
	
	/* Dihiaro le caratteristiche del proiettile (particelle alpha) */
	
	double M=3727.33; /* massa del proiettile espressa in MeV */
	double z=2.0; /* e' la carica della particella proiettile */
	
	/*Dichiaro le caratteristiche del bersaglio (foglio d'alluminio)*/
	
	double Z=13.0; /* numero atomico del materiale del bersaglio */
	double A=26.9815; /* numero di massa dell'alluminio espresso in g/mol*/
	double rho=2.7;  /* densita' dell'alluminio espressa in g/(cm^3)*/
	
	/* Dichiaro le variabili che individuano la formual di Bethe-Bloch*/
	double gamma, beta, phi, E_riposo, arg;
	double delta_x=0.004; /* e' lo spessore del target espresso in g/(cm^2) (densita' superficiale del foglio d'alluminio) */
	double dx=delta_x/n; /* e' la larghezza dei piccoli intervalli nei quali abbiamo scomposto lo spessore */
	
	/* Dichiaro i vettori che dovranno essere plottati */	
	double SP[n]; /* e' lo stopping power */
	double E[n]; /* l'energia che assume la particella man mano che incontra gli spessori dx. Inizialmente, sara' pari a E0 */
	double dE[n]; /* e' la quantita' d'energia persa nello spessore dx */
	double delta_SP=0; /* lo stopping power calcolato in ogni singolo spessore. */
	double Etot; /* l'energia totale della particella alpha. */
	E[0]=E0; /* l'energia iniziale. E[0] e' il primo elemento del vettore E[n]. */
	E_riposo=M*pow(c,2);
		for(int ix=0; ix<n-1; ix++)
		{
			Etot=E[ix]+E_riposo;
			beta=sqrt((1-pow((1/(Etot/(E_riposo))),2)));
			gamma=1.0/(sqrt(1.0-(beta*beta)));
			arg=(2.0*gamma*gamma*beta*beta)/I;
			phi=log(arg)-pow(beta,2);
			SP[ix]=-(K*(Z/A)*z*phi)/(beta*beta*rho); /*Stopping Power*/
			printf("Lo stopping power e':, %.4f \n", SP[ix]);
			printf("L'energia all'ingresso di ogni ciclo e': %.4f \n", E[ix]);
			dE[ix]=SP[ix]*dx;
			E[ix+1]=E[ix]-dE[ix];
				if(E[ix+1]<=0)
				{
				printf("La particella si e' fermata \n");
				continue;
				}
			delta_SP=delta_SP+ dE[ix];
		}
	printf("La perdita d'energia effettiva delle particelle alpha e': %.4f \n", delta_SP);
}
