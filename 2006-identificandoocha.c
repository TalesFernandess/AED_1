#include <stdio.h>

int main(){
    int T, A, B, C, D, E, contador = 0;

    scanf("%d\n %d %d %d %d %d",&T, &A, &B, &C, &D, &E);

    if (A == T) contador++;
    if (B == T) contador++;
    if (C == T) contador++;
    if (D == T) contador++;
    if (E == T) contador++;

    printf("%d\n", contador);

    return 0;
}
