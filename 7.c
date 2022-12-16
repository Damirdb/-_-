#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int rows, columns;

void fill(int n, int m, int matr[][columns]) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            matr[i][j] = rand() % 101 - 50;
        }
    }
}

void print(int n, int m, int matr[][columns]) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            printf("%d\t", matr[i][j]);
        }
        printf("\n");
    }
}

void swapRows(int a, int b, int m, int matr[][columns]) {
    int i, sw;
    for (i = 0; i < m; ++i) {
        sw = matr[a][i];
        matr[a][i] = matr[b][i];
        matr[b][i] = sw;
    }
}

void sortByFirstColumn(int n, int m, int matr[][columns]) {
    int i, j;
    for (i = 0; i + 1 < n; ++i) {
        for (j = 0; j + 1 + i < n; ++j) {
            if (matr[j][0] < matr[j + 1][0]) {
                swapRows(j, j + 1, m, matr);
            }
        }
    }
}


int main() {
    srand(time(0));

    printf("Enter rows -> ");
    scanf("%d", &rows);
    printf("Enter columns -> ");
    scanf("%d", &columns);

    int matr[rows][columns];

    fill(rows, columns, matr);
    printf("\nMatrix\n");
    print(rows, columns, matr);
    printf("\n");

    sortByFirstColumn(rows, columns, matr);

    printf("\nMatrix\n");
    print(rows, columns, matr);
    printf("\n");


    return 0;
}
