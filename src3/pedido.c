#include "pedido.h"

typedef struct produto{
	char codigo[10];
	char descricao[50];
	int qtd_estoque;
	float preco;
}Produto;

typedef struct listaProduto{
	Produto* produto;
}ListaProduto;

int qtdPed = 0;
int maxPed = 0;

char codigo[10];
bool confirmado = false;
float totalGeral = 0;

struct pedido{
	Produto* produto;
	int quantidade;
	float preco;
	float total;
};

struct listaPedido{
	Pedido* pedido;
};

Pedido* incluir_pedido(){
	return (Pedido*) malloc(sizeof(Pedido));
}

int buscar_produto_codigo_pedido(ListaPedido* listaPedido, char codigo[10]){
	int i = 0;
	int retorno = ITEM_NAO_ENCONTRADO;
	for(i = 0; i < qtdProd; i++){
		if(!strcmp(listaPedido[i].pedido->produto->codigo, codigo)){
			return i;
		}
	}
	return retorno;
}

ListaPedido* adicionar_produto_carrinho(ListaProduto* listaProduto, ListaPedido* listaPedido){
	//LISTAR PRODUTOS DISPONIVEIS
	printf("Produtos Disponiveis\n\n");
	listar_produtos(listaProduto, qtdProd, false);
	//SELECIONAR O PRODUTO
	char codProd[10];
	printf("Digite o codigo do produto desejado! ");
	scanf("%s", codProd);
	//VERIFICAR EXISTENCIA
	int prodResult = buscar_produto_codigo(listaProduto, codProd, false);
	if(prodResult > ITEM_NAO_ENCONTRADO){
		consultar_produto(listaProduto, prodResult);
	}else{
		printf("\n\nPRODUTO NAO ENCONTRADO\n\n");
		pausa();
		limpar();
		adicionar_produto_carrinho(listaProduto, listaPedido);
	}

	//MALLOC LISTAPEDIDO
	if(maxPed == 0){
		maxPed = REALLOCFACT;
		listaPedido = (ListaPedido*) malloc(maxPed * sizeof(ListaPedido));
		if (listaPedido == NULL){
			printf("\n\nMemoria insuficiente\n\n");
			exit(0);
	    }
	}
	//REALLOC LISTAPEDIDO
	if(qtdPed == maxPed){
		listaPedido = (ListaPedido*) realloc(listaPedido, (maxPed + REALLOCFACT) * sizeof(ListaPedido));
		if (listaPedido == NULL){
			printf("\n\nMemoria insuficiente\n\n");
			exit(0);
	    }
	    maxPed = maxPed + REALLOCFACT;
	}
	//MALLOC PEDIDO
	listaPedido[qtdPed].pedido = incluir_pedido();

	//INCLUIR PEDIDO
	sprintf(codigo, "%lld", rand_code());
	listaPedido[qtdPed].pedido->produto = listaProduto[prodResult].produto;
	listaPedido[qtdPed].pedido->preco = listaProduto[prodResult].produto->preco;
	
	//VERIFICAR QUANTIDADE DISPONIVEL
	do{
		printf("\nDigite a quantidade de produto desejada! ");
		scanf("%d", &listaPedido[qtdPed].pedido->quantidade);
	}while(!consulta_disponibilidade(listaProduto, prodResult, listaPedido[qtdPed].pedido->quantidade));
	
	listaPedido[qtdPed].pedido->total = listaPedido[qtdPed].pedido->quantidade * listaPedido[qtdPed].pedido->preco;
	totalGeral += listaPedido[qtdPed].pedido->total;
	qtdPed++;
	printf("\nProduto adicionado com sucesso!\n\n");
	return listaPedido;
}

void consultar_carrinho_compras(ListaPedido* listaPedido, int qtd){
	int i = 0;
	if(qtd == 0){
		printf("\n\nPedido se encontra vazio!\n");
		return;
	}
	//printf("\n\nPedido : -- %s", codigo);
	printf("\n\nItens :\n");
	for (i = 0; i < qtd; i++){
		printf("\Codigo: %s -- Descricao: %s -- Quantidade: %d -- Preco Unitario: %.2f -- Total: %.2f\n", 
			listaPedido[i].pedido->produto->codigo,
			listaPedido[i].pedido->produto->descricao,
			listaPedido[i].pedido->quantidade,
			listaPedido[i].pedido->produto->preco,
			listaPedido[i].pedido->total
		);
	}
	printf("\nA pagar : -- %.2f\n", totalGeral);
	printf("\n");	
}

void excluir_produto_carrinho(ListaPedido* listaPedido){
	consultar_carrinho_compras(listaPedido, qtdPed);
	char codProd[10];
	int index = 0;
	printf("Por favor, digite o codigo do produto a ser exluido. ");
	scanf("%s", codProd);
	index = buscar_produto_codigo_pedido(listaPedido, codProd);
	if(index == ITEM_NAO_ENCONTRADO){
		printf("\nItem nao encontrado!!!\n\n");
		return;
	}
	//EXCLUSAO
	if(qtdPed == 1 || index == qtdPed - 1){
		//LIMPA O VET DE PEDIDO
		totalGeral -= listaPedido[index].pedido->total;
		free(listaPedido[index].pedido);
		qtdPed--;
	}
	else{
		totalGeral -= listaPedido[index].pedido->total;
		listaPedido[index].pedido->produto = listaPedido[qtdPed - 1].pedido->produto;
		listaPedido[index].pedido->preco = listaPedido[qtdPed - 1].pedido->preco;
		listaPedido[index].pedido->quantidade = listaPedido[qtdPed - 1].pedido->quantidade;
		listaPedido[index].pedido->total = listaPedido[qtdPed - 1].pedido->total;
		//LIMPA O VET DE PEDIDO
		free(listaPedido[qtdPed-1].pedido);
		qtdPed--;
	}
	printf("\nProduto excluido com sucesso\n\n");
}

void alterar_quantidade_produto_carrinho(ListaPedido* listaPedido){
	consultar_carrinho_compras(listaPedido, qtdPed);
	char codProd[10];
	int index = 0;
	printf("Por favor, digite o codigo do produto desejado. ");
	scanf("%s", codProd);
	index = buscar_produto_codigo_pedido(listaPedido, codProd);
	if(index == ITEM_NAO_ENCONTRADO){
		printf("\nItem nao encontrado!!!\n\n");
		pausa();
		return;
	}
}

void finalizar_pedido(){
	printf("\nIMPLEMENTAR");
}

void esvaziar_carrinho(Pedido* pedido){
	printf("\nIMPLEMENTAR");
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
	printf("\n\nSelecionar opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_pedido(ListaProduto* listaProduto, ListaPedido* listaPedido){
	int opcao;
	int sair = 0;
	limpar();
	do{
		opcao = menu_pedido();
		switch(opcao){
			case 1:
				limpar();
				printf("\nAdicionar produto no carrinho\n\n");
				listaPedido = adicionar_produto_carrinho(listaProduto, listaPedido);
				pausa();
				break;
			case 2:
				limpar();
				printf("Consultar carrinho de compras");
				consultar_carrinho_compras(listaPedido, qtdPed);
				pausa();
				break;								
			case 3:
				limpar();
				printf("Excluir produto do carrinho");
				excluir_produto_carrinho(listaPedido);
				pausa();
				break;
			case 4:
				limpar();
				printf("Alterar quantidade do produto do carrinho");
				alterar_quantidade_produto_carrinho(listaPedido);
				pausa();
				break;
			case 5:
				limpar();
				printf("Finalizar Pedido");
				//finalizar_pedido();
				break;
			case 6:
				limpar();
				printf("Esvaziar carrinho de compras");
				//esvaziar_carrinho(pedido);
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
