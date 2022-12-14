#include "configuration.h"
#include "produto.h"
#include "pedido.h"

//GERENCIAR
int menu_principal(){
	int opcao = 0;
	printf("\n#########################");
	printf("\n        HORTIFRUTI       ");
	printf("\n#########################");
	printf("\n(1) Gerenciar Produto");
	printf("\n(2) Gerenciar Pedido");
	printf("\n(3) RESETAR");
	printf("\n(4) Sair");
	printf("\n\nSelecionar opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_principal(ListaProduto* listaProduto, ListaPedido* listaPedido){
	int opcao;
	int sair = 0;
	do{
		limpar();
		opcao = menu_principal();
		switch(opcao){
			case 1:
				listaProduto = gerenciar_menu_produto(listaProduto);
				break;
			case 2:
				listaPedido = gerenciar_menu_pedido(listaProduto, listaPedido);
				break;
			case 3:
				listaProduto = kill_produto(listaProduto);
				listaPedido = kill_pedido(listaPedido);
				printf("\nRESETADO COM SUCESSO!!!\n");
				pausa();
				break;
			case 4:
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

	ListaPedido* listaPedido = NULL;
	ListaProduto* listaProduto = NULL;

	gerenciar_menu_principal(listaProduto, listaPedido);
	return 0;
}
