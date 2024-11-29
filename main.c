#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    char nome[50];
    int idade;
    struct Cliente *proximo;
} Cliente;

typedef struct Fila {
    Cliente *frente;
    Cliente *tras;
} Fila;

void iniciaFila(Fila *fila) {
    fila->frente = fila->tras = NULL;
}

void adicionaCliente(Fila *fila) {
    char nome[50];
    int idade;

    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", nome);
    printf("Digite a idade do cliente: ");
    scanf("%d", &idade);

    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->proximo = NULL;

    if (fila->tras == NULL) {
        fila->frente = fila->tras = novo;
    } else {
        fila->tras->proximo = novo;
        fila->tras = novo;
    }

    printf("\nCliente %s cadastrado com sucesso!\n", nome);
}

void exibirFila(Fila *fila, const char *descricao) {
    printf("\nFila %s:\n", descricao);
    if (fila->frente == NULL) {
        printf("   Nenhum cliente na fila.\n");
        return;
    }

    Cliente *atual = fila->frente;
    while (atual != NULL) {
        printf("   Nome: %s | Idade: %d\n", atual->nome, atual->idade);
        atual = atual->proximo;
    }
}

void menu(Fila *fila) {
    int opcao;
    do {
        printf("\n- - - Bem vindo ao Banco UFG - - -\n");
        printf("1. Cadastrar cliente no banco\n");
        printf("2. Exibir filas\n");
        printf("3. Atender próximo cliente\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionaCliente(fila);
            break;
            case 2:
                exibirFila(fila, "Normal");
            break;
            case 3: {
                if (fila->frente != NULL) {
                    Cliente *cliente = fila->frente;
                    fila->frente = cliente->proximo;
                    if (fila->frente == NULL) {
                        fila->tras = NULL;
                    }
                    free(cliente);
                } else {
                    printf("\nNenhum cliente na fila para atender.\n");
                }

                exibirFila(fila, "Normal");
                break;
            }
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (1); // O loop nunca termina, pois a opção de sair foi removida.
}

int main() {
    Fila fila;
    iniciaFila(&fila);

    menu(&fila);

    return 0;
}
