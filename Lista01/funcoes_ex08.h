#include <stdio.h>
#include <stdlib.h>

struct Elemento{
    int codigo;
    char tipo;
    float preco;
    struct Elemento *prox;
};

typedef struct Elemento Elemento;

struct Fila{
    Elemento *inicio;
    Elemento *fim;
};

typedef struct Fila Fila;

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
    printf("|          1               Cadastrar tipo    |\n");
    printf("|          2              Cadastrar produto  |\n");
    printf("|          3          Consulta preco produto |\n");
    printf("|          4               Excluir tipo      |\n");
    printf("|          5                   Sair          |\n");
    printf("----------------------------------------------\n");
}

int validar_tipo(Fila *fi, char tipo){
    if(fi->inicio ==  NULL) {
        return 0;
    }
    else{
        Elemento *aux = fi->inicio;
        while(aux != NULL){
            if(aux->tipo == tipo) {
                return 1;
            }
            aux = aux->prox;
        }
    }
    return 0;
}

int validar_produto(Fila *fi, int codigo){
    if(fi->inicio ==  NULL) {
        return 0;
    }
    else{
        Elemento *aux = fi->inicio;
        while(aux != NULL){
            if(aux->codigo == codigo) {
                return 1;
            }
            aux = aux->prox;
        }
    }
    return 0;
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

void cadastrar_tipo(Fila *fi, char tipo){
    // a cada inserção alocamos dinamicamente um espaço para um novo elemento
    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    novo->tipo = tipo;
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
    printf("\nTipo Cadastrado!\n");
}

void cadastrar_produto(Fila *f1, Fila *f2, float preco, int codigo, char tipo){
    if(validar_tipo(f1, tipo) == 0){
        printf("Tipo de produto inexistente!");
    }
    else{// a cada inserção alocamos dinamicamente um espaço para um novo elemento
        Elemento *aux = f1->inicio;
        Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
        novo->tipo = aux->tipo;
        novo->codigo = codigo;
        novo->preco = preco;
        novo->prox = NULL;
        //caso a fila esteja vazia, o elemento inserido será o primeriro e o último
        if (f2->inicio == NULL) {
            f2->inicio = novo;
            f2->fim = novo;
        }
            //caso a fila já contenha algum elemento, o novo elemento será sempre inserido no fim da fila
        else {
            f2->fim->prox = novo;
            f2->fim = novo;
        }
        printf("\nProduto Cadastrado!\n");
    }
}

void consultar_preco_produto(Fila *fi, int codigo){
    if(fi->inicio == NULL){
        printf("Fila Vazia!");
    }
    else{
        if(validar_produto(fi, codigo) == 0){
            printf("Produto nao encontrado!");
        }
        else{
            Elemento *aux = fi->inicio;
            while(aux != NULL){
                if(aux->codigo == codigo){
                    printf("Preco: %.2f", aux->preco);
                }
                aux = aux->prox;
            }
        }
    }
}

void excluir(Fila *f1){
    if(f1->inicio == NULL){
        printf("Fila Vazia!");
    }
    else{
        Elemento *aux = f1->inicio;
        printf("\nTipo %c removido!\n", f1->inicio->tipo);

        f1->inicio = f1->inicio->prox;
        free(aux);
    }
}
