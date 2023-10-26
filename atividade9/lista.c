#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(float valor, No* proximo_no) {
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No** L, float valor) {
    while (*L != NULL) {
        L = &(*L)->proximo_no;
    }
    *L = no(valor, NULL);
}

void lista_inserir_no_ordenado(No** L, float valor) {
    while (*L != NULL && valor > (*L)->valor) {
        L = &(*L)->proximo_no;
    }
    *L = no(valor, *L);
}

void lista_imprimir(No* L) {
    if (L != NULL) {
        printf("%f ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L) {
    if (L != NULL) {
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L) {
    if (L != NULL) {
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc) {
    while (L->proximo_no != NULL) {
        L = L->proximo_no;
    }
    L->proximo_no = Lc;
}

void lista_liberar(No* L) {
    if (L != NULL) {
        lista_liberar(L->proximo_no);
        free(L);
    }
}
