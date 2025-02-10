#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct al{
  char nome[21]; 
  char assinatura[21];
}aluno;

typedef struct cel{
  aluno x;
  struct cel *seg;
}celula;

/*A função insere o nome e a assinatura no final da lista*/
void insere(char aluno[21], char assinatura[21], celula **lista){
  celula *nova = malloc(sizeof(celula));
  strncpy(nova->x.nome, aluno, sizeof(nova->x.nome)-1);
  nova->x.nome[sizeof(nova->x.nome)-1] = '\0';
  strncpy(nova->x.assinatura, assinatura, sizeof(nova->x.assinatura)-1);
  nova->x.assinatura[sizeof(nova->x.assinatura)-1] = '\0';
  nova->seg = NULL;
  if(*lista == NULL){
    *lista = nova;
  }else{
    celula *p = *lista;
    while(p->seg!=NULL){
      p = p->seg;
    }
    p->seg = nova;
  }
}

int compara(char Aluno_presente[21], char fassinatura[21], celula *lista){
  celula *p = lista;
  int i, tam = strlen(Aluno_presente), difere = 0;
  while(p!=NULL && strcmp(Aluno_presente, p->x.nome)!=0){
    p = p->seg;
  }
  for(i=0; i<tam; i++){
    if(p->x.assinatura[i]!=fassinatura[i]){
      difere++;
    }
  }
  if(difere>1){
    return 1;
  }else{
    return 0;
  }
}

int main(){
  int i, n, m, falso;
  char aluno[21], assinatura[21], presente[21], asspresenca[21];
  celula *lista=NULL;

  scanf("%d", &n);
  while(n!=0){
    falso = 0;
      for(i=0; i<n; i++){
        scanf("%s", aluno);
        scanf("%s", assinatura);
        insere(aluno, assinatura, &lista);
      }
      scanf("%d", &m);
      for(i=0; i<m; i++){
        scanf("%s", presente);
        scanf("%s", asspresenca);
        falso +=compara(presente, asspresenca, lista);
      }
      printf("%d\n", falso);

      celula *aux;
      while(lista!=NULL){
        aux = lista;
        lista = lista->seg;
        free(aux);
      }
      scanf("%d", &n);
  }
  return 0;
}
