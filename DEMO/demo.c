#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20
#define MAX_NODES SIZE * SIZE

typedef struct {
    int x, y;         // Coordenadas do nó
    int g;           // Custo do caminho até este nó
    int h;           // Heurística
    int f;           // Custo total
    bool closed;     // Indica se o nó foi fechado
    bool open;       // Indica se o nó está aberto para exploração
    struct Node* parent; // Nó pai
} Node;

Node* openList[MAX_NODES]; // Lista de nós abertos
int openListSize = 0;       // Tamanho da lista de nós abertos
int matriz[SIZE][SIZE] = {0}; // Matriz 20x20

// Função para calcular a heurística (distância de Manhattan)
int heuristic(int x, int y, int targetX, int targetY) {
    return abs(x - targetX) + abs(y - targetY);
}

// Função para adicionar um nó à lista de abertos
void addToOpenList(Node* node) {
    openList[openListSize++] = node;
}

// Função para verificar se um nó está na lista de abertos
bool isInOpenList(int x, int y) {
    for (int i = 0; i < openListSize; i++) {
        if (openList[i]->x == x && openList[i]->y == y) {
            return true;
        }
    }
    return false;
}

// Função para encontrar o menor custo no nó aberto
Node* getLowestCostNode() {
    Node* lowestNode = NULL;
    for (int i = 0; i < openListSize; i++) {
        if (!lowestNode || openList[i]->f < lowestNode->f) {
            lowestNode = openList[i];
        }
    }
    return lowestNode;
}

// Função que implementa o algoritmo A*
bool aStar(int startX, int startY, int targetX, int targetY) {
    Node* startNode = (Node*)malloc(sizeof(Node));
    startNode->x = startX;
    startNode->y = startY;
    startNode->g = 0;
    startNode->h = heuristic(startX, startY, targetX, targetY);
    startNode->f = startNode->g + startNode->h;
    startNode->closed = false;
    startNode->open = true;
    startNode->parent = NULL;

    addToOpenList(startNode);

    while (openListSize > 0) {
        Node* currentNode = getLowestCostNode();

        // Remover o nó atual da lista aberta
        for (int i = 0; i < openListSize; i++) {
            if (openList[i] == currentNode) {
                openList[i] = openList[--openListSize];
                break;
            }
        }

        // Marcar o nó atual como fechado
        currentNode->closed = true;

        // Verificar se chegamos ao alvo
        if (currentNode->x == targetX && currentNode->y == targetY) {
            Node* pathNode = currentNode;
            while (pathNode) {
                matriz[pathNode->x][pathNode->y] = 1; // Marcar o caminho na matriz
                pathNode = pathNode->parent;
            }
            return true; // Caminho encontrado
        }

        // Explorar os vizinhos
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) != 1) continue; // Ignorar diagonais

                int newX = currentNode->x + dx;
                int newY = currentNode->y + dy;

                // Verificar se o novo nó está dentro da matriz
                if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
                    if (matriz[newX][newY] == 0) { // Se o nó é livre
                        Node* neighbor = (Node*)malloc(sizeof(Node));
                        neighbor->x = newX;
                        neighbor->y = newY;
                        neighbor->g = currentNode->g + 1; // Custo do caminho
                        neighbor->h = heuristic(newX, newY, targetX, targetY);
                        neighbor->f = neighbor->g + neighbor->h;
                        neighbor->closed = false;
                        neighbor->open = true;
                        neighbor->parent = currentNode;

                        // Verificar se o nó já está na lista aberta
                        if (!isInOpenList(newX, newY)) {
                            addToOpenList(neighbor);
                        } else {
                            free(neighbor); // Se já estiver na lista, liberar a memória
                        }
                    }
                }
            }
        }
    }

    return false; // Caminho não encontrado
}

int main() {
    // Inicializa a matriz com zeros
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matriz[i][j] = 0;
        }
    }

    int targetX = 0; // Alvo na posição (19, 19)
    int targetY = 19;

    // Executa o algoritmo A*
    if (aStar(10, 10, targetX, targetY)) {
        printf("Caminho encontrado:\n");
    } else {
        printf("Caminho não encontrado.\n");
    }

    // Imprime a matriz
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
