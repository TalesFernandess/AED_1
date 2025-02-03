#include <stdio.h>
#include <string.h>

int distancia_circular(char a, char b) {
    int dist = (b - a + 26) % 26;
    return dist;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char A[10001], B[10001];
        scanf("%s %s", A, B);

        if (strlen(A) != strlen(B)) {
            printf("As strings devem ter o mesmo comprimento.\n");
            continue; 
        }

        int comprimento = strlen(A);
        int total_op = 0;

        for (int i = 0; i < comprimento; i++) {
            total_op += distancia_circular(A[i], B[i]);
        }
        printf("%d\n", total_op);
    }
    return 0;
}
