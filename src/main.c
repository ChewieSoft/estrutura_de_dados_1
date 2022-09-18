#include "main.h"

int main(int argc, char** argv){	
	gerenciar_menu_principal();		
	return 0;
}

int menu_principal(){
	int opcao;
	limpar();
	printf("#########################\n");
	printf("        HORTIFRUTI       \n");
	printf("#########################\n");
	printf("(1) Gerenciar Produto\n");
	printf("(2) Gerenciar Pedido\n");
	printf("(3) Sair\n");
	printf("\n\nSelecionar opcao:");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_principal(){
	int opcao;
	int sair = 0;
	do{
		opcao = menu_principal();
		switch(opcao){
			case 1:
				gerenciar_menu_produto();
				break;
			case 2:
				gerenciar_menu_pedido();
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

int menu_produto(){
	int opcao;
	limpar();
	printf("#########################\n");
	printf("    Gerenciar Produto\n");
	printf("#########################\n");
	printf("\n(1) Incluir");
	printf("\n(2) Alterar");
	printf("\n(3) Listar");
	printf("\n(4) Consultar");
	printf("\n(5) Excluir");
	printf("\n(6) Voltar");
	printf("\n\nSelecionar opcao:");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_produto(){
	int opcao;
	int sair = 0;
	do{
		opcao = menu_produto();
		switch(opcao){
			case 1:
				printf("Incluir Produto");				
				break;
			case 2:
				printf("Alterar Produto");
				break;								
			case 3:
				printf("Listar produtos");
				break;
			case 4:
				printf("Consultar Produto");				
				break;
			case 5:
				printf("Excluir Produto");
				break;								
			case 6:
				printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				sair = 0;
		}	
	}while(!sair);
	
}

int menu_pedido(){
	int opcao;
	limpar();
	printf("#########################\n");
	printf("     Gerenciar Pedido    \n");
	printf("#########################\n");
	printf("\n(1) Adicionar produto no carrinho");
	printf("\n(2) Consultar carrinho de compras");
	printf("\n(3) Excluir produto do carrinho");
	printf("\n(4) Alterar quantidade do produto do carrinho");	
	printf("\n(5) Finalizar Pedido");	
	printf("\n(6) Esvaziar carrinho de compras");
	printf("\n(7) Voltar");
	printf("\n\nSelecionar opcao:");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_pedido(){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_pedido();		
		switch(opcao){
			case 1:
				printf("Adicionar produto no carrinho");				
				break;
			case 2:
				printf("Consultar carrinho de compras");
				break;								
			case 3:
				printf("Excluir produto do carrinho");
				break;
			case 4:
				printf("Alterar quantidade do produto do carrinho");				
				break;
			case 5:
				printf("Finalizar Pedido");
				break;								
			case 6:
				printf("Esvaziar carrinho de compras");
				break;								
			case 7:
				printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				sair = 0;			
		}
	}while(!sair);
}


