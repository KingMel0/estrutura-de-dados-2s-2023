#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_arquivo_entrada>\n", argv[0]);
        return 1;
    }

    const char *nome_arquivo_entrada = argv[1];
    const char *nome_arquivo_saida = "arq_palavras_ordenado.txt";

    FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada: %s\n", nome_arquivo_entrada);
        return 1;
    }

    FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída: %s\n", nome_arquivo_saida);
        fclose(arquivo_entrada);
        return 1;
    }

    // Contar o número de palavras no arquivo de entrada
    int numero_palavras = contarPalavras(arquivo_entrada);
    
    // Alocar memória para armazenar as palavras
    char **palavras = (char **)malloc(numero_palavras * sizeof(char *));
    for (int i = 0; i < numero_palavras; i++) {
        palavras[i] = (char *)malloc(100 * sizeof(char)); // Supomos que as palavras tenham no máximo 100 caracteres
    }

    // Ler as palavras do arquivo de entrada
    lerPalavras(arquivo_entrada, palavras, numero_palavras);
    
    // Ordenar as palavras
    bubbleSort(palavras, numero_palavras);

    // Escrever as palavras ordenadas no arquivo de saída
    escreverPalavras(arquivo_saida, palavras, numero_palavras);

    // Liberar a memória alocada
    for (int i = 0; i < numero_palavras; i++) {
        free(palavras[i]);
    }
    free(palavras);

    // Fechar os arquivos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Palavras ordenadas e gravadas em %s\n", nome_arquivo_saida);

    return 0;
}
