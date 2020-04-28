#include <stdio.h>
#include <time.h>
int max(int x, int y);
int CUT_ROD(int *p, int n);
int main() {
    int p[10]={1,5,8,9,10,17,17,20,24,30};
    int n;
    double start, end, duration[100];
    printf("n=");
    scanf("%d",&n);
    int q[50];
    int k=0;
    for(k=1;k<=n;k++)
    {
        start = clock();
        q[k] = CUT_ROD(p,k);
        end = clock();
        duration[k] = (double)(end - start)/CLOCKS_PER_SEC;
        printf("when n=%-2d,q=%-8d",k,q[k]);
        printf("time cost:%8fs\n",duration[k]);
    }
    return 0;
}

int max(int x, int y)
{
    return x>y ? x:y;
}

int CUT_ROD(int *p, int n)
{
    int i = 1;
    if(n==0)
    {
        return 0;
    }
    int q = -100000000;
    for(i = 0;i<(n>10?9:n);i++)
    {
        q = max(q,p[i]+CUT_ROD(p,n-i-1));
    }
    return q;
}