#include "processos.h"

int main() {

	//Carga dos dados de arquivo
	ListaProcesso* listaProcessoRaw = inicializaListaProcesso();
	carregaDados(listaProcessoRaw);

	ListaProcesso* listaProcesso = inicializaListaProcesso();
	Processo* processo = NULL;


	while (run) {		
		//insercao
		inserirProcessos(listaProcessoRaw, listaProcesso);
		//verifica se pode parar o codigo
		if (finishHim(listaProcesso)) {
			run = 0;
			break;
		}
		//busca
		processo = selecao(listaProcesso);
		//execucao
		executar(processo);
		manutencao(processo, listaProcesso);
		//amostragem
		imprimirInfos(cycle, listaProcesso, processo);
		imprimir(listaProcesso);
		//SLEEP PARA DESACELERAR OS CICLOS
		CYCLE_TIME;
		cycle++;
	}

	return 0;
}

