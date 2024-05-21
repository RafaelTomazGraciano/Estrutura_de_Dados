/* Faça um programa que cadastre em uma pilha vários números. A entrada deles será finalizada
com a digitação de um número menor que 0. Posteriormente o programa deve gerar duas filas,
 a primeira com os números pares e a segunda com os números impares. A saída do programa
 deve apresentar a pilha digitada e as filas geradas. Caso alguma das filas seja vazia, deve-se
mostrar a mensagem. */

#include "funcoes_ex07.h"

int main(){
    Pilha *pi = cria_pilha();
    Fila *f1 = cria_fila(), *f2 = cria_fila();
    int n = 0;
    while(n >= 0){
        printf("Digite um numero ou algum unumero menor que 0 para parar\n");
        scanf("%d", &n);
        if(n > 0){
            insere_elemento_pilha(pi, n);
        }
    }
    printf("\n\nFILA 1\n");
    insere_elemento_fila_par(f1, pi);
    consulta_fila(f1);
    printf("\n\nFILA 2\n");
    insere_elemento_fila_impar(f2, pi);
    consulta_fila(f2);
    return 0;
}


