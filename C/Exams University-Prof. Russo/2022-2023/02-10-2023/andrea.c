#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura del polinomio
typedef struct {
    int grado;
    double* coeff;
} Polinomio;

// Funzione per leggere un polinomio dal file
Polinomio leggiPolinomio(FILE* file) {
    Polinomio p;
    fscanf(file, "%d", &p.grado);

    p.coeff = (double*)malloc((p.grado + 1) * sizeof(double));
    for (int i = 0; i <= p.grado; i++) {
        fscanf(file, "%lf", &p.coeff[i]);
    }

    return p;
}

// Funzione per stampare un polinomio
void stampaPolinomio(Polinomio p) {
    printf("Grado: %d\n", p.grado);
    for (int i = 0; i <= p.grado; i++) {
        printf("Coeff[%d]: %lf\n", i, p.coeff[i]);
    }
}

// Funzione per calcolare l'integrale di un polinomio
double calcolaIntegrale(Polinomio p, double a, double b, int nr) {
    double h = (b - a) / nr;
    double integrale = 0.0;

    for (int i = 0; i < nr; i++) {
        double x1 = a + i * h;
        double x2 = x1 + h;
        double area = (x2 - x1) * (p.coeff[0] + p.coeff[1] * x1 + p.coeff[2] * x1 * x1); // Corretto il calcolo dell'area
        integrale += area;
    }

    return integrale;
}

int main() {
    FILE* file = fopen("polinomi.txt", "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    int numPolinomi;
    fscanf(file, "%d", &numPolinomi);

    for (int i = 0; i < numPolinomi; i++) {
        Polinomio p = leggiPolinomio(file);

        printf("Polinomio %d:\n", i + 1);
        stampaPolinomio(p);

        double a = -2.0;
        double b = 2.0;
        int nr = 10000;
        double integrale = calcolaIntegrale(p, a, b, nr);

        printf("Integrale: %lf\n\n", integrale);

        free(p.coeff); // Liberare la memoria allocata per i coefficienti del polinomio
    }

    fclose(file);

    return 0;
}
