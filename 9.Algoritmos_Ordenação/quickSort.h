#include <stdio.h>

void preenche_vetor(int *v, int N){
    for(int i = 0; i < N; i++){
        v[i] = N-i-1;
    }
}

void printa(int *v, int N){
    printf("\n");
    for(int i = 0; i < N; i++){
        printf("%d  ", v[i]);
    }
    printf("\n");
}

int particao(int *vetor, int inicio, int fim){
    int pivo, indice, i;
    pivo = vetor[fim];
    indice = inicio;
    for(i = inicio; i < fim; i++){
        if(pivo >= vetor[i]){
            int aux = vetor[i];
            vetor[i] = vetor[indice];
            vetor[indice] = aux;
            indice++;
        }
    }
    int aux = vetor[fim];
    vetor[fim] = vetor[indice];
    vetor[indice] = aux;
    return indice;
}

void quickSort(int *vetor, int inicio, int fim){
    if(inicio < fim){
        int pivo = particao(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}

