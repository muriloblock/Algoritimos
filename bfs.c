#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Node* createNode (int data) {
	Node* newNode  = (Node*)malloc(sizeof(Node));
	newNode->data  = data;
	newNode->left  = NULL;
	newNode->right = NULL;
	return newNode;
}

typedef struct Queue {
	Node** itens;
	int front;
	int rear;
	int maxSize;
}Queue;

Queue* createQueue(int size) {
	Queue* queue   = (Queue*)malloc(sizeof(Queue));
	queue->itens   = (Node**)malloc(size * sizeof(Node*));
	queue->rear    = -1;
	queue->front   = -1;
	queue->maxSize = size;
	return queue;
}

int isFull(Queue* queue) {
	return queue->rear == queue->maxSize -1;
}

int isEmpty(Queue* queue) {
	return queue->front == -1;
}

void enqueue(Queue* queue,Node* node) {
	if(!isEmpty(queue)) {
		

int main () {
}
