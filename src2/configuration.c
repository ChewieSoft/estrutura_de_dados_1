#include "configuration.h"

int ITEM_NAO_ENCONTRADO = -1;
int REALLOCFACT = 5;

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
