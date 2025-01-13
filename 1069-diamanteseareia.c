#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char c;
    struct celula* prox;
} celula;

void insere(char c, celula* p) {
    celula* nova = (celula*)malloc(sizeof(celula));
    nova->c = c;
    nova->prox = p->prox;
    p->prox = nova;
}

char remover(celula* p) {
    if (p->prox == NULL) {
        return '\0';  
    }
    char x;
    celula* lixo = p->prox;
    x = lixo->c;
    p->prox = lixo->prox;
    free(lixo);
    return x;
}

void limpa_lista(celula* p) {
    while (p->prox != NULL) {
        remover(p);
    }
}

int main() {
    int n, i, j;
    scanf("%d", &n);
    getchar(); 

    for (i = 0; i < n; i++) {
        char entrada[1001];
        fgets(entrada, 1001, stdin);
        entrada[strcspn(entrada, "\n")] = '\0'; 

        celula* p = (celula*)malloc(sizeof(celula));
        p->prox = NULL;

        int contador = 0;
        for (j = 0; entrada[j] != '\0'; j++) {
            if (entrada[j] == '<') {
                insere(entrada[j], p);
            } else if (entrada[j] == '>') {
                if (p->prox != NULL) {
                    remover(p);
                    contador++;
                }
            }
        }

        limpa_lista(p); 
        free(p);        
        printf("%d\n", contador);
    }
    return 0;
}
