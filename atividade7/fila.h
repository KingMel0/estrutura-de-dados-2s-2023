#ifndef FILA_H
#define FILA_H

// Definição da estrutura da Fila (pode ser int, string, ou uma estrutura personalizada)
typedef struct Fila {
    int* itens;
    int tamanho;
    int frente;
    int tras;
} Fila;

Fila* criarFila(int tamanho);
void destruirFila(Fila* fila);
int enfileirar(Fila* fila, int elemento);
int desenfileirar(Fila* fila);
int tamanhoFila(Fila* fila);
int filaVazia(Fila* fila);
int filaCheia(Fila* fila);


#endif