#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void gerenciar_menu_principal();
int menu_principal();
void gerenciar_menu_produto();
int menu_produto();
void gerenciar_menu_pedido();
int menu_pedido();

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
