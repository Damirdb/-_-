#include <stdio.h>
#include <math.h>


int main()

{
    float c1, c2, c3;
    printf(" c1 = ");
    scanf("%f", &c1);
    printf(" c2 = ");
    scanf("%f", &c2);
    printf("c3 = ");
    scanf("%f", &c3);
    if (c1 > (c2 + c3) && c1 != 0)
    {
        if (c1 % 3 == 0)
        {
            printf("%f",c1-(c2+c3));
            return 0;
        }
    } 
        else
    {
        printf("%f",c1/(c2+c3));
        return 0;
    
    }
    if (c2 > (c1 + c3) && c2 != 0)
    {
        if (c2 % 3 == 0)
        {
            printf("%f",c2-(c1+c3));
            return 0;
        }
    } 
        else
    {
        printf("%f",c2/(c1+c3));
        return 0;
    
    }
    if (c3 > (c2 + c1) && c3 != 0)
    {
        if (c3 % 3 == 0)
        {
            printf("%f",c3-(c2+c1));
            return 0;
        }
    } 
        else
    {
        printf("%f",c1/(c2+c1));
        return 0;
    
    }



}
