# Sistema de Estoque - Surf Shop 🌊

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Status](https://img.shields.io/badge/Status-Concluido-brightgreen?style=for-the-badge)

Sistema desenvolvido como trabalho final da disciplina de Estruturas de Dados. O projeto simula o gerenciamento de estoque e vendas de uma loja de surf, controlando itens como **Parafina, Leash, Quilha e Deck**.

## 🚀 Estruturas de Dados Aplicadas

O diferencial deste projeto é a aplicação prática de múltiplos conceitos de alocação dinâmica e ponteiros:
- **Lista Duplamente Encadeada:** Gerencia o catálogo de produtos à venda, mantendo os itens automaticamente ordenados por preço.
- **Pilha (Stack):** Simula o estoque físico. Os itens são armazenados em caixas empilhadas. Cada tipo de produto tem uma capacidade máxima por caixa (ex: 50 parafinas por caixa, 5 decks por caixa). Quando uma caixa enche, uma nova é empilhada por cima.
- **Fila (Queue):** Gerencia a logística de entrega. Após a venda, os dados do cliente e do produto entram em uma fila para confirmação de saída.

## 🛠️ Arquitetura do Código

- `DefStructs.h` / `defstructs.c`: Estruturas dos nós (Listas, Pilhas, Filas).
- `DefConst.h` / `DefConst.c`: Constantes globais e limites de capacidade.
- `FunctionsMenu.h` / `FunctionsMenu.c`: Lógica de ordenação, venda, liberação de memória (`free`) e interface do terminal.
- `main.c`: Loop principal e menus interativos.
