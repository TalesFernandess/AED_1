#include <stdio.h>

#define TAMANHO 9

void zeradigitos(int *dg)
{
    int i;
    for (i = 0; i < TAMANHO; i++)
        dg[i] = 0;
}

int valida(int v[TAMANHO][TAMANHO], int n, int *dg)
{
    int i, j;
    for (i = 0; i < TAMANHO; i++)
    {
        for (j = 0; j < TAMANHO; j++)
        {
            if (n)
            {
                dg[v[i][j]]++;
                if (dg[v[i][j]] > 1)
                    return 1;
            }
            else
            {
                dg[v[j][i]]++;
                if (dg[v[j][i]] > 1)
                    return 1;
            }
        }
        zeradigitos(dg);
    }
    return 0;
}

int validaMatriz(int v[TAMANHO][TAMANHO], int inicio, int fim, int cInicio, int cFim, int *dg)
{
    int i, j;
    for (i = inicio; i < fim; i++)
    {
        for (j = cInicio; j < cFim; j++)
        {
            dg[v[j][i]]++;
            if (dg[v[j][i]] > 1)
                return 1;
        }
    }
    zeradigitos(dg);
    return 0;
}

int main()
{

    int n, mat[TAMANHO][TAMANHO], invalido, digitos[TAMANHO], cases, i, j;
    scanf("%i", &n);

    for (cases = 1; cases <= n; cases++)
    {
        for (i = 0; i < TAMANHO; i++)
        {
            zeradigitos(digitos);
            for (j = 0; j < TAMANHO; j++)
            {
                scanf("%i", &mat[i][j]);
                mat[i][j]--;
            }
        }
        invalido = valida(mat, 1, digitos) + valida(mat, 0, digitos);

        for (i = 0; i < TAMANHO; i += 3)
            for (j = 0; j < TAMANHO; j += 3)
                invalido += validaMatriz(mat, i, i + 3, j, j + 3, digitos);

        printf("Instancia %i\n", cases);

        if (invalido)
            printf("NAO\n\n");
        else
            printf("SIM\n\n");
    }
    return 0;
}
