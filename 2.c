#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    printf("Введите x { x > 3.106804 } -> ");
    scanf("%lf", &x);
    if (x > 3.106804)
    {
        double y = -log(x + 2) - log(x - 2);
        double z = sqrt((3 * y) - pow(y, 3));
        printf("y(x) = %lf\nz(y) = %lf\n", y, z);
    }
    else
        printf("x value is incorrect!\n");
    return 0;
}