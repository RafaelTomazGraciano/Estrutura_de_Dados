/*Faça um programa que acumula n valores da sequencia de Fibonacci em uma pilha*/

#include "funcoes_pilhas.h"

int main(){
    Pilha *pi = cria_pilha();
    int anterior, atual = 0, proximo = 1, n;
    printf("Digite a quantidade de valores da Sequencia de Fibonacci: ");
    scanf("%d", &n);
    while(atual < n){
        insere_elemento(pi, atual);
        anterior = atual;
        atual = proximo;
        proximo = atual + anterior;
    }
    consulta_pilha(pi);
    return 0;
}
