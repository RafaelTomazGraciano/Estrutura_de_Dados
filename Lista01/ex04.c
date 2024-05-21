/*Cadastre 5 numeros em uma fila dinamica e mais 5 em uma pilha dinamica. Em seguida, mostre tres realtorios:
    * Os numeros que estao nas duas estruturas.
    * Os que estao na fila
    * Os que estao na pilha
 */

#include "funcoes_pilhas.h"
#include "funcoes_ex04.h"

int main(){
    Pilha *pilha = cria_pilha();
    Fila *fila = cria_fila();
    for(int i = 0; i < 5; i++){
        insere_elemento(pilha, i);
        insere_elemento_fila(fila, i+5);
    }
    printf("Elemento das duas estruturas\n");
    consulta_pilha(pilha);
    consulta_fila(fila);
    printf("\nElementos da pilha\n");
    consulta_pilha(pilha);
    printf("Elementos da fila\n");
    consulta_fila(fila);
    return 0;
}




