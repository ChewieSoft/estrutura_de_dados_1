#include "configuration.h"
#include "produto.h"

int qtdPed;
int maxPed;

typedef struct pedido Pedido;
typedef struct listaPedido ListaPedido;

ListaPedido* kill_pedido(ListaPedido* listaPedido);

int buscar_produto_codigo_pedido(ListaPedido* listaPedido, char codigo[10]);
ListaPedido* adicionar_produto_carrinho(ListaProduto* listaProduto, ListaPedido* listaPedido);
void consultar_carrinho_compras(ListaPedido* listaPedido, int qtd);
void excluir_produto_carrinho(ListaPedido* listaPedido);
void alterar_quantidade_produto_carrinho(ListaProduto* listaProduto, ListaPedido* listaPedido);
void finalizar_pedido(ListaPedido* listaPedido);
ListaPedido* esvaziar_carrinho(ListaPedido* listaPedido);

int menu_pedido();
ListaPedido* gerenciar_menu_pedido(ListaProduto* listaProduto, ListaPedido* listaPedido);

