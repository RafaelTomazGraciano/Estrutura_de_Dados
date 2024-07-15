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

void bubble_sort(int *v, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}