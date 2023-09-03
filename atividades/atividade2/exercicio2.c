#include <stdio.h>

void menorMaiorArray(int array[], int tamanho, int *menor, int *maior) {
    if (tamanho <= 0) {
        *menor = 0;
        *maior = 0;
        return; 
    }

    *menor = array[0];
    *maior = array[0];

    for (int i = 1; i < tamanho; ++i) {
        if (array[i] < *menor) {
            *menor = array[i];
        } else if (array[i] > *maior) {
            *maior = array[i];
        }
    }
}

int main() {
    int numeros[] = {5, 7, 9, 6};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int menor, maior;
    
    menorMaiorArray(numeros, tamanho, &menor, &maior);
    
    printf("Menor elemento: %d\n", menor);
    printf("Maior elemento: %d\n", maior);
    
    return 0;
}
