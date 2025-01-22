#include <stdio.h>

int main() {
    int h1, m1, h2, m2;
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    int inicio = h1 * 60 + m1;
    int fim = h2 * 60 + m2;
    int duracao = fim - inicio;
    if (duracao < 0) {
        duracao += 24 * 60;
    }
    int horas = duracao / 60;
    int minutos = duracao % 60;

    if (horas == 0 && minutos == 0) {
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    } else {
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);
    }
}
