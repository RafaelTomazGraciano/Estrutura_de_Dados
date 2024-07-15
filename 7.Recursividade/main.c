#include "funcoes.h"

int main(){
    //fatorial
    //printf("Fatorial: %d\n", fatorial(5));

    //fibonacci
    printf("\nFibonacci\n");
    for (int i = 1; i <= 20; i++) {
        printf("%d\n", fibonacci(i));
    }
    return 0;
}