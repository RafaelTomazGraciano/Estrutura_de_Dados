/*Faça um programa utilizando o comando malloc, que leia o peso de n pessoas,
armazene em um vetor e encontre a pessoa com o peso mais distante da media*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, pos;
    float *peso, media = 0, dist_med = 0;
    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &n);
    peso = (float *) malloc(n * sizeof(float));
    for(int i = 0; i < n; i++){
        printf("Digite o peso da pessoa %d: ", i);
        scanf("%f", &peso[i]);
        media += peso[i];
    }
    media = media/n;
    for(int i = 0; i < n; i++){
        if(fabs(peso[i]-media) > dist_med){
            dist_med = peso[i];
            pos = i;
        }
    }
    printf("Media: %.2f\n", media);
    printf("Pessoa com peso mais distante da media: %d | Peso da pessoa: %.2f", pos, dist_med);
    free(peso);
    return 0;
}