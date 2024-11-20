#include <stdio.h>
#include "avl_funcoes.h"



int main() {


    No *arvore = NULL;

    arvore = inserirNo(arvore, 50);
    arvore = inserirNo(arvore, 70);
    arvore = inserirNo(arvore, 40);
    arvore = inserirNo(arvore, 10);
    arvore = inserirNo(arvore, 60);
    arvore = inserirNo(arvore, 80);
    arvore = inserirNo(arvore, 5);
    arvore = inserirNo(arvore, 4);
    arvore = inserirNo(arvore, 3);
    arvore = inserirNo(arvore, 2);
    arvore = inserirNo(arvore, 1);

    imprimirArvore(arvore);
    
    liberarArvore(arvore);
    return 0;
}