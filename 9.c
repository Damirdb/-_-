#include <stdio.h>
#include <string.h>

int countword(char *s, char *w)
{
    char t[50];
    int i, n = 0, k = 0;
    for (i = 0; i <= strlen(s); i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            t[n] = '\0';
            if (strcmp(t, w) == 0)
            {
                k++;
            }
            n = 0;
        }
        else
        {
            t[n] = s[i];
            n++;
        }
    }
    return k;
}

void uniqueword(char *s)
{
    char w[50];
    int i, n = 0;
    for (i = 0; i <= strlen(s); i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            if (n != 0)
            {
                w[n] = '\0';
                if (countword(s, w) == 1)
                {
                    printf("%s ", w);
                }
                n = 0;
            }
        }
        else
        {
            w[n] = s[i];
            n++;
        }
    }
}

int main()
{
    char s[100];
    printf("Введите строку:");
    if (scanf("%[^\n]%*c", s) != 0)
    {
        uniqueword(s);
        printf("\n");
    }
}
