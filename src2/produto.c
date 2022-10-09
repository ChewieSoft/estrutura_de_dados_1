#include "produto.h"

struct produto {
	int codigo;
	char descricao[50];
	int qtd_estoque;
	float preco;
};

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

void listar_produtos(struct produto* produtos){
	limpar();
	printf("\nListar produtos");
	int i = 0;
	for (i=0; i<3;i++){
		printf("teste%d", produtos[i].codigo);
	}
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
