#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Aluno
typedef struct {
    int id;
    float CR;
} Aluno;

// Função para mesclar dois sub-vetores
void merge(Aluno arr[], int left, int mid, int right);

// Função de ordenação mergeSort que usa a função merge
void mergeSort(Aluno arr[], int left, int right);

// Função para imprimir o vetor
void printArray(Aluno arr[], int size);

// Função principal para testar o mergeSort
int main() {
    Aluno arr[] = {{1, 3.5}, {2, 2.1}, {3, 4.0}, {4, 3.8}};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor inicial:\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nVetor ordenado:\n");
    printArray(arr, arr_size);
    return 0;
}

void mergeSort(Aluno *vetor, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio+fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(Aluno *vetor, int inicio, int meio, int fim){
    int i = inicio, j = meio+1, aux = 0;
    Aluno *vetAux = (Aluno *) malloc((fim-inicio+1) * sizeof(Aluno));
    while(i <= meio && j <= fim){
        if(vetor[j].CR >= vetor[i].CR){
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


void printArray(Aluno arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("ID: %d, CR: %.2f\n", arr[i].id, arr[i].CR);
    }
}