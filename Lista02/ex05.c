#include <stdio.h>
#include <stdlib.h>

void mergeSort(float *vetor, int inicio, int fim);

void merge(float *vetor, int inicio, int meio, int fim);

float menorDiff(float *vetor, int tam);

int main(){
    int tam;
    printf("Digite um numero: ");
    scanf("%d", &tam);
    float *vetor = (float *)malloc(tam * sizeof(float));
    for(int i = 0; i < tam; i++){
        printf("Digite um numero para a posicao %d: ",i);
        scanf("%f", &vetor[i]);
    }
    mergeSort(vetor, 0, tam-1);
    for(int i = 0; i < tam; i++){
        printf("%.2f  ",vetor[i]);
    }
    printf("\n%.2f", menorDiff(vetor, tam));
    free(vetor);
    return 0;
}

void mergeSort(float *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(float *vetor, int inicio, int meio, int fim) {
    int com1 = inicio, com2 = meio + 1, comAux = 0;
    float *vetAux = (float *)malloc((fim - inicio + 1) * sizeof(float));

    while (com1 <= meio && com2 <= fim) {
        if (vetor[com1] <= vetor[com2]) {
            vetAux[comAux++] = vetor[com1++];
        } else {
            vetAux[comAux++] = vetor[com2++];
        }
    }

    while (com1 <= meio) {
        vetAux[comAux++] = vetor[com1++];
    }

    while (com2 <= fim) {
        vetAux[comAux++] = vetor[com2++];
    }

    for (comAux = 0; comAux <= (fim - inicio); comAux++) {
        vetor[inicio + comAux] = vetAux[comAux];
    }

    free(vetAux);
}

float menorDiff(float *vetor, int tam) {
    float dif = 1000000.0;
    for (int i = 0; i < tam-1; i++) {
        if ((vetor[i+1] - vetor[i]) < dif) {
            dif = vetor[i+1] - vetor[i];
        }
    }
    return dif;
}