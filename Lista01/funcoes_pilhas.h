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


Pilha *cria_pilha(){
    //alocacao de ponteiro para controlar a pilha
    Pilha *pi = (Pilha *) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL; // a pilha  inicia_se vazia, portanto seu topo é igual a NULl
    }
    return pi;
}

//todo elemento sera inserido no topo da pilha
void insere_elemento(Pilha *pi, int val){
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

void remove_elemento(Pilha *pi){
    Elemento *aux;
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
    Elemento *aux;
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

void testa_pilha(Pilha *p1, Pilha *p2){
    Elemento *aux;
    int cont1 = 0, cont2 = 0;
    if(p1->topo == NULL){
        printf("\nPilha 1 Vazia!");
    }
        //caso a Pilha não esteja vazia
    else{
        aux = p1->topo;
        while(aux != NULL){
            cont1++;
            aux = aux->prox;
        }
    }
    if(p2->topo == NULL){
        printf("\nPilha 2 Vazia!");
    }
        //caso a Pilha não esteja vazia
    else{
        aux = p2->topo;
        while(aux != NULL){
            cont2++;
            aux = aux->prox;
        }
    }

    if(cont1 > cont2){
        printf("\nPilha 1 e maior que Pilha 2");
    }
    else if(cont2 > cont1){
        printf("\nPilha 2 e maior que Pilha 1");
    }
    else if(cont2 == cont1){
        printf("\nAs pilhas sao iguais");
    }
}

void maior_menor_media(Pilha *pi){
    Elemento *aux;
    int maior = 0, menor = 999999999, cont = 0;
    float media = 0;
    //caso a Pilha esteja vazia
    if(pi->topo == NULL){
        printf("\nPilha Vazia!");
    }
    //caso a Pilha não esteja vazia
    else{
        aux = pi->topo;
        while(aux != NULL){
            if(maior < aux->num){
                maior = aux->num;
            }
            if(menor > aux->num){
                menor = aux->num;
            }
            media += aux->num;
            cont++;
            aux = aux->prox;
        }
    }
    printf("\nMaior elemento: %d", maior);
    printf("\nMenor elemento: %d", menor);
    printf("\nMedia aritmetica: %.2f", media/cont);
}

void transfere(Pilha *p1, Pilha *p2){
    Elemento *aux;
    aux = p1->topo;
    Pilha *temp = cria_pilha();
    if(p1->topo == NULL){
        printf("\nPilha Vazia!");
    }
    while(aux != NULL) {
        insere_elemento(temp, aux->num);
        aux = aux->prox;
    }
    aux = temp->topo;
    while(aux != NULL) {
        insere_elemento(p2, aux->num);
        aux = aux->prox;
    }
}

int impares(Pilha *p1){
    Elemento *aux;
    int contador = 0;
    aux = p1->topo;
    if(p1->topo == NULL){
        printf("\nPilha Vazia!");
    }
    else{
        while(aux!=NULL){
            if(aux->num%2 != 0){
                contador++;
            }
            aux = aux->prox;
        }
    }
    return contador;
}

int pares(Pilha *p1){
    Elemento *aux;
    int contador = 0;
    aux = p1->topo;
    if(p1->topo == NULL){
        printf("\nPilha Vazia!");
    }
    else{
        while(aux!=NULL){
            if(aux->num%2 == 0){
                contador++;
            }
            aux = aux->prox;
        }
    }
    return contador;
}

