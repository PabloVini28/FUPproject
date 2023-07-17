#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <windows.h>
#include <locale.h>

#include "imprime.h"

typedef struct{
	char nome[100];
	float preco; 
} obra;


obra ler_filme(){
	obra b;
    printf("DIGITE O NOME DO FILME: ");
	scanf(" %[^\n]", b.nome);
    printf("DIGITE O VALOR DO FILME: ");
	scanf("%f", &b.preco);

	return	b;
}


obra* insere_filme(obra *v, int *n, obra novo)
{
   v = (obra*)realloc(v,(*n+1) * sizeof(obra));
   if(v==0){
       printf("ERRO: NAO FOI POSSIVEL INSERIR O FILME");
       return 0;
   }
   v[*n] = novo;
   (*n)++;
   return v;
}


obra* remove_filme(obra *v, int *n, char nome[100])
{
   for(int i=0; i<*n; i++){
        if(strcmp(v[i].nome, nome)==0){
           v[i] = v[*n-1];
           v = (obra*)realloc(v,(*n-1)*sizeof(obra));
           (*n)--;
           break;
       }
   }
   return v;
}


int salvar_catalogo(int n, obra v[n]){
    FILE *f = fopen("catalogo.txt", "w");
    if (f == 0) {
        printf("ERRO AO ABRIR O ARQUIVO DE CATALOGO!");
        return 0;
    }
    
    for(int i = 0; i<n; i++)
        fprintf(f, "%s\n%.1f\n", v[i].nome, v[i].preco);
    
    fclose(f);
}


obra* insere_carrinho(obra *v2, int *n2, obra d){
   v2 = (obra*)realloc(v2,(*n2+1) * sizeof(obra));
   if(v2==0){
       printf("ERRO: NAO FOI POSSIVEL INSERIR O FILME NO CARRINHO\n");
       return 0;
   }
   v2[*n2] = d;
   (*n2)++;
   return v2;
}


obra* remove_carrinho(obra *v2, int *n2, char nome[100])
{
   for(int i=0;i<*n2;i++){
        if(strcmp(nome, v2[i].nome)==0){
           v2[i] = v2[*n2-1];
           v2 = (obra*)realloc(v2,(*n2-1)*sizeof(obra));
           (*n2)--;
           break;
       }
   }
   return v2;
}



int main()
{   
    int opmenu = 0;
    while(opmenu!=4){
        imprime_locafup();
        imprime_menu();
        printf("OPCAO ESCOLHIDA: ");
        scanf(" %d",&opmenu);



        if(opmenu == 3){
            imprime_creditos();
        }
        else if(opmenu == 4){
            exit;
        }
        else if(opmenu == 1){                                                       //EDITAR ITENS DO CARRINHO
            int n = 0;
            obra *v = 0;


            FILE *f = fopen("catalogo.txt", "r");                                      //LE O CATALOGO E ADICIONA AO VETOR
            if (f == 0) { 
                printf("ERRO AO ABRIR O ARQUIVO DO CATALOGO!"); 
                return 0; 
            }
            
            obra c;
            while (fscanf(f, "%[^\n]\n%f\n", c.nome, &c.preco) == 2) {
                v = insere_filme(v, &n, c);
            }
        
            fclose(f);


            if(n>0){                                                                   //SE HOUVER CATALOGO, LE O ARQUIVO DO CARRINHO
                imprime_menu_carrinho();

                int n2 = 0;
                obra *v2 = 0;


                FILE *f = fopen("carrinho.txt", "r");
                if (f == 0) { 
                    printf("ERRO AO ABRIR O ARQUIVO DO CARRINHO!"); 
                    return 0; 
                }
                obra c;
                while (fscanf(f, "%[^\n]\n%f\n", c.nome, &c.preco) == 2) {
                    v2 = insere_carrinho(v2, &n2, c);
                }
                fclose(f);



                if(n2>0){                                                              //SE HOUVER ITENS NO CARRINHO, IMPRIME
                    printf("CARRINHO:\n");
                    for (int i = 0; i < n2; i++){
                        printf("%d - %s\n",i+1, v2[i].nome);
                    }
                } else {
                    printf("NAO HA FILMES NO CARRINHO! \n");
                    printf("\n");
                }


                printf("\n==================================================\n\n");     //IMPRIME O CATALOGO
                printf("|CATALOGO:|\n");
                printf("\n");

                printf("0 - FECHAR CARRINHO\n");
                for (int j = 0; j < n; j++)                                             //IMPRIME APENAS O QUE NAO ESTIVER NO CARRINHO
                {
                    int aparece = 0;
                    for (int i = 0; i < n2; i++){
                        if(strcmp(v[j].nome, v2[i].nome)==0){
                            aparece = 1;
                        }
                    }
                    if(aparece==0){
                        printf("%d - |%s| %.1f REAIS\n", j+1, v[j].nome, v[j].preco);
                    }
                }
                
                
                printf("\n");
                printf("DIGITE O NUMERO REFERENTE AO FILME QUE QUEIRA ALUGAR OU 0 PARA SAIR!\n");
                

                int opcart = 1;                                                         //ADICIONA AO CARRINHO
                while(opcart!=0){
                    scanf(" %d", &opcart);
                    if(opcart!=0)
                        for(int i = 0; i<n; i++){
                            if((opcart-1)==i){
                                v2 = insere_carrinho(v2, &n2, v[i]);
                                printf("|%s| ADICIONADO AO CARRINHO!\n\n", v[opcart-1].nome);
                                printf("ESCOLHA OUTRO FILME OU TECLE 0 PARA SAIR!\n");
                            }
                        }
                } 

                if(opcart==0) {                                                         //SALVA E VAI PARA A FINALIZACAO
                    int repcart = 1;
                    while(repcart){
                        FILE *f = fopen("carrinho.txt", "w");
                        if (f == 0) {
                            printf("ERRO AO ABRIR O ARQUIVO!");
                            return 0;
                        }
                        for(int i = 0; i<n2; i++)
                            fprintf(f, "%s\n%.1f\n", v2[i].nome, v2[i].preco);
                        fclose(f);
                        

                        system("cls");
                        printf("\n");
                        imprime_menu_finalizacao();
                        if(n2>0){
                            printf("CARRINHO:\n");
                            for (int i = 0; i < n2; i++){
                                printf("%d - %s\n",i+1, v2[i].nome);
                            }
                        } else {
                            printf("NAO HA FILMES NO CARRINHO! \n");
                            printf("\n");
                        }

                        

                        float soma = 0;
                        int opfinalizacao;
                        scanf(" %d", &opfinalizacao);
                        if(opfinalizacao==1&&n2>0){
                            system("cls");
                            printf("CARRINHO FINAL:\n");
                            for (int i = 0; i < n2; i++){
                                printf("|%s| %.1f REAIS\n", v2[i].nome,v2[i].preco);
                            }
                            for (int i = 0; i < n2; i++){
                                soma = soma+v2[i].preco;
                            }
                            printf("\nTOTAL: %.2f REAIS\n", soma);
                            printf("\n");
                            printf("ESCOLHA O METODO DE PAGAMENTO!\n");
                            printf("1 - PIX\n");
                            printf("2 - CARTAO\n");
                            int oppay;
                            scanf(" %d",&oppay);
                            if(oppay == 1){
                                printf("\n");
                                printf("COMPRA EFETIVADA POR PIX NO VALOR DE %.2f REAIS!\n", soma);
                                printf("DIGITE QUALQUER VALOR PARA AVANCAR\n");

                                int leu;
                                if(scanf(" %d",&leu)){
                                    agradece();
                                }
                            }
                            else if(oppay == 2)
                            {

                                float vezes1 = soma;
                                float vezes2 = soma/2;
                                float vezes3 = soma/3;
                                printf("\n");
                                printf("O PARCELAMENTO PODE SER FEITO EM ATE 3 VEZES, SENDO ELES:\n");
                                printf("\n");
                                printf("1 - EM UMA VEZ DE %.2f\n",vezes1);
                                printf("2 - EM DUAS VEZES DE %.2f\n",vezes2);
                                printf("3 - EM TRES VEZES DE %.2f\n",vezes3);
                                printf("EM QUANTAS VEZES DESEJA PARCELAR?\n");
                                int parcel;
                                scanf(" %d",&parcel);
                                if(parcel == 1)
                                {
                                    system("cls");
                                    printf("PARCELAMENTO EFETIVADO EM UMA VEZ!\n\n");
                                    printf("DIGITE QUALQUER VALOR PARA AVANCAR\n");

                                    int leu;
                                    if(scanf(" %d",&leu)){
                                        agradece();
                                    }

                                }
                                else if(parcel == 2)
                                {
                                    system("cls");
                                    printf("PARCELAMENTO EFETIVADO EM DUAS VEZES!\n\n");
                                    printf("DIGITE QUALQUER VALOR PARA AVANCAR\n");

                                    int leu;
                                    if(scanf(" %d",&leu)){
                                        agradece();
                                    }
                                }
                                else if(parcel == 3)
                                {
                                    system("cls");
                                    printf("PARCELAMENTO EFETIVADO EM TRES VEZES\n\n");
                                    printf("DIGITE QUALQUER VALOR PARA AVANCAR\n");

                                    int leu;
                                    if(scanf(" %d",&leu)){
                                        agradece();
                                    }
                                }
                            }
                            repcart=0;
                        }
                        else if(opfinalizacao==2&&n2>0){                                                //OPCAO DE REMOVER ITENS DO CARRINHO
                            int num_oper;
                            printf("QUANTOS FILMES VOCE DESEJA REMOVER? ");
                            scanf(" %d", &num_oper);
                            if(num_oper == 0){
                                exit;
                            }
                            for (int i = 0; i < num_oper; i++) {
                                printf("DIGITE O NOME DO FILME QUE QUEIRA REMOVER: ");
                                char nome[100];
                                scanf(" %[^\n]", nome);
                                v2 = remove_carrinho(v2, &n2, nome);
                            }

                            FILE *h = fopen("carrinho.txt", "w");                                       //DEPOIS SALVA O CARRINHO
                            if (h == 0) {
                                printf("ERRO AO ABRIR O ARQUIVO!");
                                return 0;
                            }
                
                            for(int i = 0; i<n2; i++)
                                fprintf(h, "%s\n%.1f\n", v2[i].nome, v2[i].preco);
                
                            fclose(h);
                        } else if(opfinalizacao==3){
                            repcart=0;
                        }
                    }
                }
            } else {
                printf("NAO HA FILMES NO CATALOGO: \n");
                printf("\n");
            }
        }



        else if(opmenu == 2){                                                                                   //EDICAO DO CATALOGO
            int x = 1;
                system("cls");
                printf("\n");
                printf("O CATALOGO DE FILMES FOI PREVIAMENTE FEITO PELOS DESENVOLVEDORES\n");
                printf("POREM, ELE PODE SER ALTERADO PELO USUARIO!\n");
                printf("\n");
                printf("DIGITE A SENHA:\n");
                printf("DICA:ANO DE LANCAMENTO DO PRIMEIRO COMPUTADOR ELETRONICO E DIGITAL\n");

                int pass;
                scanf(" %d",&pass);
                if(pass == 1946){
                    while(x){
                        system("cls");
                        int n = 0, i;
                        obra *v = 0;

                        FILE *f = fopen("catalogo.txt", "r");
                        if (f == 0) { 
                            printf("ERRO AO ABRIR O ARQUIVO!"); 
                            return 0; 
                        }
                        obra c;
                        while (fscanf(f, "%[^\n]\n%f\n", c.nome, &c.preco) == 2) {
                            v = insere_filme(v, &n, c);
                        }
                        fclose(f);

                        imprime_menu_edicao();

                        if(n>0){
                            printf("\n");
                            printf("CATALOGO: \n");
                            printf("|| NOME | PRECO ||\n\n");
                            for (i = 0; i < n; i++){
                                printf("%s |RS%.2f|\n", v[i].nome, v[i].preco);
                            }
                        } else {
                            printf("NAO HA FILMES NO CATALOGO: \n");
                            printf("\n");
                        }
                        
                        

                        printf("\nDIGITE O NUMERO DE MUDANCAS: ");
                        int num_oper = 0;
                        scanf(" %d", &num_oper);
                        if(num_oper == 0){
                            x=0;
                            exit;
                        }
                        for (i = 0; i < num_oper; i++) {
                            char oper;
                            printf("\nDIGITE A OPERACAO\n"); 
                            printf("+ PARA ADICIONAR FILMES OU - PARA REMOVER: ");
                            scanf(" %c", &oper);
                            if (oper == '+') {
                                obra a = ler_filme();
                                v = insere_filme(v, &n, a);
                            } else {
                                printf("DIGITE APENAS O NOME DO FILME QUE QUEIRA REMOVER: ");
                                char nome[100];
                                scanf(" %[^\n]", nome);
                                v = remove_filme(v, &n, nome);
                            }
                        }
                        printf("\n");
                        printf("CATALOGO: \n");	
                        for (i = 0; i < n; i++)
                        printf("%s |RS%.2f|\n", v[i].nome, v[i].preco);	
                        



                        salvar_catalogo(n, v);
                    }
                }
                else{
                    printf("\n");
                    printf("SENHA ERRADA!\n\n");
                    printf("DIGITE QUALQUER NUMERO PARA VOLTAR AO MENU!\n");
                    int erro;
                    scanf(" %d",&erro);
                }
        }
    }
}