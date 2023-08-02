#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define VERTICES 10
#define ARISTAS 10

typedef int vertice;

typedef struct _ARISTA
{
    vertice u;
    vertice v;
    int costo;
} arista;

// Prototipo de funciones.
void ordenarAristas(arista aristas[]);
bool existe(int, int vertices[]);

int main()
{
    // Le asignamos valores a los vertices y al costo.
    arista arista1;
    arista1.costo = 6;
    arista1.u = 1;
    arista1.v = 2;
    arista arista2;
    arista2.costo = 5;
    arista2.u = 1;
    arista2.v = 4;
    arista arista3;
    arista3.costo = 5;
    arista3.u = 4;
    arista3.v = 3;
    arista arista4;
    arista4.costo = 5;
    arista4.u = 2;
    arista4.v = 3;
    arista arista5;
    arista5.costo = 3;
    arista5.u = 2;
    arista5.v = 5;
    arista arista6;
    arista6.costo = 6;
    arista6.u = 3;
    arista6.v = 5;
    arista arista7;
    arista7.costo = 6;
    arista7.u = 5;
    arista7.v = 6;
    arista arista8;
    arista8.costo = 4;
    arista8.u = 3;
    arista8.v = 6;
    arista arista9;
    arista9.costo = 2;
    arista9.u = 4;
    arista9.v = 6;
    arista arista10;
    arista10.costo = 1;
    arista10.u = 1;
    arista10.v = 3;

    printf("Arbol completo:\n");
    printf("\n");
    printf("costo| u Arista v\n");

    arista aristas[] = {arista1, arista2, arista3, arista4, arista5, arista6, arista7, arista8, arista9, arista10};
    int i;
    int lenghtAristas = sizeof(aristas) / sizeof(aristas[0]);
    for (i = 0; i < lenghtAristas; i++)
    {
        printf("  %d  | %d ------ %d \n", aristas[i].costo, aristas[i].u, aristas[i].v);
    }

    printf("\n");

    printf("Ordenamos las aristas de menor costo a mayor costo, osea de forma ascendente:\n");
    printf("\n");
    ordenarAristas(aristas);

    printf("costo| u Arista v\n");
    for (i = 0; i < ARISTAS; i++)
    {
        printf("  %d  | %d ------ %d \n", aristas[i].costo, aristas[i].u, aristas[i].v);
    }

    printf("\n");

    arista aristasResultante[10];
    aristasResultante[0] = aristas[0]; // Por defecto agregamos la arista de menor costo en 1er lugar.

    // Primero ponemos los dos vertices del arista menos costoso.
    int vertices[VERTICES] = {aristas[0].u, aristas[0].v};
    int x = 2;         // Contador de array vertices, la inicializamos en 2 porque ya se asignaron los dos primeros vertices de la arista menos costosa.
    int contArRes = 1; // Contador de array aristasResultante, la inicializamos en 1 porque ya fue añadida por defeco la arista de menor costo.
    int j;

    for (j = 0; j < lenghtAristas; j++)
    {
        // Condición: en aristasResultante agregamos el arista donde, unos de sus vertices no existe en la lista de vertices pero el otro si existe.
        if (existe(aristas[j].u, vertices) && !existe(aristas[j].v, vertices))
        {
            // ejemplo: aristas[j].u es 3 y dentro del vertices[] ya existe 1 y 3, entonces se agrega a vertices[], aristas[j].v que es 6 y no existe.
            vertices[x] = aristas[j].v; // Almacenamos en vertices a partir del indice 2 en adelante los vertices que cumplen la condicion.
            x++;                        // Incrementeamos la variable x una vez encontrado el vertice.

            aristasResultante[contArRes] = aristas[j]; // Almacenamos en arista resultante el resultado dado hasta el momento.
            contArRes++;
            j = 0;    // Reiniciamos la busqueda en todo el array de aristas nuevamente.
            continue; // Finaliza la iteración en curso, con j = 0 para que reinicien la busqueda.
        }
        else if (existe(aristas[j].v, vertices) && !existe(aristas[j].u, vertices)) // Si el vertice v de todas las aristas es igual a alguno de los vertices de todas las aristas y el otro vertice v no es igual.
        {

            vertices[x] = aristas[j].u; // Almacenamos en vertices a partir del indice 2 en adelante los vertices que cumplen la condicion.
            x++;

            aristasResultante[contArRes] = aristas[j];
            contArRes++;
            j = 0;    // Reiniciamos la busqueda en todo el array de aristas nuevamente.
            continue; // Finaliza la iteración en curso, con j = 0 para que reinicien la busqueda.
        }
    }

    printf("Arbol abarcador de costo minimo:\n");
    printf("\n");
    printf("costo| u Arista v\n");
    for (i = 0; i < contArRes; i++)
    {

        printf("  %d  | %d ------ %d \n", aristasResultante[i].costo, aristasResultante[i].u, aristasResultante[i].v);
    }
    return 0;
}

// Declaracion de funciones.
void ordenarAristas(arista *aristas)
{
    int i;
    int j;
    arista aristaTemp; // Arista temporal que se utiliza para ordenar.
    // Ordenamos aristas de menor peso a mayor, osea de forma ascendente.
    for (i = 0; i < ARISTAS; i++)
    {
        for (j = i + 1; j < ARISTAS; j++)
        {
            if (aristas[i].costo > aristas[j].costo)
            {
                aristaTemp = aristas[i];
                aristas[i] = aristas[j];
                aristas[j] = aristaTemp;
            }
        }
    }
}

bool existe(int n, int vertices[])
{
    int i;
    for (i = 0; i < VERTICES; i++)
    {
        if (vertices[i] == n)
        {
            return true;
        }
    }
    return false;
}