#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char valor;
    struct no *prox;
} no;

typedef struct pilha {
    no *topo;
} pilha;

void inicializar(pilha *p) {
    p->topo = NULL;
}

int pilhavazia(pilha *p) {
    return p->topo == NULL;
}

void empilha(pilha *p, char c) {
    no* novo = (no*)malloc(sizeof(no));
    novo->valor = c;
    novo->prox = p->topo;
    p->topo = novo;
}

char desempilha(pilha *p) {
    if (pilhavazia(p)) {
        return '\0';
    }
    char valor = p->topo->valor;
    no* lixo = p->topo;
    p->topo = p->topo->prox;
    free(lixo);
    return valor;
}

void limpapilha(pilha *p) {
    while (!pilhavazia(p)) {
        desempilha(p);
    }
}

void balanceamento(const char* expressao) {
    pilha pilha;
    inicializar(&pilha);
    for (int i = 0; expressao[i] != '\0'; i++) {
        char x = expressao[i];
        if (x == '(') {
            empilha(&pilha, x);
        } else if (x == ')') {
            if (pilhavazia(&pilha)) {
                printf("incorrect\n");
                limpapilha(&pilha);
                return;
            }
            desempilha(&pilha);
        }
    }

    if (pilhavazia(&pilha)) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }

    limpapilha(&pilha);
}

int main() {
    char expressao[1001];
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        expressao[strcspn(expressao, "\n")] = '\0';
        if (strlen(expressao) == 0) {
            break;
        }
        balanceamento(expressao);
    }
    return 0;
}
