#include <stdio.h>
#include <stdlib.h>
#define N 1.42e8

int main()
{
    int n;
    double term=1,sum=1;
    printf("Number:180110416\n");
    printf("Subject No.3 - program No.2\n");
    for(n=2;n<=64;n++)
    {
        term=term*2;
        sum=sum+term;
    }
    printf("sum=%e\n",sum);
    printf("volume=%e\n",sum/N);
    return 0;
}
