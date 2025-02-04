#include <stdio.h>
#include <string.h>
#include <ctype.h>

void transformar_sentenca(char* str) {
    int alterar = 1; 

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = alterar ? toupper(str[i]) : tolower(str[i]);
            alterar = !alterar;
        }
    }
}

int main() {
    char linha[51]; 

    while (fgets(linha, sizeof(linha), stdin)) {
        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0';
        }

        transformar_sentenca(linha);
        printf("%s\n", linha);
    }

    return 0;
}
