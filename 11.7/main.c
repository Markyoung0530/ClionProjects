#include <stdio.h>
#include <stdlib.h>
void Inputarray(int *p,int m,int n);
int  FindMax(int *p,int m,int n,int *row,int *col);
int main()
{
    int m,n;
    int *p=NULL;
    int max,row,col;
    printf("How many classes are there:");
    scanf("%d",&m);
    printf("How many students in each class:");
    scanf("%d",&n);
    p=calloc(m*n, sizeof(int));
    if(p==NULL)
    {
        printf("NO enough memory!\n");
        exit(1);
    }
    Inputarray(p,m,n);
    max=FindMax(p,m,n,&row,&col);
    printf("The highest score is :%d  He comes class %d,No.%d",max,row+1,col+1);
    return 0;
}
void Inputarray(int *p,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Class %d,No.%d:",i+1,j+1);
            scanf("%d",&p[i*n+j]);
        }
    }
}

int  FindMax(int *p,int m,int n,int *row,int *col)
{
    int max=p[0],i,j;
    *row=0;*col=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[i*n+j]>max)
            {
                max=p[i*n+j];
                *row=i;
                *col=j;
            }
        }
    }
    return max;
}