#include <stdio.h>
#define N 5
int main()
{
    int a[N]={88,99,65,39,87};
    printf("本程序使用冒泡排序法排序！\n");
    int i,j,t;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

    /* 输出排列后的数 */
    printf("Numbers have been well ordered!");
    for(i=0;i<N;i++)
    {
        printf("%d   ",a[i]);
    }
    return 0;
}
