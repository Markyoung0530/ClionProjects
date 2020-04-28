#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 2147483647
#define maxn 10020
#define maxm 200020
int n, m, s;
int D[maxn];          //ans储存源点到各点的距离
int adj_matrix[maxn][maxn];
int final[maxn];        //已确定的顶点集合

void add_edge(int x, int y, int z)//加边(起始及权值)x,y为起始点编号,z为权值
{
    adj_matrix[x-1][y-1]=z;
}

int checkFinal()                   //检查是否还有点未进入路径，如果还有，则返回它的编号
{
    for(int i=0;i<n;i++)
    {
        if(final[i]==0)
            return i;
    }
    return -1;
}

int FindShortest()
{
    int min=D[0];
    int location=0;
    for(int i=1;i<n;i++)
    {
        if(D[i]<=min && final[i]==0)
        {
            min=D[i];
            location=i;
        }
    }
    return location;
}

// 求最短路径
void get_path(int start)
{
    start--;
    int i,j;
    final[start]=1;
    while(checkFinal()>=0)                          //还有点未进入路径
    {
        j=FindShortest();
        final[j]=1;
        for(i=0;i<n;++i)
        {
            if(final[i]==0)                         //如果i号点未进入路径
            {
                if(adj_matrix[j][i]==INF)           //如果不能到达
                {
                    D[i]=D[i];
                }
                else //比较直接和间接到达，选择近点那个
                {
                    D[i]=D[i]<D[j]+adj_matrix[j][i]?D[i]:D[j]+adj_matrix[j][i];
                }
            }
        }
    }
}

int main()
{
    printf("n m s:");
    scanf("%d %d %d", &n, &m, &s);        //点个数，边条数，出发点编号
    int x, y, z;
    for(int i=0;i<n;i++)                     /**初始化邻接矩阵*/
    {
        for(int j=0;j<n;j++)
        {
            adj_matrix[i][j]=INF;
        }
    }
    printf("Start creating a graph:\n");
    for (int i=1; i<=m; i++)                /** 构造邻接矩阵 */
    {
        scanf("%d %d %d", &x, &y, &z);
        add_edge(x, y, z);
    }

    for (int i=0; i<n; i++)                /** 初始化距离矩阵和路径点集 */
    {
        final[i] = 0;
        D[i] = adj_matrix[s-1][i];
    }

    get_path(s);
    D[s-1]=0;
    for (int i=0; i<n; i++)
    {
        printf("%d  ", D[i]);
    }

    return 0;
}
