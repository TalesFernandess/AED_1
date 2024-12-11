#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000000; 
    }
}

void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
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
    quickSort(array, 0, n - 1);
    clock_t end = clock();

    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo para QuickSort com %d elementos: %.6f segundos\n", n, elapsedTime);

    free(array);
    return 0;
}
