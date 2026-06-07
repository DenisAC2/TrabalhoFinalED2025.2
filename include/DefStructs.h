#pragma once

/**
 * @brief Estrutura que representa um produto no catálogo da Surf Shop.
 * Implementa um nó de uma lista duplamente encadeada, mantendo os itens ordenados.
 */
typedef struct Produto {
    int codigo;/**< Código identificador único do produto */
    char tipo_produto[32];   /**< Categoria do item (Parafina, Leash, Quilha, Deck) */
    char descricao[64];      /**< Descrição ou nome comercial do produto */
    float preco;             /**< Preço de venda unitário */
    struct Produto* next;    /**< Ponteiro para o próximo produto na lista */
    struct Produto* prev;    /**< Ponteiro para o produto anterior na lista */
} ListaProdutos;

/**
 * @brief Lista encadeada simples para armazenar os códigos dos produtos.
 * Utilizada internamente nas caixas para rastrear exatamente quais itens estão guardados.
 */
typedef struct LC {
    int codigo;/**< Código do produto armazenado */
    struct LC* next;    /**< Ponteiro para o próximo código na caixa */
} ListaCodigos;

/**
 * @brief Estrutura que representa uma caixa de estoque físico (Pilha).
 * Funciona como um nó de uma pilha encadeada orientada verticalmente.
 */
typedef struct caixa {
    int codigo;/**< Código identificador único desta caixa */
    int quantP;                  /**< Quantidade atual de itens guardados nesta caixa */
    ListaCodigos* lista_codigos; /**< Histórico de códigos dos produtos contidos aqui */
    struct caixa* below;         /**< Ponteiro para a caixa imediatamente abaixo nesta pilha */
} Caixa;

/**
 * @brief Fila de logística para registrar as entregas aos clientes.
 * Armazena os dados do comprador e o ponteiro para o produto que ele adquiriu.
 */
typedef struct fila {
    char nomeCliente[64];               /**< Nome completo do comprador */
    char cpfCliente[16];                /**< CPF do comprador */
    int cepCliente;                     /**< CEP do endereço de entrega */
    char ruaCliente[64];                /**< Nome da rua para entrega */
    int numeroCasaCliente;              /**< Número da residência */
    char complementoCasaCliente[64];    /**< Complemento do endereço (ex: Bloco B) */
    ListaProdutos* ProdutoVendido;      /**< Ponteiro para os dados do produto que foi vendido */
    struct fila* next;                  /**< Ponteiro para a próxima entrega na fila */
} FilaEntrega;

// Variáveis globais externadas para evitar múltiplas definições na linkagem
extern ListaProdutos* headP;  /**< Ponteiro para o início da lista de produtos */
extern ListaProdutos* tailP;  /**< Ponteiro para o final da lista de produtos */
extern int tamP;              /**< Tamanho atual da lista de produtos */

extern Caixa* topoParafina;   /**< Topo da pilha de caixas de Parafina */
extern Caixa* topoLeash;      /**< Topo da pilha de caixas de Leash */
extern Caixa* topoQuilha;     /**< Topo da pilha de caixas de Quilha */
extern Caixa* topoDeck;       /**< Topo da pilha de caixas de Deck */

extern FilaEntrega* headFE;   /**< Início da fila de entregas (próximo a sair) */
extern FilaEntrega* tailFE;   /**< Final da fila de entregas (último a entrar) */
extern int tamFE;             /**< Tamanho atual da fila de entregas */
