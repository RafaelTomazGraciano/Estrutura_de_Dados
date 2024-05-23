#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTOS 10

struct pilha{
    int elementos[MAX_ELEMENTOS];
    int topo;
};

typedef struct pilha pilha;

pilha *cria(){
    struct pilha *p;
    p = malloc(sizeof (pilha));
    if(!p) {
        perror(NULL);
        exit(1);
    }
    /*IMPORTANTE*/
    p->topo = 0;
    return p;
}

void empilha(struct pilha *p, int a){
    if(p->topo == MAX_ELEMENTOS){
        printf("pilha cheia");
        exit(1);
    }
    p->elementos[p->topo] = a;
    p->topo = p->topo + 1;
}

int desempilha(pilha *p){
    if(p->topo == 0){
        printf("Pilha Vazia");
        exit(1);
    }
    p->topo = p->topo-1;
    return p->elementos[p->topo];
}


int tamanho(pilha *p){
    return p->topo;
}

void destroi(pilha *p){
    free(p);
}