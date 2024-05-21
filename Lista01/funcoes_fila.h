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

void insere_elemento(Fila *fi, int val){
    // a cada inserção alocamos dinamicamente um espaço para um novo elemento
    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
     novo->num = val;
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

void remove_elemento(Fila *fi){
    Elemento *aux;
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
    Elemento *aux;
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

void testa_fila(Fila *f1, Fila *f2){
    Elemento *aux;
    int cont1 = 0, cont2 = 0;
    if(f1->inicio == NULL){
        printf("\nFila Vazia!\n");
    }
        //caso a Fila não esteja vazia
    else{
        aux = f1->inicio;
        while(aux != NULL){
            cont1++;
            aux = aux->prox;
        }
    }
    if(f2->inicio == NULL){
        printf("\nFila Vazia!\n");
    }
        //caso a Fila não esteja vazia
    else{
        aux = f2->inicio;
        while(aux != NULL){
            cont2++;
            aux = aux->prox;
        }
    }

    if(cont1 > cont2){
        printf("\nFila 1 e maior que Fila 2");
    }
    else if(cont2 > cont1){
        printf("\nFila 2 e maior que Fila 1");
    }
    else if(cont2 == cont1){
        printf("\nAs filas sao iguais");
    }
}

void maior_menor_media(Fila *fi){
    Elemento *aux;
    int maior = 0, menor = 999999999, cont = 0;
    float media = 0;
    //caso a Pilha esteja vazia
    if(fi->inicio == NULL){
        printf("\nPilha Vazia!");
    }
        //caso a Pilha não esteja vazia
    else{
        aux = fi->inicio;
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

void transfere(Fila *f1, Fila *f2){
    Elemento *aux;
    aux = f1->inicio;
    if(f1->inicio == NULL){
        printf("\nPilha Vazia!");
    }
    while(aux != NULL) {
        insere_elemento(f2, aux->num);
        aux = aux->prox;
    }
}

int impares(Fila *f1){
    Elemento *aux;
    int contador = 0;
    aux = f1->inicio;
    if(f1->inicio == NULL){
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

int pares(Fila *f1){
    Elemento *aux;
    int contador = 0;
    aux = f1->inicio;
    if(f1->inicio == NULL){
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