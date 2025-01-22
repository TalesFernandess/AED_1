#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente {
    int id;
    int itens;
    struct Cliente* seg;
} Cliente;

typedef struct {
    int id;
    int tempo_livre;
} Funcionario;


void enfileirar(Cliente **es, Cliente **et, int id, int itens) {
    Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
    novo->id = id;
    novo->itens = itens;
    novo->seg = NULL;

    if (*et == NULL) {
        *et = *es = novo;
    }
    else {
        (*et)->seg = novo;
        *et = novo;
    }
}

void desenfileirar(Cliente **es, Cliente **et) {
    Cliente *p;
    p = *es;
    *es = p->seg;
    free(p);
    if (*es == NULL) {
        *et = NULL;
    }
}

void inicializar_e_ler_funcionarios(Funcionario* funcionarios, int* tempos_funcionarios, int N) {
    for (int i = 0; i < N; i++) {
        scanf("%d", &tempos_funcionarios[i]);
        if (tempos_funcionarios[i] < 1 || tempos_funcionarios[i] > 100) {
            printf("Tempo de processamento inválido para o funcionário %d.\n", i + 1);
            exit(1);
        }
        funcionarios[i].id = i + 1;
        funcionarios[i].tempo_livre = 0;
    }
}

int processar_fila (Cliente** es, Cliente** et, Funcionario* funcionarios, int* tempos_funcionarios, int N) {
    int tempo_total = 0;
    while (*es != NULL) {
        Cliente* cliente = *es;
        int cliente_itens = cliente->itens;
        desenfileirar(es, et);
        int min_id = 0;
        for (int i = 1; i < N; i++) {
            if (funcionarios[i].tempo_livre < funcionarios[min_id].tempo_livre) {
                min_id = i;
            }
        }
        if (funcionarios[min_id].tempo_livre + cliente_itens * tempos_funcionarios[min_id] > tempo_total) {
            tempo_total = funcionarios[min_id].tempo_livre + cliente_itens * tempos_funcionarios[min_id];
        }
        funcionarios[min_id].tempo_livre += cliente_itens * tempos_funcionarios[min_id];
    }

    return tempo_total;
}

int main () {
    int N, M;
    Cliente *s, *t;
    s = NULL; 
    t = NULL;
        scanf("%d %d", &N, &M);
    
    if (N < 1 || N > 10000 || M < N || M > 10000) {
        return 1;
    }
    int* tempos_funcionarios = (int*)malloc(N * sizeof(int));
    Funcionario* funcionarios = (Funcionario*)malloc(N * sizeof(Funcionario));
    inicializar_e_ler_funcionarios(funcionarios, tempos_funcionarios, N);
    for (int i = 0; i < M; i++) {
        int itens;
        scanf("%d", &itens);
        if (itens < 1 || itens > 100) {
            printf("Número de itens inválido para o cliente %d.\n", i + 1);
            return 1;
        }
        enfileirar(&s, &t, i + 1, itens);
    }
    int tempo_total = processar_fila(&s, &t, funcionarios, tempos_funcionarios, N);
    printf("%d\n", tempo_total);
    free(tempos_funcionarios);
    free(funcionarios);
    return 0;
}
