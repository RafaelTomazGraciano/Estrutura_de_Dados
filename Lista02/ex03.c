#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int valor;
    struct lista *p;
};

typedef struct lista lista;

lista* lst_insere(lista *lst, int val);
lista *buscaLinear(lista *lst, int v);

int main(){
    lista *lst = NULL;
    for(int i = 0; i < 100; i++){
        lst = lst_insere(lst, i);
    }
    lst = buscaLinear(lst, 63);
    printf("%d", lst->valor);
    return 0;
}

lista* lst_insere(lista *lst, int val){
    lista *novo = (lista *) malloc(sizeof(lista));
    novo->valor = val;
    novo->p = lst;
    return novo;
}

lista *buscaLinear(lista *lst, int v){
    if(lst->p == NULL){
        return NULL;
    }
    if(v == lst->valor){
        return lst;
    }
    return buscaLinear(lst->p, v);
}