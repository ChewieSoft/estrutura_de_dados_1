#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#define CYCLE_TIME Sleep(500)

int cycle;

typedef struct processo Processo;
typedef struct listaProcesso ListaProcesso;

void carregaDados(ListaProcesso* lista);
ListaProcesso* inicializaListaProcesso();
Processo* selecao(ListaProcesso* lista);
void executar(Processo* processo);
Processo* excluirTerminado(Processo* anterior, Processo* processo);
void manutencao(Processo* processo, ListaProcesso* lista);
void imprimirInfos(int ciclo, Processo* processo);
void imprimir(ListaProcesso* lista);
