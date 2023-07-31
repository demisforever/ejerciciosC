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
    struct _ARISTA *siguiente[10];
} Arista;

// Estructura para representar el grafo
typedef struct
{
    int numVertices;
    Arista *listaAristas[10];
} Grafo;
// Prototipo de funciones.
void ordenarAristas(Arista *aristas[]);
bool existe(int, int vertices[]);
void armarArbol(Arista *aristasResultante[], int contArRes);
void aristasRelacionadas(int numIndiceArista, Arista *aristasResultante[]);

void agregarAristaAlGrafo(Grafo *grafo, int u, int v, int costo, int contArista)
{
    Arista *aristaTemp = (Arista *)malloc(sizeof(Arista));
    aristaTemp->costo = costo;
    aristaTemp->u = u;
    aristaTemp->v = v;
    aristaTemp->siguiente[0] = NULL;
    grafo->listaAristas[contArista] = aristaTemp;
}

int main()
{
    printf("Arbol completo:\n");
    printf("\n");

    Grafo *grafo1 = (Grafo *)malloc(sizeof(Grafo));
    grafo1->numVertices = 6;
    grafo1->listaAristas[10];
    // int contArista = 0;
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

    int p;
    // int lenghtAristas = sizeof(aristas) / sizeof(aristas[0]);
    for (p = 0; p < 10; p++)
    {
        printf("  %d  | %d ------ %d \n", grafo1->listaAristas[p]->costo, grafo1->listaAristas[p]->u, grafo1->listaAristas[p]->v);
    }

    printf("\n");

    printf("Ordenamos las aristas de menor costo a mayor costo, osea de forma ascendente:\n");
    printf("\n");
    ordenarAristas(grafo1->listaAristas);

    printf("costo| u Arista v\n");
    for (p = 0; p < 9; p++)
    {
        printf("  %d  | %d ------ %d \n", grafo1->listaAristas[p]->costo, grafo1->listaAristas[p]->u, grafo1->listaAristas[p]->v);
    }

    printf("\n");

    Arista *aristasResultante[10];
    aristasResultante[0] = grafo1->listaAristas[0]; // Por defecto agregamos la arista de menor costo en 1er lugar.

    // Primero ponemos los dos vertices del arista menos costoso
    int vertices[VERTICES] = {grafo1->listaAristas[0]->u, grafo1->listaAristas[0]->v};
    int x = 2;         // Contador de array vertices, la inicializamos en 2 porque ya se asignaron los dos primeros vertices de la arista menos costosa.
    int contArRes = 1; // Contador de array aristasResultante, la inicializamos en 1 porque ya fue añadida por defeco la arista de menor costo
    int j;

    int lenghtAristas = sizeof(grafo1->listaAristas) / sizeof(grafo1->listaAristas[0]);
    for (j = 0; j < 10; j++)
    {
        // condición: en aristasResultante agregamos el arista donde, unos de sus vertices no existe en la lista de vertices pero el otro si existe.
        if (existe(grafo1->listaAristas[j]->u, vertices) && !existe(grafo1->listaAristas[j]->v, vertices))
        {
            // ejemplo: aristas[j].u es 3 y dentro del vertices[] ya existe 1 y 3, entonces se agrega a vertices[], aristas[j].v que es 6 y no existe.
            vertices[x] = grafo1->listaAristas[j]->v; // Almacenamos en vertices a partir del indice 2 en adelante los vertices que cumplen la condicion.
            x++;                                      // Incrementeamos la variable x una vez encontrado el vertice.

            aristasResultante[contArRes] = grafo1->listaAristas[j]; // Almacenamos en arista resultante el resultado dado hasta el momento.
            contArRes++;
            j = 0;    // reiniciamos la busqueda en todo el array de aristas nuevamente
            continue; // finaliza la iteración en curso, con j = 0 para que reinicien la busqueda
        }
        else if (existe(grafo1->listaAristas[j]->v, vertices) && !existe(grafo1->listaAristas[j]->u, vertices)) // Si el vertice v de todas las aristas es igual a alguno de los vertices de todas las aristas y el otro vertice v no es igual.
        {

            vertices[x] = grafo1->listaAristas[j]->u; // Almacenamos en vertices a partir del indice 2 en adelante los vertices que cumplen la condicion.
            x++;

            aristasResultante[contArRes] = grafo1->listaAristas[j];
            contArRes++;
            j = 0;    // reiniciamos la busqueda en todo el array de aristas nuevamente
            continue; // finaliza la iteración en curso, con j = 0 para que reinicien la busqueda
        }
    }

    armarArbol(aristasResultante, contArRes);

    printf("Arbol abarcador de costo minimo:\n");
    printf("\n");
    printf("costo| u Arista v\n");
    for (p = 0; p < contArRes; p++)
    {
        printf("  %d  | %d ------ %d \n", aristasResultante[p]->costo, aristasResultante[p]->u, aristasResultante[p]->v);
    }

    aristasRelacionadas(2, aristasResultante);

    return 0;
}

// Declaracion de funciones.
void ordenarAristas(Arista *aristas[])
{
    int i;
    int j;
    Arista *aristaTemp;
    // Ordenamos aristas de menor peso a mayor, osea de forma ascendente.
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (aristas[i]->costo > aristas[j]->costo)
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

// usamos la lista enlasada de Arista para armar la unión del grafo
void armarArbol(Arista *aristasResultante[], int contArRes)
{
    int i;
    int j;
    int cont = 0;
    Arista *aristaTemp;

    for (i = 0; i < contArRes; i++)
    {
        for (j = 0; j < contArRes - 1; j++)
        {
            if (i == j)
            {
                j++; // desfasamos i y j para que un arista no sea "hija" de si misma
            }

            if (aristasResultante[i]->u == aristasResultante[j]->u || aristasResultante[i]->u == aristasResultante[j]->v || aristasResultante[i]->v == aristasResultante[j]->u || aristasResultante[i]->v == aristasResultante[j]->v)
            {
                aristasResultante[i]->siguiente[cont] = aristasResultante[j];
            }
            else
            {
                aristasResultante[i]->siguiente[cont] = NULL;
            }
            cont++;
        }
        cont = 0;
    }
}

// metodo para visualizar los "hijos" (aristas siguientes) relacionadas a partir de una arista
void aristasRelacionadas(int numIndiceArista, Arista *aristasResultante[])
{
    printf("\n");
    printf("costo| u Arista v\n");
    printf("  %d  | %d ------ %d \n", aristasResultante[numIndiceArista]->costo, aristasResultante[numIndiceArista]->u, aristasResultante[numIndiceArista]->v);
    printf("\n");
    int longitud = sizeof(aristasResultante[numIndiceArista]->siguiente) / sizeof(aristasResultante[numIndiceArista]->siguiente[0]);
    int i;
    for (i = 0; i < longitud; i++)
    {
        printf("  %d  | %d ------ %d \n", aristasResultante[numIndiceArista]->siguiente[i]->costo, aristasResultante[numIndiceArista]->siguiente[i]->u, aristasResultante[numIndiceArista]->siguiente[i]->v);
    }
}
