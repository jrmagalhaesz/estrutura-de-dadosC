#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = newNode; 
    } else {
        newNode->next = queue->front; 
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Valor %d enfileirado com sucesso.\n", value);
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Erro: a fila está vazia. Não é possível desenfileirar.\n");
        return;
    }

    int removedValue = queue->front->data;
    Node* temp = queue->front;

    if (queue->front == queue->rear) { 
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front; 
    }

    free(temp);
    printf("Valor %d desenfileirado com sucesso.\n", removedValue);
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return;
    }

    printf("Elementos da fila: ");
    Node* current = queue->front;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

void freeQueue(Queue* queue) {
    if (isEmpty(queue)) {
        free(queue);
        return;
    }

    Node* current = queue->front;
    Node* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != queue->front);

    free(queue);
}

int main() {
    Queue* queue = createQueue();
    int choice, value;

    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Exibir fila\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Informe o valor a ser enfileirado: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 0);

    freeQueue(queue);

    return 0;
}
