#include <stdio.h>

void multiplicaArray(const int array1[], const int array2[], int resultado[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        resultado[i] = array1[i] * array2[i];
    }
}

int main() {
    int array1[] = {5, 7, 3, 6};
    int array2[] = {5, 7, 4, 6};
    int tamanho = sizeof(array1) / sizeof(array1[0]);

    int resultado[tamanho];

    multiplicaArray(array1, array2, resultado, tamanho);

    printf("Resultado da multiplicacao: [");
    for (int i = 0; i < tamanho; ++i) {
        printf("%d", resultado[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
