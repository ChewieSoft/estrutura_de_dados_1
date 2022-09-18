#include "main.h"

int main(int argc, char** argv){
	
	gerenciar_menu_principal();
		
	return 0;
}

int menu_principal(){
	int opcao;
	limpar();
	printf("(1) Gerenciar Produto\n");
	printf("(2) Gerenciar Pedido\n");
	printf("(3) Sair\n");
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
				getch();
				break;
			case 2:
				gerenciar_menu_pedido();
				getch();
				break;
			case 3:
				limpar();
				printf("Sair\n");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!!!\n");
				getch();
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
	printf("(1) A\n");
	printf("(2) B\n");
	printf("(3) Sair\n");
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
				getch();
				break;
			case 2:
				printf("Alterar Produto");
				getch();
				break;								
			case 3:
				printf("Listar produtos");
				sair = 1;
				break;
			case 4:
				printf("Consultar Produto");				
				getch();
				break;
			case 5:
				printf("Excluir Produto");
				getch();
				break;								
			case 6:
				printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
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
	printf("(1) C\n");
	printf("(2) D\n");
	printf("(3) Sair\n");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_pedido(){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_gerenciar_pedido_opcoes();		
		switch(opcao){
			case 1:
				printf("Adicionar produto no carrinho");				
				getch();
				break;
			case 2:
				printf("Consultar carrinho de compras");
				getch();
				break;								
			case 3:
				printf("Excluir produto do carrinho");
				sair = 1;
				break;
			case 4:
				printf("Alterar quantidade do produto do carrinho");				
				getch();
				break;
			case 5:
				printf("Finalizar Pedido");
				getch();
				break;								
			case 6:
				printf("Esvaziar carrinho de compras");
				getch();
				break;								
			case 7:
				printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
}


