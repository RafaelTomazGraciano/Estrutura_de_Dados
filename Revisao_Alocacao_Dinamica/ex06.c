/*Faça um programa utilizando struct que leia a informação de peso e
altura(cm) de n pessoas, calcule o IMC e determine o maior valor. Use calloc. Dica: imc = peso/(altura²).*/

#include <stdio.h>
#include <stdlib.h>

struct IMC
{
    float peso;
    float altura;
};

typedef struct IMC IMC;

int main(){
    IMC *imc;
    float calcular_imc, maior = 0;
    int n;
    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &n);
    imc = calloc(n, sizeof(IMC));
    for(int i = 0; i < n;  i++){
        printf("Digite o peso em Kg da pessoa %d: ", i);
        scanf("%f", &imc[i].peso);
        printf("Digite a altura em cm da pessoa %d: ", i);
        scanf("%f", &imc[i].altura);
        calcular_imc = imc[i].peso/((imc[i].altura/100)*(imc[i].altura/100));
        if(maior < calcular_imc){
            maior = calcular_imc;
        }
    }
    printf("Maior IMC: %.2f", maior);
    free(imc);
    return 0;
}