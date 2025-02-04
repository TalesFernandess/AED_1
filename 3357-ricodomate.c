#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[13];
    struct No* proximo;
} No;

No* criar_no(char* nome) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (!novo_no) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(novo_no->nome, nome);
    novo_no->proximo = NULL;
    return novo_no;
}

void inserir_no(No** cabeca, char* nome) {
    No* novo_no = criar_no(nome);
    if (*cabeca == NULL) {
        *cabeca = novo_no;
        novo_no->proximo = novo_no; 
    } else {
        No* temp = *cabeca;
        while (temp->proximo != *cabeca) {
            temp = temp->proximo;
        }
        temp->proximo = novo_no;
        novo_no->proximo = *cabeca;
    }
}

void liberar_lista(No* cabeca) {
    if (cabeca == NULL) return;
    
    No* temp = cabeca->proximo;
    while (temp != cabeca) {
        No* proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }
    free(cabeca);
}

int main() {
    int num_participantes;
    float valor_limite, valor_reducao; 
    No* cabeca = NULL;

    scanf("%d", &num_participantes);
    scanf("%f %f", &valor_limite, &valor_reducao);
    
    for (int i = 0; i < num_participantes; i++) {
        char nome[13];
        scanf("%s", nome);
        inserir_no(&cabeca, nome);
    }

    No* atual = cabeca;
    while (valor_limite > valor_reducao) {
        valor_limite -= valor_reducao;
        atual = atual->proximo;
    }

    printf("%s %.1f\n", atual->nome, valor_limite);
    
    liberar_lista(cabeca);

    return 0;
}
