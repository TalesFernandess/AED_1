#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char nome[21];
    struct celula *prox;
} celula;

void adicionar_no_final(celula **inicio, const char *nome) {
    celula *novo = (celula *)malloc(sizeof(celula));
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    celula *atual = *inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}

void inserir_nova_lista(celula **inicio, const char *nova_lista, const char *amigo_indicado) {
    celula *nova_lista_temp = NULL;
    char *token = strtok((char *)nova_lista, " ");

    while (token != NULL) {
        adicionar_no_final(&nova_lista_temp, token);
        token = strtok(NULL, " ");
    }

    if (strcmp(amigo_indicado, "nao") == 0) {
        if (*inicio == NULL) {
            *inicio = nova_lista_temp;
        } else {
            celula *atual = *inicio;
            while (atual->prox != NULL) {
                atual = atual->prox;
            }
            atual->prox = nova_lista_temp;
        }
        return;
    }

    celula *atual = *inicio, *anterior = NULL;
    while (atual != NULL && strcmp(atual->nome, amigo_indicado) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        *inicio = nova_lista_temp;
    } else {
        anterior->prox = nova_lista_temp;
    }

    celula *final_nova_lista = nova_lista_temp;
    while (final_nova_lista->prox != NULL) {
        final_nova_lista = final_nova_lista->prox;
    }
    final_nova_lista->prox = atual;
}

void imprimir_lista(celula *inicio) {
    celula *atual = inicio;
    int primeiro = 1;
    while (atual != NULL) {
        if (!primeiro) printf(" ");
        printf("%s", atual->nome);
        primeiro = 0;
        atual = atual->prox;
    }
    printf("\n");
}

void liberar_lista(celula *inicio) {
    celula *atual = inicio;
    while (atual != NULL) {
        celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    celula *lista_amigos = NULL;
    char lista_inicial[21000], nova_lista[21000], amigo_indicado[21];

    fgets(lista_inicial, 21000, stdin);
    lista_inicial[strcspn(lista_inicial, "\n")] = '\0';
    char *token = strtok(lista_inicial, " ");
    while (token != NULL) {
        adicionar_no_final(&lista_amigos, token);
        token = strtok(NULL, " ");
    }

    fgets(nova_lista, 21000, stdin);
    nova_lista[strcspn(nova_lista, "\n")] = '\0';
    fgets(amigo_indicado, 21, stdin);
    amigo_indicado[strcspn(amigo_indicado, "\n")] = '\0';

    inserir_nova_lista(&lista_amigos, nova_lista, amigo_indicado);

    imprimir_lista(lista_amigos);
    liberar_lista(lista_amigos);

    return 0;
}
