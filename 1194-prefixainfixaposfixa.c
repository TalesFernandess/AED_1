#include <stdio.h>
#include <string.h>

void posfixa(char *prefixa, char *infixa, int n) {
    if (n <= 0) return;
    char raiz = prefixa[0];
    int raizIndice = strchr(infixa, raiz) - infixa;
    posfixa(prefixa + 1, infixa, raizIndice);
    posfixa(prefixa + 1 + raizIndice, infixa + raizIndice + 1, n - raizIndice - 1);
    printf("%c", raiz);
}

int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        int N;
        char prefixa[53], infixa[53];
        
        scanf("%d %s %s", &N, prefixa, infixa);
        
        posfixa(prefixa, infixa, N);
        printf("\n");
    }
    return 0;
}
