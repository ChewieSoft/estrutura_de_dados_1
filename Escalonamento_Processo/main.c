#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listaProcesso {
	int qtd;
	struct processo* processos;
} ListaProcesso;

typedef struct processo {
	struct processo* prox;
	//Conteudo util
	int tarefaId;
	int tempoExecucao;
	int tempoRemanescente;
	int ingresso;
	int proridadeEstatica;
	int proridadeDinamica;
} Processo;

//Metodos
ListaProcesso* inicializaListaProcesso(ListaProcesso* lista);
void carregaDados(ListaProcesso* lista);

int main() {

	ListaProcesso* listaProcesso = NULL;
	listaProcesso = inicializaListaProcesso(listaProcesso);

	carregaDados(listaProcesso);
	
	printf("ASDASD");

	return 0;
}

ListaProcesso* inicializaListaProcesso(ListaProcesso* lista) {
	
	lista = malloc(sizeof(ListaProcesso));

	lista->qtd = 0;
	lista->processos = NULL;
}

void carregaDados(ListaProcesso* lista) {
	
	//Leitura do arquivo txt
	FILE* arq = fopen("Teste.txt", "r");
	if (arq == NULL) {
		exit(1);
	}

	//Primeira linha define a quantidade de processos a serem listados
	fscanf_s(arq, "%d\n", &lista->qtd);
	int i;

	Processo* processo = NULL;
	for (i = 0; i < lista->qtd; i ++) {
		Processo* processo_aux = (Processo*) malloc(sizeof(Processo));
		
		//LER VALORES => ENTRADA - TEMPO EXECUCAO - PRIORIDADE
		fscanf(arq, "%d %d %d\n", &processo_aux->ingresso, &processo_aux->tempoExecucao, &processo_aux->proridadeEstatica);
		
		//ATRIBUICAO DOS VALORES RESTANTES
		processo_aux->tarefaId = rand() % 1000;
		processo_aux->proridadeDinamica = processo_aux->proridadeEstatica;
		processo_aux->tempoRemanescente = processo_aux->tempoExecucao;

		if (i == 0) {
			lista->processos = processo_aux;
		}
		else {
			processo->prox = processo_aux;
		}

		if (i == lista->qtd - 1)
			processo_aux->prox = NULL;

		processo = processo_aux;
	}
	fclose(arq);
}
