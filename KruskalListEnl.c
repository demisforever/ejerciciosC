#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VERTICES 7
#define ARISTAS 11

typedef int vertice;

// Esrtuctura para representar la arista.
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
    int numVertices;               // Variable para representar el numero total de vertices.
    Arista *listaAristas[ARISTAS]; // Estructura anidada.
} Grafo;
// Prototipo de funciones.
void ordenarAristas(Arista *aristas[]);
bool existe(int, int vertices[]);
void armarArbol(Arista *aristasResultante[], int contArRes);
void aristasRelacionadas(int numIndiceArista, Arista *aristasResultante[]);
void agregarAristaAlGrafo(Grafo *grafo, int u, int v, int costo, int contArista);

int main()
{
    printf("Arbol completo:");
    printf("\n");

    Grafo *grafo1 = (Grafo *)malloc(sizeof(Grafo)); // Reservamos memoria dinamica para la estructura Grafo.

    grafo1->numVertices = VERTICES;
    grafo1->listaAristas[ARISTAS];
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
    agregarAristaAlGrafo(grafo1, 7, 6, 7, 10);

    printf("costo| u Arista v");

    int p;
    for (p = 0; p < ARISTAS; p++)
    {
        printf("  %d  | %d ------ %d \n", grafo1->listaAristas[p]->costo, grafo1->listaAristas[p]->u, grafo1->listaAristas[p]->v);
    }

    printf("\n");

    printf("Ordenamos las aristas de menor costo a mayor costo, osea de forma ascendente:");
    printf("\n");
    ordenarAristas(grafo1->listaAristas);

    printf("costo| u Arista v");
    for (p = 0; p < ARISTAS; p++)
    {
        printf("  %d  | %d ------ %d \n", grafo1->listaAristas[p]->costo, grafo1->listaAristas[p]->u, grafo1->listaAristas[p]->v);
    }

    printf("\n");

    Arista *aristasResultante[ARISTAS];             // Array para almacenar las aristas de menor peso.
    aristasResultante[0] = grafo1->listaAristas[0]; // Por defecto agregamos la arista de menor costo en 1er lugar.

    // Primero ponemos los dos vertices del arista menos costoso
    int vertices[VERTICES] = {grafo1->listaAristas[0]->u, grafo1->listaAristas[0]->v};
    int x = 2;         // Contador de array vertices, la inicializamos en 2 porque ya se asignaron los dos primeros vertices de la arista menos costosa.
    int contArRes = 1; // Contador de array aristasResultante, la inicializamos en 1 porque ya fue añadida por defeco la arista de menor costo
    int j;

    int lenghtAristas = sizeof(grafo1->listaAristas) / sizeof(grafo1->listaAristas[0]);
    for (j = 0; j < ARISTAS; j++)
    {
        // Condición: en aristasResultante agregamos la arista donde, unos de sus vertices no existe en la lista de vertices pero el otro si existe.
        if (existe(grafo1->listaAristas[j]->u, vertices) && !existe(grafo1->listaAristas[j]->v, vertices))
        {
            // Ejemplo: aristas[j].u es 3 y dentro del array vertices[] ya existe 1 y 3, entonces se agrega a vertices[], aristas[j].v que es 6 y no existe.
            vertices[x] = grafo1->listaAristas[j]->v; // Almacenamos en vertices a partir del indice 2 en adelante los vertices que cumplen la condicion.
            x++;                                      // Incrementeamos la variable x una vez encontrado el vertice.

            aristasResultante[contArRes] = grafo1->listaAristas[j]; // Almacenamos en arista resultante el resultado dado hasta el momento.
            contArRes++;
            j = 0;    // Reiniciamos la busqueda en todo el array de aristas nuevamente.
            continue; // Finaliza la iteración en curso, con j = 0 para que reinicien la busqueda.
        }
        else if (existe(grafo1->listaAristas[j]->v, vertices) && !existe(grafo1->listaAristas[j]->u, vertices)) // Si el vertice v de todas las aristas es igual a alguno de los vertices de todas las aristas y el otro vertice v no es igual.
        {

            vertices[x] = grafo1->listaAristas[j]->u; // Almacenamos en vertices a partir del indice 2 en adelante los vertices que cumplen la condicion.
            x++;

            aristasResultante[contArRes] = grafo1->listaAristas[j]; // Almacenamos en arista resultante el resultado dado hasta el momento.
            contArRes++;
            j = 0;    // Reiniciamos la busqueda en todo el array de aristas nuevamente.
            continue; // Finaliza la iteración en curso, con j = 0 para que reinicien la busqueda.
        }
    }

    armarArbol(aristasResultante, contArRes);

    printf("Arbol abarcador de costo minimo:");
    printf("\n");
    printf("costo| u Arista v | indice \n");
    for (p = 0; p < contArRes; p++)
    {
        printf("  %d  | %d ------ %d | %d  \n", aristasResultante[p]->costo, aristasResultante[p]->u, aristasResultante[p]->v, p);
    }

    int opcion = 0;
    while (opcion >= 0 && opcion <= 4)
    {
        printf("\n Seleccione una arista por su indice para ver aristas siguientes:\n");
        printf("persione cualquier otra tecla para salir\n");

        scanf(" %d", &opcion);
        aristasRelacionadas(opcion, aristasResultante);
    }
    
    // Liberamos la memoria.
    free(grafo1);
    grafo1 = NULL;

    return 0;
}

// Declaracion de funciones.
void agregarAristaAlGrafo(Grafo *grafo, int u, int v, int costo, int contArista)
{
    Arista *aristaTemp = (Arista *)malloc(sizeof(Arista));
    aristaTemp->costo = costo;
    aristaTemp->u = u;
    aristaTemp->v = v;
    // aristaTemp->siguiente = NULL;
    grafo->listaAristas[contArista] = aristaTemp;
}

void ordenarAristas(Arista *aristas[])
{
    int i;
    int j;
    Arista *aristaTemp;
    // Ordenamos aristas de menor peso a mayor, osea de forma ascendente.
    for (i = 0; i < ARISTAS; i++)
    {
        for (j = i + 1; j < ARISTAS; j++)
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
    int k;
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
                cont++;
            }
        }
        cont = 0;
    }
}

// metodo para visualizar los "hijos" (aristas siguientes) relacionadas a partir de una arista
void aristasRelacionadas(int numIndiceArista, Arista *aristasResultante[])
{
    printf("Arista seleccionada: \n");
    printf("  %d  | %d ------ %d \n", aristasResultante[numIndiceArista]->costo, aristasResultante[numIndiceArista]->u, aristasResultante[numIndiceArista]->v);
    int longitud = sizeof(aristasResultante[numIndiceArista]->siguiente) / sizeof(aristasResultante[numIndiceArista]->siguiente[0]);
    int i;

    printf("Siguientes:\n");
    for (i = 0; i < longitud; i++)
    {
        if (aristasResultante[numIndiceArista]->siguiente[i] != NULL)
        {
            printf("  %d  | %d ------ %d \n", aristasResultante[numIndiceArista]->siguiente[i]->costo, aristasResultante[numIndiceArista]->siguiente[i]->u, aristasResultante[numIndiceArista]->siguiente[i]->v);
        }
    }
}
