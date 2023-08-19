#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int v[10];
    v[0] = 1;

    int v1[3] ={5, 11, 3};

    printf("%d", sizeof(v1)/sizeof(int));

    for(int i = 0; int i < sizeof(v1)/sizeof(int); i++){
        v1[i] > v1[i+1];
    }

    return 0;

    }