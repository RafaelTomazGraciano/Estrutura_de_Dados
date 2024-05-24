/*Testando funcoes de Pilha Dinamica*/

#include "funcoes_pilhas.h"

int main(){
    Pilha *pi = cria_pilha();
    insere_elemento(pi, 10);
    insere_elemento(pi, 17);
    insere_elemento(pi, 22);
    consulta_pilha(pi);
    remove_elemento(pi);
    consulta_pilha(pi);
    esvazia_pilha(pi);
    consulta_pilha(pi);
    return 0;
}

