#include <stdio.h>

int prov(int a, int b)
{
    if (a>b) return a;
    else return b;

}
int main()
{
int k, c1, c2, c3;
scanf("%d", &c1);
scanf("%d", &c2);
scanf("%d", &c3);
k=prov(c1, prov(c2, c3));

if (k == c1 && c1%3==0) printf("%d", c1-(2+3));

else if (k == c2 && c2%3==0) printf("%d", c2-(1+3));

else if (k == c3 && c3%3==0) printf("%d", c3-(1+2));

else
    {
        if (k==c1) printf("%f", (float) (2+3)/c1);

        else if (k==c2) printf("%f", (float) (3+1)/c2);

        else if (k==c3) printf("%f", (float) (1+2)/c3);

        }

    return 0;
}
