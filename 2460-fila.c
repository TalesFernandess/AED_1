#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int identificador;
    struct celula* seg;
} celula;

void enfileira (int y, celula **es, celula **et) {
    celula *nova = (celula*)malloc(sizeof(celula));
    nova->identificador = y;
    nova->seg = NULL;
    if (*et == NULL) {
        *es = *et = nova;
    } else {
        (*et)->seg = nova;
        *et = nova;
    }
}

void busca_remove (celula **es, celula **et, int x) {
    celula *lixo = *es;
    celula *anterior = NULL;
    while (lixo != NULL && lixo->identificador != x) {
        anterior = lixo;
        lixo = lixo->seg;
    }
    if (lixo == NULL) {
        return;
    }
    if (lixo == *es) {
        *es = lixo->seg;
    } else {
        anterior->seg = lixo->seg;
    }
    if (lixo == *et) {
        *et = anterior;
    }
    free(lixo);
}

void imprime (celula *s) {
    celula *aux = s;
    while (aux != NULL) {
        if (aux->seg != NULL) {
            printf("%d ", aux->identificador);
        } else {
            printf("%d\n", aux->identificador);
        }
        aux = aux->seg;
    }
}
void libera (celula *s) {
    celula *aux = s;
    while (aux != NULL) {
        celula *lixo = aux;
        aux = aux->seg;
        free(lixo);
    }
}

int main() {
    int N, M, i;
    int *vetorN, *vetorM;
    celula *s = NULL, *t = NULL;
    scanf("%d", &N);
    vetorN = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &vetorN[i]);
        enfileira(vetorN[i], &s, &t);
    }
    scanf("%d", &M);
    vetorM = (int*)malloc(M * sizeof(int));
    for (i = 0; i < M; i++) {
        scanf("%d", &vetorM[i]);
        busca_remove(&s, &t, vetorM[i]);
    }
    imprime(s);
    libera(s);
    free(vetorN);
    free(vetorM);
    return 0;
}
