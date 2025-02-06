#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
  int n, i, *kilos, cont;
  double v, soma = 0, total_kg = 0, pordia_kg, pordia_rs;
  char frutas[10000], *produto;

  scanf("%d", &n);
  kilos = malloc(n*sizeof(int));

  for(i = 0; i < n; i++){
    scanf("%lf", &v);
    getchar();
    soma += v;

    fgets(frutas, sizeof(frutas), stdin);
    
    produto = strtok(frutas, " \n");
    cont = 0;
    while(produto != NULL){
      cont++;
      produto = strtok(NULL, " \n");
    }

    total_kg += cont;
    kilos[i] = cont;
  }

  pordia_kg = total_kg/n;
  pordia_rs = soma/n;

  for(i = 0; i < n; i++){
    printf("day %d: %d kg\n", i+1, kilos[i]);
  }

  printf("%.2f kg by day\n", pordia_kg);
  printf("R$ %.2f by day\n", pordia_rs);

  free(kilos);
  return 0;
}
