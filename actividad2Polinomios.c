#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n; // grado del polinomio
    double *coeficiente;
} Polinomio;

Polinomio crearPolinomio(int n)
{
    Polinomio polinomio;
    polinomio.n = n;
    polinomio.coeficiente = malloc((n + 1) * sizeof(double)); // Asignar memoria para los coeficientes

    // Leer los coeficientes del usuario
    int i;
    for (i = 0; i <= n; i++)
    {
        printf("Ingrese el coeficiente para x^%d: ", i);
        scanf("%lf", &polinomio.coeficiente[i]);
    }

    return polinomio;
}

void imprimirPolinomio(Polinomio polinomio)
{
    int i;
    for (i = polinomio.n; i >= 0; i--)
    {
        if (i > 1)
        {
            printf("%.2lf * x^%d ", polinomio.coeficiente[i], i);
            printf("+ ");
        }
        else if (i == 1)
        {
            printf("%.2lf * x ", polinomio.coeficiente[i]);
            printf("+ ");
        }
        else if (i == 0)
        {
            printf("%.2lf", polinomio.coeficiente[i]);
        }
    }
    printf("\n");
}

// 2.b
void setCoef(int n, double c, Polinomio poliamodificar)
{
    printf("polinomio original:\n");
    imprimirPolinomio(poliamodificar);

    printf("en el %d grado del polinomio agregamos el coeficiente %.2lf  \n", n, c);
    poliamodificar.coeficiente[n] = c;
    poliamodificar.n = n;
    imprimirPolinomio(poliamodificar);
}

// 2.c
double getCoef(int n, Polinomio p)
{
    return p.coeficiente[p.n];
}

// 2.d
double especializa(double x, Polinomio p)
{
    double res[p.n - 1];
    double sum = 0;
    int i;
    for (i = p.n; i > 0; i--)
    {
        res[i] = p.coeficiente[i] * x;
    }

    for (i = p.n; i >= 0; i--)
    {
        sum = sum + res[i];
    }
    return sum + p.coeficiente[0];
}

// 2.e
Polinomio sum(Polinomio polinomio1, Polinomio polinomio2)
{
    int maxGrado = (polinomio1.n > polinomio2.n) ? polinomio1.n : polinomio2.n;
    int minGrado = (polinomio1.n < polinomio2.n) ? polinomio1.n : polinomio2.n;
    int i;

    Polinomio resultado;
    resultado.n = maxGrado;
    resultado.coeficiente = malloc((maxGrado + 1) * sizeof(double));

    for (i = 0; i <= minGrado; i++)
    {
        resultado.coeficiente[i] = polinomio1.coeficiente[i] + polinomio2.coeficiente[i];
    }

    for (i = minGrado + 1; i <= maxGrado; i++)
    {
        if (polinomio1.n > polinomio2.n)
        {
            resultado.coeficiente[i] = polinomio1.coeficiente[i];
        }
        else
        {
            resultado.coeficiente[i] = polinomio2.coeficiente[i];
        }
    }

    return resultado;
}

// 2.f

Polinomio mult(Polinomio polinomio1, Polinomio polinomio2)
{
	int gradoResultado = polinomio1.n + polinomio2.n;
    int i, j;

    Polinomio resultado;
    resultado.n = gradoResultado;
    resultado.coeficiente = malloc((gradoResultado + 1) * sizeof(double));

    for (i = 0; i <= gradoResultado; i++) {
        resultado.coeficiente[i] = 0.0;
    }
    
    for (i = 0; i <= polinomio1.n; i++) {
        for (j = 0; j <= polinomio2.n; j++) {
        	resultado.coeficiente[i + j] += polinomio1.coeficiente[i] * polinomio2.coeficiente[j];
        }
    }

    return resultado;
}

int main()
{
    /*int grado;
    printf("Ingrese el grado del polinomio: ");
    scanf("%d", &grado);

    Polinomio nuevoPolinomio = crearPolinomio(grado);

    printf("El polinomio ingresado es: ");
    imprimirPolinomio(nuevoPolinomio);
    */

    printf("2.b\n");

    Polinomio poli;
    poli.n = 4;
    // Asignar memoria para los coeficientes
    poli.coeficiente = (double *)malloc((poli.n + 1) * sizeof(double));

    // Asignar los valores de los coeficientes
    poli.coeficiente[0] = -7;  // Coeficiente del t�rmino constante
    poli.coeficiente[1] = 1;   // Coeficiente del t�rmino x
    poli.coeficiente[2] = -5;  // Coeficiente del t�rmino x^2
    poli.coeficiente[3] = 2.5; // Coeficiente del t�rmino x^3
    poli.coeficiente[4] = 3;   // Coeficiente del t�rmino x^4

    setCoef(7, 9, poli);

    printf("2.c \n");
    printf("el n_esimo coeficiente del Polinomio es %.2lf :\n", getCoef(poli.n, poli));

    printf("2.d \n");
    printf("resultado %.2lf :\n", especializa(2, poli));

    printf("2.e : suma de dos polinomios: \n");
    Polinomio poli2;
    poli2.n = 3;
    // Asignar memoria para los coeficientes
    poli2.coeficiente = (double *)malloc((poli2.n + 1) * sizeof(double));

    // Asignar los valores de los coeficientes
    poli2.coeficiente[0] = 6;
    poli2.coeficiente[1] = 3;
    poli2.coeficiente[2] = 2;
    poli2.coeficiente[3] = 4;
/*
    Polinomio poli3;
    poli3.n = 4;
    // Asignar memoria para los coeficientes
    poli3.coeficiente = (double *)malloc((poli3.n + 1) * sizeof(double));

    // Asignar los valores de los coeficientes
    poli3.coeficiente[0] = 0;
    poli3.coeficiente[1] = 3;
    poli3.coeficiente[2] = 0;
    poli3.coeficiente[3] = 0;
    poli3.coeficiente[4] = -4;*/

    Polinomio resultado = sum(poli, poli2);
    imprimirPolinomio(resultado);

    printf("2.f multiplicacion de dos polinomios: \n");
    printf("Polinomio 1: ");    
    imprimirPolinomio(poli);
    printf("Polinomio 2: ");
    imprimirPolinomio(poli2);
    
    resultado = mult(poli, poli2);
    imprimirPolinomio(resultado);

	printf("2.fffffff \n");
    // Liberar memoria asignada para los coeficientes
    free(poli.coeficiente);
    free(poli2.coeficiente);
    //free(poli3.coeficiente);

    return 0;
}
