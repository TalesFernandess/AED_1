#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char pais[20];
    char palavra[50]; 
    struct celula *prox;
} celula;

void insere(char pais[20], char traducao[50], celula **lista) {
    celula *nova = malloc(sizeof(celula));
    if (!nova) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(1);
    }
    strncpy(nova->pais, pais, sizeof(nova->pais) - 1);
    nova->pais[sizeof(nova->pais) - 1] = '\0';
    strncpy(nova->palavra, traducao, sizeof(nova->palavra) - 1);
    nova->palavra[sizeof(nova->palavra) - 1] = '\0';
    nova->prox = *lista;
    *lista = nova;
}

void busca(char nome[20], celula *lista) {
    celula *p = lista;
    while (p != NULL && strcmp(nome, p->pais) != 0) {
        p = p->prox;
    }
    if (p != NULL) {
        printf("%s\n", p->palavra);
    } else {
        printf("--- NOT FOUND ---\n");
    }
}

int main() {
    char nome[20];
    celula *lista = NULL;

    insere("alemanha", "Frohliche Weihnachten!", &lista);
    insere("antardida", "Merry Christmas!", &lista);
    insere("argentina", "Feliz Navidad!", &lista);
    insere("australia", "Merry Christmas!", &lista);
    insere("austria", "Frohe Weihnacht!", &lista);
    insere("belgica", "Zalig Kerstfeest!", &lista);
    insere("brasil", "Feliz Natal!", &lista);
    insere("canada", "Merry Christmas!", &lista);
    insere("chile", "Feliz Navidad!", &lista);
    insere("coreia", "Chuk Sung Tan!", &lista);
    insere("espanha", "Feliz Navidad!", &lista);
    insere("estados-unidos", "Merry Christmas!", &lista);
    insere("grecia", "Kala Christougena!", &lista);
    insere("inglaterra", "Merry Christmas!", &lista);
    insere("irlanda", "Nollaig Shona Dhuit!", &lista);
    insere("italia", "Buon Natale!", &lista);
    insere("japao", "Merii Kurisumasu!", &lista);
    insere("libia", "Buon Natale!", &lista);
    insere("marrocos", "Milad Mubarak!", &lista);
    insere("mexico", "Feliz Navidad!", &lista);
    insere("portugal", "Feliz Natal!", &lista);
    insere("siria", "Milad Mubarak!", &lista);
    insere("suecia", "God Jul!", &lista);
    insere("turquia", "Mutlu Noeller", &lista);

    while (scanf("%19s", nome) != EOF) {
        busca(nome, lista);
    }

    celula *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    return 0;
}
