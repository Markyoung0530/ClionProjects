#include <stdio.h>
#define MAXLEN 20
int front=MAXLEN-1;//队列初始化
int rear=MAXLEN-1;

void enqueue(int q[],int x) //入队
{
    rear=(rear+1)%MAXLEN;
    q[rear]=x;

}
int dequeue(int q[])  //出队
{
    front=(front+1)%MAXLEN;
    return q[front];
}

int main()
{
    int i,j,y,n,m;  //j是，y是，n是参与的人数，m是出列时所报的数
    int q[20];
    printf("请依次输入参与的人数和出列时报的数:");
    scanf("%d%d",&n,&m);
    printf("人数=%d,出列数字=%d\n",n,m);
    for(i=1;i<=n;i++) //队列的元素进队
    enqueue(q,i);
    j=n; //j初始化，代表剩余未出列的人数
    printf("输出出列顺序如下所示：");
    while(j!=0) //当报数i=m时删掉此元素，元素出列，i用来计报的数，判断是否出列

    {
        for(i=1;i<=m;i++)
        {
            y=dequeue(q);
            if(i!=m)
            enqueue(q,y);
            else
            {
                printf("%2d",y);
                j--;
            }
        }
    }
}
