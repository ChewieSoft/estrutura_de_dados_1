void gerenciar_menu_produto();
void gerenciar_menu_pedido();

int menu_principal(){
	int opcao = 0;
	printf("\n#########################");
	printf("\n        HORTIFRUTI       ");
	printf("\n#########################");
	printf("\n(1) Gerenciar Produto");
	printf("\n(2) Gerenciar Pedido");
	printf("\n(3) Sair");
	printf("\n\nSelecionar opção: ");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_principal(){
	int opcao;
	int sair = 0;
	do{
		limpar();
		opcao = menu_principal();
		switch(opcao){
			case 1:
				gerenciar_menu_produto();
				break;
			case 2:
				gerenciar_menu_pedido();
				break;
			case 3:
				limpar();
				sair = 1;
				break;
			default:
				printf("Opção Inválida!!!\n");
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
	printf("\n\nSelecionar opção: ");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_produto(){
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
				listar_produtos();
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
				printf("Opção Inválida!");
				sair = 0;
		}	
	}while(!sair);	
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
	printf("\n\nSelecionar opção: ");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_pedido(){
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
				printf("Opção Inválida!");
				sair = 0;			
		}
	}while(!sair);
}
