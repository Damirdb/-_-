#include <stdio.h>
#include <math.h>
int main()
{
    double x,f,h,s;
    int i=0;
    x=0;
    printf("Введите шаг h (0<=h<=1.6) \n");
    scanf("%lf" ,&h);
    s=2.00/h;
    if (h >= 0 && h <= 1.6)
    {
        printf("\tx\tf(x)\n");
        printf("------------------\n");
        while (i<=s)
        {
            x=i*h;
            if(x>=0 && x<=0.6)
                f = 1/(1 + (25*(x*x)));
            else
                f = (x + (2*(pow(x, 4)))) * (sin(x * x));

            printf("%lf\t%lf\n", x ,f);
            i++;
        }
    }
    else
    {
        printf("incorect h");

    }
    return 0;
}