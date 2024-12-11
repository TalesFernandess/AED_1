#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000000; 
    }
}

void insertionSort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    int n = 20000; // Alterar este valor para testar diferentes tamanhos
    int *array = malloc(n * sizeof(int));
    if (!array) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    srand(time(NULL));
    generateRandomArray(array, n);

    clock_t start = clock();
    insertionSort(array, n);
    clock_t end = clock();

    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo para InsertionSort com %d elementos: %.6f segundos\n", n, elapsedTime);

    free(array);
    return 0;
}
