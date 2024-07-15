#include <stdio.h>
#include <stdlib.h>

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

void merge(int *vetor, int inicio, int meio, int fim){
    int i = inicio, j = meio+1, aux = 0;
    int *vetAux = (int *) malloc((fim-inicio+1) * sizeof(int));
    while(i <= meio && j <= fim){
        if(vetor[j] > vetor[i]){
            vetAux[aux++] = vetor[i++];
        }
        else{
            vetAux[aux++] = vetor[j++];
        }
    } 

    while(i <= meio){
        vetAux[aux++] = vetor[i++];
    }
    while(j <= fim){
        vetAux[aux++] = vetor[j++];
    }
    for(aux = 0; aux < (fim-inicio+1); aux++){
        vetor[inicio+aux] = vetAux[aux];
    }
}

void mergeSort(int *vetor, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio+fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

