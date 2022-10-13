#include "configuration.h"

const int REALLOCFACT = 5;
const int ITEM_NAO_ENCONTRADO = -1;

long rand_code(){
	long n = 0;
	do{
	 n *= RAND_MAX;
	 n += rand();
	} while(n < 1000000000);
	return n % 10000000000;
}

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
