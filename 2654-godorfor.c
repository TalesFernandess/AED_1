#include <stdio.h>
#include <string.h>

typedef struct classificacao{
  char nome[1000];
  int poder;
  int m;
  int menos;
}candidato;

int main(){
  int testes, i;
  candidato entrada, maisforte;

  scanf("%d", &testes);

  for(i = 0; i < testes; i++){
    scanf("%s %d %d %d", entrada.nome, &entrada.poder, &entrada.m, &entrada.menos);
    if(i==0)maisforte = entrada;
    else{
      if(entrada.poder > maisforte.poder){
        maisforte = entrada;
      }else if(entrada.poder == maisforte.poder){
        if(entrada.m > maisforte.m){
          maisforte = entrada;
          }else if(entrada.m == maisforte.m){
          if(entrada.menos < maisforte.menos){
            maisforte = entrada;
            }else if(entrada.menos == maisforte.menos){
              if(strcmp(entrada.nome, maisforte.nome) < 0){
                maisforte = entrada;
              }
            }
          }
        }
    } 
  }

  printf("%s\n", maisforte.nome);

  return 0;
}
