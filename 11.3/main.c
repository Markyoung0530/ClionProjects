#include <stdio.h>

int main()
{
    char a[][10]={"January","February","March","April","May","June","July","August",
                  "September","October","November","December"};
    int i,month;
    char *pa[12];
    for(i=0;i<12;i++)
    {
        pa[i]=a[i];
    }
    A:;
    printf("Please input month:");
    scanf("%d",&month);
    if(month>12 || month<1)
    {
        printf("Illegal month!\n");
        goto A;
    }
    else
    {
        printf("%s\n",pa[month-1]);
    }
    return 0;
}