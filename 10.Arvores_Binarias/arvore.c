#include "arvore.h"

int main(){
    // sub-arvore 'd'
    noArv *a1 = arv_cria('d', arv_criavazia(), arv_criavazia());
    // sub-arvore 'b'
    noArv *a2 = arv_cria('b', arv_criavazia(), a1);
    //sub-arvore 'e'
    noArv *a3 = arv_cria('e', arv_criavazia(),arv_criavazia());
    //sub-arvore 'f'
    noArv *a4 = arv_cria('f', arv_criavazia(), arv_criavazia());
    //sub-arvore 'c'
    noArv *a5 = arv_cria('c', a3, a4);
    //*arvore a
    noArv *a = arv_cria('a', a2,a5);
    arv_imprime(a);
    liberarArvore(a);
    return 0;
}