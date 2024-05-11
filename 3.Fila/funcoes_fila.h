#include <stdio.h>
#include <stdlib.h>

//regisro que representara cada elemento da fila
struct Elemento{
    int num;
    struct Elemento *prox;
};

typedef struct Elemento Elemento;

struct Fila{
    Elemento *inicio;
    Elemento *fim;
};

typedef struct Fila Fila;

//Ponteiro auxiliar
Elemento *aux;

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

void insere_elemento(Fila *fi){
    // a cada inserção alocamos dinamicamente um espaço para um novo elemento
    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    printf("Digite o numero a ser insrido na fila: ");
    scanf("%d", &novo->num);
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
    printf("\nNumero inserido na fila!\n");
}

void consulta_fila(Fila *fi){
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

void remove_elemento(Fila *fi){
    if(fi->inicio == NULL){
        printf("\nFila Vazia!\n");
    }
    else{
        aux = fi->inicio;
        printf("\n%d removido!\n", fi->inicio->num);
        fi->inicio = fi->inicio->prox;
        free(aux);
    }
}

void esvazis_fila(Fila *fi){
    if(fi->inicio =NULL){
        printf("\nFila Vazia!\n");
    }
    else{
        aux = fi->inicio;
        while(aux != NULL){
            fi->inicio = fi->inicio->prox;
            free(aux);
            aux = fi->inicio;
        }
        printf("\nFila esvaziada!\n");
    }
}
