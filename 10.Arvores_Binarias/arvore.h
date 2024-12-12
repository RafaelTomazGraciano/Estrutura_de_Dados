#include <stdio.h>
#include <stdlib.h>

struct noArv{
    char info;
    struct noArv *esq;
    struct noArv *dir;
};

typedef struct noArv noArv;

noArv *arv_criavazia(){
    return NULL;
}

noArv *arv_cria (char c, noArv *sae, noArv *sad){
    noArv *p = (noArv *) malloc(sizeof(noArv));
    if(p == NULL){
        exit(1);
    } 
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p; 
}

int arv_vazia(noArv *a){
    return a == NULL;
}

noArv * arv_libera(noArv *a){
    if(!arv_vazia(a)){
        arv_libera(a->esq); //libera sae
        arv_libera(a->dir); //libera sad
        free(a); // libera raiz
    }
    return NULL;
}

int arv_pertence (noArv *a, char c){
    if(arv_vazia(a)){
        return 0;   //arvore vazia
    }
    return  a->info == c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c);
}

void arv_imprime(noArv *a){
    if(!arv_vazia(a)){
        printf("%c  ", a->info); //mostra raiz
        arv_imprime(a->esq); //mostra sae
        arv_imprime(a->dir); //mostra sad
    }
}