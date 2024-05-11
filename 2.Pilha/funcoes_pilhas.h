#include <stdio.h>
#include <stdlib.h>

//registro que representar[a cada elemento da pilha
struct Elemento{
    int num;
    struct Elemento *prox;
};

typedef struct Elemento Elemento;

struct Pilha{
    Elemento *topo; // aponta para o elemento que etsá no topo da pilha
};

typedef struct Pilha Pilha;

//Ponteiro auxiliar
Elemento *aux;

Pilha *cria_pilha(){
    //alocacao de ponteiro para controlar a pilha
    Pilha *pi = (Pilha *) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL; // a pilha  inicia_se vazia, portanto seu topo é igual a NULl
    }
    return pi;
}

//todo elemento sera inserido no topo da pilha
void insere_elemento(Pilha *pi){
    //A cada insercao alocamos dinamicamente um espaço para um novo elemento
    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    printf("Digite o numero a ser inserido na Pilha: ");
    scanf("%d", &novo->num);
    //Como o numero inserido sera o novo topo, ele apontara para o topo atual que sera
    novo->prox = pi->topo;
    //topo aponta para o endereco de novo
    pi->topo = novo;
    printf("\nNumero Inserido na Pilha!\n");
}

void consulta_pilha(Pilha *pi){
    //caso a Pilha esteja vazia
    if(pi->topo == NULL){
        printf("\nPilha Vazia!");
    }
    //caso a Pilha não esteja vazia
    else{
        aux = pi->topo;
        while(aux != NULL){
            printf(" %d ", aux->num);
            aux = aux->prox;
        }
    }
}

void remove_elemento(Pilha *pi){
    if(pi->topo == NULL){
        printf("\nPilha vazia\n");
    }
    else{
        aux = pi->topo;
        printf("\n%d removido!\n", pi->topo->num);
        pi->topo = pi->topo->prox;
        free(aux);
    }
}

void esvazia_pilha(Pilha *pi){
    if(pi->topo == NULL){
        printf("\nPilha vazia!\n");
    }
    else{
        aux = pi->topo;
        while(aux != NULL){
            pi->topo = pi->topo->prox;
            free(aux);
            aux = pi->topo;
        }
        printf("\n Pilha vazia!\n");
    }
}