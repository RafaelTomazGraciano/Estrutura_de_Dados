/*  Faça um programa que apresente o menu de opções abaixo:
MENU
    Cadastrar tipo
    Cadastrar produto
    Consultar preço de um produto
    Excluir tipo
    Sair
Observações:
    a) Mostrar mensagem de opção inválida no menu. A opção 5 é a única que sai do programa;

    b) Para a implementação do programa acima é necessário utilizar duas estruturas de dados
        do tipo fila;

    c) Na primeira estrutura serão armazenados os tipos dos produtos . Lembrando que não é necessário
        validar a repetição de tipos, ou seja, suponha que todos os tipos cadastrados são diferentes.
        Cada tipo é apenas uma letra.

    d) Na segunda estrutura serão armazenados os produtos cujo número (Código) deve ser.
        gerado automaticamente. O preço e o tipo devem ser digitados. Lembrando que um produto só
        pode ser cadastrado se for de um tipo também já cadastrado, fazer a verificação antes de
        cadastrar o produto e se não tiver o tipo gerar uma mensagem.

    e) Na primeira opção do menu serão cadastrados os tipos, um de cada vez: cada vez que o
        usuário escolhe a opção 1 do menu, ele tem a possibilidade de cadastrar um novo tipo
        (Letra que representa o tipo). Nessa opção a mensagem de
        retorno deverá ser: Tipo cadastrado.

    f) Na segunda opção do menu serão cadastrados os produtos, um de cada vez: cada vez
        que o usuário escolhe a opção 2 do menu, ele tem a possibilidade de cadastrar um novo
        produto (número gerado automaticamente, preço e tipo). Lembrando que um produto só pode ser
        cadastrado se o tipo ao qual ele pertence já existe na fila de tipo. Nesta opção as mensagens
        disponíveis são: Produto cadastrado e Tipo de produto inexistente.

    g) Na terceira opção do menu o usuário digita o número do produto que deseja consultar o preço e,
        se este existir na fila de produtos, o programa deve mostrar seu preço. Nesta opção,
        as mensagens são: Preço, Produto não encontrado e Fila vazia.

    h) Na quarta opção o programa deve excluir um tipo da fila de tipos, respeitando a forma
        de organização de uma fila.
*/

#include "funcoes_ex08.h"

int main(){
    Fila *f1 = cria_fila(), *f2 = cria_fila();
    int opcao, n = 1, numero_produto;
    char tipo;
    float preco;
    do{
        clear_terminal();
        menu();
        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);
        switch (opcao) {
            case 1:
                printf("Digite o tipo do produto: ");
                scanf("%c", &tipo);
                cadastrar_tipo(f1, tipo);
                break;
            case 2:
                printf("Digite o preco: ");
                scanf("%f", &preco);
                setbuf(stdin, NULL);
                printf("Digite o tipo do produto: ");
                scanf("%c", &tipo);
                setbuf(stdin, NULL);
                cadastrar_produto(f1, f2, preco, n, tipo);
                n++;
                break;
            case 3:
                printf("Digite o numero do produto: ");
                scanf("%d", &numero_produto);
                consultar_preco_produto(f2, numero_produto);
                break;
            case 4:
                excluir(f1);
                break;
            case 5:
                return 0;
            default:
                printf("Opcao invalida!");
        }
        printf("\n\n\t\tPress Enter to Continue");
        setbuf(stdin,NULL);
        while( getchar() != '\n' );
    }while(opcao != 5);
    return 0;
}
