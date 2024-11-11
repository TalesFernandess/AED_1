#include <stdio.h>

int sudoku(int matriz[9][9]) {
    int i, j, k, linha, coluna;

    // Verificação de linhas
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            for (k = j + 1; k < 9; k++) {
                if (matriz[i][j] == matriz[i][k]) {
                    return 1; // Repetição encontrada na linha
                }
            }
        }
    }

    // Verificação de colunas
    for (j = 0; j < 9; j++) {
        for (i = 0; i < 9; i++) {
            for (k = i + 1; k < 9; k++) {
                if (matriz[i][j] == matriz[k][j]) {
                    return 1; // Repetição encontrada na coluna
                }
            }
        }
    }

    // Verificação das submatrizes 3x3
    for (linha = 0; linha < 9; linha += 3) {
        for (coluna = 0; coluna < 9; coluna += 3) {
            int contador[9] = {0};
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    int num = matriz[linha + i][coluna + j];
                    if (num >= 1 && num <= 9) {
                        contador[num - 1]++;
                        if (contador[num - 1] > 1) {
                            return 1; // Repetição encontrada na submatriz 3x3
                        }
                    }
                }
            }
        }
    }
    return 0; // Sem repetições
}

int main() {
    int n, matriz[9][9], p, i, j;

    // Lê o número de instâncias
    scanf("%d", &n);
    
    // Loop para cada instância
    for (p = 0; p < n; p++) {
        // Lê a matriz 9x9
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        // Impressão da instância
        printf("Instancia %d\n", p + 1);
        if (sudoku(matriz) == 0) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }
    return 0;
}
