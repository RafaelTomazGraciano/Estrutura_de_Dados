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

int arv_vazia(noArv *a){
    return a == NULL;
}

void arv_imprime(noArv *a){
    if(!arv_vazia(a)){
        arv_imprime(a->esq); //mostra sae
        printf("%d  ", a->info); //mostra raiz
        arv_imprime(a->dir); //mostra sad
    }
}

noArv *abb_busca (noArv *r, int v){
    if(r == NULL){
        return NULL;
    }
    else if(r->info > v){
        return abb_busca(r->esq, v);
    }
    else if(r->info < v){
        return abb_busca(r->dir, v);
    }
    else{
        return r;
    }
}

noArv *abb_insere (noArv *a, int v){
    if(a == NULL){
        a = (noArv*) malloc(sizeof(noArv));
        a->info = v;
        a->esq = a->dir =  NULL;
    }
    else if(v < a->info){
        a->esq = abb_insere(a->esq, v);
    }
    else if (v > a->info){
        a->dir = abb_insere(a->dir, v);
    }
    return a;
}

noArv *abb_retira (noArv *r, int v){
    if(r == NULL){
        return NULL;
    }
    else if(r->info > v){
        r->esq = abb_retira(r->esq, v);
    }
    else if(r->info < v){
        r->dir = abb_retira(r->dir, v);
    }
    else{
        //no sem filhos
        if(r->esq == NULL && r->dir == NULL){
            free(r);
            r =  NULL;
        }
        //no so tem filho a direita 
        else if(r->esq == NULL){
            noArv *t = r;
            r = r->dir;
            free(t);
        }
        //no so tem filho a esquerda 
        else if(r->dir == NULL){
            noArv *t = r;
            r = r->esq;
            free(t);
        }
        //no so tem os dois filhos
        else{
            noArv *f = r->esq;
            while(f->dir != NULL){
                f = f->dir;
            }
            r->info = f->info; //troca as informacoes
            f->info = v;
            r->esq = abb_retira(r->esq, v);
        }
    }
    return r;
}

