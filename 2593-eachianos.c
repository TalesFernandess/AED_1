#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comparacao(char palavra[50], char texto[10000]){
    char *comparacao;
    int i=0, posicoes[50], cont = 0, j;
    
    comparacao = strtok(texto, " ");
    posicoes[0] = -1;

    while(comparacao != NULL){
        if(strcmp(palavra, comparacao)==0){
          posicoes[cont] = i;
          cont++;
        }
        i += strlen(comparacao) + 1;
        comparacao = strtok(NULL, " ");
    }

    if(posicoes[0] == -1){
      printf("%d", posicoes[0]);
      return;
}

    for(j = 0; j < cont; j++){
      printf("%d", posicoes[j]);
      if(j < cont - 1){
        printf(" ");
      }
    }
    printf("\n");
}

int main(){
    char texto[10000], *copiatexto, palavra[50];
    int n, i, j = 0, tamanho, y = 0;

    fgets(texto, sizeof(texto), stdin);
    tamanho = strlen(texto);
    if(tamanho<50){
        return 0;
    }

    scanf("%d", &n);
    
    if(n > 128 || n < 1){
      return 0;
    }

    for(i=0; i<n; i++){
      copiatexto = strdup(texto);
      scanf("%s", palavra);  
      comparacao(palavra, copiatexto);
      free(copiatexto);
    }

    return 0;
}
