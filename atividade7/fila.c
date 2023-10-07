#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criarFila(int tamanho) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->itens = (int*)malloc(sizeof(int) * tamanho);
    fila->tamanho = tamanho;
    fila->frente = -1;
    fila->tras = -1;
    return fila;
}

void destruirFila(Fila* fila) {
    free(fila->itens);
    free(fila);
}

int enfileirar(Fila* fila, int elemento) {
    if (filaCheia(fila))
        return 0; // Fila cheia
    if (filaVazia(fila))
        fila->frente = 0;
    fila->tras = (fila->tras + 1) % fila->tamanho;
    fila->itens[fila->tras] = elemento;
    return 1;
}

int desenfileirar(Fila* fila) {
    if (filaVazia(fila))
        return -1; // Fila vazia
    int elemento = fila->itens[fila->frente];
    if (fila->frente == fila->tras)
        fila->frente = fila->tras = -1;
    else
        fila->frente = (fila->frente + 1) % fila->tamanho;
    return elemento;
}

int tamanhoFila(Fila* fila) {
    if (filaVazia(fila))
        return 0;
    if (fila->tras >= fila->frente)
        return fila->tras - fila->frente + 1;
    else
        return fila->tamanho - fila->frente + fila->tras + 1;
}

int filaVazia(Fila* fila) {
    return fila->frente == -1;
}

int filaCheia(Fila* fila) {
    return (fila->tras + 1) % fila->tamanho == fila->frente;
}