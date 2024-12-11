#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000000; 
    }
}

void merge(int *array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int j = 0; j < n2; j++) R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) array[k++] = L[i++];
        else array[k++] = R[j++];
    }

    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
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
    mergeSort(array, 0, n - 1);
    clock_t end = clock();

    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo para MergeSort com %d elementos: %.6f segundos\n", n, elapsedTime);

    free(array);
    return 0;
}
