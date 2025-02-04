#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

typedef struct {
    int x, y;
} Posicao;

int movimentos[8][2] = {
    { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 },
    { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }
};

int eh_valida(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

Posicao pos_para_coord(char *pos) {
    Posicao p;
    p.x = pos[0] - 'a';
    p.y = pos[1] - '1';
    return p;
}

int movimentos_cavalo(Posicao inicio, Posicao fim) {
    if (inicio.x == fim.x && inicio.y == fim.y) {
        return 0;
    }

    Posicao fila[N * N];
    int frente = 0, tras = 0;

    int visitado[N][N] = { 0 };
    visitado[inicio.x][inicio.y] = 1;

    fila[tras++] = inicio;

    int distancia = 0;
    while (frente < tras) {
        int n = tras - frente;
        distancia++;
        while (n--) {
            Posicao atual = fila[frente++];
            for (int i = 0; i < 8; i++) {
                int nx = atual.x + movimentos[i][0];
                int ny = atual.y + movimentos[i][1];
                if (eh_valida(nx, ny) && !visitado[nx][ny]) {
                    if (nx == fim.x && ny == fim.y) {
                        return distancia;
                    }
                    visitado[nx][ny] = 1;
                    Posicao proximo = { nx, ny };
                    fila[tras++] = proximo;
                }
            }
        }
    }
    return -1;
}

int main() {
    char inicio_str[3], fim_str[3];
    while (scanf("%s %s", inicio_str, fim_str) != EOF) {
        Posicao inicio = pos_para_coord(inicio_str);
        Posicao fim = pos_para_coord(fim_str);
        int moves = movimentos_cavalo(inicio, fim);
        printf("To get from %s to %s takes %d knight moves.\n", inicio_str, fim_str, moves);
    }
    return 0;
}
