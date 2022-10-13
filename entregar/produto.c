#include "produto.h"

int qtdProd = 0;
int maxProd = 0;

struct produto{
	char codigo[10];
	char descricao[50];
	int qtd_estoque;
	float preco;
};

struct listaProduto{
	Produto* produto;
};

void export_prod(ListaProduto* listaProduto){
	FILE *estoque; //criando arquivo estoque
	estoque = fopen("registro_estoque.txt", "w"); //abrir e/ou criar o arquivo txt do estoque	
	if(estoque == NULL){		
		printf("Erro ao gerar os dados do estoque");
		return 1;			
	}
	int i = 0;		
	for (i=0; i<qtdProd;i++){ //estrutura de repetição para armazenar os dados dos produtos no txt base de dados do estoque
		fprintf(estoque, "%s, ", listaProduto[i].produto->codigo);
		fprintf(estoque, "%s, ", listaProduto[i].produto->descricao);
		fprintf(estoque, "%d, ", listaProduto[i].produto->qtd_estoque);
		fprintf(estoque, "%.2f; \n", listaProduto[i].produto->preco);
	}
	fclose(estoque);
}

ListaProduto* kill_produto(ListaProduto* listaProduto){
	int pro = 0;
	for(pro = 0; pro < qtdProd; pro++){
		free(listaProduto[pro].produto);
	}
	qtdProd = 0;
	maxProd = REALLOCFACT;
	listaProduto = (ListaProduto*) realloc(listaProduto, REALLOCFACT * sizeof(ListaProduto));
}

bool consulta_disponibilidade(ListaProduto* listaProduto, int index, int qtd){
	if(listaProduto[index].produto->qtd_estoque >= qtd){
		return true;
	}
	else{
		printf("\nQuantidade informada indisponivel!\n");
		return false;
	}
}

Produto* cria_produto(){
	return (Produto*) malloc(sizeof(Produto));
}

ListaProduto* incluir_produto(ListaProduto* listaProduto){
	//MALLOC LISTA
	if(maxProd == 0){
		maxProd = REALLOCFACT;
		listaProduto = (ListaProduto*) malloc(maxProd * sizeof(ListaProduto));
	}
	//REALLOC LISTA
	if(qtdProd == maxProd){
		listaProduto = (ListaProduto*) realloc(listaProduto, (maxProd + REALLOCFACT) * sizeof(ListaProduto));
		if (listaProduto == NULL){
			printf("\n\nMemoria insuficiente\n\n");
			exit(0);           
	    }
		maxProd = maxProd + REALLOCFACT;
	}
	//MALLOC PARA O PRODUTO
	listaProduto[qtdProd].produto = cria_produto();
	//ADICIONAR
	printf("Cadastrando produto: %d\n", qtdProd+1);
	printf("Digite o codigo do produto: ");
	scanf(" %[^\n]",listaProduto[qtdProd].produto->codigo);
	getchar();
	
	printf("Digite a descricao do produto: ");
	scanf(" %[^\n]",listaProduto[qtdProd].produto->descricao);
	getchar();
	
	printf("Digite a quantidade inicial do produto em estoque: ");
	scanf("%d", &listaProduto[qtdProd].produto->qtd_estoque);
	getchar();
	
	printf("Digite o preco do produto: ");
	scanf("%f", &listaProduto[qtdProd].produto->preco);
	getchar();
	
	printf("\nProduto cadastrado com sucesso\n");
	consultar_produto(listaProduto, qtdProd);
	limpar();
	qtdProd++;
	
	return listaProduto;
}

void alterar_produto(ListaProduto* listaProduto){
	char codProd[10];
	int index = 0;
	printf("Por favor, digite o codigo do produto desejado. ");
	scanf("%s", codProd);
	index = buscar_produto_codigo(listaProduto, codProd, true);
	if(index == ITEM_NAO_ENCONTRADO){
		printf("\nItem nao encontrado!!!\n\n");
		return;
	}
	//ALTERACAO
	int opcao;
	int sair = 0;
	do{
		printf("\nInformacoes do produto:\n Codigo: %s\n Descricao: %s\n Quantidade em estoque: %d\n Preco: %.2f\n",
			listaProduto[index].produto->codigo,
			listaProduto[index].produto->descricao,
			listaProduto[index].produto->qtd_estoque,
			listaProduto[index].produto->preco
		);
		printf("\nQual informacao voce deseja editar ?");
		printf("\n(1) Codigo");
		printf("\n(2) Descricao");
		printf("\n(3) Quantidade em estoque");
		printf("\n(4) Preco");
		printf("\n(5) Sair");
		printf("\n\nSelecionar opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				printf("\nDigite o novo codigo do produto: ");
				scanf(" %[^\n]", listaProduto[index].produto->codigo);
				getchar();
				printf("\nAlterado com sucesso!\n");
				pausa();
				limpar();
				break;
			case 2:
				printf("Digite a nova descricao do produto: ");
				scanf(" %[^\n]", listaProduto[index].produto->descricao);
				getchar();
				printf("\nAlterado com sucesso!\n");
				pausa();
				limpar();
				break;
			case 3:
				printf("Digite a nova quantidade do produto em estoque: ");
				scanf("%d", &listaProduto[index].produto->qtd_estoque);
				getchar();
				printf("\nAlterado com sucesso!\n");
				pausa();
				limpar();
				break;
			case 4:
				printf("Digite o novo preco do produto: ");
				scanf("%f", &listaProduto[index].produto->preco);
				getchar();
				printf("\nAlterado com sucesso!\n");
				pausa();
				limpar();
				break;
			case 5:
				sair = 1;
				break;
			default:
				printf("\nOpcao Invalida!!!\n\n");
				pausa();
				limpar();
				sair = 0;
		}
	}while(!sair);
}

void listar_produtos(ListaProduto* listaProduto, int qtd, bool isVazio){
	int i = 0;
	if(qtd == 0){
		printf("Lista se encontra vazia!\n");
	}
	for (i = 0; i < qtd; i++){
		if(isVazio){
			printf("Produto : -- Codigo: %s -- Descricao: %s -- Quantidade em estoque: %d -- Preco: %.2f\n", 
				listaProduto[i].produto->codigo,
				listaProduto[i].produto->descricao,
				listaProduto[i].produto->qtd_estoque,
				listaProduto[i].produto->preco
			);
		}
		else if(listaProduto[i].produto->qtd_estoque > 0){			
			printf("Produto : -- Codigo: %s -- Descricao: %s -- Quantidade em estoque: %d -- Preco: %.2f\n", 
				listaProduto[i].produto->codigo,
				listaProduto[i].produto->descricao,
				listaProduto[i].produto->qtd_estoque,
				listaProduto[i].produto->preco
			);
		}
	}
	printf("\n");
}

int buscar_produto_codigo(ListaProduto* listaProduto, char codigo[10], bool isVazio){
	int i = 0;
	int retorno = ITEM_NAO_ENCONTRADO;
	for(i=0; i<qtdProd; i++){
		if(!strcmp(listaProduto[i].produto->codigo, codigo)){
			if(isVazio){
				return i;
			}
			else if(listaProduto[i].produto->qtd_estoque > 0){
				return i;
			}
		}
	}
	return retorno;
}

void consultar_produto(ListaProduto* listaProduto, int index){
	if(index == ITEM_NAO_ENCONTRADO){
		char codProd[10];
		printf("Por favor, digite o codigo do produto desejado. ");
		scanf("%s", codProd);
		index = buscar_produto_codigo(listaProduto, codProd, true);
		if(index == ITEM_NAO_ENCONTRADO){
			printf("\nItem nao encontrado!!!\n\n");
			pausa();
			return;
		}			
	}
	printf("\nInformacoes do produto:\n Codigo: %s\n Descricao: %s\n Quantidade em estoque: %d\n Preco: %.2f\n\n", 
		listaProduto[index].produto->codigo,
		listaProduto[index].produto->descricao,
		listaProduto[index].produto->qtd_estoque,
		listaProduto[index].produto->preco
	);
	pausa();
}

void excluir_produto(ListaProduto* listaProduto){
	char codProd[10];
	int index = 0;
	printf("Por favor, digite o codigo do produto desejado. ");
	scanf("%s", codProd);
	index = buscar_produto_codigo(listaProduto, codProd, true);
	if(index == ITEM_NAO_ENCONTRADO){
		printf("\nItem nao encontrado!!!\n\n");
		pausa();
		return;
	}
	//EXCLUSAO
	if(qtdProd == 1 || index == qtdProd - 1){
		//LIMPA O VET DE PRODUTO
		free(listaProduto[index].produto);
		qtdProd--;
		printf("\nProduto excluido com sucesso\n");
		pausa();
	}
	else{
		strcpy(listaProduto[index].produto->codigo, listaProduto[qtdProd - 1].produto->codigo);
		strcpy(listaProduto[index].produto->descricao, listaProduto[qtdProd - 1].produto->descricao);
		listaProduto[index].produto->qtd_estoque = listaProduto[qtdProd - 1].produto->qtd_estoque;
		listaProduto[index].produto->preco = listaProduto[qtdProd - 1].produto->preco;
		//LIMPA O VET DE PRODUTO
		free(listaProduto[qtdProd-1].produto);
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

ListaProduto* gerenciar_menu_produto(ListaProduto* listaProduto){
	int opcao;
	int sair = 0;
	do{
		opcao = menu_produto();
		switch(opcao){
			case 1:
				limpar();
				printf("\nIncluir Produto\n\n");
				listaProduto = incluir_produto(listaProduto);
				break;
			case 2:
				limpar();
				printf("\nAlterar Produto\n\n");
				alterar_produto(listaProduto);
				pausa();
				break;								
			case 3:
				limpar();
				printf("\nListar produtos\n\n");
				listar_produtos(listaProduto, qtdProd, true);
				pausa();
				break;
			case 4:
				limpar();
				printf("\nConsultar Produto\n\n");
				consultar_produto(listaProduto, ITEM_NAO_ENCONTRADO);
				break;
			case 5:
				limpar();
				printf("\nExcluir Produto\n\n");
				excluir_produto(listaProduto);
				break;								
			case 6:
				sair = 1;
				pausa();
				export_prod(listaProduto);
				return listaProduto;
				break;
			default:
				printf("Opcao Invalida!!!\n");
				sair = 0;
		}	
	}while(!sair);	
}
