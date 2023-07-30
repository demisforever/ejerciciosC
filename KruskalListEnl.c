#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define VERTICES 10

typedef int vertice;

typedef struct _ARISTA
{
    vertice u;
    vertice v;
    int costo;
    struct Arista *siguiente;
} Arista;

// Estructura para representar el grafo
typedef struct
{
    int numVertices;
    Arista *listaAristas[];
} Grafo;

// Prototipo de funciones.
void ordenarAristas(Arista aristas[]);
bool existe(int, int vertices[]);

void agregarAristaAlGrafo(Grafo *grafo, int u, int v, int costo, int contArista)
{
    //printf("  %d  | %d ------ %d \n", u, v, costo);

    Arista *aristaTemp = (Arista *)malloc(sizeof(Arista));
    aristaTemp->costo = costo;
    aristaTemp->u = u;
    aristaTemp->v = v;
    aristaTemp->siguiente = NULL;
    grafo->listaAristas[contArista] = aristaTemp;
    //free(aristaTemp); //libero memoria
}

int main()
{
    //printf("Arbol completo:\n");
    //printf("\n");
    //printf("costo| u Arista v\n");

    Grafo *grafo1 = (Grafo *)malloc(sizeof(Grafo));
    //grafo1->numVertices = 6;
    grafo1->listaAristas[10];
    //int contArista = 0;
    agregarAristaAlGrafo(grafo1, 1, 2, 6, 0);
    agregarAristaAlGrafo(grafo1, 1, 4, 5, 1);
    agregarAristaAlGrafo(grafo1, 4, 3, 5, 2);
    agregarAristaAlGrafo(grafo1, 2, 3, 5, 3);
    agregarAristaAlGrafo(grafo1, 2, 5, 3, 4);
    agregarAristaAlGrafo(grafo1, 3, 5, 6, 5);
    agregarAristaAlGrafo(grafo1, 5, 6, 6, 6);
    agregarAristaAlGrafo(grafo1, 3, 6, 4, 7);
    agregarAristaAlGrafo(grafo1, 4, 6, 2, 8);
    agregarAristaAlGrafo(grafo1, 1, 3, 1, 9);

    printf("costo| u Arista v\n");

    // Arista *aristas[] = grafo1->listaAristas; //{arista1, arista2, arista3, arista4, arista5, arista6, arista7, arista8, arista9, arista10};
    int i;
    // int lenghtAristas = sizeof(aristas) / sizeof(aristas[0]);
    for (i = 0; i < 10; i++)
    {
        printf("  %d  | %d ------ %d \n", grafo1->listaAristas[i]->costo, grafo1->listaAristas[i]->u, grafo1->listaAristas[i]->v);
    }

    printf("\n");

    printf("Ordenamos las aristas de menor costo a mayor costo, osea de forma ascendente:\n");
    printf("\n");
    // ordenarAristas(aristas);

    printf("costo| u Arista v\n");
    //for (i = 0; i < 10; i++)
    //{
        // printf("  %d  | %d ------ %d \n", aristas[i].costo, aristas[i].u, aristas[i].v);
    //}

    printf("\n");
    /*
        Arista *aristasResultante[10];
        aristasResultante[0] = aristas[0]; // Por defecto agregamos la arista de menor costo en 1er lugar.

        // Primero ponemos los dos vertices del arista menos costoso
        int vertices[VERTICES] = {aristas[0]->u, aristas[0]->v};
        int x = 2; // Contador de array vertices, la inicializamos en 2 porque ya se asignaron los dos primeros vertices de la arista menos costosa.
        int r = 1; // Contador de array aristasResultante, la inicializamos en 1 porque ya fue añadida por defeco la arista de menor costo
        int j;

        for (j = 0; j < lenghtAristas; j++)
        {
            // condición: en aristasResultante agregamos el arista donde, unos de sus vertices no existe en la lista de vertices pero el otro si existe.
            if (existe(aristas[j]->u, vertices) && !existe(aristas[j]->v, vertices))
            {
                // ejemplo: aristas[j].u es 3 y dentro del vertices[] ya existe 1 y 3, entonces se agrega a vertices[], aristas[j].v que es 6 y no existe.
                vertices[x] = aristas[j]->v; // Almacenamos en vertices a partir del indice 2 en adelante los vertices que cumplen la condicion.
                x++;                         // Incrementeamos la variable x una vez encontrado el vertice.

                aristasResultante[r] = aristas[j]; // Almacenamos en arista resultante el resultado dado hasta el momento.
                r++;
                j = 0;    // reiniciamos la busqueda en todo el array de aristas nuevamente
                continue; // finaliza la iteración en curso, con j = 0 para que reinicien la busqueda
            }
            else if (existe(aristas[j]->v, vertices) && !existe(aristas[j]->u, vertices)) // Si el vertice v de todas las aristas es igual a alguno de los vertices de todas las aristas y el otro vertice v no es igual.
            {

                vertices[x] = aristas[j]->u; // Almacenamos en vertices a partir del indice 2 en adelante los vertices que cumplen la condicion.
                x++;

                aristasResultante[r] = aristas[j];
                r++;
                j = 0;    // reiniciamos la busqueda en todo el array de aristas nuevamente
                continue; // finaliza la iteración en curso, con j = 0 para que reinicien la busqueda
            }
        }

        int tam_final = r; // r contiene la cantidad de aristas agregadas al árbol abarcador

        printf("Arbol abarcador de costo minimo:\n");
        printf("\n");
        printf("costo| u Arista v\n");
        for (i = 0; i < tam_final; i++)
        {

            printf("  %d  | %d ------ %d \n", aristasResultante[i]->costo, aristasResultante[i]->u, aristasResultante[i]->v);
        }*/
    return 0;
}

// Declaracion de funciones.
void ordenarAristas(Arista *aristas)
{
    int i;
    int j;
    Arista aristaTemp; // Arista temporal que se utiliza para ordenar.
    // Ordenamos aristas de menor peso a mayor, osea de forma ascendente.
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
