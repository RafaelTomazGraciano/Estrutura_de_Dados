/*Testando funcoes de Lista Estatica*/

#include "funcoes.h"

int main(){
    lista *l = cria();
    insere_final(l, 10);
    remover(l, 5);
    remover_final(l);
    printf("%d\n", recupera(l, 0));
    printf("%d\n", tamanho(l));
    destroi(l);
    return 0;
}