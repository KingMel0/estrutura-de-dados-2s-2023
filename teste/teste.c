#include <stdio.h>

double calcular_double(double n){
    return n*2;
}

int main(int argc, char* argv[]){
    int n = 11;
    int n2 = 0;
    float f1 = 1.5;
    double d1 = 1.55555555;
    char letra = 'J';

    if(n2){
        printf("0 eh verdadeiro\n");
    }else{
        printf("N eh verdadeiro\n");
    }

    if(n){
        printf("-11 eh verdadeiro\n");
    }

    for(n = 0; n < 10; n++){
        printf("%d ", n);
    }

    printf("\n");
    n = 0;

    do{
        printf("%d ", n);
        n++;
    } while (n < 10);

    printf("O dobro de %f eh %f", d1, calcular_double(d1));

    return 0;
}