#include "ABB_funcoes.h"

int main(){
    //*arvore a
    noArv *a = arv_criavazia();
    a = abb_insere(a, 6);
    a = abb_insere(a, 4);
    a = abb_insere(a, 8);
    a = abb_insere(a, 2);
    a = abb_insere(a, 5);
    a = abb_insere(a, 1);
    a = abb_insere(a, 3);
    a = abb_insere(a, 7);
    a = abb_insere(a, 9);
    arv_imprime(a);
    noArv *busca = abb_busca(a, 7);
    printf("\n%d\n", busca->info);
    a = abb_retira(a, 4);
    arv_imprime(a);

    liberarArvore(a);
    return 0;
}