#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(int m)       /*判断m是否为素数*/
{
    int  find=0,i;
    if(m==2||m==3)    find=0;
    else
    {
        for(i=2;i<=(int)(sqrt(m));i++)   /* 如果find==1，则m不是素数；如果find==0,则m是素数 */
        {
            if(m%i==0)
            {
                find=1;
            }
        }
     }
     return find;
}

int main() {
    int m, n, i, j, a[40], ret, sum = 1;
    i = -1;
    printf("Number:180110416\n");
    printf("Subject No.3 - program No.1.2\n");
    printf("Input m:");
    scanf("%d", &m);
    if (m <= 0) {
        do {
            printf("Error!Input again:");
            scanf("%d", &m);
        } while (m <= 0);        /* 检测m的合法性 */
    }
    if (m == 1)     printf("It is not a perfect number\n");
    else {
        ret = IsPrime(m);
    }
    if (ret == 0)    /* m是素数 */
        printf("It is not a perfect number\n");
    else {
        for (j = 2; j < m; j++)
        {
            if (m % j == 0)
            {
                i++;
                a[i] = j;
            }
        }
        for (n = 0; n <= i; n++)
        {
            sum = sum + a[n];
        }
        if (sum != m)      printf("It is not a perfect number\n");
        else               printf("It is a perfect number!\n");
    }
    return 0;
}