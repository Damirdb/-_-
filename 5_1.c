
#include <stdio.h>

void Perevod(int x)
{
    printf("%d", x%10);
    if (x > 9)
        Perevod(x / 10);
}

unsigned int perev1(unsigned int n)
{
    int m;
    m = 0;
    while (n > 0)
    {
        if (n % 10 == 0)
        {
            printf("0");
            n = n / 10;
        }
        else
        {
            m=n % 10;
            printf("%d" ,m);
            n = n / 10;
        }
        m = m * 10 + n % 10;

    }
    return m;
}

int main ()
{
    unsigned int n;
    printf("Введи неотрицательное целое число\nn -> ");
    scanf("%u", &n);
    printf("С помощью цикла =\n");
    perev1(n);
    printf("\n");
    printf("С помощью рекурсии = ");
    printf("\n");
    Perevod(n);
    printf("\n");
    return 0;
}