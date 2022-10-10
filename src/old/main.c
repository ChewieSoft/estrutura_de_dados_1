#include "produto.h"
#include "pedido.h"
#include "configuration.h"
#include "menu.h"

int main(int argc, char** argv){
	setlocale(LC_ALL, "Portuguese");

	Produto* produtos = NULL;
	Pedido* pedidos = NULL;
	
	produtos = (Produto*) malloc(5 * sizeof(Produto));
	int i =0;
	for(i=0;i<5;i++){
		produtos[i].codigo = i;
		strcpy(produtos[i].descricao, "Produto");
		produtos[i].preco = rand() % 21;
		produtos[i].qtd_estoque = rand() % 50;
	}
	
	gerenciar_menu_principal(produtos, pedidos);
	return 0;
}
