#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* L, No* no){
    if(L != NULL){
        if(L->proximo_no == NULL){
            L->proximo_no = no;
        }
        else{
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L){
    if(L != NULL){
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L){
    if(L != NULL){
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L){
    if(L != NULL){
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc){
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L){
    if(L != NULL){
        lista_liberar(L->proximo_no);
        free(L);
    }
}

int lista_verificar_existencia(No* L, char valor_busca) {
    while (L != NULL) {
        if (L->valor == valor_busca) {
            return 1;
        }
        L = L->proximo_no;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    while (L != NULL) {
        if (L->valor == valor_busca) {
            ocorrencias++;
        }
        L = L->proximo_no;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L == NULL) {
        return;
    }
    lista_imprimir_inversa(L->proximo_no);
    printf("%c ", L->valor);
}

void lista_inserir_no_i(No* L, int i, char valor) {
    if (i == 0) {
        No* novo_no = no(valor, L->proximo_no);
        L->proximo_no = novo_no;
    } else {
        lista_inserir_no_i(L->proximo_no, i - 1, valor);
    }
}

void lista_remover_no_i(No* L, int i) {
    if (i == 0 && L->proximo_no != NULL) {
        No* no_removido = L->proximo_no;
        L->proximo_no = no_removido->proximo_no;
        free(no_removido);
    } else if (i > 0) {
        lista_remover_no_i(L->proximo_no, i - 1);
    }
}

void lista_remover_no(No* L, char valor_busca) {
    while (L->proximo_no != NULL) {
        if (L->proximo_no->valor == valor_busca) {
            No* no_removido = L->proximo_no;
            L->proximo_no = no_removido->proximo_no;
            free(no_removido);
        } else {
            L = L->proximo_no;
        }
    }
}
