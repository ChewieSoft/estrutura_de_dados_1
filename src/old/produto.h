/*
 * produto.h
 *
 * Created on: Oct 10, 2022
 *		Author: Brenno, Jorge e Hamilton
 *
 */
 
 #include <stdbool.h>
 
 #ifndef PRODUTO_
 #define PRODUTO_ 
 #define ITEM_NAO_ENCONTRADO -1
 
 
 typedef struct produto Produto; 
 
int qtdProd;
int maxProd;
Produto* produtos;
 
 
 
 
 
 void incluir_produto(Produto* produto);
 void consultar_produto(Produto* produto, int index);
 int buscar_produto_codigo(Produto* produto, int codigo, bool isVazio);
 void excluir_produto(Produto* produto);
 void listar_produtos(Produto* produto, int qtd, bool isVazio);

 
 
 
 #endif /* PRODUTO_ */
