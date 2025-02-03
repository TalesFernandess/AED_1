#include <stdlib.h>
#include <stdio.h>

struct No {
    int valor;
    struct No *prox;
};

struct Lista {
    struct No *lista;
};

struct Tabela {
    int n;
    struct Lista *tabela;
};

void inicializaLista(struct Lista *l) {
    l->lista = NULL;
}

void destroiNo(struct No *p) {
    if (p->prox != NULL) {
        destroiNo(p->prox);
    }
    free(p);
}

void destroiLista(struct Lista *l) {
    if (l->lista != NULL) {
        destroiNo(l->lista);
    }
}

struct No *insereNo(struct No *p, int valor) {
    if (p == NULL) {
        struct No *novo = (struct No *)malloc(sizeof(struct No));
        novo->valor = valor;
        novo->prox = NULL;
        return novo;
    } else {
        p->prox = insereNo(p->prox, valor);
        return p;
    }
}

void insereElemento(struct Lista *l, int valor) {
    if (l == NULL) {
        l = (struct Lista *)malloc(sizeof(struct Lista));
    }
    l->lista = insereNo(l->lista, valor);
}

void exibeLista(struct Lista *l) {
    if (l != NULL) {
        struct No *p = l->lista;
        while (p != NULL) {
            printf("%d -> ", p->valor);
            p = p->prox;
        }
    }
    printf("\\\n");
}

void inicializaTabela(struct Tabela *tabela, int n) {
    tabela->n = n;
    tabela->tabela = (struct Lista *)malloc(n * sizeof(struct Lista));
    for (int i = 0; i < n; ++i) {
        inicializaLista(&(tabela->tabela[i]));
    }
}

void destroiTabela(struct Tabela *tabela) {
    for (int i = 0; i < tabela->n; ++i) {
        destroiLista(&(tabela->tabela[i]));
    }
    tabela->n = 0;
    free(tabela->tabela);
}

int hash(struct Tabela *tabela, int valor) {
    return valor % tabela->n;
}

void insereElementoTabela(struct Tabela *tabela, int valor) {
    int indice = hash(tabela, valor);
    insereElemento(&(tabela->tabela[indice]), valor);
}

void exibeTabela(struct Tabela *tabela) {
    for (int i = 0; i < tabela->n; ++i) {
        printf("%d -> ", i);
        exibeLista(&(tabela->tabela[i]));
    }
}

int main() {
    int N, M, C, numero;
    struct Tabela th;

    scanf("%d", &N);

    for (int k = 0; k < N; ++k) {
        if (k) printf("\n");

        scanf("%d %d", &M, &C);
        inicializaTabela(&th, M);

        for (int i = 0; i < C; ++i) {
            scanf("%d", &numero);
            insereElementoTabela(&th, numero);
        }

        exibeTabela(&th);
        destroiTabela(&th);
    }

    return 0;
}
