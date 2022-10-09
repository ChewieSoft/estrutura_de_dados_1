#include "configuration.h"
#include "menu.h"

typedef struct pedido{
	int codigo;
	struct produto* produto;	
	int quantidade;
	int total;
}Pedido;

typedef struct produto {
	int codigo;
	char descricao[50];
	int qtd_estoque;
	float preco;
}Produto;

Produto* produtos = NULL;
Pedido* pedidos = NULL;

int main(int argc, char** argv){
	setlocale(LC_ALL, "Portuguese");
	
	produtos = (Produto*) malloc(5 * sizeof(Produto));
	int i =0;
	for(i=0;i<5;i++){
		produtos[i].codigo = i;
		strcpy(produtos[i].descricao, "Produto");
		produtos[i].preco = rand() % 21;
		produtos[i].qtd_estoque = rand() % 50;
	}
	
	gerenciar_menu_principal(*produtos, *pedidos);
	
	gerenciar_menu_principal();
	return 0;
}
