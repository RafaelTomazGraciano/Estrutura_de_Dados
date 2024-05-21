/*Dado duas pilhas P1 e P2 que armazenam números inteiros, faça um programa que tenha as
seguintes funções:
    * Uma função para testar se as duas pilhas P1 e P2 são iguais. Caso não forem iguais diga qual pilha é maior
    * Uma função que forneça o maior, o menor e a média aritmética dos elementos de uma pilha.
    * Uma função para transferir elementos de P1 para P2 (copia).
    * Uma função para retornar o número de elementos de uma pilha que possuem valor Impar.
    * Uma função para retornar o número de elementos da uma pilha que possuem valor par */

#include "funcoes_pilhas.h"

int main(){
    Pilha *P1 = cria_pilha(), *P2 = cria_pilha();
    insere_elemento(P1, 10);
    insere_elemento(P1, 15);
    insere_elemento(P1, 21);
    consulta_pilha(P1);
    transfere(P1, P2);
    consulta_pilha(P2);
    printf("%d\n", impares(P1));
    printf("%d\n", pares(P1));
    return 0;
}

