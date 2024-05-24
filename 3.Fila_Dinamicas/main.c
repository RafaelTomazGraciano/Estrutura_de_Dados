/*Testando funcoes de Fila Dinamica*/

#include "funcoes_fila.h"

int main(){
    Fila *fi = cria_fila();
    insere_elemento(fi,10);
    insere_elemento(fi,15);
    insere_elemento(fi,27);
    consulta_fila(fi);
    remove_elemento(fi);
    consulta_fila(fi);
    esvazis_fila(fi);
    consulta_fila(fi);
}