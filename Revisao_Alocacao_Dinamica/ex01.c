/*Faça um programa utilizando struct e malloc, que leia a informação do raio de n
círculos e calcule a circunferência e área. Circunferência = 2*pi*r , Área = pi*r²
Obs: Não esqueça de liberar a memória ao final. */

#include <stdio.h>
#include <stdlib.h>

#define pi 3.14

struct raio
{
    float raio;
};

typedef struct raio raio;


int main(){
    raio *r;
    int n;
    printf("Digite a quantidade de circulos: ");
    scanf("%d", &n);
    r = (raio *) malloc(n * sizeof(raio));
    for(int i = 0; i < n; i++){
        printf("Digite o valor do raio do circulo %d: ", i);
        scanf("%f", &r[i].raio);
    }
    for(int i = 0; i < n; i++){
        printf("Area do circulo %d: %.2f | Circunferencia do circulo %d: %.2f\n", i, pi*r[i].raio*r[i].raio, i, 2*pi*r[i].raio);
    }

    free(r);
    return 0;
}