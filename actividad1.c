#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strncpy

// creamos la estructura tiempo
typedef struct tiempo
{
    int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

// creamos la estructura archivo
typedef struct
{
    char *nombre;
    Tiempo ultima_mod;
} Archivo;

int compare(int tiempo1, int tiempo2)
{
    if (tiempo1 < tiempo2)
    {
        return 1;
    }
    else if (tiempo1 > tiempo2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int compara_tiempos(Tiempo t1, Tiempo t2)
{

    // metemos los tiempos en un array
    int tiemposA[6];
    int tiemposB[6];

    tiemposA[0] = t1.anio;
    tiemposA[1] = t1.mes;
    tiemposA[2] = t1.dia;
    tiemposA[3] = t1.hora;
    tiemposA[4] = t1.minuto;
    tiemposA[5] = t1.segundo;

    tiemposB[0] = t2.anio;
    tiemposB[1] = t2.mes;
    tiemposB[2] = t2.dia;
    tiemposB[3] = t2.hora;
    tiemposB[4] = t2.minuto;
    tiemposB[5] = t2.segundo;

    int ret = 0;
    int cont = 0;

    while (ret == 0 && cont < 6)
    {
        ret = compare(tiemposA[cont], tiemposB[cont]);
        cont = cont + 1;
    }
    return ret;
}

int imprime_tiempo(Tiempo t)
{
    printf("%d/%d/%d %d:%d:%d\n", t.anio, t.mes, t.dia, t.hora, t.minuto, t.segundo);
    return 0;
}

void ordena_alfa(Archivo *archivos, int n)
{
    char *archivosOrdenados[n];

    // se asigna memoria din�micamente para cada nombre en archivosOrdenados utilizando malloc y strlen.
    int i;
    for (i = 0; i < n; i++)
    {
        archivosOrdenados[i] = malloc(strlen(archivos[i].nombre) + 1);
    }
    // Utiliza la funci�n strcpy para copiar cada archivos[i].nombre al array archivosOrdenados.
    for (i = 0; i < n; i++)
    {
        strcpy(archivosOrdenados[i], archivos[i].nombre);
    }

    int j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(archivosOrdenados[i], archivosOrdenados[j]) > 0)
            {
                char *archivoTemp;
                archivoTemp = archivosOrdenados[i];
                archivosOrdenados[i] = archivosOrdenados[j];
                archivosOrdenados[j] = archivoTemp;
            }
        }
    };

    printf("");
    printf("\n Actividad 1.2.a Archivos ordenados alfabeticamente:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", archivosOrdenados[i]);
    };
}

void ordena_temporal(Archivo *archivos, int n)
{
    int i;
    int j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (compara_tiempos(archivos[i].ultima_mod, archivos[j].ultima_mod) > 0)
            {
                Archivo archivoTemp;
                archivoTemp = archivos[i];
                archivos[i] = archivos[j];
                archivos[j] = archivoTemp;
            }
        }
    }

    printf("");
    printf("\n Actividad 1.2.b Archivos ordenados por fecha:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", archivos[i].nombre);
    };
}

int main()
{
    // actividad 1.1
    // hardcodeamos los tiempos de pruebas
    Tiempo t1;
    t1.anio = 2022, t1.mes = 10, t1.dia = 30, t1.hora = 15, t1.minuto = 30, t1.segundo = 45;
    Tiempo t2;
    t2.anio = 2010;
    t2.mes = 12;
    t2.dia = 30;
    t2.hora = 15, t2.minuto = 30, t2.segundo = 45;

    int a = compara_tiempos(t1, t2);
    printf("resultado compara_tiempos: %d\n", a);

    // actividad 1.2
    imprime_tiempo(t1);

    // actividad 1.2.a
    //  hardcodeamos los datos
    Archivo archivo0;
    archivo0.nombre = "fotos",
    archivo0.ultima_mod.anio = 2017,
    archivo0.ultima_mod.mes = 10,
    archivo0.ultima_mod.dia = 30,
    archivo0.ultima_mod.hora = 15,
    archivo0.ultima_mod.minuto = 30,
    archivo0.ultima_mod.segundo = 45;

    Archivo archivo1;
    archivo1.nombre = "musica",
    archivo1.ultima_mod.anio = 2023,
    archivo1.ultima_mod.mes = 8,
    archivo1.ultima_mod.dia = 30,
    archivo1.ultima_mod.hora = 22,
    archivo1.ultima_mod.minuto = 30,
    archivo1.ultima_mod.segundo = 45;

    Archivo archivo2;
    archivo2.nombre = "documentos",
    archivo2.ultima_mod.anio = 2012,
    archivo2.ultima_mod.mes = 12,
    archivo2.ultima_mod.dia = 30,
    archivo2.ultima_mod.hora = 22,
    archivo2.ultima_mod.minuto = 30,
    archivo2.ultima_mod.segundo = 45;

    Archivo archivo3;
    archivo3.nombre = "escuela",
    archivo3.ultima_mod.anio = 2012,
    archivo3.ultima_mod.mes = 12,
    archivo3.ultima_mod.dia = 31,
    archivo3.ultima_mod.hora = 22,
    archivo3.ultima_mod.minuto = 30,
    archivo3.ultima_mod.segundo = 45;

    Archivo archivos[3];
    archivos[0] = archivo0;
    archivos[1] = archivo1;
    archivos[2] = archivo2;
    archivos[3] = archivo3;

    ordena_alfa(archivos, 4);

    ordena_temporal(archivos, 4);

    // actividad 1.2.b
    return 0;
}
