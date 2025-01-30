#include <stdio.h>
#include <string.h>

int podeOrdenarComUmaTroca(char *s, int n) {
    int pos1 = -1, pos2 = -1;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            if (pos1 == -1) {
                pos1 = i;
            } else {
                pos2 = i + 1;
                break;
            }
        }
    }

    if (pos1 == -1) {
        return 0;
    }

    if (pos2 == -1) {
        pos2 = pos1 + 1;
    }

    char temp = s[pos1];
    s[pos1] = s[pos2];
    s[pos2] = temp;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    int N, M;
    char s[27]; 

    scanf("%d", &N);
    while (N--) {
        scanf("%d", &M);
        scanf("%s", s);

        if (podeOrdenarComUmaTroca(s, M)) {
            printf("There aren't the chance.\n");
        } else {
            printf("There are the chance.\n");
        }
    }

    return 0;
}
