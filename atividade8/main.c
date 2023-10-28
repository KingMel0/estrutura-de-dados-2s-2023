#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]) {

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    
    // NOVAS FUNÇÔES
    char valor_busca = 'X';
    printf("Existe '%c' na lista: %d\n", valor_busca, lista_verificar_existencia(n0, valor_busca));
    printf("Quantidade de ocorrencias de '%c': %d\n", valor_busca, lista_verificar_ocorrencias(n0, valor_busca));
    
    printf("Lista inversa: ");
    lista_imprimir_inversa(n0);
    
    int i = 3;
    char valor_inserir = 'M';
    lista_inserir_no_i(n0, i, valor_inserir);
    
    int indice_remover = 2;
    lista_remover_no_i(n0, indice_remover);
    
    char valor_remover = 'A';
    lista_remover_no(n0, valor_remover);
    
    printf("\nLista final: ");
    lista_imprimir(n0);
    
    lista_inverter(&lisa_nao_ordenada);

    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);



    return 0;
}
