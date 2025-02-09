#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 500

int prefix_pretas[MAX_N][MAX_N];
int prefix_brancas[MAX_N][MAX_N];

void calcular_prefixo(int N, char tabuleiro[MAX_N][MAX_N]) {
    memset(prefix_pretas, 0, sizeof(prefix_pretas));
    memset(prefix_brancas, 0, sizeof(prefix_brancas));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            prefix_pretas[i][j] = (tabuleiro[i][j] == 'P');
            prefix_brancas[i][j] = (tabuleiro[i][j] == 'B');

            if (i > 0) {
                prefix_pretas[i][j] += prefix_pretas[i-1][j];
                prefix_brancas[i][j] += prefix_brancas[i-1][j];
            }
            if (j > 0) {
                prefix_pretas[i][j] += prefix_pretas[i][j-1];
                prefix_brancas[i][j] += prefix_brancas[i][j-1];
            }
            if (i > 0 && j > 0) {
                prefix_pretas[i][j] -= prefix_pretas[i-1][j-1];
                prefix_brancas[i][j] -= prefix_brancas[i-1][j-1];
            }
        }
    }
}

int contar_pedras(int x1, int y1, int x2, int y2, int prefix[MAX_N][MAX_N]) {
    int soma = prefix[x2][y2];
    if (x1 > 0) soma -= prefix[x1-1][y2];
    if (y1 > 0) soma -= prefix[x2][y1-1];
    if (x1 > 0 && y1 > 0) soma += prefix[x1-1][y1-1];
    return soma;
}

int main() {
    int N, P;
    scanf("%d %d", &N, &P);
    char tabuleiro[MAX_N][MAX_N];
    memset(tabuleiro, '.', sizeof(tabuleiro));
    for (int i = 0; i < P; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        tabuleiro[L - 1][C - 1] = 'P';
    }
    for (int i = 0; i < P; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        tabuleiro[L - 1][C - 1] = 'B';
    }
    calcular_prefixo(N, tabuleiro);
    int cont_pretas = 0, cont_brancas = 0;
    for (int tamanho = 1; tamanho <= N; tamanho++) {
        for (int linha = 0; linha <= N - tamanho; linha++) {
            for (int coluna = 0; coluna <= N - tamanho; coluna++) {
                int x1 = linha, y1 = coluna;
                int x2 = linha + tamanho - 1, y2 = coluna + tamanho - 1;
                int total_pretas = contar_pedras(x1, y1, x2, y2, prefix_pretas);
                int total_brancas = contar_pedras(x1, y1, x2, y2, prefix_brancas);
                if (total_pretas > 0 && total_brancas == 0) cont_pretas++;
                if (total_brancas > 0 && total_pretas == 0) cont_brancas++;
            }
        }
    }
    printf("%d %d\n", cont_pretas, cont_brancas);
}
