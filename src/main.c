#include "configuration.h"
#include "menu.h"
#include "produto.h"
#include "pedido.h"

int main(int argc, char** argv){
	setlocale(LC_ALL, "Portuguese");
	gerenciar_menu_principal();
	return 0;
}
