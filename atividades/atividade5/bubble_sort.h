#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdio.h>

int contarPalavras(FILE *arquivo);
void lerPalavras(FILE *arquivo, char **palavras, int numero_palavras);
void bubbleSort(char **palavras, int numero_palavras);
void escreverPalavras(FILE *arquivo, char **palavras, int numero_palavras);

#endif
