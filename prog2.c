#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fail() {
    printf("Memory  allocation failure\n");
    exit(EXIT_FAILURE);
}


int** allocMemory(int n, int m) {
    int** a = (int**)malloc(n * sizeof(int*)), i;
    if (!a) {
        fail();
    }
    for (i = 0; i < n; ++i) {
        a[i] = (int*)malloc(m * sizeof(int));
        if (!a[i]) {
            fail();
        }
    }
    return a;
}


void freeMemory(int n, int** a) {
    int i;
    for (i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);
}


void fill(int n, int m, int** matr) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            matr[i][j] = rand() % 101 - 50;
        }
    }
}


void print(int n, int m, int** matr) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            printf("%d\t", matr[i][j]);
        }
        printf("\n");
    }
}


void swapRows(int a, int b, int** matr) {
    int* sw = matr[a];
    matr[a] = matr[b];
    matr[b] = sw;
}


void sortByFirstColumn(int n, int m, int** matr) {
    int i, j;
    for (i = 0; i + 1 < n; ++i) {
        for (j = 0; j + 1 + i < n; ++j) {
            if (matr[j][0] < matr[j + 1][0]) {
                swapRows(j, j + 1, matr);
            }
        }
    }
}


int main() {
    srand(time(0));

    int rows, columns;
    printf("Enter rows -> ");
    scanf("%d", &rows);
    printf("Enter columns -> ");
    scanf("%d", &columns);

    int** matr = allocMemory(rows, columns);

    fill(rows, columns, matr);
    printf("\nMatrix\n");
    print(rows, columns, matr);
    printf("\n");

    sortByFirstColumn(rows, columns, matr);

    printf("\nMatrix\n");
    print(rows, columns, matr);
    printf("\n");

    freeMemory(rows, matr);

    return 0;
}
