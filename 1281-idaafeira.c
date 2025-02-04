#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
    char nome[50];
    float preco;
} prod;

typedef struct cel {
    prod item;
    struct cel *seg;
} celula;

void insere(char n[50], float y, celula **lista) {
    celula *nova = (celula*) malloc(sizeof(celula));
    if (!nova) {
        fprintf(stderr, "Erro de alocação de memória!\n");
        exit(1);
    }
    strcpy(nova->item.nome, n);
    nova->item.preco = y;
    nova->seg = *lista;
    *lista = nova;
}

float busca(char e[50], celula *lista) {
    celula *p = lista;
    while (p != NULL) {
        if (strcmp(p->item.nome, e) == 0) {
            return p->item.preco;
        }
        p = p->seg;
    }
    return 0.0;  
}

void liberaLista(celula **lista) {
    celula *aux;
    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->seg;
        free(aux);
    }
}

int main() {
    int n, m, p, quantidade, i, j;
    float preco, custo_unidade;
    char produto[50], escolha[50];
    celula *feira = NULL;

    scanf("%d", &n);
    float custo_total[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        for (j = 0; j < m; j++) {
            scanf("%s %f", produto, &preco);
            insere(produto, preco, &feira);
        }

        scanf("%d", &p);
        custo_total[i] = 0;
        for (j = 0; j < p; j++) {
            scanf("%s %d", escolha, &quantidade);
            custo_unidade = busca(escolha, feira) * quantidade;
            custo_total[i] += custo_unidade;
        }

        liberaLista(&feira);
    }

    for (i = 0; i < n; i++) {
        printf("R$ %.2f\n", custo_total[i]);
    }

    return 0;
}
