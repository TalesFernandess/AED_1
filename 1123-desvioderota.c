#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF INT_MAX
#define MAX_VERTICES 1010

typedef struct {
    int num_vertices, num_arestas, cidade_destino, cidade_inicial;
    int grafo[MAX_VERTICES][MAX_VERTICES];
    int custo_minimo[MAX_VERTICES];
} Mapa;

void inicializar_mapa(Mapa *m) {
    for (int i = 0; i <= m->num_vertices; i++) {
        m->custo_minimo[i] = INF;
        for (int j = 0; j <= m->num_vertices; j++) {
            m->grafo[i][j] = INF;
        }
    }
}

int dijkstra(Mapa *m, int origem, int destino) {
    bool visitado[MAX_VERTICES] = {false};
    m->custo_minimo[origem] = 0;

    for (int cont = 0; cont < m->num_vertices - 1; cont++) {
        int menor_custo = INF, indice_minimo = -1;

        for (int v = 0; v < m->num_vertices; v++) {
            if (!visitado[v] && m->custo_minimo[v] <= menor_custo) {
                menor_custo = m->custo_minimo[v];
                indice_minimo = v;
            }
        }

        if (indice_minimo == -1) break;

        visitado[indice_minimo] = true;

        for (int v = 0; v < m->num_vertices; v++) {
            if (!visitado[v] && m->grafo[indice_minimo][v] != INF && 
                m->custo_minimo[indice_minimo] != INF &&
                m->custo_minimo[indice_minimo] + m->grafo[indice_minimo][v] < m->custo_minimo[v]) {
                
                m->custo_minimo[v] = m->custo_minimo[indice_minimo] + m->grafo[indice_minimo][v];
            }
        }
    }

    return m->custo_minimo[destino];
}

int main() {
    Mapa mapa;

    while (scanf("%d %d %d %d", &mapa.num_vertices, &mapa.num_arestas, 
                 &mapa.cidade_destino, &mapa.cidade_inicial), 
                 (mapa.num_vertices || mapa.num_arestas || mapa.cidade_destino || mapa.cidade_inicial)) {
        
        inicializar_mapa(&mapa);

        for (int i = 0; i < mapa.num_arestas; i++) {
            int origem, destino, peso;
            scanf("%d %d %d", &origem, &destino, &peso);

            if (origem >= mapa.cidade_destino && destino >= mapa.cidade_destino) {
                mapa.grafo[origem][destino] = peso;
                mapa.grafo[destino][origem] = peso;
            } 
            if (origem >= mapa.cidade_destino && destino < mapa.cidade_destino) {
                mapa.grafo[origem][destino] = peso;
            } 
            if (origem < mapa.cidade_destino && destino >= mapa.cidade_destino) {
                mapa.grafo[destino][origem] = peso;
            } 
            if (origem < mapa.cidade_destino && destino < mapa.cidade_destino && abs(origem - destino) == 1) {
                mapa.grafo[origem][destino] = peso;
                mapa.grafo[destino][origem] = peso;
            }
        }

        printf("%d\n", dijkstra(&mapa, mapa.cidade_inicial, mapa.cidade_destino - 1));
    }

    return 0;
}
