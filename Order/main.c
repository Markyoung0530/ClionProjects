#include <stdio.h>
int CountWords(char str[]);
int  main()
{
    char str[20];
    printf("Input a string:");
    gets(str);
    printf("Numbers of words = %d\n", CountWords(str));
}

int CountWords(char str[])
{
    int i, num;
    num = (str[0] != ' ') ? 1 : 0;
    for (i=1;str[i]!='\0'; i++)
    {
        if (str[i]==' ')
        {
            num++;
        }
    }
    return num;
}
