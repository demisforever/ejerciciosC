#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define MONTO_MAX 80

// Prototipo de funciones
void precio_uni_compra();

int main()
{
    precio_uni_compra();
    return 0;
}

// Declaracion de funciones
void precio_uni_compra()
{
	int i;
    // Productos a ofrecer
    char productos[][100] = {"jabon", "shampoo", "cepillo", "dentrifico", "hisopo"};

    // Precios unitarios de los productos
    float precios[5] = {10.99, 5.99, 8.99, 3.99, 12.99};

    // Cantidad de productos a comprar
    int cantidades[5]; // = {3, 5, 12, 3, 2};

    int numProductos = sizeof(productos) / sizeof(productos[0]);
    for (i = 0; i < numProductos; i++)
    {
        printf("Ingrese la cantidad de %s %.2f a comprar: ", productos[i], precios[i]);
        scanf("%d", &cantidades[i]);
        if (cantidades[i] < 0)
        {
            printf("Por favor, ingrese valores positivos.\n");
            i--;
        }
    }
    
    for (i = 0; i < 5; i++)
    {
        if (cantidades[i] == 0)
        {
            printf("El usuario no compro %s\n", productos[i]);
        }
    }
    
	float suma_costo_total = 0;
    for (i = 0; i < 5; i++)
    {    	
        if (cantidades[i] > 10)
        {
        	printf("se aplica 8por desc al producto %s por comprar %d : %.2f \n", productos[i], cantidades[i], cantidades[i] * precios[i]);  
        	printf("queda en : %.2f \n",  (cantidades[i] * precios[i])*0.92);  
        	precios[i] = precios[i] * 0.92;
        }
    	suma_costo_total += cantidades[i] * precios[i];
    }
    
    printf("costo total de todo %.2f \n", suma_costo_total);
    if (suma_costo_total > MONTO_MAX) {
    	printf("el monto es de %.2f, supero %d se aplica el 15porc de descuento \n", suma_costo_total, MONTO_MAX );
    	suma_costo_total = suma_costo_total *0.85;
    	printf("suma del monto total: %.2f \n", suma_costo_total );
	}
}

