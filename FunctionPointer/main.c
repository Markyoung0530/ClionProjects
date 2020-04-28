#include <stdio.h>
void selectsort(int c[],int n,int (*compare)(int ,int ) );
int descending(int a,int b);
int ascending(int a,int b);
void swap(int *a,int *b);
int main()
{
    int c[]={93,98,45,31,56,60,77,00,100,44};
    int order,n=10;
    printf("Input 1 to order in descending order\n");
    printf("Input 2 to order in ascending order:");
    scanf("%d",&order);
    if(order==1)
    {
        selectsort(c,n,descending);
    }
    if(order==2)
    {
        selectsort(c,n,ascending);
    }
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",c[i]);
    }
    return 0;
}

/* 选择排序函数 */

void selectsort(int c[],int n,int (*compare)(int ,int ) )
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((* compare)(c[j],c[k]))
            {
                k=j;
            }
        }
        if(k!=i)
        {
            swap(&c[i],&c[k]);
        }
    }
}

/* 降序排列函数 */

int descending(int a,int b)
{
    return a>b;
}
int ascending(int a,int b)
{
    return a<b;
}
/* 交换两数 */
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
