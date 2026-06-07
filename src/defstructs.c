/**
 * @file defstructs.c
 * @brief Instanciação das variáveis globais de controle das estruturas de dados.
 * * Inicializa os ponteiros de cabeça (head), cauda (tail) e contadores de tamanho 
 * com valores nulos/zero para garantir a segurança da memória no início da execução.
 * As documentações completas destas estruturas estão no DefStructs.h.
 */
#include <stdlib.h>
#include "DefStructs.h"

ListaProdutos* headP = NULL;
ListaProdutos* tailP = NULL;
int tamP = 0;

Caixa* topoParafina = NULL;
Caixa* topoLeash = NULL;
Caixa* topoQuilha = NULL;
Caixa* topoDeck = NULL;

FilaEntrega* headFE = NULL;
FilaEntrega* tailFE = NULL;
int tamFE = 0;
