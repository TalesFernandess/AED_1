#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int  V, W, p; 
} Aresta;

typedef struct {
    int pai[200];
    int rank[60];
} UniFind;

void inicializa(UniFind *uf, int n) {
    for (int i = 1; i <= n; i++) {
        uf->pai[i] = i;
        uf->rank[i] = 0;
    }
}

int encontra(UniFind *uf, int u) {
    if (uf->pai[u] != u) {
        uf->pai[u] = encontra(uf, uf->pai[u]);
    }
    return uf->pai[u];
}

void une(UniFind *uf, int u, int v) {
    int raiz_u = encontra(uf, u);
    int raiz_v = encontra(uf, v);

    if (raiz_u != raiz_v) {
        if (uf->rank[raiz_u] > uf->rank[raiz_v]) {
            uf->pai[raiz_v] = raiz_u;
        } else if (uf->rank[raiz_u] < uf->rank[raiz_v]) {
            uf->pai[raiz_u] = raiz_v;
        } else {
            uf->pai[raiz_v] = raiz_u;
            uf->rank[raiz_u]++;
        }
    }
}

int compara(const void *a, const void *b) {
    return ((Aresta *)a)->p - ((Aresta *)b)->p;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    Aresta arestas[200];
    for (int i = 0; i < C; i++) {
        scanf("%d %d %d", &arestas[i].V, &arestas[i].W, &arestas[i].p);
    }
    qsort(arestas, C, sizeof(Aresta), compara);
    UniFind uf;
    inicializa(&uf, R);
    int custo_total = 0;
    int arestas_usadas = 0;
    for (int i = 0; i < C; i++) {
        int u = arestas[i].V;
        int v = arestas[i].W;
        int custo = arestas[i].p;

        if (encontra(&uf, u) != encontra(&uf, v)) {
            une(&uf, u, v);
            custo_total += custo;
            arestas_usadas++;
        }
        if (arestas_usadas == R - 1) {
            break;
        }
    }
    printf("%d\n", custo_total);
}
