# Algoritmo de Busca em Largura (Breadth-First Search - BFS)

O algoritmo de Busca em Largura, ou em inglês Breadth-First Search (BFS), é amplamente utilizado para realizar travessias em árvores e grafos. Sua principal característica está em visitar todos os nós de um nível antes de avançar para o próximo. Dessa forma, o BFS é muito utilizado para encontrar o caminho mais curto em grafos ou para verificar todos os nós em uma árvore.

## Características do BFS

- **Travessia por níveis**: O algoritmo percorre a árvore nível por nível, começando pela raiz e visitando todos os nós de cada camada antes de passar para a próxima.
- **Aplicações**: É útil para encontrar o caminho mais curto em um grafo não ponderado ou para realizar verificações em árvores balanceadas.

## Implementação do BFS em uma Árvore Balanceada

O algoritmo de BFS em uma árvore binária balanceada segue os seguintes passos:

1. A função recebe a raiz da árvore como entrada.
2. Usa uma fila para armazenar todos os nós do nível atual.
3. Remove o nó da frente da fila e processa seu valor.
4. Enfileira os filhos esquerdo e direito do nó, se existirem.
5. Repete o processo até que todos os níveis sejam percorridos.