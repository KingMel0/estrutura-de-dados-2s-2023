#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha(int tamanho) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->itens = (int*)malloc(sizeof(int) * tamanho);
    pilha->tamanho = tamanho;
    pilha->topo = -1;
    return pilha;
}

void destruirPilha(Pilha* pilha) {
    free(pilha->itens);
    free(pilha);
}

int empilhar(Pilha* pilha, int elemento) {
    if (pilhaCheia(pilha))
        return 0; // Pilha cheia
    pilha->topo++;
    pilha->itens[pilha->topo] = elemento;
    return 1;
}

int desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha))
        return -1; // Pilha vazia
    int elemento = pilha->itens[pilha->topo];
    pilha->topo--;
    return elemento;
}

int tamanhoPilha(Pilha* pilha) {
    return pilha->topo + 1;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}


int pilhaCheia(Pilha* pilha) {
    return pilha->topo == pilha->tamanho - 1;
}
