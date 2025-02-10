#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct informacoes{
  int horario_minutos;
  char nome[101];
}info;

typedef struct cel{
  info pessoa;
  struct cel *seg;
}celula;

void insere(int h, char n[101], celula **lista){
  celula *nova = malloc(sizeof(celula));
  
  nova->pessoa.horario_minutos = h;
  
  strncpy(nova->pessoa.nome, n, sizeof(nova->pessoa.nome)-1);
  nova->pessoa.nome[sizeof(nova->pessoa.nome)-1] = '\0';

  nova->seg = NULL;

  if(*lista == NULL || (*lista)->pessoa.horario_minutos > h){
    
    nova->seg = *lista;
    *lista = nova;

  }else{
    celula *p = *lista;

    while(p->seg != NULL && p->seg->pessoa.horario_minutos <= h){
      p = p->seg;
    }
    nova->seg = p->seg;
    p->seg = nova;
  }
}

int main(){
  int p, i, q, hora, min, conv_min, i_intervalo, f_intervalo;
  char nome[101];
  celula *lista = NULL;

  scanf("%d %d", &p, &q);

  for(i = 0; i < q; i++){

    scanf("%d:%d", &hora, &min);
    if(min > 59)return 0;
    scanf("%s", nome);

    conv_min = (hora%24)*60 + min;
    i_intervalo = 1440 - p;
    f_intervalo = 1440 + p;

    if(hora == 0){
      conv_min += 24*60;
    }

    if(conv_min >= i_intervalo && conv_min <= f_intervalo){
      insere(conv_min, nome, &lista);
    }
  }

  celula *aux;
  while(lista!=NULL){
    printf("%s\n", lista->pessoa.nome);
    aux = lista;
    lista = lista->seg;
    free(aux);
  }

  return 0;
}
