#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {

    Pilha* desfazerPilha = criarPilha(10);

    printf("Adicionando tarefa 1...\n");
    empilhar(desfazerPilha, 1);
    printf("Adicionando tarefa 2...\n");
    empilhar(desfazerPilha, 2);

    printf("Desfazendo acao anterior...\n");
    int desfeito = desempilhar(desfazerPilha);
    if (desfeito != -1) {
        printf("Acao desfeita: %d\n", desfeito);
    } else {
        printf("Sem acoes para desfazer.\n");
    }

    destruirPilha(desfazerPilha);

    Fila* enfileirarTarefa = criarFila(10);

    printf("Adicionando tarefa de impressao...\n");
    enfileirar(enfileirarTarefa, 1);
    printf("Adicionando tarefa de digitalizacao...\n");
    enfileirar(enfileirarTarefa, 2);

    printf("Executando a proxima tarefa na fila...\n");
    int executado = desenfileirar(enfileirarTarefa);
    if (executado != -1) {
        printf("Tarefa finalizada: %d\n", executado);
    } else {
        printf("Sem tarefas na fila.\n");
    }

    destruirFila(enfileirarTarefa);

    return 0;
}
