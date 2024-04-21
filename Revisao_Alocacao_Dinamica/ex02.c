/*Crie um programa utilizando struct e calloc que leia a informação de peso(N) e
área da base (m2) de n objetos e calcule a pressão de cada objeto. 
Pressão = Força Peso(N)/Área(m2). */

#include <stdio.h>
#include <stdlib.h>

struct dados
{
    float peso;
    float area;
};

typedef struct dados dados;


int main(){
    dados *d;
    int n;
    printf("Digite a quantidade de objetos: ");
    scanf("%d", &n);
    d = calloc(n, sizeof(dados));
    for(int i = 0; i < n; i ++){
        printf("Digite o peso do objeto %d: ", i);
        scanf("%f", &d[i].peso);
        printf("Digite a area do objeto %d: ", i);
        scanf("%f", &d[i].area);
    }
    for(int i = 0; i < n; i++){
        printf("Pressao do objeto %d: %.2f\n", i, d[i].peso/d[i].area);
    }
    free(d);
    return 0;
}