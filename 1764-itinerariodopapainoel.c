#include <stdio.h>
#include <stdlib.h>

#define MAX_M 40000
#define MAX_N 50000

typedef struct {
    int u, v, w;
} Aresta;

Aresta arestas[MAX_N];
int pai[MAX_M], rank[MAX_M];

int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->w - ((Aresta*)b)->w;
}

int encontrar(int x) {
    if (pai[x] != x) {
        pai[x] = encontrar(pai[x]);
    }
    return pai[x];
}

void unir(int x, int y) {
    int raizX = encontrar(x);
    int raizY = encontrar(y);
    if (raizX != raizY) {
        if (rank[raizX] > rank[raizY]) {
            pai[raizY] = raizX;
        } else if (rank[raizX] < rank[raizY]) {
            pai[raizX] = raizY;
        } else {
            pai[raizY] = raizX;
            rank[raizX]++;
        }
    }
}

int main() {
    int M, N;
    while (scanf("%d %d", &M, &N), M || N) {
        for (int i = 0; i < M; i++) {
            pai[i] = i;
            rank[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
        }
        qsort(arestas, N, sizeof(Aresta), comparar);
        int custo_mst = 0;
        for (int i = 0; i < N; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;
            int w = arestas[i].w;
            
            if (encontrar(u) != encontrar(v)) {
                unir(u, v);
                custo_mst += w;
            }
        }
        printf("%d\n", custo_mst);
    }
    
    return 0;
}
