#include "selection_sort.h"
#define n 30

int main(){
    int *v = preenche_vetor(v, n);
    print(v, n);
    selection_sort(v, n);
    print(v, n);
    free(v);
}