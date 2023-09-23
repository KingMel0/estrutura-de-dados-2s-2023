#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int arg, char* argv[]){

    Objeto o1;
    o1.valor = 'A';
    Objeto o2;
    o2.valor = 'B';

    Pilha* P = pilha();

    empilhar(&o1, P);
    empilhar(&o2, P);

    Objeto* o;

    do{
        o = desempilhar(P);
        if(o != NULL){
            printf("%c\n", o->valor);
        }
    }while(o != NULL);

    desempilhar(P);

    exit(0);
}