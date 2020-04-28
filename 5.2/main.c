#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int *q) //将p所在的地址指向的值和q地址所指向的值交换
{
    int temp = *p;
    *p = *q;
    *q = temp;
}


// 排序
void sortColors(int nums[], int n)
{
    int i = 0, j = n - 1, k = 0;
    while (k < j)
    {
        if (nums[k] == 2)
        {
            while (nums[j] == 2 && j > k)
            {
                j--;
            }
            if (j > k)
            {
                swap(nums+k, nums+j);
            }
        }
        if (nums[k] == 0)
        {
            while (nums[i] == 0 && i < k)
            {
                i++;
            }
            if (i < k)
            {
                swap(nums+i, nums+k);
            }
        }
        if (nums[k] == 1 || k == i)
        {
            k++;
        }
    }
}

int main()
{
    int nums[100];
    int n = 10, i = 0;
    printf("please input n:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("please input %d number:", i);
        scanf("%d", &nums[i]);
    }
    sortColors(nums, n);
    for (i = 0; i < n; i++)
    {
        printf("%d\n", nums[i]);
    }
}
