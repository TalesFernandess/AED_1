#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel {
    int num;
    struct cel *seg;
    struct cel *ant;
} celula;

void insere(int y, celula **lista) {
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1); 
    }
    nova->num = y;
    nova->seg = *lista;
    nova->ant = NULL;
    if (*lista != NULL) {
        (*lista)->ant = nova;
    }
    *lista = nova;
}

void remover(celula **lista) {
    if (*lista == NULL) {
        printf("EMPTY\n");
        return;
    }
    celula *descarte = *lista;
    *lista = descarte->seg;
    if (*lista != NULL) {
        (*lista)->ant = NULL;
    }
    free(descarte);
}

void minimo(celula *lista) {
    if (lista == NULL) {
        printf("EMPTY\n");
        return;
    }
    celula *p = lista;
    int min = lista->num;
    while (p != NULL) {
        if (min > p->num) {
            min = p->num;
        }
        p = p->seg;
    }
    printf("%d\n", min);
}

int main() {
    int operacoes, i, n;
    char op[10];
    celula *pilha = NULL, *p;

    scanf("%d", &operacoes);

    for (i = 0; i < operacoes; i++) {
        scanf("%s", op);
        if (strcmp(op, "PUSH") == 0) {
            scanf("%d", &n);
            insere(n, &pilha);
        } else if (strcmp(op, "POP") == 0) {
            remover(&pilha);
        } else if (strcmp(op, "MIN") == 0) {
            minimo(pilha);
        } else {
            printf("Operação inválida: %s\n", op);
        }
    }

    while (pilha != NULL) {
        p = pilha;
        pilha = pilha->seg;
        free(p);
    }

    return 0;
}
