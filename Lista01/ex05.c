/* Faca um programa que apresente o menu de opcoes abaixo:
    MENU
    1 - Cadastrar numero
    2 - Mostrar numeros pares
    3 - excluir numero
    4 - Sair
Observacoes:
    a) O programa deve ser implementado usando ums estrutura do tipo pilha
    b) A opcao 1 do menu cadastra um numero de cada vez
    c) Mostrar mensagem para opcao invalida do menu
 */

#include "funcoes_ex05.h"

int main(){
    Pilha *pi = cria_pilha();
    int opcao;
    do{
        clear_terminal();
        menu();
        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrar(pi);
                break;
            case 2:
                mostrar_par(pi);
                break;
            case 3:
                excluir(pi);
                break;
            case 4:
                return 0;
            default:
                printf("Opcao invalida!");
        }
        printf("\n\n\t\tPress Enter to Continue");
        setbuf(stdin,NULL);
        while( getchar() != '\n' );
    }while(opcao != 4);

    return 0;
}