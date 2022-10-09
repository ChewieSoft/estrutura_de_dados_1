#include "configuration.h"

//STRUCT
typedef struct produto{
	int codigo;
	char descricao[50];
	int qtd_estoque;
	float preco;
}Produto;

typedef struct pedido{
	int codigo;
	struct produto* produto;
	int quantidade;
	int total;
}Pedido;

//VARIAVEIS
Produto* produtos = NULL;
qtdProd = 0;
maxProd = 5;
Pedido* pedidos = NULL;
qtdPed = 0;
maxPed = 5;

//PRODUTO
void incluir_produto(){
	limpar();
	printf("\nIncluir Produto");
	printf("\nIMPLEMENTAR");
}

void alterar_produto(){
	limpar();
	printf("\nAlterar Produto");
	printf("\nIMPLEMENTAR");
}

void listar_produtos(struct produto* produtos, int qtd){
	limpar();
	printf("\nListar produtos\n\n");
	int i = 0;
	for (i = 0; i < qtd; i++){
		printf("Produto : -- Codigo: %d -- Descricao: %s -- Quantidade em estoque: %d -- Preco: %.2f\n", 
			produtos[i].codigo,
			produtos[i].descricao,
			produtos[i].qtd_estoque,
			produtos[i].preco
		);
	}
	printf("\n");
	pausa();
}

void consultar_produto(){
	limpar();
	printf("\nConsultar Produto");
	printf("\nIMPLEMENTAR");
}

void excluir_produto(){
	limpar();
	printf("\nExcluir Produto");
	printf("\nIMPLEMENTAR");
}

//PEDIDO
void adicionar_produto_carrinho(){
	limpar();
	printf("\nAdicionar produto no carrinho");
	printf("\nIMPLEMENTAR");
}

void consultar_carrinho_compras(){
	limpar();
	printf("Consultar carrinho de compras");
	printf("\nIMPLEMENTAR");
}

void excluir_produto_carrinho(){
	limpar();
	printf("Excluir produto do carrinho");
	printf("\nIMPLEMENTAR");
}

void alterar_quantidade_produto_carrinho(){
	limpar();
	printf("Alterar quantidade do produto do carrinho");
	printf("\nIMPLEMENTAR");
}

void finalizar_pedido(){
	limpar();
	printf("Finalizar Pedido");
	printf("\nIMPLEMENTAR");
}

void esvaziar_carrinho(){
	limpar();
	printf("Esvaziar carrinho de compras");
	printf("\nIMPLEMENTAR");
}

//GERENCIAR
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
	printf("\n\nSelecionar opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_pedido(Pedido* pedidos){
	int opcao;
	int sair = 0;
	limpar();
	do{	
		opcao = menu_pedido();		
		switch(opcao){
			case 1:				
				adicionar_produto_carrinho();
				break;
			case 2:
				consultar_carrinho_compras();
				break;								
			case 3:
				excluir_produto_carrinho();
				break;
			case 4:
				alterar_quantidade_produto_carrinho();
				break;
			case 5:
				finalizar_pedido();
				break;								
			case 6:
				esvaziar_carrinho();
				break;								
			case 7:
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				sair = 0;			
		}
	}while(!sair);
}

int menu_produto(){
	int opcao;
	limpar();
	printf("#########################\n");
	printf("    Gerenciar Produto    \n");
	printf("#########################\n");
	printf("\n(1) Incluir");
	printf("\n(2) Alterar");
	printf("\n(3) Listar");
	printf("\n(4) Consultar");
	printf("\n(5) Excluir");
	printf("\n(6) Voltar");
	printf("\n\nSelecionar opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_produto(Produto* produtos){
	int opcao;
	int sair = 0;
	do{
		opcao = menu_produto();
		switch(opcao){
			case 1:
				incluir_produto();
				break;
			case 2:
				alterar_produto();
				break;								
			case 3:
				listar_produtos(produtos, qtdProd);
				break;
			case 4:
				consultar_produto();
				break;
			case 5:
				excluir_produto();
				break;								
			case 6:
				sair = 1;
				break;
			default:
				printf("Op��o Inv�lida!");
				sair = 0;
		}	
	}while(!sair);	
}

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

void gerenciar_menu_principal(Produto* produto, Pedido* pedido){
	int opcao;
	int sair = 0;
	do{
		limpar();
		opcao = menu_principal();
		switch(opcao){
			case 1:
				gerenciar_menu_produto(produto);
				break;
			case 2:
				gerenciar_menu_pedido(pedido);
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
	
	produtos = (Produto*) malloc(maxProd * sizeof(Produto));
	int i = 0;
	for(i = 0; i < 2 ; i++){
		produtos[i].codigo = i;
		strcpy(produtos[i].descricao, "Produto");
		produtos[i].preco = rand() % 21;
		produtos[i].qtd_estoque = rand() % 50;
		qtdProd ++;
	}
	
	gerenciar_menu_principal(produtos, pedidos);
	return 0;
}
