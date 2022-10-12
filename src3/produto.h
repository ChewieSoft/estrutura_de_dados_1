#include "configuration.h"

typedef struct produto Produto;
typedef struct listaProduto ListaProduto;

ListaProduto* incluir_produto(ListaProduto* listaProduto, int maxProd, int qtdProd);
void alterar_produto(ListaProduto* listaProduto, int qtdProd);
void listar_produtos(ListaProduto* listaProduto, int qtd, bool isVazio);
int buscar_produto_codigo(ListaProduto* listaProduto, int qtdProd, char codigo[10], bool isVazio);
void consultar_produto(ListaProduto* listaProduto, int index, int qtdProd);
void excluir_produto(ListaProduto* listaProduto, int qtdProd);

int menu_produto();
ListaProduto* gerenciar_menu_produto(ListaProduto* listaProduto, int maxProd, int qtdProd );

