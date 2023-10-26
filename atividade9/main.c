#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]) {
    No* lista_nao_ordenada = NULL; 
    No* lista_ordenada = NULL;     

    FILE* arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[50]; 
    float valor;   

    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%f", &valor);

        lista_inserir_no(&lista_nao_ordenada, valor);
        lista_inserir_no_ordenado(&lista_ordenada, valor);
    }

    fclose(arquivo);

    lista_liberar(lista_nao_ordenada);
    lista_liberar(lista_ordenada);

    return 0;
}
