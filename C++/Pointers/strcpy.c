#include <stdio.h>
#include <stdlib.h>

void strcpy1(char *s, char *t)
{
    int i;
    i = 0;
    while (*t != '\0')
    {
        *s = *t;
        s++;
        t++;
    }
}

// Same program, better way.

void strcpy2(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
    {
        ;
    }
}

int main()
{
    char first[30], last[30];
    printf("Enter first string : ");
    fgets(first, 30, stdin);
    printf("Enter second string : ");
    fgets(last, 30, stdin);
    // strcpy1(first, last);
    strcpy2(first, last);
    printf("%s", last);
    printf("%s", first);

    return 0;
}