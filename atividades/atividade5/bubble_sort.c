#include "bubble_sort.h"
#include <string.h>

int contarPalavras(FILE *arquivo) {
    int contador = 0;
    char palavra[100]; // Supomos que as palavras tenham no máximo 100 caracteres

    while (fscanf(arquivo, "%s", palavra) != EOF) {
        contador++;
    }

    fseek(arquivo, 0, SEEK_SET); // Voltar ao início do arquivo
    return contador;
}

void lerPalavras(FILE *arquivo, char **palavras, int numero_palavras) {
    for (int i = 0; i < numero_palavras; i++) {
        fscanf(arquivo, "%s", palavras[i]);
    }
}

void bubbleSort(char **palavras, int numero_palavras) {
    for (int i = 0; i < numero_palavras - 1; i++) {
        for (int j = 0; j < numero_palavras - i - 1; j++) {
            if (strcmp(palavras[j], palavras[j + 1]) > 0) {
                // Troca as palavras
                char temp[100];
                strcpy(temp, palavras[j]);
                strcpy(palavras[j], palavras[j + 1]);
                strcpy(palavras[j + 1], temp);
            }
        }
    }
}

void escreverPalavras(FILE *arquivo, char **palavras, int numero_palavras) {
    for (int i = 0; i < numero_palavras; i++) {
        fprintf(arquivo, "%s\n", palavras[i]);
    }
}
