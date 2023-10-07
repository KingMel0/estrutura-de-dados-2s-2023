#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {

    Pilha* undoStack = criarPilha(10);

    printf("Adicionando tarefa 1...\n");
    empilhar(undoStack, 1);
    printf("Adicionando tarefa 2...\n");
    empilhar(undoStack, 2);

    printf("Desfazendo acao anterior...\n");
    int desfeito = desempilhar(undoStack);
    if (desfeito != -1) {
        printf("Acao desfeita: %d\n", desfeito);
    } else {
        printf("Sem acoes para desfazer.\n");
    }

    destruirPilha(undoStack);

    Fila* taskQueue = criarFila(10);

    printf("Adicionando tarefa de impressao...\n");
    enfileirar(taskQueue, 1);
    printf("Adicionando tarefa de digitalizacao...\n");
    enfileirar(taskQueue, 2);

    printf("Executando a proxima tarefa na fila...\n");
    int executado = desenfileirar(taskQueue);
    if (executado != -1) {
        printf("Tarefa finalizada: %d\n", executado);
    } else {
        printf("Sem tarefas na fila.\n");
    }

    destruirFila(taskQueue);

    return 0;
}
