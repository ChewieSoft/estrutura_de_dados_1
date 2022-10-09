#include "configuration.h"

#define ITEM_NAO_ENCONTRADO -1

//STRUCTS
typedef struct produto{
	int codigo;
	char descricao[50];
	int qtd_estoque;
	float preco;
}Produto;

typedef struct pedido{
	int codigo;
	int produto;
	int quantidade;
	int total;
}Pedido;

//VARIAVEIS
Produto* produtos = NULL;
int qtdProd = 0;
int maxProd = 10;
Pedido* pedidos = NULL;
int qtdPed = 0;
int maxPed = 2;

//PRODUTO
void incluir_produto(){
	printf("\nIMPLEMENTAR");
}

void alterar_produto(){
	printf("\nIMPLEMENTAR");
}

void listar_produtos(struct produto* produtos, int qtd, bool isVazio){
	int i = 0;
	for (i = 0; i < qtd; i++){
		if(isVazio){
			printf("Produto : -- Codigo: %d -- Descricao: %s -- Quantidade em estoque: %d -- Preco: %.2f\n", 
				produtos[i].codigo,
				produtos[i].descricao,
				produtos[i].qtd_estoque,
				produtos[i].preco
			);
		}
		else if(produtos[i].qtd_estoque > 0){
			
			printf("Produto : -- Codigo: %d -- Descricao: %s -- Quantidade em estoque: %d -- Preco: %.2f\n", 
				produtos[i].codigo,
				produtos[i].descricao,
				produtos[i].qtd_estoque,
				produtos[i].preco
			);
		}		
	}
	printf("\n");
}

void consultar_produto(){
	printf("\nIMPLEMENTAR");
}

void excluir_produto(){
	printf("\nIMPLEMENTAR");
}

int buscar_produto_codigo(Produto* produtos, int codigo){
	int i = 0;
	int retorno = ITEM_NAO_ENCONTRADO;
	for(i=0; i<qtdProd; i++){
		if(produtos[i].codigo == codigo){
			return i;
		}
	}
	return retorno;
}

//PEDIDO
void adicionar_produto_carrinho(){
	printf("Produtos Disponiveis\n\n");
	listar_produtos(produtos, qtdProd, false);
	int codProd;
	printf("Digite o codigo do produto desejado! ");
	scanf("%d", &codProd);
	printf("%d", codProd);
	printf("INDEX %d", buscar_produto_codigo(produtos, codProd));
	printf("\nIMPLEMENTAR");
	pausa();
}

void consultar_carrinho_compras(){
	printf("\nIMPLEMENTAR");
}

void excluir_produto_carrinho(){
	printf("\nIMPLEMENTAR");
}

void alterar_quantidade_produto_carrinho(){
	printf("\nIMPLEMENTAR");
}

void finalizar_pedido(){
	printf("\nIMPLEMENTAR");
}

void esvaziar_carrinho(Pedido* pedidos){
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
				limpar();
				printf("\nAdicionar produto no carrinho\n\n");
				adicionar_produto_carrinho(pedidos);
				break;
			case 2:
				limpar();
				printf("Consultar carrinho de compras");
				consultar_carrinho_compras();
				break;								
			case 3:
				limpar();
				printf("Excluir produto do carrinho");
				excluir_produto_carrinho();
				break;
			case 4:
				limpar();
				printf("Alterar quantidade do produto do carrinho");
				alterar_quantidade_produto_carrinho();
				break;
			case 5:
				limpar();
				printf("Finalizar Pedido");
				finalizar_pedido();
				break;								
			case 6:
				limpar();
				printf("Esvaziar carrinho de compras");
				esvaziar_carrinho(pedidos);
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
				limpar();
				printf("\nIncluir Produto");
				incluir_produto();
				break;
			case 2:
				limpar();
				printf("\nAlterar Produto");
				alterar_produto();
				break;								
			case 3:
				limpar();
				printf("\nListar produtos\n\n");
				listar_produtos(produtos, qtdProd, true);
				pausa();
				break;
			case 4:
				limpar();
				printf("\nConsultar Produto");
				consultar_produto();
				break;
			case 5:
				limpar();
				printf("\nExcluir Produto");
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
	pedidos = (Pedido*) malloc(maxPed * sizeof(Pedido));
	
	int i = 0;
	for(i = 0; i < 10 ; i++){
		produtos[i].codigo = i * 10;
		strcpy(produtos[i].descricao, "Produto");
		produtos[i].preco = rand() % 21;
		produtos[i].qtd_estoque = rand() % 50;
		qtdProd ++;
	}
	
	gerenciar_menu_principal(produtos, pedidos);
	return 0;
}
