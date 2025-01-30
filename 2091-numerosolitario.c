#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *seg; 
};
typedef struct cel celula;

void Imprima(celula *lst) {
    celula *p;
    for (p = lst->seg; p != NULL; p = p->seg)
        printf("%lld\n", p->conteudo);
}

celula *Busca(int x, celula *lst) {
    celula *p;
    p = lst->seg;
    while (p != NULL && p->conteudo != x)
        p = p->seg;
    return p;
}

void Remove(celula *p) {
    if (p->seg == NULL) exit(1);
    celula *lixo;
    lixo = p->seg;
    p->seg = lixo->seg;
    free(lixo);
}

void Insere(int y, celula *p) {
    celula *aux = p->seg;
    celula *ant = p;
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = y;
    nova->seg = NULL;

    while (aux != NULL && aux->conteudo != y) {
        ant = aux;
        aux = aux->seg;
    }

    if (aux != NULL) { 
        ant->seg = aux->seg;
        free(aux);
        free(nova);
    } else { 
        nova->seg = p->seg;
        p->seg = nova;
    }
}

int main() {
    int n;
    int x;
    celula *G = malloc(sizeof(celula));
    G->seg = NULL;

    do {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &x);
            Insere(x, G);
        }
        Imprima(G);
        G->seg = NULL; 
    } while (n != 0);

    free(G);
    return 0;
}
