#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand () % 101 - 50;
}

int maximum(int n, int A[])
{
    int m, sum;
    m = -120;
    int k;
    for (k = 0; k < n-1; k++)
    {
        sum = A[k] + A[k + 1];
        if (sum > m)
            m = sum;
    }
    return m;
}

void GetArray(int n, int A[])
{
    int i;
    printf("Массив: ");
    for (i = 0; i < n; i++)
        printf("%4d", A[i]);
    printf("\n");
}

int sort(int n, int A[])
{
    int i, j, min1, min2, result;
    for(i = 0 ; i < n - 1; i++)
    {
        for(j = 0 ; j < n - i - 1 ; j++)
        {
            if (A[j] > A[j+1])
            {
                int tmp = A[j];
                A[j] = A[j+1] ;
                A[j+1] = tmp;
            }
        }
    }
    GetArray(n, A);
    min1 = A[0]; min2 = A[1];
    result = min1 + min2;
    return result;
}

int main()
{
    srand(time(NULL));
    int n, max, otvet, k;
    printf("Введи кол-во элементов в массиве -> ");
    scanf("%d", &n);
    int A[n];
    fill(n, A);
    GetArray(n, A);
    max = maximum(n, A);
    k = sort(n, A);
    otvet = max + k;
    printf("Ответ: %d\n", otvet);
}
