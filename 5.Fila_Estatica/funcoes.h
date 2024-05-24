#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTOS 10

struct fila
{
    int elementos [MAX_ELEMENTOS];
    int primeiro;
    int ultimo;
};

typedef struct fila fila;

fila *cria(){
    fila *f;
    f = malloc(sizeof(struct fila));
    if(!f) {
        perror(NULL);
        exit(1);
    }
    /*IMPORTANTE*/
    f->primeiro = 0;
    f->ultimo = 0;
    return f;
}

void enfileira(fila *f, int val){
    if((f->ultimo + 1 == f->primeiro) || (f->ultimo == MAX_ELEMENTOS-1 && f->primeiro == 0)){
        printf("Fila Cheia!\n");
    }
    else{
        f->elementos[f->ultimo] = val;
        f->ultimo += 1;
            if(f->ultimo ==  MAX_ELEMENTOS){
            f->ultimo = 0;
        }
    }
}

int desenfileira(fila *f){
    int r;
    if(f->primeiro == f->ultimo){
        printf("Fila Vazia!\n");
    }
    else{
        r = f->elementos[f->primeiro];
        f->primeiro += 1;
        if(f->primeiro == MAX_ELEMENTOS){
            f->primeiro = 0;
        }
    }
    return r;
}

int tamanho(fila *f){
    int t = f->ultimo - f->primeiro;
    if(t <= 0){
        t += MAX_ELEMENTOS;
    }
    return t;
}

void destroi(fila *f){
    free(f);
}