#include <stdio.h>

int main(){
   int p1, p2, n, j, k;

    while(1){
        p1 = 0;
        p2 = 0;

        scanf("%d",&n);
        if(n == 0)break;
    
        for(int i =0; i < n; i++){
            scanf("%d %d", &j, &k);

            if(j > k){
            p1++;
        }
        else if(j < k){
            p2++;
        }
    }
        printf("%d %d\n", p1, p2);
    }
    return 0;
}
