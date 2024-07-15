#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Alunos{
    int matricula;
    float nota;
};

typedef struct Alunos Alunos;

struct pilha{
    Alunos *alunos[MAX];
    int topo;
};

typedef struct pilha pilha;

pilha *cria();
void empilha(pilha *p, Alunos *a);
int buscaBinaria(pilha *p, int v);

int main(){
    pilha *pi = cria();
    for(int i = 0; i < 100; i++){
        Alunos *a = (Alunos *)malloc(sizeof(Alunos));
        a->matricula = i;
        empilha(pi, a);
    } 
    printf("%d", buscaBinaria(pi, 57));
    return 0; 
}

pilha *cria(){
    pilha *p;
    p = malloc(sizeof (pilha));
    if(!p) {
        perror(NULL);
        exit(1);
    }
    /*IMPORTANTE*/
    p->topo = 0;
    return p;
}

void empilha(pilha *p, Alunos *a){
    if(p->topo == MAX){
        printf("pilha cheia");
        exit(1);
    }
    p->alunos[p->topo] = a;
    p->topo = p->topo + 1;
}

int buscaBinaria(pilha *p, int v){
    int inicio = 0, meio, final = p->topo-1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if(v < p->alunos[meio]->matricula){
            final = meio-1;
        }
        else{
            if(v > p->alunos[meio]->matricula){
                inicio = meio+1;
            }
            else{
                return meio;
            }
        }
    }
    return -1;
}