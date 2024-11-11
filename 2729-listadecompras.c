#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char item[21];
    struct celula *prox;
} celula;

void adicionar_ordenado(celula **inicio, const char *palavra) {
    celula *novo = (celula *)malloc(sizeof(celula));
    strncpy(novo->item, palavra, sizeof(novo->item) - 1);
    novo->item[sizeof(novo->item) - 1] = '\0';
    celula *atual = *inicio, *anterior = NULL;

    while (atual != NULL && strcmp(novo->item, atual->item) > 0) {
        anterior = atual;
        atual = atual->prox;
    }

    novo->prox = atual;
    if (anterior == NULL) {
        *inicio = novo;
    } else {
        anterior->prox = novo;
    }
}

int item_existe(celula *inicio, const char *palavra) {
    for (celula *atual = inicio; atual != NULL; atual = atual->prox) {
        if (strcmp(atual->item, palavra) == 0) {
            return 1;
        }
    }
    return 0;
}

void exibir_lista(celula *inicio) {
    celula *atual = inicio;
    while (atual != NULL) {
        printf("%s", atual->item);
        if (atual->prox != NULL) {
            printf(" ");
        }
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    int n;
    char linha[21000], *token;

    scanf("%d", &n);
    getchar(); 

    for (int i = 0; i < n; i++) {
        celula *lista = NULL; 

        fgets(linha, sizeof(linha), stdin);
        token = strtok(linha, " \n");

        while (token != NULL) {
            if (!item_existe(lista, token)) {
                adicionar_ordenado(&lista, token);
            }
            token = strtok(NULL, " \n");
        }

        exibir_lista(lista);

        while (lista != NULL) {
            celula *temp = lista;
            lista = lista->prox;
            free(temp);
        }
    }
    return 0;
}
