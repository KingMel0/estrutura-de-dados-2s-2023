#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {

    Pilha* Pilha = criarPilha(10);

    printf("Adicionando tarefa 1...\n");
    empilhar(Pilha, 1);
    printf("Adicionando tarefa 2...\n");
    empilhar(Pilha, 2);

    printf("Desfazendo acao anterior...\n");
    int desfeito = desempilhar(Pilha);
    if (desfeito != -1) {
        printf("Acao desfeita: %d\n", desfeito);
    } else {
        printf("Sem acoes para desfazer.\n");
    }

    destruirPilha(Pilha);

    Fila* Fila = criarFila(10);

    printf("Adicionando tarefa de impressao...\n");
    enfileirar(Fila, 1);
    printf("Adicionando tarefa de digitalizacao...\n");
    enfileirar(Fila, 2);

    printf("Executando a proxima tarefa na fila...\n");
    int executado = desenfileirar(Fila);
    if (executado != -1) {
        printf("Tarefa finalizada: %d\n", executado);
    } else {
        printf("Sem tarefas na fila.\n");
    }

    destruirFila(Fila);

    return 0;
}
