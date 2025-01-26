#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 101

typedef struct {
    char nome[MAX_NOME];
    char regiao;
    int custo;
} Aluno;

int comparar(const void* a, const void* b) {
    Aluno* alunoA = (Aluno*)a;
    Aluno* alunoB = (Aluno*)b;
    if (alunoA->custo != alunoB->custo) {
        return alunoA->custo - alunoB->custo;
    }
    if (alunoA->regiao != alunoB->regiao) {
        return alunoA->regiao - alunoB->regiao;
    }
    return strcmp(alunoA->nome, alunoB->nome);
}

int main() {
    int Q;
    while (scanf("%d", &Q) != EOF) {
        Aluno alunos[Q];
        for (int i = 0; i < Q; ++i) {
            scanf("%s %c %d", alunos[i].nome, &alunos[i].regiao, &alunos[i].custo);
        }
        qsort(alunos, Q, sizeof(Aluno), comparar);
        for (int i = 0; i < Q; ++i) {
            printf("%s\n", alunos[i].nome);
        }
    }
}
