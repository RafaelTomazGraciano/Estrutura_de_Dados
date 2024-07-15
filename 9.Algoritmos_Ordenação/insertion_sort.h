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

void insertion_sort(int *v, int n){
    int chave, j;
    for(int i = 1; i < n; i++){
        chave = v[i];
        for(j = i-1; j >= 0 && v[j] > chave; j--){
            v[j+1] = v[j];
        }
        v[j+1] = chave;
    }
}
