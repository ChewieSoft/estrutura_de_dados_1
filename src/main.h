#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

//PRINCIPAL
void gerenciar_menu_principal();
int menu_principal();

//PRODUTO
void gerenciar_menu_produto();
int menu_produto();
void incluir_produto();
void alterar_produto();
void listar_produtos();
void consultar_produto();
void excluir_produto();

//PEDIDO
void gerenciar_menu_pedido();
int menu_pedido();
void adicionar_produto_carrinho();
void consultar_carrinho_compras();
void excluir_produto_carrinho();
void alterar_quantidade_produto_carrinho();
void finalizar_pedido();
void esvaziar_carrinho();

void limpar(){
    #if defined(WIN32) || defined (WIN64)
        system("cls");
    #elif defined(unix)
        system("clear");
    #endif
}

void pausa(){
    #if defined(WIN32) || defined (WIN64)
        system("pause");
    #elif defined(unix)
        system("read -p 'Aperte Enter para continuar...' var");
    #endif
}

void sair() {
    printf("Sair\n");
    exit(0);
}
