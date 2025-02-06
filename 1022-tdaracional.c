#include <stdio.h>

typedef struct Fracao {
    int num, den;
} Fracao;

Fracao operacao(Fracao f1, Fracao f2, char operador) {
    Fracao resultado;
    switch (operador) {
        case '+':
            resultado.num = f1.num * f2.den + f2.num * f1.den;
            resultado.den = f1.den * f2.den;
            break;
        case '-':
            resultado.num = f1.num * f2.den - f2.num * f1.den;
            resultado.den = f1.den * f2.den;
            break;
        case '*':
            resultado.num = f1.num * f2.num;
            resultado.den = f1.den * f2.den;
            break;
        case '/':
            resultado.num = f1.num * f2.den;
            resultado.den = f2.num * f1.den;
            break;
        default:
            resultado.num = 0;
            resultado.den = 1;
            break;
    }
    return resultado;
}

int mdc(int a, int b) {
    return (b == 0) ? a : mdc(b, a % b);
}

struct Fracao reduz(struct Fracao f) {
    int divisor_comum = mdc(abs(f.num), abs(f.den));
    f.num /= divisor_comum;
    f.den /= divisor_comum;
    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
    return f;
}

int main() {
    int N;
    char operador;
    struct Fracao f1, f2, resultado;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d / %d %c %d / %d", &f1.num, &f1.den, &operador, &f2.num, &f2.den);
        resultado = operacao(f1, f2, operador);
        printf("%d/%d = ", resultado.num, resultado.den);
        resultado = reduz(resultado);
        printf("%d/%d\n", resultado.num, resultado.den);
    }

}
