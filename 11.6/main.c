#include <stdio.h>
void Inputarray(int *p,int m,int n);
int FindMax(int *p,int m,int n,int *pRow,int *pCol);
int main()
{
    int m,n,max;
    int a[10][10];
    int pRow,pCol;
    printf("Enter m,n:");
    scanf("%d,%d",&m,&n);
    Inputarray(*a,m,n);
    max=FindMax(*a,m,n,&pRow,&pCol);
    printf("Max is %d and it lies in row %d,col %d",max,pRow,pCol);
    return 0;
}
void Inputarray(int *p,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d]=",i,j);
            scanf("%d",&p[i*n+j]);
        }
    }
}

int FindMax(int *p,int m,int n,int *pRow,int *pCol)
{
    int i=0,j=0,max=0;
    *pRow=0;*pCol=0;
    for(i=0;i<m;i++)
    {
        max=p[i*n+j];
        for(j=0;j<n;j++)
        {
            if(p[i*n+j]>max)
            {
                max=p[i*n+j];
                *pRow=i;
                *pCol=j;
            }
        }
    }
    return max;
}