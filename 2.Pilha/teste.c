#include "funcoes_pilhas.h"

int main(){
    Pilha *pi = cria_pilha();
    insere_elemento(pi);
    insere_elemento(pi);
    insere_elemento(pi);
    consulta_pilha(pi);
    return 0;
}

