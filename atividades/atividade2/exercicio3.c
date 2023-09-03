#include <stdio.h>
#include <string.h>

int buscaString(const char *array[], int tamanho, const char *busca) {
    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(array[i], busca) == 0) {
            return 1; 
        }
    }
    
    return 0; 
}

int main() {
    const char *strings[] = {"texto", "J", "EDA"};
    int tamanho = sizeof(strings) / sizeof(strings[0]);
    const char *busca = "EDO";
    
    int resultado = buscaString(strings, tamanho, busca);
    
    if (resultado == 1) {
        printf("A string de busca existe no array.\n");
    } else {
        printf("A string de busca nao existe no array.\n");
    }
    
    return 0;
}
