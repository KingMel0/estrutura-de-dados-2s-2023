#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    float y;
} Ponto;

int contarLinhas(FILE *arquivo) {
    int contador = 0;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
    }

    rewind(arquivo); 
    return contador;
}

int lerPontos(FILE *arquivo, Ponto *pontos, int numPontos) {
    char linha[100];
    int i = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ",");
        pontos[i].x = atoi(token);
        token = strtok(NULL, ",");
        pontos[i].y = atof(token);
        i++;
    }

    return i; // Retorna o número de pontos lidos
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo.csv\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");

    if (arquivo == NULL) {
        printf("N foi possivel abrir o arquivo %s.\n", argv[1]);
        return 1;
    }

    int numPontos = contarLinhas(arquivo);
    Ponto *pontos = (Ponto *)malloc(numPontos * sizeof(Ponto));

    if (pontos == NULL) {
        printf("Erro de alocacao de memoria.\n");
        fclose(arquivo);
        return 1;
    }

    int numPontosLidos = lerPontos(arquivo, pontos, numPontos);
    fclose(arquivo);

    if (numPontosLidos != numPontos) {
        printf("Erro na leitura dos pontos.\n");
        free(pontos);
        return 1;
    }

    int somaX = 0;
    float somaY = 0.0;

    for (int i = 0; i < numPontos; i++) {
        somaX += pontos[i].x;
        somaY += pontos[i].y;
    }

    float mediaX = (float)somaX / numPontos;
    float mediaY = somaY / numPontos;

    float somaXY = 0.0;
    float somaX2 = 0.0;

    for (int i = 0; i < numPontos; i++) {
        somaXY += (pontos[i].x - mediaX) * (pontos[i].y - mediaY);
        somaX2 += (pontos[i].x - mediaX) * (pontos[i].x - mediaX);
    }

    float coeficienteAngular = somaXY / somaX2;
    float coeficienteLinear = mediaY - coeficienteAngular * mediaX;

    printf("Resultado da equacao da regressao linear: y = %.2fx + %.2f\n", coeficienteAngular, coeficienteLinear);

    free(pontos);
    return 0;
}
