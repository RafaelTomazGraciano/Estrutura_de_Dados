#include <stdio.h>
#include<stdlib.h>

int quickSort(int *vetor, int menor, int maior, int k);
int particao(int *vetor, int menor, int maior);

int main(){
    int tam = 6;
    int vetor[6] = {7,1,2,4,5,3};
    printf("%d\n", quickSort(vetor, 0, tam-1, 2));
    for(int i = 0; i < tam; i++){
        printf("%d  ",  vetor[i]);
    }
    return 0;
}

int quickSort(int *vetor, int menor, int maior, int k){
    if(menor < maior){
        int pivo = particao(vetor, menor, maior);
        // O índice da partição é o mesmo que k
        if (pivo == k) {
            return vetor[pivo];
        }
        // Se o índice da partição é maior que k, então recursivamente chama a função à esquerda da partição
        else if (pivo > k) {
            return quickSort(vetor, menor, pivo - 1, k);
        }
        // Se o índice da partição é menor que k, então recursivamente chama a função à direita da partição
        else {
            return quickSort(vetor, pivo + 1, maior, k);
        }
    }
    return -1;
}

int particao(int *vetor, int menor, int maior) {
    int pivo = vetor[maior];
    int pivoIndice = menor;

    for (int i = menor; i < maior; i++) {
        if (vetor[i] <= pivo) {
            int aux = vetor[pivoIndice];
            vetor[pivoIndice] = vetor[i];
            vetor[i] = aux;
            pivoIndice++;
        }
    }

    int aux = vetor[pivoIndice];
    vetor[pivoIndice] = vetor[maior];
    vetor[maior] = aux;

    return pivoIndice;
}