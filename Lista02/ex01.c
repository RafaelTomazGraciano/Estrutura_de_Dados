#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int valor;
    struct lista *p;
};

typedef struct lista lista;

lista* lst_insere(lista *lst, int val);
int soma (lista *lst);


int main(){
    lista *lst = NULL;
    for(int i = 1; i <= 10; i++){
        lst = lst_insere(lst, i);
    }
    printf("%d", soma(lst));
    return 0;
}

lista* lst_insere(lista *lst, int val){
    lista *novo = (lista *) malloc(sizeof(lista));
    novo->valor = val;
    novo->p = lst;
    return novo;
}

int soma (lista *lst){
    if(lst == NULL){
        return 0;
    }
    return lst->valor + soma(lst->p);   
}
