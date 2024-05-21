#include <stdio.h>
#include <stdlib.h>
#include "../2.Pilha/funcoes_pilhas.h"

void clear_terminal(){
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}

void menu(){
    clear_terminal();
    printf("----------------------------------------------\n");
    printf("|        Opcoes                Comando       |\n");
    printf("|          1               Cadastrar numero  |\n");
    printf("|          2             Mostar numeros pares|\n");
    printf("|          3                Excluir numeros  |\n");
    printf("|          4                      Sair       |\n");
    printf("----------------------------------------------\n");
}

void cadastrar(Pilha *pi){
    clear_terminal();
    //A cada insercao alocamos dinamicamente um espaço para um novo elemento
    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    printf("Digite um numero: ");
    scanf("%d", &novo->num);
    //Como o numero inserido sera o novo topo, ele apontara para o topo atual que sera
    novo->prox = pi->topo;
    //topo aponta para o endereco de novo
    pi->topo = novo;
    printf("Numero inserido!");
}

void mostrar_par(Pilha *pi){
    clear_terminal();
    Elemento *aux;
    //caso a Pilha esteja vazia
    if(pi->topo == NULL){
        printf("\nPilha Vazia!\n");
    }
        //caso a Pilha não esteja vazia
    else{
        aux = pi->topo;
        while(aux != NULL){
            if(aux->num%2 == 0){
                printf("Numero(s) par(es)\n");
                printf(" %d ", aux->num);
            }
            aux = aux->prox;
        }
    }
}

void excluir(Pilha *pi){
    clear_terminal();
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