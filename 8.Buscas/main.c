#include "funcoes.h"

int main(){
    int v[99999];

    for(int i = 0; i < 99999; i++){
        v[i] = i;
    }

    //busca linear
    printf("Busca Linear: %d\n\n", buscaLinear(v, 99999, -10)); //valor nao existe, criando o pior caso
    
    //busca Ordenado
    printf("Busca Ordenado: %d\n\n", buscaOrdenada(v, 99999, 99998)); //ultimo valor, criando o pior caso

    //busca Binaria
    printf("Busca Binaria: %d\n\n", buscaBinaria(v, 99999, -10)); //valor nao existe, criando o pior caso

    return 0;
}