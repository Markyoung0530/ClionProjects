#include <stdio.h>
void Transpose1(int a[][10],int m,int n);
void Transpose2(int (*a)[10],int m,int n);
void Transpose3(int *a,int m,int n);
void Swap(int *x,int *y);
int main()
{
    int m,n,i,j;
    int a[10][10];
    printf("Enter m,n:");
    scanf("%d,%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    /* 方法一*/
    Transpose1(a,m,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%-3d",a[i][j]);
        }
        printf("\n");
    }
    /* 方法二
    Transpose2(a,m,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%-3d",a[i][j]);
        }
        printf("\n");
    }
*/
    return 0;
}

void Transpose1(int a[][10],int m,int n)
{
    int i,j;
    if(m>n)
    {
        for(i=0;i<n-1;i++)
        {
            j=i+1;
            for(;j<n;j++)
            {
                Swap(&a[i][j],&a[j][i]);
            }
        }
        for(i=n;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                a[j][i]=a[i][j];
            }
        }
    }
    if(m<n)
    {
        for(i=0;i<m;i++)
        {
            for(j=i+1;j<n;j++)
            {
                Swap(&a[i][j],&a[j][i]);
            }
        }
        for(i=m;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                a[j][i]=a[i][j];
            }
        }
    }


}

void Transpose2(int (*a)[10],int m,int n)
{
    int i,j;
    if(m>n)
    {
        for(i=0;i<n-1;i++)
        {
            j=i+1;
            for(;j<n;j++)
            {
                Swap(&a[i][j],&a[j][i]);
            }
        }
        for(i=n;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                a[j][i]=a[i][j];
            }
        }
    }
    if(m<n)
    {
        for(i=0;i<m;i++)
        {
            for(j=i+1;j<n;j++)
            {
                Swap(&a[i][j],&a[j][i]);
            }
        }
        for(i=m;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                a[j][i]=a[i][j];
            }
        }
    }


}

void Transpose3(int *a,int m,int n)/* 看成一维数组 */
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
