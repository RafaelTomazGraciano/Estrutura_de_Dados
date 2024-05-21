/* Apresente o menu de opções abaixo:
    1- Cadastrar aluno
    2- Cadastrar nota
    3- Calcular a média de um aluno
    4- Listar os nomes dos alunos sem notas
    5- Excluir aluno
    6- Excluir nota
    7- Sair

Observações:
    a) Cadastre um aluno (número e nome) de cada vez em uma pilha. Os números dos alunos
        devem ser gerados automaticamente, partindo do no 1.

    b) Cadastre uma nota (número do aluno e nota) de cada vez em uma fila. Uma nota só
        pode ser cadastrada se pertencer a um aluno cadastrado na pilha de alunos.
        Mostrar mensagem caso o aluno não esteja cadastrado. Valide as notas para que sejam digitadas
        no intervalo entre 0 e 10.

    c) O usuário deve digitar o número de aluno para exibir seu nome e sua respectiva média.
    Caso não existir o aluno ou não houver notas cadastradas para ele emitir mensagem de aviso ao usuário.

    d) Um aluno só pode ser excluído se não possuir notas. O usuário não deve escolher o
        aluno a ser excluído, pois deve obedecer às regras de funcionamento da estrutura de dados tipo pilha.

    e) As notas devem ser excluídas respeitando as regras de funcionamento de uma estrutura
        do tipo fila.
*/

#include "funcoes_ex06.h"

int main(){
    Pilha * pi = cria_pilha();
    Fila *fi = cria_fila();
    int opcao, numero = 1, numeroAluno;
    float nota;
    char nome[255];
    do{
        clear_terminal();
        menu();
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);
        switch (opcao) {
            case 1:
                printf("Digite o nome do aluno: ");
                fgets(nome, 255, stdin);
                setbuf(stdin, NULL);
                cadastrar_aluno(pi, numero, nome);
                numero++;
                break;
            case 2:
                printf("Digite a nota: ");
                scanf("%f", &nota);
                printf("Digite o numero do aluno: ");
                scanf("%d", &numeroAluno);
                if(numeroAluno > numero){
                    printf("Esse aluno nao existe");
                }
                else{
                    cadastrar_nota(pi, fi, numeroAluno, nota);
                }
                break;
            case 3:
                printf("Digite o numero do aluno: ");
                scanf("%d", &numeroAluno);
                if(numeroAluno > numero){
                    printf("Esse aluno nao existe");
                }
                else{
                    media(pi, fi, numeroAluno);
                }
                break;
            case 4:
                listar(pi);
                break;
            case 5:
                excluirAluno(pi);
                break;
            case 6:
                excluirNota(pi, fi);
                break;
            case 7:
                return 0;
            default:
                printf("Opcao invalida!");
        }
        printf("\n\n\t\tPress Enter to Continue");
        setbuf(stdin,NULL);
        while( getchar() != '\n' );
    }while(opcao != 7);
    return 0;
}


