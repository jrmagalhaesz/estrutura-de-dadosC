#include <stdio.h>
#include <stdlib.h>

typedef struct SFila
{
    int dado;
    struct SFila *next;
} TFila;

TFila *fila = NULL;

void adicionarElemento(int info)
{
    TFila *novo = malloc(sizeof(TFila));
    novo->dado = info;
    novo->next = NULL;

    if (fila == NULL)
    {
        fila = novo;
    }
    else
    {
        TFila *ultimo = fila;
        while (ultimo->next != NULL)
        {
            ultimo = ultimo->next;
        }
        ultimo->next = novo;
    }
}

void imprimirFila()
{
    printf("\nValores da fila:\n");
    TFila *atual = fila;
    while (atual != NULL)
    {
        printf("%d\n", atual->dado);
        atual = atual->next;
    }
}

TFila *buscarElemento(int chave)
{
    TFila *atual = fila;
    while (atual != NULL)
    {
        if (atual->dado == chave)
        {
            return atual;
        }
        atual = atual->next;
    }
    return NULL;
}

void removerElemento()
{
    if (fila == NULL)
    {
        printf("A fila está vazia.\n");
    }
    else
    {
        TFila *remover = fila;
        fila = fila->next;
        free(remover);
        printf("Um elemento foi removido da fila.\n");
    }
}

int main()
{
    int opcao;
    int leitura;
    int chave;
    TFila *posicao;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Adicionar elemento\n");
        printf("2. Imprimir fila\n");
        printf("3. Remover elemento\n");
        printf("4. Buscar elemento\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("Encerrando o programa...\n");
            return 0;
        case 1:
            printf("Informe o valor a ser adicionado: ");
            scanf("%d", &leitura);
            adicionarElemento(leitura);
            printf("Valor adicionado com sucesso!\n");
            break;
        case 2:
            imprimirFila();
            break;
        case 3:
            removerElemento();
            break;
        case 4:
            printf("Informe o valor a ser buscado: ");
            scanf("%d", &chave);
            posicao = buscarElemento(chave);
            if (posicao == NULL)
            {
                printf("Não encontramos nenhum registro para a sua busca.\n");
            }
            else
            {
                printf("O valor foi encontrado na posição: %p\n", posicao);
            }
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    }
}
