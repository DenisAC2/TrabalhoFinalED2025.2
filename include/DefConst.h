#pragma once

/**
 * @file DefConst.h
 * @brief Definição das constantes globais, capacidades e categorias do sistema.
 */
#define CAP_PARAFINA 50 /**< Capacidade máxima de itens por caixa de Parafina */
#define CAP_LEASH 25    /**< Capacidade máxima de itens por caixa de Leash */
#define CAP_QUILHA 10   /**< Capacidade máxima de itens por caixa de Quilha */
#define CAP_DECK 5      /**< Capacidade máxima de itens por caixa de Deck */

/** * @brief Enumeração para mapear as categorias de produtos em índices numéricos. 
 */
enum { TYPE_PARAFINA = 0, TYPE_LEASH = 1, TYPE_QUILHA = 2, TYPE_DECK = 3, NUM_TYPES = 4 }; /**< Quantidade total de categorias disponíveis */

/** @brief Array global contendo os nomes das categorias em formato string. */
extern const char* PRODUCT_TYPE_NAMES[NUM_TYPES];

/** @brief Array global de contadores para gerar IDs únicos para cada nova caixa, separados por categoria. */
extern int caixa_id_counters[NUM_TYPES];