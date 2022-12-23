#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int *a, int n)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
        a[i] = rand () % 101 - 50;
}

void GetArray(int *a, int n)
{
    int i;
    printf("Массив: ");
    for (i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
}

void smm(int *x, int n)
{
    int min1 = 0;
    int min2 = 1;
    if(x[min1] > x[min2])
        min2 = 0;
        min1 = 1;
    for (int i = 0; i < n; i++)
        if (x[min1] > x[i])
        {
            min2 = min1;
            min1 = i;
        }
        else
            if(x[min2] > x[i])
                min2 = i;
    int m, sum;
    m = -120;
    int k;
    for (k = 0; k < n; k++)
    {
        sum = x[k] + x[k + 1];
        if (sum > m)
            m = sum;
    }
    printf("Сумма %d", m);
    x[min1] = x[min1] + m;
    x[min2] = x[min2] + m;
}

int main()
{
    int N = 100;
    int x[N], n;
    printf("Введи кол-во элементов в массиве -> ");
    scanf("%d", &n);
    fill(x, n);
    printf("\nИсходный массив:\n");
    GetArray(x, n);
    smm(x, n);
    printf("\nПреобразованный массив:\n");
    GetArray(x, n);
}
