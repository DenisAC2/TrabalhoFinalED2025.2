#pragma once
#include "DefStructs.h"
#include "DefConst.h"

// --- Funções de Inserção e Manipulação de Dados ---

/**
 * @brief Adiciona um produto à pilha correspondente à sua categoria.
 * @param codigo Código do produto.
 * @param tipo A categoria do produto (Parafina, Leash, Quilha, Deck).
 * @return true em caso de erro de alocação ou tipo inválido. false em caso de sucesso.
 */
bool AddPilhaCaixa(int, const char*);

/**
 * @brief Adiciona um novo produto à Lista Duplamente Encadeada (Catálogo).
 * O item é inserido de forma ordenada baseada no preço.
 * @param codigo Código do produto.
 * @param tipo Categoria do produto.
 * @param descricao Descrição comercial do produto.
 * @param preco Valor do produto.
 */
void AdicionarLPV(int, const char*, const char*, float);

/**
 * @brief Adiciona um pedido validado à Fila de Entregas.
 * @param nomeCliente Nome do comprador.
 * @param cpf CPF do comprador.
 * @param cep CEP de entrega.
 * @param rua Rua de entrega.
 * @param num Número da residência.
 * @param complemento Complemento do endereço.
 * @param produto Ponteiro para o nó do produto vendido.
 */
void AdicionarFE(const char*, const char*, int, const char*, int, const char*, ListaProdutos*);

// --- Funções de Venda e Remoção ---

/**
 * @brief Remove um produto específico da Pilha de estoque.
 * @param codigo Código do produto a ser desempilhado.
 * @param tipo Categoria do produto.
 * @return true se houver falha (produto não encontrado). false se sucesso.
 */
bool RemoverProdutoDaPilha(int, const char*);

/**
 * @brief Processa a venda de um produto, removendo-o da Lista e da Pilha.
 * @param codigo Código do produto sendo vendido.
 * @return ListaProdutos* Ponteiro do produto desvinculado, ou NULL se falhar.
 */
ListaProdutos* VendaProduto(int);

/**
 * @brief Confirma a saída para entrega do primeiro item da fila e libera sua memória.
 */
void ConfirmacaoSE();

// --- Funções de Exibição e Impressão ---

/** @brief Imprime um produto específico baseado em seu índice ou a lista inteira se -1. */
void Imprimir(int pos);
/** @brief Imprime o estado detalhado de uma pilha de caixas específica. */
void ImprimirPilha(const char* nome, Caixa* topo, int capacidade);
/** @brief Imprime o painel geral com todas as pilhas e o estado do estoque. */
void ImprimirPilhas();
/** @brief Imprime todos os produtos de uma categoria específica. */
void ImprimirVendaC(const char* tipo);
/** @brief Imprime produtos que estão dentro de uma faixa de preço. */
void ImprimirVendaP(float valorI, float valorF);
/** @brief Imprime os detalhes formatados de um nó ListaProdutos. */
void ImprimirProdutoNode(const ListaProdutos* node);
/** @brief Imprime os detalhes formatados de um nó FilaEntrega. */
void ImprimirEntregaNode(const FilaEntrega* node);

// --- Funções de Gerenciamento de Memória (Free) ---

/** @brief Libera toda a memória alocada para os códigos dentro de uma caixa. */
void LiberarCodigos(ListaCodigos* head);
/** @brief Libera recursivamente toda a pilha de caixas e seus conteúdos. */
void LiberarCaixas(Caixa** topo_ptr);
/** @brief Libera a Lista Duplamente Encadeada de produtos. */
void LiberarProdutos();
/** @brief Função principal de limpeza. Libera TODAS as estruturas alocadas no programa. */
void LiberarTudo();

// --- Funções Utilitárias e Validações ---

/** @brief Compara duas strings ignorando maiúsculas e minúsculas. */
bool StringsCaseInsensitive(const char* a, const char* b);
/** @brief Converte a string de categoria de produto para seu índice numérico constante. */
int IndiceParaString(const char* s);
/** @brief Verifica se um código de produto já existe no catálogo. */
bool CodigoExiste(int codigo);

// --- Funções de Tratamento de Input Seguro (Substitutos do scanf) ---

/** @brief Lê um inteiro com segurança via teclado. Retorna 0 (sucesso), 1, 2 ou 3 (códigos de erro). */
int InsercaoInt(int* destino);
/** @brief Lê um float com segurança via teclado. Retorna 0 (sucesso), 1, 2 ou 3 (códigos de erro). */
int InsercaoFloat(float* destino);
/** @brief Lê uma string via teclado, tratando limpeza de buffer e quebra de linha. */
int InsercaoString(char* destino, int TamBuffer);