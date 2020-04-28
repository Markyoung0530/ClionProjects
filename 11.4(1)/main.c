#include <stdio.h>
void Transpose1(int a[][10],int n);
void Transpose2(int (*a)[10],int n);
void Transpose3(int *a,int n);
void Swap(int *x,int *y);
int main()
{
    int n,i,j;
    int a[10][10];
    printf("Enter n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    /* 方法一 */
    Transpose1(a,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%-3d",a[i][j]);
        }
        printf("\n");
    }

    /* 方法二 */
    Transpose2(a,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%-3d",a[i][j]);
        }
        printf("\n");
    }
    /* 方法三 */
    Transpose3(*a,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%-3d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void Transpose1(int a[][10],int n)
{
    int i=0,j;
    for(i=0;i<n-1;i++)
    {
        j=i+1;
        for(;j<n;j++)
        {
            Swap(&a[i][j],&a[j][i]);
        }
    }

}

void Transpose2(int (*a)[10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            Swap(*((a+i)+j),*(a+j)+i);
        }
    }
}

void Transpose3(int *a,int n)/* 看成一维数组 */
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            Swap(&a[i*n+j],&a[j*n+i]);
        }
    }
}

void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
