#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elemento{
    char nome[255];
    int numero;
    float nota;
    struct Elemento *prox;
};

typedef struct Elemento Elemento;

struct Pilha{
    Elemento *topo; // aponta para o elemento que etsá no topo da pilha
};

struct Fila{
    Elemento *inicio;
    Elemento *fim;
};

typedef struct Fila Fila;

typedef struct Pilha Pilha;

void clear_terminal(){
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}

Pilha *cria_pilha(){
    //alocacao de ponteiro para controlar a pilha
    Pilha *pi = (Pilha *) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL; // a pilha  inicia_se vazia, portanto seu topo é igual a NULl
    }
    return pi;
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

void menu(){
    clear_terminal();
    printf("-----------------------------------------------------\n");
    printf("|        Opcoes                Comando              |\n");
    printf("|          1               Cadastrar numero         |\n");
    printf("|          2                Cadastrar nota          |\n");
    printf("|          3                Calcular media          |\n");
    printf("|          4        Listar nomes dos alunos sem nota|\n");
    printf("|          5                Excluir aluno           |\n");
    printf("|          6                Excluir nota            |\n");
    printf("|          7                     Sair               |\n");
    printf("-----------------------------------------------------\n");
}

int verificaAluno(Pilha *pi, int numero) {
    Elemento *aux;
    aux = pi->topo;
    while (aux != NULL) {
        if (aux->numero == numero && aux->nota == 11){
            return 0;
        }
            aux = aux->prox;
    }
    return 1;
}

    void cadastrar_aluno(Pilha *pi, int numero, char nome[]){
    clear_terminal();
    //A cada insercao alocamos dinamicamente um espaço para um novo elemento
    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    novo->numero = numero;
    novo->nota = 11;
    strcpy(novo->nome, nome);
    //Como o numero inserido sera o novo topo, ele apontara para o topo atual que sera
    novo->prox = pi->topo;
    //topo aponta para o endereco de novo
    pi->topo = novo;
    printf("Aluno inserido!");
}

void cadastrar_nota(Pilha *pi, Fila *fi, int numero, float nota){
    clear_terminal();
    Elemento *aux = pi->topo;
    if(nota > 10 || nota < 0){
        printf("Valor de nota Invalida\n");

    }
    if(pi->topo == NULL){
        printf("\nNao ha alunos cadastrados!\n");
    }
    else{
        // a cada inserção alocamos dinamicamente um espaço para um novo elemento
        Elemento *novo = (Elemento *) malloc(sizeof(Elemento));

        novo->nota = nota;
        novo->numero = numero;
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
        while (aux != NULL) {
            if (aux->numero == numero) {
                aux->nota = nota;
                strcpy(novo->nome, aux->nome);
            }
            aux = aux->prox;
        }
        printf("\nNota inserida!\n");
    }
}

void media(Pilha *pi, Fila *fi, int numero){
    Elemento *aux;
    char nome[255];
    int cont = 0;
    float media = 0;
    if(fi->inicio == NULL){
        printf("\nNao ha alunos cadastrados!\n");
    }
    else{
        if(verificaAluno(pi, numero) == 0){
            printf("Nota nao cadastrada!\n");
        }
        else{
            aux = fi->inicio;
            while(aux != NULL) {
                if(aux->numero == numero){
                    strcpy(nome, aux->nome);
                    media += aux->nota;
                    cont++;
                }
                aux = aux->prox;
            }
        }

    }
    printf("Nome: %s", nome);
    printf("Media: %.2f", media/cont);
}

void listar(Pilha *pi){
    Elemento *aux;
    if(pi->topo == NULL){
        printf("Nao ha Alunos Cadastrados");
    }
    else{
        aux = pi->topo;
        while(aux != NULL){
            if(aux->nota == 11){
                printf("%s", aux->nome);
            }
            aux = aux->prox;
        }
    }
}

void excluirAluno(Pilha *pi){
    Elemento *aux;
    if(pi->topo == NULL){
        printf("\nPilha vazia\n");
    }
    else{
        aux = pi->topo;
        if(aux -> nota == 11){
            printf("\nAluno %d removido!\n", pi->topo->numero);
            pi->topo = pi->topo->prox;
            free(aux);
        }
        else{
            printf("O Aluno nao pode ser excluido, pois ele possui uma nota");
        }
    }
}

void excluirNota(Pilha *pi, Fila *fi){
    Elemento *aux, *auxpi = pi->topo;
    if(fi->inicio == NULL){
        printf("\nFila Vazia!\n");
    }
    else{
        aux = fi->inicio;
        while(auxpi != NULL){
            if(aux->numero == auxpi->numero){
                auxpi->nota = 11;
            }
            auxpi = auxpi->prox;
        }
        printf("\nNota do aluno %d removido!\n", fi->inicio->numero);
        fi->inicio = fi->inicio->prox;
        free(aux);
    }
}