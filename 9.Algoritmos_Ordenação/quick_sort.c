#include "quickSort.h"
#define N 30

int main(){
    int vetor[N];
    preenche_vetor(vetor, N);
    printa(vetor, N);
    quickSort(vetor, 0, N-1);
    printa(vetor, N);
    return 0;
}
