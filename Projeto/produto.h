#include "configuration.h"

int qtdProd;
int maxProd;

typedef struct produto Produto;
typedef struct listaProduto ListaProduto;

void save_prod(ListaProduto* listaProduto);

void export_prod(ListaProduto* listaProduto);

ListaProduto* kill_produto(ListaProduto* listaProduto);

bool consulta_disponibilidade(ListaProduto* listaProduto, int index, int qtd);
ListaProduto* incluir_produto(ListaProduto* produto);
void alterar_produto(ListaProduto* listaProduto);
void listar_produtos(ListaProduto* listaProduto, int qtd, bool isVazio);
int buscar_produto_codigo(ListaProduto* listaProduto, char codigo[10], bool isVazio);
void consultar_produto(ListaProduto* listaProduto, int index);
void excluir_produto(ListaProduto* listaProduto);

int menu_produto();
ListaProduto* gerenciar_menu_produto(ListaProduto* listaProduto);
