#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }

    int num[argc - 1];
    
    for (int i = 1; i < argc; i++) {
        num[i - 1] = atoi(argv[i]);
    }

    bubbleSort(num, argc - 1);

    printf("Saida:");

    for (int i = 0; i < argc - 1; i++) {
        printf(" %d", num[i]);
    }

    printf("\n");

    return 0;
}
