#include <stdio.h>

int fatorial(int n){
    if(n == 1){
        return 1;
    }
    return n*fatorial(n-1);
}

int fibonacci(int n){
    if(n < 3){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}