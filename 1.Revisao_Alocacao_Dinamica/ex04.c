/*Faça um programa utilizando calloc e struct que irá receber as notas de três
avaliações de n pessoas, armazene em um vetor e calcule a média final de cada
prova e apresente a maior nota.*/

#include <stdio.h>
#include <stdlib.h>

struct notas
{
    float nota1;
    float nota2;
    float nota3;
};

typedef struct notas notas;

int main(){
    notas *nota;
    float media1 = 0, media2 = 0, media3 = 0, maior_nota = 0;
    int n;  
    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &n);
    nota = calloc(n, sizeof(notas));
    for(int i = 0; i < n; i++){
        printf("Digite a nota 1 da pessoa %d: ", i);
        scanf("%f", &nota[i].nota1);
        printf("Digite a nota 2 da pessoa %d: ", i);
        scanf("%f", &nota[i].nota2);
        printf("Digite a nota 3 da pessoa %d: ", i);
        scanf("%f", &nota[i].nota3);
        media1 += nota[i].nota1;
        media2 += nota[i].nota2;
        media3 += nota[i].nota3;
        if(maior_nota < nota[i].nota1){
            maior_nota = nota[i].nota1;
        }
        else if(maior_nota < nota[i].nota2){
            maior_nota = nota[i].nota2;
        }
        else if (maior_nota < nota[i].nota3){
            maior_nota = nota[i].nota3;
        }
    }
    media1 /= n;
    media2 /= n;
    media3 /= n;
    printf("Media1: %.2f | Media2: %.2f | Media: %.2f\n", media1, media2, media3);
    printf("Maior nota: %.2f", maior_nota);
    free(nota);
    return 0;
}