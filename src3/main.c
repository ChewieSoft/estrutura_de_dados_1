#include "configuration.h"
#include "produto.h"
#include "pedido.h"

int qtdProd = 0;
int maxProd = 0;

//GERENCIAR
int menu_principal(){
	int opcao = 0;
	printf("\n#########################");
	printf("\n        HORTIFRUTI       ");
	printf("\n#########################");
	printf("\n(1) Gerenciar Produto");
	printf("\n(2) Gerenciar Pedido");
	printf("\n(3) Sair");
	printf("\n\nSelecionar opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_principal(ListaProduto* listaProduto, int maxProd, ListaPedido* listaPedido){
	int opcao;
	int sair = 0;
	do{
		limpar();
		opcao = menu_principal();
		switch(opcao){
			case 1:
				listaProduto = gerenciar_menu_produto(listaProduto, maxProd, qtdProd);
				break;
			case 2:
				gerenciar_menu_pedido(listaProduto, qtdProd, listaPedido);
				break;
			case 3:
				limpar();
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!!!\n");
				sair = 0;
		}
	}while(!sair);
}

//CODIGO
int main(int argc, char** argv){

	ListaProduto* listaProduto = NULL;
	ListaPedido* listaPedido = NULL;

	gerenciar_menu_principal(listaProduto, maxProd, listaPedido);
	return 0;
}
