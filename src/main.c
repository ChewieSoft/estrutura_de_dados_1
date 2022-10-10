#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

#include "configuration.h"
#include "produto.h"

#define ITEM_NAO_ENCONTRADO -1

//STRUCTS

struct produto{
	int codigo;
	char descricao[50];
	int qtd_estoque;
	float preco;
};

typedef struct pedido{
	int codigo;
	int produto;
	int quantidade;
	float preco;
	int total;
}Pedido;

//VARIAVEIS
Produto* produtos = NULL;
Pedido* pedidos = NULL;
int qtdPed = 0;
int maxPed = 2;

//PRODUTO


void alterar_produto(){
	printf("\nIMPLEMENTAR");
}


bool produto_disponivel(Produto* produto, int index){

}

//PEDIDO
void adicionar_produto_carrinho(Pedido* pedido){
	printf("Produtos Disponiveis\n\n");
	listar_produtos(produtos, qtdProd, false);
	
	int codProd;
	printf("Digite o codigo do produto desejado! ");
	scanf("%d", &codProd);
	
	int prodResult = buscar_produto_codigo(produtos, codProd, false);
	if(prodResult > ITEM_NAO_ENCONTRADO){
		consultar_produto(produtos, prodResult);
	}else{
		printf("\n\nPRODUTO NAO ENCONTRADO\n\n");
		pausa();
		limpar();
		adicionar_produto_carrinho(pedidos);		
	}		
	
	if(qtdPed == maxPed){
		realloc(pedido, (maxPed + 10) * sizeof(Pedido));
		maxPed = maxPed + 10;
	}
	
	pedido[qtdPed].codigo = qtdPed + 1;
	pedido[qtdPed].produto = prodResult;
	pedido[qtdPed].preco = produtos[prodResult].preco;
	
	printf("Digite a quantidade de produto desejada! ");
	scanf("%d", pedido[qtdPed].quantidade);
	pedido[qtdPed].total = pedido[qtdPed].quantidade * pedido[qtdPed].preco;
	
	printf("\nIMPLEMENTAR");
	pausa();
}

void consultar_carrinho_compras(Pedido* pedido, int qtd){
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

void gerenciar_menu_pedido(Pedido* pedido){
	int opcao;
	int sair = 0;
	limpar();
	do{	
		opcao = menu_pedido();		
		switch(opcao){
			case 1:
				limpar();
				printf("\nAdicionar produto no carrinho\n\n");
				adicionar_produto_carrinho(pedido);
				break;
			case 2:
				limpar();
				printf("Consultar carrinho de compras");
				consultar_carrinho_compras(pedidos, qtdPed);
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
				esvaziar_carrinho(pedido);
				break;								
			case 7:
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!\n\n");
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

void gerenciar_menu_produto(Produto* produto){
	int opcao;
	int sair = 0;
	do{
		opcao = menu_produto();
		switch(opcao){
			case 1:
				limpar();
				printf("\nIncluir Produto\n\n");
				incluir_produto(produto);
				break;
			case 2:
				limpar();
				printf("\nAlterar Produto\n\n");
				alterar_produto();
				break;								
			case 3:
				limpar();
				printf("\nListar produtos\n\n");
				listar_produtos(produto, qtdProd, true);
				pausa();
				break;
			case 4:
				limpar();
				printf("\nConsultar Produto\n\n");
				consultar_produto(produto, ITEM_NAO_ENCONTRADO);
				break;
			case 5:
				limpar();
				printf("\nExcluir Produto\n\n");
				excluir_produto(produtos);
				break;								
			case 6:
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!!!\n");
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
	
	gerenciar_menu_principal(produtos, pedidos);
	return 0;
}
