#include "processos.h"

int main() {

	//Carga dos dados de arquivo
	ListaProcesso* listaProcessoRaw = inicializaListaProcesso();
	carregaDados(listaProcessoRaw);

	ListaProcesso* listaProcesso = inicializaListaProcesso();

	int carinha = 1;

	while (carinha) {
		inserirProcessos(listaProcessoRaw, listaProcesso);
		Processo* processo = selecao(listaProcesso);
		executar(processo);
		manutencao(processo, listaProcesso);
		imprimir(listaProcesso);
		//SLEEP PARA DESACELERAR OS CICLOS
		CYCLE_TIME;
		cycle++;
	}

	return 0;
}