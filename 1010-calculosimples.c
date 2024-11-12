#include <stdio.h>

int main(){
    int p1, q1, p2, q2;
    double v1, v2, total;

    scanf("%d %d %lf", &p1, &q1, &v1);
    scanf("%d %d %lf", &p2, &q2, &v2);

    total = (v1 * q1) + (v2 * q2);
    printf("VALOR A PAGAR: R$ %.2lf\n", total);
    return 0;
}
