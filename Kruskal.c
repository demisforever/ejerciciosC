#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int tipo_nombre;
typedef int tipo_elemento;
typedef int vertice;

#define VERTICES 10

typedef struct _ARISTA
{
    vertice u;
    vertice v;
    int costo;
} arista;

void ordenarAristas(arista aristas[])
{
    int i;
    int j;
    arista aristaTemp;
    // ordenamos aristas de menor peso a mayor
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
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
    for (i = 0; i < 10; i++)
    {
        if (vertices[i] == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
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

    printf("Arbol completo: \n");
    printf("costo| v Arista v \n");

    arista aristas[10] = {arista1, arista2, arista3, arista4, arista5, arista6, arista7, arista8, arista9, arista10};
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d    | %d ------- %d \n", aristas[i].costo, aristas[i].u, aristas[i].v);
    }

    printf("\n");

    int lenghtAristas = sizeof(aristas) / sizeof(aristas[0]);

    printf("se ordenan las aristas de menor costo a mayor costo \n");
    ordenarAristas(aristas);

    printf("costo| v Arista v \n");
    for (i = 0; i < 10; i++)
    {
        printf("%d    | %d ------- %d \n", aristas[i].costo, aristas[i].u, aristas[i].v);
    }

    printf("\n");

    arista aristasResultante[10];
    aristasResultante[0] = aristas[0];// por defecto agregamos el arista de menor costo en 1er lugar

    // primero ponemos los dos vertices del arista menos costoso
    int vertices[VERTICES] = {aristas[0].u, aristas[0].v, 0, 0, 0, 0, 0, 0, 0, 0};
    int x = 2; // contador de array vertices
    int r = 1; // contador de array aristasResultante
    int j;

    for (j = 0; j < lenghtAristas; j++)
    {
        if (existe(aristas[j].u, vertices) && !existe(aristas[j].v, vertices))
        {
            vertices[x] = aristas[j].v;
            x++;

            aristasResultante[r] = aristas[j];
            r++;
            j = 0;
            continue;
        }
        else if (existe(aristas[j].v, vertices) && !existe(aristas[j].u, vertices))
        {

            vertices[x] = aristas[j].u;
            x++;

            aristasResultante[r] = aristas[j];
            r++;
            j = 0;
            continue;
        }
    }

    printf("Mostramos las aristas resultantes: Arbol de menor costo: \n");

    printf("costo| v Arista v \n");
    for (i = 0; i < 6; i++)
    {

        printf("%d    | %d ------- %d \n", aristasResultante[i].costo, aristasResultante[i].u, aristasResultante[i].v);
    }
    return 0;
}
