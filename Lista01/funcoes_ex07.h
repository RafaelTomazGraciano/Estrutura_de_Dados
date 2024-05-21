#include <stdio.h>
#include <stdlib.h>


struct Elemento{
    int num;
    struct Elemento *prox;
};

typedef struct Elemento Elemento;

struct Pilha{
    Elemento *topo; // aponta para o elemento que etsá no topo da pilha
};

typedef struct Pilha Pilha;

struct Fila{
    Elemento *inicio;
    Elemento *fim;
};

typedef struct Fila Fila;


Pilha *cria_pilha(){
    //alocacao de ponteiro para controlar a pilha
    Pilha *pi = (Pilha *) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL; // a pilha  inicia_se vazia, portanto seu topo é igual a NULl
    }
    return pi;
}

//todo elemento sera inserido no topo da pilha
void insere_elemento_pilha(Pilha *pi, int val){
    //A cada insercao alocamos dinamicamente um espaço para um novo elemento
    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    novo->num = val;
    //Como o numero inserido sera o novo topo, ele apontara para o topo atual que sera
    novo->prox = pi->topo;
    //topo aponta para o endereco de novo
    pi->topo = novo;
}

void consulta_pilha(Pilha *pi){
    Elemento *aux;
    //caso a Pilha esteja vazia
    if(pi->topo == NULL){
        printf("\nPilha Vazia!\n");
    }
        //caso a Pilha não esteja vazia
    else{
        aux = pi->topo;
        while(aux != NULL){
            printf(" %d ", aux->num);
            aux = aux->prox;
        }
        printf("\n");
    }
}


Fila *cria_fila(){
    //alocacao do ponteiro fi para controlar a fila
    Fila *fi = (Fila *) malloc(sizeof(Fila));
    if(fi != NULL){
        //A fila inicia-se vazia, portanto inicio e fim são iguais a NULL
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void insere_elemento_fila_par(Fila *fi, Pilha *pi){
    Elemento *aux = pi->topo;
    while(aux != NULL){
        if(aux->num%2 == 0){
            // a cada inserção alocamos dinamicamente um espaço para um novo elemento
            Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
            novo->num = aux->num;
            novo->prox = NULL;
            //caso a fila esteja vazia, o elemento inserido será o primeriro e o último
            if(fi->inicio == NULL){
                fi->inicio = novo;
                fi->fim = novo;
            }
                //caso a fila já contenha algum elemento, o novo elemento será sempre inserido no fim da fila
            else{
                fi->fim->prox = novo;
                fi->fim = novo;
            }
        }
        aux = aux->prox;
    }
}

void insere_elemento_fila_impar(Fila *fi, Pilha *pi){
    Elemento *aux = pi->topo;
    while(aux != NULL){
        if(aux->num%2 == 1){
            // a cada inserção alocamos dinamicamente um espaço para um novo elemento
            Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
            novo->num = aux->num;
            novo->prox = NULL;
            //caso a fila esteja vazia, o elemento inserido será o primeriro e o último
            if(fi->inicio == NULL){
                fi->inicio = novo;
                fi->fim = novo;
            }
                //caso a fila já contenha algum elemento, o novo elemento será sempre inserido no fim da fila
            else{
                fi->fim->prox = novo;
                fi->fim = novo;
            }
        }
        aux = aux->prox;
    }
}

void consulta_fila(Fila *fi){
    Elemento *aux;
    if(fi->inicio == NULL){
        printf("\nFila Vazia!\n");
    }
    else{
        aux = fi->inicio;
        while(aux != NULL){
            printf(" %d ", aux->num);
            aux = aux->prox;
        }
    }
}