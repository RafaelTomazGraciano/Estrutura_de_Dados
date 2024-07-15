#include "insertion_sort.h"
#define n 30

int main(){
    int *v = preenche_vetor(v, n);
    print(v, n);
    insertion_sort(v, n);
    print(v, n);
    free(v);
}