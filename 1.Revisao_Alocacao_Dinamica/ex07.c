/*Faça um programa que leia uma matriz quadrada de dimensão n de distâncias e
determine maior e menor distância . Use calloc.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float **matriz, maior = 0, menor = 100000;
    int n;
    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &n);
    matriz = calloc(n, sizeof(float));
    for(int i = 0; i < n; i++){
        matriz[i] = calloc(n, sizeof(float));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Digite a distancia para a posicao %d %d: ",i,j);
            scanf("%f", &matriz[i][j]);
            if(maior < matriz[i][j]){
                maior = matriz[i][j];
            }
            if(menor > matriz[i][j]){
                menor = matriz[i][j];
            }
        }
    }
    printf("Maior: %.2f | Menor: %.2f", maior, menor);
    for(int i = 0; i < n; i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}