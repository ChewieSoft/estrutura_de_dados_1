#include "configuration.h"
#include "produto.h"
#include "pedido.h"

int lista[2000] = {0};


//GERENCIAR
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

void gerenciar_menu_principal(ListaProduto* listaProduto, ListaPedido* listaPedido){
	int opcao;
	int sair = 0;
	do{
		limpar();
		opcao = menu_principal();
		switch(opcao){
			case 1:
				listaProduto = gerenciar_menu_produto(listaProduto);
				break;
			case 2:
				gerenciar_menu_pedido(listaProduto, listaPedido);
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

void load_database(char *file_name)
{	
	int counter = 0;
	FILE *file;
	char line[100];
	
	file = fopen(file_name, "r");	
	if(file == NULL){
		printf("Data base does not exist.");
		exit(EXIT_SUCCESS);
	}		 
	while(fgets(line, 100, file) != NULL)
	{
		char *item = strtok(line, " ");				
		lista[counter] = strtol(item, NULL, 0);		
		counter++;
	}
	fclose(file);		
}



//CODIGO
int main(int argc, char** argv){

	ListaPedido* listaPedido = NULL;
	ListaProduto* listaProduto = NULL;

	load_database("produtos.db");

	gerenciar_menu_principal(listaProduto, listaPedido);
	return 0;
}
