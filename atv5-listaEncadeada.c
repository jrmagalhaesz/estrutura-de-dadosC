#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

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

void insertAtBeginning(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Valor %d inserido no início da lista.\n", value);
}

void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Valor %d inserido no final da lista.\n", value);
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("Valores da lista: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int value;

    printf("Digite os valores da lista (0 para sair):\n");

    while (1) {
        printf("Digite um valor: ");
        scanf("%d", &value);
        if (value == 0)
            break;

        insertAtEnd(&head, value);
    }

    displayList(head);

    return 0;
}
