#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    
    int pendentes = 0;  

    for (int i = 0; s[i] != '\0'; i++) { 
        if (s[i] == '(') {
            pendentes++;  
        } else if (s[i] == ')') {
            if (pendentes > 0) {
                pendentes--;  
            }
        }
    }

    if (pendentes > 0) {
        printf("Ainda temos %d assunto(s) pendente(s)!\n", pendentes);
    } else {
        printf("Partiu RU!\n");
    }

    return 0;
}
