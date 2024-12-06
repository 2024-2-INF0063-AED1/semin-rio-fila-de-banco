#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Estrutura do cliente (id, nome, idade e se possui preferencia ou nao)
typedef struct Cliente {
    int id;
    char nome[50];
    int idade;
    bool preferencia;
    struct Cliente *proximo;
} Cliente;

// Estrutura da fila (First In, First Out)
typedef struct Fila {
    Cliente *frente;
    Cliente *tras;
} Fila;

int contadorID = 0; // Contador para IDs

// Função para inicializar a fila
void iniciaFila(Fila *fila) {
    fila->frente = fila->tras = NULL;
}

// Função para liberar a memória de uma fila
void liberaFila(Fila *fila) {
    Cliente *atual = fila->frente;
    while (atual != NULL) {
        Cliente *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    fila->frente = fila->tras = NULL;
    printf("Fila liberada com sucesso.\n");
}

// função para remover cliente pelo ID
void removerClientePorID(Fila *fila, int id) {
    if (fila->frente == NULL) {
        printf("\nA fila está vazia.\n");
        return;
    }

    Cliente *anterior = NULL;
    Cliente *atual = fila->frente;

    while (atual != NULL) {
        if (atual->id == id) {
            if (anterior == NULL) {
                fila->frente = atual->proximo;
                if (fila->frente == NULL) {
                    fila->tras = NULL;
                }
            } else {
                anterior->proximo = atual->proximo;
                if (atual == fila->tras) {
                    fila->tras = anterior;
                }
            }

            printf("\nCliente com ID %d (%s) foi removido da fila.\n", atual->id, atual->nome);
            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("\nCliente com ID %d não encontrado.\n", id);
}

// Função para remover cliente por ID nas duas filas
void removerPorID(Fila *filaPreferencial, Fila *filaNormal, int id) {
    printf("\nProcurando cliente com ID %d para remover...\n", id);
    removerClientePorID(filaPreferencial, id);
    removerClientePorID(filaNormal, id);
}

// Função para adicionar cliente à fila 
void adicionaCliente(Fila *filaPreferencial, Fila *filaNormal) {
    char nome[50];
    int idade;
    char escolha;

    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", nome);
    printf("Digite a idade do cliente: ");
    scanf("%d", &idade);

    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo->id = ++contadorID;
    strcpy(novo->nome, nome);
    novo->idade = idade;

    // Determinar preferência com base na idade e na escolha do usuário
    if (idade >= 60) {
        printf("Cliente tem direito à fila preferencial por idade. Deseja adicionar à fila preferencial? (s/n): ");
        scanf(" %c", &escolha);
        novo->preferencia = (escolha == 's' || escolha == 'S');
    } else {
        printf("Esse cliente tem direito a fila preferencial? (s/n): ");
        scanf(" %c", &escolha);
        novo->preferencia = (escolha == 's' || escolha == 'S');
    }
    
    novo->proximo = NULL;

    Fila *fila = (novo->preferencia) ? filaPreferencial : filaNormal;

    if (fila->tras == NULL) {
        fila->frente = fila->tras = novo;
    } else {
        fila->tras->proximo = novo;
        fila->tras = novo;
    }

    printf("\nCliente %s cadastrado com sucesso! ID: %d\n", nome, novo->id);
}

// Função para exibir a fila 
void exibirFila(Fila *fila, const char *descricao) {
    printf("\nFila %s:\n", descricao);
    if (fila->frente == NULL) {
        printf("   Nenhum cliente na fila.\n");
        return;
    }

    Cliente *atual = fila->frente;
    while (atual != NULL) {
        printf("   ID: %d | Nome: %s | Idade: %d | Preferência: %s\n",
               atual->id, atual->nome, atual->idade, atual->preferencia ? "Sim" : "Não");
        atual = atual->proximo;
    }
}

// Função do menu principal do Banco da UFG 
void menu(Fila *filaPreferencial, Fila *filaNormal) {
    int opcao;
    do {
        printf("\n- - - Bem vindo ao Banco UFG - - -\n");
        printf("1. Cadastrar cliente no banco\n");
        printf("2. Exibir filas\n");
        printf("3. Atender próximo cliente\n");
        printf("4. Remover cliente por ID\n");
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
                if (filaPreferencial->frente != NULL) {
                    removerClientePorID(filaPreferencial, filaPreferencial->frente->id);
                } else if (filaNormal->frente != NULL) {
                    removerClientePorID(filaNormal, filaNormal->frente->id);
                } else {
                    printf("\nNenhum cliente na fila para atender.\n");
                }
                break;
            case 4: {
                int id;
                printf("\nDigite o ID do cliente a ser removido: ");
                scanf("%d", &id);
                removerPorID(filaPreferencial, filaNormal, id);
                break;
            }
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

// Função principal
int main() {
    Fila filaPreferencial, filaNormal;
    iniciaFila(&filaPreferencial);
    iniciaFila(&filaNormal);

    menu(&filaPreferencial, &filaNormal);

    // Libera a memória antes de encerrar o programa
    liberaFila(&filaPreferencial);
    liberaFila(&filaNormal);

    printf("\nMemória liberada. Encerrando o programa.");
    return 0;
}
