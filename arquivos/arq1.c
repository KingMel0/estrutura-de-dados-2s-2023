#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cpf;
    char nome[100];
    char data_nascimento[100];
} Pessoa;

int main(int argc, char* argv[]){

    FILE *f;

    f = fopen("teste.dat", "wb");
    if(f == NULL){
        perror("Nao foi possivel abrir o arquivo");
        exit(1);
    }

    Pesoa p;
    p.cpf = 07890132158;
    strcpy(p.nome, "Marco");
    
    strcpy(p.data_nascimento, "06/01/2003");

    fwrite(&p, sizeof(Pessoa), 1, f);

    fclose(f);
    exit(0);

}