/*Testando funcoes de Fila Estatica*/

#include "funcoes.h"

int main(){
    fila *fi = cria();
    for(int i = 0; i < 9; i++){
        enfileira(fi, i);
    }
    for(int i = 0; i < 10; i++){
        printf("%d  ",desenfileira(fi));
    }
    printf("\n%d\n", tamanho(fi));
    destroi(fi);
    return 0;
}
