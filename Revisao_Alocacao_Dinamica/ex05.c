/*Faça um programa que leia n pontos (x, y), e calcule o ponto médio (xm,ym) e
apresente a distância do ponto mais próximo do ponto médio. Use struct e calloc.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pontos
{
    int x;
    int y;
};

typedef struct pontos pontos;


int main(){
    pontos *ponto;
    int n, xm = 0, ym = 0, dist, proximo = 0;
    printf("Digite a quantidade de pontos: ");
    scanf("%d", &n);
    ponto = calloc(n, sizeof(pontos));
    for(int i = 0; i < n; i++){
        printf("Digite o valor do ponto X %d: ", i);
        scanf("%d", &ponto[i].x);
        printf("Digite o valor do ponto Y %d: ", i);
        scanf("%d", &ponto[i].y);
        xm += ponto[i].x;
        ym += ponto[i].y;
    }
    xm /= n;
    ym /= n;
    for(int i = 0; i < n; i++){
        dist = sqrt(pow(ponto[i].x-xm,2) + pow(ponto[i].y-ym,2));
        if(dist > proximo){
            proximo = dist;
        }
    }
    printf("Distancia do ponto mais proximo: %d", proximo);
    free(ponto);
    return 0;
}