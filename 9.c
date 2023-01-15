#include <stdio.h>
#include <string.h>

int main() {
    char str[128] = { 0 }, * pword, delim[] = " ";
    char words[128][128] = { 0 };
    int nwords = 0, i, j, is_unique, nuniq = 0;

    printf("Вводная строка -> ");
    scanf("%1024[^\n]s", str);

    if ((pword = strtok(str, delim))) {
        strcpy(words[nwords++], pword);
    }
    while ((pword = strtok(NULL, delim))) {
        strcpy(words[nwords++], pword);
    }

    for (i = 0; i + 1 < nwords; ++i) {
        is_unique = 1;
        for (j = i + 1; j < nwords; ++j) {
            if (strcmp(words[i], words[j]) == 0) {
                is_unique = 0;
                words[j][0] = '\0';
            }
        }
        if (is_unique) {
            ++nuniq;
        } else {
            words[i][0] = '\0';
        }
    }

    if (nuniq != 0) {
        printf("\nуникальные слова: ");
        for (i = 0; i < nwords; ++i) {
            if (words[i][0] != '\0') {
                printf("%s ", words[i]);
            }
        }
        printf("\n");
    } else {
        printf("\nнет уникальных слов\n");
    }

    return 0;
}
