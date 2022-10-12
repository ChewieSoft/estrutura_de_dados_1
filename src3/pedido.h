#include "configuration.h"
#include "produto.h"

//int qtdPed;
//int maxPed;

typedef struct pedido Pedido;
typedef struct listaPedido ListaPedido;


void adicionar_produto_carrinho(ListaProduto* listaProduto, int qtdProd, ListaPedido* listaPedido);
//void consultar_carrinho_compras(Pedido* pedido, int qtd);
//void excluir_produto_carrinho();
//void alterar_quantidade_produto_carrinho();
//void finalizar_pedido();
//void esvaziar_carrinho(Pedido* pedido);

int menu_pedido();
void gerenciar_menu_pedido(ListaProduto* listaProduto, int qtdProd, ListaPedido* listaPedido);

