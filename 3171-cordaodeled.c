#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100

void dfs(int graph[MAX_N + 1][MAX_N + 1], bool visitado[], int node, int N) {
    visitado[node] = true;
    for (int i = 1; i <= N; i++) {
        if (graph[node][i] && !visitado[i]) {
            dfs(graph, visitado, i, N);
        }
    }
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    int graph[MAX_N + 1][MAX_N + 1] = {0}; 
    bool visitado[MAX_N + 1] = {0}; 
    for (int i = 0; i < L; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        graph[X][Y] = 1;
        graph[Y][X] = 1;
    }
    dfs(graph, visitado, 1, N);
    bool completo = true;
    for (int i = 1; i <= N; i++) {
        if (!visitado[i]) {
            completo = false;
            break;
        }
    }
    if (completo) {
        printf("COMPLETO\n");
    } else {
        printf("INCOMPLETO\n");
    }
    
    return 0;
}
