#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTOS 10

struct lista
{
    int elementos[MAX_ELEMENTOS];
    int ultimo;
};

typedef struct lista lista;

lista *cria(){
    lista *l;
    l = malloc(sizeof(struct lista));
    if(!l){
        perror(NULL);
        exit(1);
    }
    /*IMPORTANTE*/
    l->ultimo = 0;
    return l;
}

void insere_final(lista *l, int val){
    if(l->ultimo == MAX_ELEMENTOS){
        printf("lista cheia!\n");
    }
    else{
        l->elementos[l->ultimo] = val;
        l->ultimo += 1;
    }
}

void insere(lista *l, int val, int x){
    if(l->ultimo == MAX_ELEMENTOS){
        printf("lista cheia!\n");
    }
    else{
        for(int i = l->ultimo; i > x; i--){
            l->elementos[i] = l->elementos[i-1];
        }
        l->ultimo += 1;
        l->elementos[x] = val;
    }
}

void remover(lista *l, int pos){
    if(l->ultimo == 0){
        printf("lista vazia!\n");
    }
    else{
        l->elementos[pos] = 0;
    }
}

void remover_final(lista *l){
    if(l->ultimo == 0){
        printf("lista vazia!\n");
    }
    else{
        l->elementos[MAX_ELEMENTOS] = 0; 
    }
}

int recupera(lista *l, int pos){
    return l->elementos[pos];
}

int tamanho(lista *l){
    return l->ultimo;
}

void destroi(lista *l){
    free(l);
}