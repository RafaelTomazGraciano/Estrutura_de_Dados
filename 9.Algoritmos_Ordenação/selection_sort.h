#include <stdio.h>
#include <stdlib.h>

int *preenche_vetor(int *v, int n){
    v = (int *) malloc(n*sizeof(int));
    int i = n, j = 0;
    while(i > 0){ //insere inverso, criando pior caso
        v[j] = i;
        i--;
        j++;
    }
    return v;
}

void print(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("%d  ", v[i]);
    }
    printf("\n");
}

void selection_sort(int *v, int n){
    for(int i = 0; i < n-1; i++){
        int indice_menor = i;
        for(int j = i+1; j < n; j++){
            if(v[indice_menor] > v[j]){
                indice_menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[indice_menor];
        v[indice_menor] = aux;
    }
}