/*Testando funcoes de Pilha Estatica*/

#include "funcoes.h"

int main(){
    pilha *pi = cria();
    for (int i = 0; i <10; i++){
        empilha(pi, i);
    }
    for (int i = 0; i <10; i++){
        printf("  %d  ", desempilha(pi));
    }
    printf("\n %d\n", tamanho(pi));
    destroi(pi);
    printf("  %d  ", desempilha(pi));
    return 0;
}