#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int arr[MAX_SIZE];
    int topo;
} Pilha;

void empilhar(Pilha* p, int x) {
    p->arr[++(p->topo)] = x;
}

int desempilhar(Pilha* p) {
    return p->arr[(p->topo)--];
}

bool pilha_vazia(Pilha* p) {
    return p->topo == -1;
}

typedef struct {
    int arr[MAX_SIZE];
    int frente, traseira;
} Fila;

void enfileirar(Fila* f, int x) {
    f->arr[f->traseira++] = x;
}

int desenfileirar(Fila* f) {
    return f->arr[f->frente++];
}

bool fila_vazia(Fila* f) {
    return f->frente == f->traseira;
}

typedef struct {
    int arr[MAX_SIZE];
    int tamanho;
} FilaPrioridade;

void empilhar_fila_prioridade(FilaPrioridade* fp, int x) {
    fp->arr[fp->tamanho++] = x;
    int i = fp->tamanho - 1;
    while (i > 0 && fp->arr[i] > fp->arr[(i - 1) / 2]) {
        int temp = fp->arr[i];
        fp->arr[i] = fp->arr[(i - 1) / 2];
        fp->arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int retirar_fila_prioridade(FilaPrioridade* fp) {
    int raiz = fp->arr[0];
    fp->arr[0] = fp->arr[--(fp->tamanho)];
    int i = 0, filho;
    while ((filho = 2 * i + 1) < fp->tamanho) {
        if (filho + 1 < fp->tamanho && fp->arr[filho + 1] > fp->arr[filho]) {
            filho++;
        }
        if (fp->arr[i] >= fp->arr[filho]) {
            break;
        }
        int temp = fp->arr[i];
        fp->arr[i] = fp->arr[filho];
        fp->arr[filho] = temp;
        i = filho;
    }
    return raiz;
}

bool fila_prioridade_vazia(FilaPrioridade* fp) {
    return fp->tamanho == 0;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Pilha pilha = {.topo = -1};
        Fila fila = {.frente = 0, .traseira = 0};
        FilaPrioridade fila_prioridade = {.tamanho = 0};
        bool eh_pilha = true, eh_fila = true, eh_fila_prioridade = true;
        for (int i = 0; i < n; ++i) {
            int op;
            scanf("%d", &op);
            if (op == 1) {
                int x;
                scanf("%d", &x);
                if (eh_pilha) empilhar(&pilha, x);
                if (eh_fila) enfileirar(&fila, x);
                if (eh_fila_prioridade) empilhar_fila_prioridade(&fila_prioridade, x);
            } else if (op == 2) {
                int x;
                scanf("%d", &x);
                bool valid_pilha = !pilha_vazia(&pilha) && desempilhar(&pilha) == x;
                bool valid_fila = !fila_vazia(&fila) && desenfileirar(&fila) == x;
                bool valid_fila_prioridade = !fila_prioridade_vazia(&fila_prioridade) && retirar_fila_prioridade(&fila_prioridade) == x;

                if (!valid_pilha) eh_pilha = false;
                if (!valid_fila) eh_fila = false;
                if (!valid_fila_prioridade) eh_fila_prioridade = false;
            }
        }
        if (eh_pilha && !eh_fila && !eh_fila_prioridade) {
            printf("stack\n");
        } else if (!eh_pilha && eh_fila && !eh_fila_prioridade) {
            printf("queue\n");
        } else if (!eh_pilha && !eh_fila && eh_fila_prioridade) {
            printf("priority queue\n");
        } else if (!eh_pilha && !eh_fila && !eh_fila_prioridade) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }
}
