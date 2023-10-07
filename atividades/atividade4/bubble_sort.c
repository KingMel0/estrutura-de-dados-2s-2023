#include "bubble_sort.h"

void bubbleSort(int array[], int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {

        for (int j = 0; j < tamanho - i - 1; j++) {
            
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
