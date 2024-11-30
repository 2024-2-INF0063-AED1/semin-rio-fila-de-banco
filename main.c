#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Cliente {
    char nome[50];
    int idade;
    bool preferencia;
    struct Cliente *proximo;
} Cliente;

typedef struct Fila {
    Cliente *frente;
    Cliente *tras;
} Fila;

void iniciaFila(Fila *fila) {
    fila->frente = fila->tras = NULL;
}
// função que add um cliente
void adicionaCliente(Fila *filaPreferencial, Fila *filaNormal) {
    char nome[50];
    int idade;

    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", nome);
    printf("Digite a idade do cliente: ");
    scanf("%d", &idade);

    bool preferencia = (idade > 60);

    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->preferencia = preferencia;
    novo->proximo = NULL;

    Fila *fila = preferencia ? filaPreferencial : filaNormal;

    if (fila->tras == NULL) {
        fila->frente = fila->tras = novo;
    } else {
        fila->tras->proximo = novo;
        fila->tras = novo;
    }

    printf("\nCliente %s cadastrado com sucesso!\n", nome);
}
// função que exibe a fila
void exibirFila(Fila *fila, const char *descricao) {
    printf("\nFila %s:\n", descricao);
    if (fila->frente == NULL) {
        printf("   Nenhum cliente na fila.\n");
        return;
    }

    Cliente *atual = fila->frente;
    while (atual != NULL) {
        printf("   Nome: %s | Idade: %d | Preferência: %s\n",
               atual->nome, atual->idade, atual->preferencia ? "Sim" : "Não");
        atual = atual->proximo;
    }
}
// função que apaga o primeiro cliente e avança a fila
void atenderProximoCliente(Fila *filaPreferencial, Fila *filaNormal) {
    if (filaPreferencial->frente != NULL) {
        Cliente *cliente = filaPreferencial->frente;
        filaPreferencial->frente = cliente->proximo;
        if (filaPreferencial->frente == NULL) {
            filaPreferencial->tras = NULL;
        }
        printf("\nAtendendo cliente preferencial: %s\n", cliente->nome);
        free(cliente);
    } else if (filaNormal->frente != NULL) {
        Cliente *cliente = filaNormal->frente;
        filaNormal->frente = cliente->proximo;
        if (filaNormal->frente == NULL) {
            filaNormal->tras = NULL;
        }
        printf("\nAtendendo cliente normal: %s\n", cliente->nome);
        free(cliente);
    } else {
        printf("\nNenhum cliente na fila para atender.\n");
    }
}
//menu que serve de interface para navegar nas funçoes
void menu(Fila *filaPreferencial, Fila *filaNormal) {
    int opcao;

    do {
        printf("\n- - - Bem vindo ao Banco UFG - - -\n");
        printf("1. Cadastrar cliente no banco\n");
        printf("2. Exibir filas\n");
        printf("3. Atender próximo cliente\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionaCliente(filaPreferencial, filaNormal);
                break;
            case 2:
                exibirFila(filaPreferencial, "Preferencial");
                exibirFila(filaNormal, "Normal");
                break;
            case 3:
                atenderProximoCliente(filaPreferencial, filaNormal);
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

int main() {
    Fila filaPreferencial, filaNormal;
    iniciaFila(&filaPreferencial);
    iniciaFila(&filaNormal);

    menu(&filaPreferencial, &filaNormal);

    return 0;
}
