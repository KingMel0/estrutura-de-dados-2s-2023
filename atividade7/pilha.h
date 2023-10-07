#ifndef PILHA_H
#define PILHA_H

typedef struct Pilha {
    int* itens;
    int tamanho;
    int topo;
} Pilha;

Pilha* criarPilha(int tamanho);
void destruirPilha(Pilha* pilha);
int empilhar(Pilha* pilha, int elemento);
int desempilhar(Pilha* pilha);
int tamanhoPilha(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
int pilhaCheia(Pilha* pilha);


#endif