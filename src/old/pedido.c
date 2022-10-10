#include "pedido.h"

struct pedido{
	int codigo;
	struct produto* produto;
	int quantidade;
	int total;
};

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
