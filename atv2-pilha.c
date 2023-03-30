#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 5

typedef struct {
    int itens[TAMANHO_PILHA];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int estaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

int estaCheia(Pilha *pilha) {
    return (pilha->topo == TAMANHO_PILHA - 1);
}

void push(Pilha *pilha, int elemento) {
    if (estaCheia(pilha)) {
        printf("Erro: a pilha esta cheia\n");
        return;
    }
    
    pilha->topo++;
    pilha->itens[pilha->topo] = elemento;
}

int pop(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: a pilha esta vazia\n");
        return -1;
    }
    
    int elemento = pilha->itens[pilha->topo];
    pilha->topo--;
    return elemento;
}

void mostrarPilha(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("A pilha esta vazia\n");
        return;
    }
    
    printf("Elementos da pilha:\n");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%d\n", pilha->itens[i]);
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);
    
    int opcao, valor;
    
    do {
        printf("\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir um elemento\n");
        printf("2 - Remover um elemento\n");
        printf("3 - Mostrar a pilha\n");
        printf("0 - Sair\n");
        printf("Opcao escolhida: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                break;
            case 2:
                valor = pop(&pilha);
                if (valor != -1) {
                    printf("Elemento removido: %d\n", valor);
                }
                break;
            case 3:
                mostrarPilha(&pilha);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao != 0);
    
    return 0;
}
