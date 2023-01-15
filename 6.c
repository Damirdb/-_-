#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandom(int* array, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        array[i] = rand () % 101 - 50;
    }
}

void printArray(int* array, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int getMaxSumTwoNeibours(int* array, int size) {
    int i, max_sum, cur_sum;
    if (size < 2) {
        return 0;
    }
    max_sum = array[0] + array[1];
    for (i = 2; i < size; ++i) {
        cur_sum = array[i] + array[i - 1];
        max_sum = cur_sum <= max_sum ? max_sum : cur_sum;
    }
    return max_sum;
}

void addToTwoMin(int* array, int size, int value) {
    int i, first_min, second_min;
    first_min = 1000000000, second_min = 1000000000;
    for (i = 0; i < size; ++i) {
        if (array[i] < first_min) {
            second_min = first_min;
            first_min = array[i];
        } else if (first_min < array[i] && array[i] < second_min) {
            second_min = array[i];
        }
    }
    for (i = 0; i < size; ++i) {
        if (array[i] == first_min || array[i] == second_min) {
            array[i] += value;
        }
    }
}

int main() {
    srand(time(NULL));

    int size, max_sum;
    printf("Размер массива  -> ");
    scanf("%d", &size);

    int array[size];
    fillRandom(array, size);

    printf("\nисходный массив: ");
    printArray(array, size);

    max_sum = getMaxSumTwoNeibours(array, size);
    printf("максимальная сумма двух соседей: %d\n", max_sum);
    addToTwoMin(array, size, max_sum);

    printf("результат массива: ");
    printArray(array, size);

    return 0;
}
