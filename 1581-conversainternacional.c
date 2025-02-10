#include <stdio.h>
#include <string.h>

int main(){
  int i, j, n, k, verifica;
  char string[50], anterior[50];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &k);
    verifica = 0;

    for(j = 0; j < k; j++){
      scanf("%s", string);
      if(j == 0){
        strcpy(anterior, string);
      }else{
        if(strcmp(anterior, string) != 0)verifica++;
      }
    }

    if(verifica > 0)printf("ingles\n");
    else printf("%s\n", string);
  }

  return 0;
}
