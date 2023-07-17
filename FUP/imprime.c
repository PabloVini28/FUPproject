#include <stdio.h>
#include <windows.h>
#include "imprime.h"

void imprime_locafup(){
    system("cls");
    printf("\n");
    printf("888                                8888888888 888     888 8888888b.  \n");
    printf("888                                888        888     888 888   Y88b \n");
    printf("888                                888        888     888 888    888 \n");
    printf("888      .d88b.   .d8888b  8888b.  8888888    888     888 888   d88P \n");
    printf("888     d88''88b d88P'        '88b 888        888     888 8888888P'  \n");
    printf("888     888  888 888      .d888888 888        888     888 888     \n");
    printf("888     Y88..88P Y88b.    888  888 888        Y88b. .d88P 888    \n");
    printf("88888888 'Y88P'   'Y8888P 'Y888888 888         'Y88888P'  888   \n");
    printf("\n\n");
}

void imprime_menu()
{
    printf("|--------------------------------------------------|\n");
    printf("|                  MENU PRINCIPAL                  |\n");
    printf("|--------------------------------------------------|\n");
    printf("|               BEM-VINDO AO LOCAFUP               |\n");
    printf("|--------------------------------------------------|\n");
    printf("|         :DIGITE 1 PARA ALUGAR FILMES:            |\n");
    printf("|         :DIGITE 2 PARA EDITAR CATALOGO:          |\n");
    printf("|         :DIGITE 3 PARA VER A EQUIPE:             |\n");
    printf("|         :DIGITE 4 PARA SAIR DA LOCAFUP:          |\n");
    printf("|--------------------------------------------------|\n\n");
}

void imprime_menu_carrinho(){
    system("cls");
    printf("|----------------------------------------------------------------------|\n");
    printf("|                           MENU DO CARRINHO                           |\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("|  -ESTE E O MENU DO CARRINHO, AQUI VOCE PODE ACRESCENTAR SEUS FILMES! |\n");
    printf("|----------------------------------------------------------------------|\n");   
    printf("|  -BASTA DIGITAR O NUMERO REFERENTE AO FILME!                         |\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("|  -VOCE PODE FINALIZAR A QUALQUER MOMENTO DIGITANDO 0!                |\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("\n");
}

void imprime_menu_edicao(){
    printf("\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                            MENU DE EDICAO                           |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|  -PRIMEIRO, DECIDA QUANTOS FILMES VAI ADICIONAR E(OU)REMOVER!       |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|  -FEITO ISSO, UTILIZE OS OPERADORES + E - PARA REALIZAR AS MUDANCAS!|\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|  -CASO QUEIRA REMOVER, DIGITE APENAS O NOME DO FILME!               |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|  -CASO QUEIRA RETORNAR AO MENU, DIGITE 0 NA PRIMEIRA OPERACAO!      |\n");
    printf("|---------------------------------------------------------------------|\n\n");
}

void imprime_menu_finalizacao(){
    printf("\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("|                        MENU DE FINALIZACAO                           |\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("|  -DIGITE 1 CASO QUEIRA FINALIZAR SUA COMPRA!                         |\n");
    printf("|----------------------------------------------------------------------|\n");   
    printf("|  -DIGITE 2 CASO QUEIRA REMOVER ALGUM FILME DO CARRINHO!              |\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("|  -DIGITE 3 CASO QUEIRA RETORNAR AO MENU!                             |\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("\n");
}

void imprime_creditos()
{
    system("cls");
    printf("\n");
    printf("====================================\n");
    printf("|           DESENVOLVIDO           |\n");
    printf("|               POR:               |\n");
    printf("|==================================|\n");
    printf("|           -PABLO VINI            |\n");
    printf("|           -GABRIEL B.            |\n");
    printf("|           -WILLIAM M.            |\n");
    printf("|==================================|\n");
    printf("|- ENGENHARIA DA COMPUTACAO 2022.1 |\n");
    printf("|==================================|\n");
    printf("|- UFC - CAMPUS DE QUIXADA         |\n");
    printf("|==================================|\n");
    printf("|-PROFESSOR ORIENTADOR:            |\n");
    printf("|-CRISTON SOUZA                    |\n");
    printf("====================================\n");
    printf("\n");
    printf("DIGITE QUALQUER NUMERO PARA VOLTAR!\n\n");
    int a;
    scanf(" %d", &a);
}

int agradece(){
    system("cls");
    printf("\n");
    printf("|--------------------------------------------------|\n");
    printf("|              FINALIZACAO DA COMPRA               |\n");
    printf("|--------------------------------------------------|\n");
    printf("|         A LOCAFUP AGRADECE A PREFERENCIA         |\n");
    printf("|--------------------------------------------------|\n");
    printf("|                  OBRIGADO,TURMA!                 |\n");
    printf("|            OBRIGADO,PROFESSOR CRISTON!           |\n");
    printf("|               BOAS FERIAS A TODOS!               |\n");
    printf("|--------------------------------------------------|\n\n");
    printf("\n");
    printf("DIGITE QUALQUER NUMERO PARA VOLTAR!\n");
    int u;
    if(scanf("%d",&u)){
        FILE *h = fopen("carrinho.txt", "w");
        if (h == 0) {
            printf("ERRO AO ABRIR O ARQUIVO!");
            return 0;
        }
        fclose(h);
    }
}
