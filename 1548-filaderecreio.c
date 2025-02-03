#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 1000

int comparador(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N; 
    scanf("%d", &N);
    while (N--) {
        int M;
        scanf("%d", &M);
        int notas[MAX_ALUNOS];
        int notas_ordenadas[MAX_ALUNOS];
        
        for (int i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
            notas_ordenadas[i] = notas[i];
        }
        
        qsort(notas_ordenadas, M, sizeof(int), comparador);
        
        int contagem = 0;
        for (int i = 0; i < M; i++) {
            if (notas[i] == notas_ordenadas[i]) {
                contagem++;
            }
        }
        
        printf("%d\n", contagem);
    }
    
    return 0;
}
