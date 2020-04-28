#include <stdio.h>

int main()
{
    int a[]={1801,1802,1803,1804,1805,1806,1807,1808,1809,1810};
    int low=0,high=9,mid=0;
    int number;
    printf("Enter the number you wanna check:");
    scanf("%d",&number);
    while(low<=high)
    {
        mid = (low + high) / 2;
        if (number > a[mid])
        {
            low = mid + 1;
        }
        else if(number<a[mid])
        {
            high=mid-1;
        }
        else break;
    }
    mid++;
    printf("The number you check ranks %d",mid);
    return 0;
}