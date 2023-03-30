#include <stdio.h>
#define MAX 100

typedef struct {
    int elementos[MAX];
    int tamanho;
} ListaLinear;

void inicializar(ListaLinear *lista) {
    lista->tamanho = 0;
}

int inserir(ListaLinear *lista, int elemento) {
    if (lista->tamanho >= MAX) {
        return 0;
    }
    int i;
    for (i = lista->tamanho - 1; i >= 0 && lista->elementos[i] > elemento; i--) {
        lista->elementos[i+1] = lista->elementos[i];
    }
    lista->elementos[i+1] = elemento;
    lista->tamanho++;
    return 1;
}

int main() {
    ListaLinear lista;
    inicializar(&lista);

    printf("Digite 10 numeros inteiros em ordem crescente:\n");

    int i, elemento;
    for (i = 0; i < 10; i++) {
        scanf("%d", &elemento);
        if (!inserir(&lista, elemento)) {
            printf("Lista cheia, nao foi possivel inserir o elemento.\n");
            return 1;
        }
    }

    printf("\nElementos da lista:\n");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d\n", lista.elementos[i]);
    }

    printf("Digite o numero que deseja inserir: ");
    scanf("%d", &elemento);

    for (i = lista.tamanho - 1; i >= 0 && lista.elementos[i] > elemento; i--);

    printf("O valor %d deveria ser inserido na posicao %d\n", elemento, i+1);

    return 0;
}
