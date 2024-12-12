#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
    int altura;
} No;


int altura(No* n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

int maior(int a, int b) {
    return (a >= b) ? a : b;
}

int obterBalanceamento(No* no) {
    if (no == NULL)
        return 0;
    return altura(no->esq) - altura(no->dir);
}

No* criarNo(int chave) {
    No* no = malloc(sizeof(No));
    no->chave = chave;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 1;
    return no;
}

No* rotacionarDireita(No* no) {
    No* novoPai = no->esq;
    No* temp = novoPai->dir;
    novoPai->dir = no;
    no->esq = temp;
    no->altura = 1 + maior(altura(no->esq), altura(no->esq));
    novoPai->altura = 1 + maior(altura(novoPai->dir), altura(novoPai->dir));
    return novoPai;
}

No* rotacionarEsquerda(No* no) {
    No* novoPai = no->dir;
    No* temp = novoPai->esq;
    novoPai->esq = no;
    no->dir = temp;
    no->altura = 1 + maior(altura(no->esq), altura(no->dir));
    novoPai->altura = 1 + maior(altura(novoPai->esq), altura(novoPai->dir));
    return novoPai;
}


No* inserirNo(No* no, int chave) {
    if (no == NULL)
        return criarNo(chave);

    if (chave < no->chave)
        no->esq = inserirNo(no->esq, chave);
    else if (chave > no->chave)
        no->dir = inserirNo(no->dir, chave);
    else
        return no;
    

    no->altura = 1 + maior(altura(no->esq), altura(no->dir));
    int balanceamento = obterBalanceamento(no);

    if (balanceamento < -1){
        if (chave < no->dir->chave) {
            no->dir = rotacionarDireita(no->dir);
        }
        no = rotacionarEsquerda(no);
    }


    if (balanceamento > 1){
        if(chave > no->esq->chave){
            no->esq = rotacionarEsquerda(no->esq);
        }
        no = rotacionarDireita(no);
    }

    return no;
}

// Imprime a árvore em pré-ordem
void imprimirArvore(No* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esq);
        printf("%d ", raiz->chave);
        imprimirArvore(raiz->dir);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq); 
        liberarArvore(raiz->dir); 
        free(raiz);               
    }
}