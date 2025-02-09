#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int tempo;
    int incorretas;
} Problema;

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        Problema problemas[26] = {0};
        for (int i = 0; i < N; ++i) {
            char id;
            int tempo;
            char julgamento[10];
            scanf(" %c %d %s", &id, &tempo, julgamento);
            int index = id - 'A';
            if (strcmp(julgamento, "correct") == 0) {
                if (problemas[index].tempo == 0) {
                    problemas[index].tempo = tempo;
                }
            } else {
                if (problemas[index].tempo == 0) {
                    problemas[index].incorretas++;
                }
            }
        }
        int num_problemas_corretos = 0;
        int tempo_total = 0;
        for (int i = 0; i < 26; ++i) {
            if (problemas[i].tempo > 0) {
                num_problemas_corretos++;
                tempo_total += problemas[i].tempo + problemas[i].incorretas * 20;
            }
        }
        printf("%d %d\n", num_problemas_corretos, tempo_total);
    }
}
