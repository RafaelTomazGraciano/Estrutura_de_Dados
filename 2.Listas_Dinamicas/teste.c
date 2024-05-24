/*Fazendo testes e aprendendo sobre listas*/

#include <stdio.h>
#include "funcoes_listas.h"

int main(){
    Lista *lst1, *lst2, *busc;
    lst1 = lst_cria();
//    lst2 = lst_cria();
    lst1 = lst_insere(lst1,23);
    lst1 = lst_insere(lst1, 45);
//    lst_imprime(lst1);
//    busc = busca(lst1, 20);
//    lst_imprime(busc);
//    busc = busca(lst1, 23);
//    lst_imprime(busc);
//    lst2 = lst_insere_ordenado(lst2, 17);
//    lst2 = lst_insere_ordenado(lst2, 54);
//    lst2 = lst_insere_ordenado(lst2, 5);
//    lst_imprime(lst2);
//    printf("%d\n",lst_igual(lst1, lst2));
//    lst1 = lst_retira(lst1, 23);
//    lst_imprime(lst1);
//    lst_libera(lst1);
//    printf("%d\n",lst_vazia(lst1));
//    lst_libera(lst2);
//    printf("%d",lst_vazia(lst2));
    lst_insere_final(lst1, 57);
    lst_imprime(lst1);
    inverte(lst1);
    lst_imprime(lst1);
    printf("Quantidade: %d\n", quantidade_elementos(lst1));
    lst1 = inverte(lst1);
    lst_imprime(lst1);
    printf("\n");
    ordena_crescente(lst1);
    lst_imprime(lst1);
    return 0;
}

