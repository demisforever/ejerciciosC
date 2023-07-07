#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char sign;
    unsigned char num_bytes;
    unsigned char* bytes;
} APint;

APint sumarAPint(APint num1, APint num2) {
    APint resultado;
    resultado.sign = '+';
    resultado.num_bytes = (num1.num_bytes > num2.num_bytes) ? num1.num_bytes : num2.num_bytes;
    resultado.bytes = (unsigned char*)malloc(resultado.num_bytes * sizeof(unsigned char));

    int i;
    unsigned char carry = 0;

    for (i = 0; i < resultado.num_bytes; i++) {
        unsigned char byte1 = (i < num1.num_bytes) ? num1.bytes[i] : 0;
        unsigned char byte2 = (i < num2.num_bytes) ? num2.bytes[i] : 0;

        unsigned char sum = byte1 + byte2 + carry;
        resultado.bytes[i] = sum % 256;
        carry = sum / 256;
    }

    if (carry > 0) {
        resultado.num_bytes++;
        resultado.bytes = (unsigned char*)realloc(resultado.bytes, resultado.num_bytes * sizeof(unsigned char));
        resultado.bytes[resultado.num_bytes - 1] = carry;
    }

    return resultado;
}

void imprimirAPint(APint num) {
    int i;
    printf("Signo: %c\n", num.sign);
    printf("Numero de bytes: %u\n", num.num_bytes);
    printf("Bytes: ");
    for (i = 0; i < num.num_bytes; i++) {
        printf("%u ", num.bytes[i]);
    }
    printf("\n");
}

void liberarAPint(APint num) {
    free(num.bytes);
}

int main() {
    APint num1;
    num1.sign = '+';
    num1.num_bytes = 3;
    num1.bytes = (unsigned char*)malloc(3 * sizeof(unsigned char));
    num1.bytes[0] = 255;
    num1.bytes[1] = 1;
    num1.bytes[2] = 2;

    APint num2;
    num2.sign = '+';
    num2.num_bytes = 2;
    num2.bytes = (unsigned char*)malloc(2 * sizeof(unsigned char));
    num2.bytes[0] = 3;
    num2.bytes[1] = 4;

    printf("Numero 1:\n");
    imprimirAPint(num1);

    printf("Numero 2:\n");
    imprimirAPint(num2);

    APint suma = sumarAPint(num1, num2);

    printf("Resultado de la suma:\n");
    imprimirAPint(suma);

    liberarAPint(num1);
    liberarAPint(num2);
    liberarAPint(suma);

    return 0;
}

