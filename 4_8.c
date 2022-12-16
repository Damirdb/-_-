#include <stdio.h>
#include <math.h>

double f(int n) {
    double h, x, intgr = 0;
    double a = 0;
    double b = 1.6;
    h = (b-a)/n;
    for (int y = 0; y < n; y ++) {
        double fun;
        if (x <= 0.6)
            fun = 1/(1 + (25*(x*x)));
        else 
            fun = (x + (2*(pow(x, 4)))) * (sin(x * x));
        intgr += fun;
    }
    intgr *= h;
    return intgr;
}

int main() {
    double e;
    printf("Введите точность > ");
    scanf("%lf", &e);
    int n = 1;
    double intgr1 = 0;
    double intgr2 = 1;
    while ((fabs(intgr2 - intgr1) / 3) >= e) {
            n *= 2;
            intgr1 = intgr2;
            intgr2 = f(n * 2);
    }
    printf("%lf\n", intgr2);
    return 0;
}
