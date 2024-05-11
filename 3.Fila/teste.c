#include "funcoes_fila.h"

int main(){
    Fila *fi = cria_fila();
    insere_elemento(fi);
    insere_elemento(fi);
    insere_elemento(fi);
    consulta_fila(fi);
    remove_elemento(fi);
    consulta_fila(fi);
    esvazis_fila(fi);
    consulta_fila(fi);
}