#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 10020
#define maxm 200020

int n, m, p, q;
int input[maxn], output[maxn];
int adj_matrix[maxn][maxn];
int final[maxn];            //已计算出结果的神经元集合
void add_edge(int x, int y, int z){
    adj_matrix[x][y]=z;
}

int checkFinal(){
    for(int i=1;i<=n;i++)
    {
        if(final[i]==0)
            return i;
    }
    return -1;
}

// 前向传播
void forward_propagation()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            output[j]+=output[i]*adj_matrix[i][j];
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &p, &q);//n:神经元个数，m:边个数，p:输入层神经元个数，q:输出层神经元个数。
    int x, y, z;
    memset(final, 0, sizeof(final));
    memset(adj_matrix, 0, sizeof(adj_matrix));

    for (int i=1; i<=m; i++)                    //构建图
    {
        scanf("%d%d%d", &x, &y, &z);
        add_edge(x, y, z);
    }

    for (int i=1; i<=p; i++)                    //输入层初始化
    {
        scanf("%d", &input[i]);
        output[i]=input[i];
        final[i]=1;
    }

    forward_propagation();

    for (int i=n-q+1; i<=n; i++)                //输出层
    {
        printf("%d\n", output[i]);
    }
    return 0;
}
