#include "produto.h"

int qtdProd = 0;
int maxProd = 0;

struct produto{
	int codigo;
	char descricao[50];
	int qtd_estoque;
	float preco;
};

Produto* incluir_produto(Produto* produto){
	if(maxProd == 0){
		maxProd = REALLOCFACT;
		produto = (Produto*) malloc(maxProd * sizeof(Produto));
	}
	if(qtdProd == maxProd){
		produto = (Produto*) realloc(produto, (maxProd + REALLOCFACT) * sizeof(Produto));
		if (produto == NULL){
			printf("\n\nMemoria insuficiente\n\n");
			exit(0);           
	    }
		maxProd = maxProd + REALLOCFACT;
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
	limpar();
	qtdProd++;
	
	return produto;
}

void alterar_produto(Produto* produto){
	printf("IMPLEMENTAR\n\n");
}

void listar_produtos(Produto* produto, int qtd, bool isVazio){
	int i = 0;
	if(qtd == 0){
		printf("Lista se encontra vazia!\n");
	}
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

void consultar_produto(Produto* produto, int index){
	if(index == ITEM_NAO_ENCONTRADO){
		int codProd;
		printf("Por favor, digite o codigo do produto desejado. ");
		scanf("%d", &codProd);
		index = buscar_produto_codigo(produto, codProd, true);
		if(index == ITEM_NAO_ENCONTRADO){
			printf("\nItem nao encontrado!!!\n\n");
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

void excluir_produto(Produto* produto){
	int codProd;
	int index = 0;
	printf("Por favor, digite o codigo do produto desejado. ");
	scanf("%d", &codProd);
	index = buscar_produto_codigo(produto, codProd, true);
	if(index == ITEM_NAO_ENCONTRADO){
		printf("\nItem nao encontrado!!!\n\n");
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
		produto[index].codigo = produto[qtdProd-1].codigo;
		strcpy(produto[index].descricao, produto[qtdProd-1].descricao);
		produto[index].qtd_estoque = produto[qtdProd-1].qtd_estoque;
		produto[index].preco =	produto[qtdProd-1].preco;
		qtdProd--;
		printf("\nProduto excluido com sucesso\n");
		pausa();	
	}	
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
				produto = incluir_produto(produto);
				break;
			case 2:
				limpar();
				printf("\nAlterar Produto\n\n");
				alterar_produto(produto);
				pausa();
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
				//consultar_produto(produto, ITEM_NAO_ENCONTRADO);
				break;
			case 5:
				limpar();
				printf("\nExcluir Produto\n\n");
				excluir_produto(produto);
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
