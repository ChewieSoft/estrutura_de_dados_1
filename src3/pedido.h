#include "configuration.h"
#include "produto.h"

int qtdPed;
int maxPed;

typedef struct pedido Pedido;
typedef struct listaPedido ListaPedido;

int buscar_produto_codigo_pedido(ListaPedido* listaPedido, char codigo[10]);
ListaPedido* adicionar_produto_carrinho(ListaProduto* listaProduto, ListaPedido* listaPedido);
void consultar_carrinho_compras(ListaPedido* listaPedido, int qtd);
void excluir_produto_carrinho(ListaPedido* listaPedido);
void alterar_quantidade_produto_carrinho(ListaProduto* listaProduto, ListaPedido* listaPedido);
//void finalizar_pedido();
//void esvaziar_carrinho(Pedido* pedido);

int menu_pedido();
void gerenciar_menu_pedido(ListaProduto* listaProduto, ListaPedido* listaPedido);

