#include <stdio.h>

void binario(int num){
  int cont = 0, i, quociente, resto[50];

  if(num == 0){
    printf("0\n");
    return;
  }

  quociente = num;

  while(quociente != 0){;
    resto[cont] = quociente%2;
    cont++;
    quociente = quociente/2;
  }
  for(i = cont-1; i >= 0; i--){
    printf("%d", resto[i]);
  }
  printf("\n");
}

int main(){
  int mais_acessos = -1, num, soma_semanal, i, j;

  for(i = 0; i < 4; i++){
    soma_semanal = 0;
    for(j = 0; j < 7; j++){
      scanf("%d", &num);
      soma_semanal += num;
    }
    if(soma_semanal > mais_acessos)mais_acessos = soma_semanal;
  }

  printf("%d = ", mais_acessos);

  binario(mais_acessos);

  return 0;
}
