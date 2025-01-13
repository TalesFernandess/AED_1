#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char valor;
    struct celula *prox;
} celula;

void push(char y, celula *p) {
    celula *nova = malloc(sizeof(celula));
    if (!nova) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(1);
    }
    nova->valor = y;
    nova->prox = p->prox;
    p->prox = nova;
}

char pop(celula *p) {
    if (p->prox == NULL) {
        fprintf(stderr, "Erro: tentativa de remover de uma pilha vazia\n");
        exit(1);
    }
    celula *lixo = p->prox;
    char x = lixo->valor;
    p->prox = lixo->prox;
    free(lixo);
    return x;
}

int prioridade(char operador) {
    if (operador == '(') return 0;
    if (operador == '+' || operador == '-') return 1;
    if (operador == '*' || operador == '/') return 2;
    if (operador == '^') return 3;
    return -1;
}

void infixaparaposfixa(char *expressao) {
    celula cabeca;
    celula *p = &cabeca;
    p->prox = NULL;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            printf("%c", c); 
        } else if (c == '(') {
            push(c, p);
        } else if (c == ')') {
            while (p->prox != NULL && p->prox->valor != '(') {
                printf("%c", pop(p));
            }
            pop(p); 
        } else {
            while (p->prox != NULL && prioridade(c) <= prioridade(p->prox->valor)) {
                printf("%c", pop(p));
            }
            push(c, p);
        }
    }

    while (p->prox != NULL) {
        printf("%c", pop(p));
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); 

    for (int i = 0; i < n; i++) {
        char expressao[301];
        scanf("%s", expressao);
        infixaparaposfixa(expressao);
    }
    return 0;
}
