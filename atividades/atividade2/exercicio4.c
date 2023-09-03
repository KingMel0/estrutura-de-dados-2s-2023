#include <stdio.h>

int contaIntNoArray(const int array[], int tamanho, int busca) {
    int contador = 0;

    for (int i = 0; i < tamanho; ++i) {
        if (array[i] == busca) {
            contador++;
        }
    }

    return contador;
}

int main() {
    int numeros[] = {5, 7, 9, 7, 7, 11, 6, 5};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int busca = 7;

    int quantidade = contaIntNoArray(numeros, tamanho, busca);

    printf("A quantidade de vezes que %d aparece no array eh: %d\n", busca, quantidade);

    return 0;
}
