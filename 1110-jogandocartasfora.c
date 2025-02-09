#include <stdlib.h>
#include <stdio.h>

typedef struct noDeque {
    int valor;
    struct noDeque *anterior, *proximo;
} NoDeque;

typedef struct deque {
    int tamanho;
    NoDeque *frente, *tras;
} Deque;

void inicializarDeque(Deque* d) {
    d->tamanho = 0;
    d->frente = NULL;
    d->tras = NULL;
}

void empurrarFrente(Deque* d, int valor) {
    NoDeque* novo = (NoDeque*) malloc(sizeof(NoDeque));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = d->frente;
    if (d->frente != NULL) {
        d->frente->anterior = novo;
    }
    d->frente = novo;
    if (d->tras == NULL) {
        d->tras = novo;
    }
    d->tamanho++;
}

void empurrarTras(Deque* d, int valor) {
    NoDeque* novo = (NoDeque*) malloc(sizeof(NoDeque));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = d->tras;
    if (d->tras != NULL) {
        d->tras->proximo = novo;
    }
    d->tras = novo;
    if (d->frente == NULL) {
        d->frente = novo;
    }
    d->tamanho++;
}

void removerFrente(Deque* d) {
    if (d->frente != NULL) {
        NoDeque* antigoFront = d->frente;
        d->frente = antigoFront->proximo;
        if (d->frente != NULL) {
            d->frente->anterior = NULL;
        } else {
            d->tras = NULL;
        }
        free(antigoFront);
        d->tamanho--;
    }
}

void removerTras(Deque* d) {
    if (d->tras != NULL) {
        NoDeque* antigoBack = d->tras;
        d->tras = antigoBack->anterior;
        if (d->tras != NULL) {
            d->tras->proximo = NULL;
        } else {
            d->frente = NULL;
        }
        free(antigoBack);
        d->tamanho--;
    }
}

int main() {
    int n;
    Deque cartas;
    while (scanf("%d", &n) == 1) {
        if (n == 0)
            break;
        inicializarDeque(&cartas);
        for (int i = 1; i <= n; ++i) {
            empurrarTras(&cartas, i);
        }
        printf("Discarded cards: ");
        int first = 1;
        while (cartas.tamanho > 1) {
            if (!first) {
                printf(", ");
            } else {
                first = 0;
            }
            printf("%d", cartas.frente->valor);
            removerFrente(&cartas);
            empurrarTras(&cartas, cartas.frente->valor);
            removerFrente(&cartas);
        }
        if (cartas.tamanho == 0) {
            printf("\nRemaining card: None\n");
        } else {
            printf("\nRemaining card: %d\n", cartas.frente->valor);
        }
        while (cartas.tamanho > 0) {
            removerFrente(&cartas);
        }
    }
}
