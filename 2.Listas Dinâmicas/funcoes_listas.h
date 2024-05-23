#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista{
    int info;
    Lista *prox;
};

Lista* lst_cria(){
    return NULL;
}

Lista* lst_insere(Lista *lst, int val){
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->info = val;
    novo->prox = lst;
    return novo;
}

void lst_imprime(Lista *lst){
    Lista *p;
    for(p = lst; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

int lst_vazia(Lista *lst){
    return (lst == NULL);
}

Lista* busca(Lista *lst, int v){
    Lista *p;
    for(p = lst; p!= NULL; p = p->prox){
        if(p->info == v)
            return p;
    }
    return NULL;
}

Lista* lst_retira(Lista *lst, int val){
    Lista *ant = NULL; //ponteiro para elemento anterior
    Lista *p = lst; //ponteiro para percorrer a lista
    //procura elemento na lista, guardando anterior
    while(p != NULL && p->info != val){
        ant = p;
        p = p->prox;
    }
    //verifica se achou elemento
    if(p == NULL){
        return lst; //nao achou, retorna lista original
    }
    //retira elemento
    if(ant == NULL){
        //retira elemento do inicio
        lst = p->prox;
    }
    else{
        //retira elemento do meio da lista
        ant->prox = p->prox;
    }
    free(p);
    return lst;
}

void lst_libera(Lista *lst){
    Lista *aux;
    Lista *p = lst;
    while(p != NULL){
        aux = p->prox; // guarda referencia para o proximo elemento
        free(p); // libera memoria apontada para p
        p = aux; // faz aponta p para o proximo
    }
}

Lista* lst_insere_ordenado(Lista *lst, int val){
    Lista *novo;
    Lista *ant = NULL; //ponteiro para elemento anterior
    Lista *p = lst; //ponteiro para percorer a lista
    //procura insercao de corecao
    while(p != NULL && p->info < val){
        ant = p;
        p = p->prox;
    }
    // cria novo elemento
    novo = (Lista *) malloc(sizeof(Lista));
    novo->info = val;
    //encadeia elemento
    if(ant == NULL){
        //insere elemento no comeco
        novo->prox = lst;
        lst = novo;
    }
    else{
        //insere elemento no meio ou no final da lista
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return lst;
}

int lst_igual (Lista *lst1, Lista *lst2){
    Lista *p1; // ponteiro para percorrer l1
    Lista *p2; // ponteiro para percorrer l2
    for(p1 = lst1, p2 = lst2; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox){
        if(p1->info != p2->info){
            return 0;
        }
    }
    return p1==p2;
}

void lst_insere_final(Lista *lst, int val){
    Lista *atual, *novo = (Lista *) malloc(sizeof(Lista));
    novo->prox = NULL;
    novo->info = val;
    if(lst->prox ==  NULL){
         lst->prox = novo;
    }
    else{
        atual = lst->prox;
        while(atual->prox){
            atual = atual->prox;
        }
         atual->prox = novo;
    }
}

Lista* inverte(Lista* lst){
    Lista *nova = lst_cria(), *p;
    for(p = lst; p != NULL; p = p->prox){
        nova = lst_insere(nova, p->info);
    }
    return nova;
}

int quantidade_elementos(Lista *lst){
    int cont = 0;
    Lista *p;
    for(p = lst; p!= NULL; p = p->prox){
        cont++;
    }
    return cont;
}

void ordena_crescente(Lista *lst){
    Lista *i, *j;
    for(i = lst; i != NULL; i = i->prox){
        for(j = lst; j != NULL; j = j->prox){
            if(i->info < j->info){
                int aux = i->info;
                i->info = j->info;
                j->info = aux;
            }
        }
    }
}



