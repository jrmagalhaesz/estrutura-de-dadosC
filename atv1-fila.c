#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_FILA 5

typedef struct {
    int itens[TAMANHO_FILA];
    int inicio, fim;
    int tamanho;
} FilaCircular;

void inicializarFila(FilaCircular *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}

int estaVazia(FilaCircular *fila) {
    return (fila->tamanho == 0);
}

int estaCheia(FilaCircular *fila) {
    return (fila->tamanho == TAMANHO_FILA);
}

void inserir(FilaCircular *fila, int elemento) {
    if (estaCheia(fila)) {
        printf("Erro: a fila esta cheia\n");
        return;
    }
    
    fila->fim = (fila->fim + 1) % TAMANHO_FILA;
    fila->itens[fila->fim] = elemento;
    fila->tamanho++;
}

void remover(FilaCircular *fila) {
    if (estaVazia(fila)) {
        printf("Erro: a fila esta vazia\n");
        return;
    }
    
    printf("Elemento removido: %d\n", fila->itens[fila->inicio]);
    fila->inicio = (fila->inicio + 1) % TAMANHO_FILA;
    fila->tamanho--;
}

void mostrarFila(FilaCircular *fila) {
    if (estaVazia(fila)) {
        printf("A fila esta vazia\n");
        return;
    }

    printf("Fila: ");
    int i;
    for (i = 0; i < fila->tamanho; i++) {
        int indice = (fila->inicio + i) % TAMANHO_FILA;
        printf("%d ", fila->itens[indice]);
    }
    printf("\n");
}

int main() {
    FilaCircular fila;
    inicializarFila(&fila);

    int opcao, elemento;
    
    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Mostrar fila\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                inserir(&fila, elemento);
                break;
            case 2:
                remover(&fila);
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 0:
                printf("Encerrando programa\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
        
        printf("\n");
        
    } while (opcao != 0);

    return 0;
}
