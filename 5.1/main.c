#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int digit_judge(int x)
{
    if(x<=9)      return 1;
    if(x<=99)     return 2;
    if(x<=999)    return 3;
    else          return 4;
}

int greater_compare(int x, int y)
{
    int difference;
    difference=abs(digit_judge(x)-digit_judge(y));
    if(digit_judge(x)<=digit_judge(y))
    {
        if(x<y/(int)pow(10, difference))
            return 0;
        else
            return 1;
    }
    else
    {
        if(x/(int)pow(10, difference)<=y)
            return 0;
        else
            return 1;
    }
}

void swap(int *p, int *q) //将p所在的地址指向的值和q地址所指向的值交换
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// 请实现排序算法
int *resort(int nums[], int n)
{
    int *max=nums, *p=NULL, *pr=NULL;
    for(p=nums;p<=nums+n-2;p++)
    {
        max=p;
        for(pr=p+1;pr<=nums+n-1;pr++)
        {
            if(greater_compare(*pr, *max))
            {
                swap(pr, max);
            }
        }
    }
    return nums;
}

int main()
{
    int n;
    int i;
    int *nums;
    // 输入
    scanf("%d", &n);
    nums = (int *)malloc(n * (sizeof(int)));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    // 排序
    int *a = resort(nums, n);

    // 输出
    printf("排序后\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
