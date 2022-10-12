#include "produto.h"
#include "configuration.h"

int qtdProd = 0;
int maxProd = 2;


 struct produto{
	int codigo;
	char descricao[50];
	int qtd_estoque;
	float preco;
};


void incluir_produto(Produto* produto){
	if(qtdProd == maxProd){
		realloc(produto, (maxProd + 10) * sizeof(Produto));
		maxProd = maxProd + 10;
	}
	printf("Cadastrando produto: %d\n", qtdProd+1);
	printf("Digite o codigo do produto: ");
	scanf("%d", &produto[qtdProd].codigo);
	getchar();
	
	printf("Digite a descricao do produto: ");
	scanf("%s", produto[qtdProd].descricao); 
	getchar();
	
	printf("Digite a quantidade inicial do produto em estoque: ");
	scanf("%d", &produto[qtdProd].qtd_estoque);
	getchar();
	
	printf("Digite o preco do produto: ");
	scanf("%f", &produto[qtdProd].preco);
	getchar();
	
	printf("\nProduto cadastrado com sucesso\n");
	consultar_produto(produto, qtdProd);
	getchar();
	limpar();
	qtdProd++;
};


void consultar_produto(Produto* produto, int index){
	if(index == ITEM_NAO_ENCONTRADO){
		int codProd;
		printf("Por favor, digite o codigo do produto desejado. ");
		scanf("%d", &codProd);
		index = buscar_produto_codigo(produto, codProd, true);
		if(index == ITEM_NAO_ENCONTRADO){
			printf("Item nao encontrado!!!\n");
			pausa();
			return;
		}			
	}
	printf("\nInformacoes do produto:\n Codigo: %d\n Descricao: %s\n Quantidade em estoque: %d\n Preco: %.2f\n\n", 
		produto[index].codigo,
		produto[index].descricao,
		produto[index].qtd_estoque,
		produto[index].preco
	);
	pausa();
}


int buscar_produto_codigo(Produto* produto, int codigo, bool isVazio){
	int i = 0;
	int retorno = ITEM_NAO_ENCONTRADO;
	for(i=0; i<qtdProd; i++){
		if(produto[i].codigo == codigo){
			if(isVazio){
				return i;
			}
			else if(produto[i].qtd_estoque > 0){
				return i;
			}
		}
	}
	return retorno;
}


void excluir_produto(Produto* produto){
	int codProd;
	int index = 0;
	printf("Por favor, digite o codigo do produto desejado. ");
	scanf("%d", &codProd);
	index = buscar_produto_codigo(produto, codProd, true);
	if(index == ITEM_NAO_ENCONTRADO){
		printf("Item nao encontrado!!!\n");
		pausa();
		return;
	}
	//EXCLUSAO
	if(qtdProd == 1 || index == qtdProd - 1){
		qtdProd--;
		printf("\nProduto excluido com sucesso\n");
		pausa();
	}
	else{
		produtos[index].codigo = produtos[qtdProd-1].codigo;
		strcpy(produtos[index].descricao, produtos[qtdProd-1].descricao);
		produtos[index].qtd_estoque = produtos[qtdProd-1].qtd_estoque;
		produtos[index].preco =	produtos[qtdProd-1].preco;
		qtdProd--;
		printf("\nProduto excluido com sucesso\n");
		pausa();	
	}	
}	


void listar_produtos(Produto* produto, int qtd, bool isVazio){
	int i = 0;
	for (i = 0; i < qtd; i++){
		if(isVazio){
			printf("Produto : -- Codigo: %d -- Descricao: %s -- Quantidade em estoque: %d -- Preco: %.2f\n", 
				produto[i].codigo,
				produto[i].descricao,
				produto[i].qtd_estoque,
				produto[i].preco
			);
		}
		else if(produto[i].qtd_estoque > 0){			
			printf("Produto : -- Codigo: %d -- Descricao: %s -- Quantidade em estoque: %d -- Preco: %.2f\n", 
				produto[i].codigo,
				produto[i].descricao,
				produto[i].qtd_estoque,
				produto[i].preco
			);
		}		
	}
	printf("\n");
}
