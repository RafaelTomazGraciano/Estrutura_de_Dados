/*Dado duas filas F1 e F2 que armazenam números inteiros, faça um programa que tenha as
seguintes funções:
    * Uma função para testar se as duas filas F1 e P2 são iguais. Caso não forem iguais diga qual fila é maior
    * Uma função que forneça o maior, o menor e a média aritmética dos elementos de uma fila.
    * Uma função para transferir elementos de F1 para F2 (copia).
    * Uma função para retornar o número de elementos de uma filas que possuem valor Impar.
    * Uma função para retornar o número de elementos da uma filas que possuem valor par */

#include "funcoes_fila.h"

int main(){
    Fila *F1 = cria_fila(), *F2 = cria_fila();
    insere_elemento(F1,10);
    insere_elemento(F1,21);
    insere_elemento(F1,30);
    transfere(F1,F2);
    printf("%d\n",impares(F1));
    printf("%d",pares(F2));
    return 0;
}

