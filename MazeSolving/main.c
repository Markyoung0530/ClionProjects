#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1002
/*
maze数组用于存储迷宫
vis数组用于在遍历的时候标记已经访问过的点
dir数组用于表示上下左右方向
n和m分别表示迷宫的行数和列数
*/
char maze[maxn][maxn];
int vis[maxn][maxn];
int n,m;

int LegalPosition(int x, int y,int n,int m)        /** Judge whether (x,y) is legal(in the maze and not the wall) */
{
    if(x>=0 && x<n && y>=0 && y<m)//If the dot is in the maze
    {
        if(maze[x][y]=='#')
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return -1;
    }
}

void FindStart(char maze[maxn][maxn],int n,int m,int *x,int *y)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(maze[i][j]=='?')
            {
                *x=i;
                *y=j;
                return;
            }
        }
    }
}

typedef struct s_node                                   /** node stored in stack */
{
    int x; // line coordinate
    int y; // column coordinate
    int flag;
    struct s_node *prev; // a pointer point to the node before in the stack
}StackNode;

typedef struct
{
    StackNode *top;
    int size; // num of nodes in the stack
}Stack;

Stack *InitStack()                                      /** Initializing the stack */
{
    Stack* sta = (Stack *)malloc(sizeof(Stack));
    sta->top = NULL;
    sta->size = 0;
    return sta;
}
int isEmpty(Stack *sta)                                /** Judge whether the stack is empty */
{
    if(sta->size!=0)
    {
        return 0;
    }
    else
        return 1;
}

StackNode *CreateNode(x,y)
{
    StackNode* p=(StackNode *)malloc(sizeof(StackNode));
    p->x=x;p->y=y;
    p->flag=1;p->prev=NULL;
    return p;
}

void Push(Stack *sta, StackNode *now)                  /** Push a node into the stack */
{
    now->prev=sta->top;
    sta->top=now;
    sta->size+=1;
}
StackNode *Pop(Stack *sta)                             /** Pop a node out of the stack */
{
    if(isEmpty(sta)==1)
    {
        printf("It's blank stack,fail to pop!\n");
        return NULL;
    }
    else
    {
        StackNode *p=sta->top->prev,*p_top=sta->top;
        sta->top=p;
        sta->size-=1;
        return p_top;
    }
}

void OutPutMaze(char maze[maxn][maxn],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
}

void ResetMaze(char maze[maxn][maxn], int n, int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(maze[i][j]=='$')
            {
                maze[i][j]='0';
            }
        }
    }
}

void DFS(char maze[maxn][maxn], int n, int m)
{
    Stack *q = InitStack();
    StackNode *p=NULL;
    int x_start,y_start;
    int points=0;
    memset(vis, 0, sizeof(vis));                      /** a matrix marks nodes have in the path */
    FindStart(maze,n,m,&x_start,&y_start);

    StackNode now;now.flag=1;now.prev=NULL;           /** Create node now and initializing it **/
    now.x=x_start;now.y=y_start;

    p=CreateNode(now.x,now.y);
    Push(q,p);
    vis[now.x][now.y]=1;
    do{
        switch(q->top->flag)
        {
            case 1:
                if(LegalPosition(now.x,now.y-1,n,m)==1 && vis[now.x][now.y-1]==0)//Left dot is legal
                {
                    now.y-=1;
                    p=CreateNode(now.x,now.y);
                    Push(q,p);
                    vis[now.x][now.y]=1;
                    maze[now.x][now.y]='$';points++;
                }
                else
                {
                    q->top->flag++;
                }
                break;
            case 2:
                if(LegalPosition(now.x+1,now.y,n,m)==1 && vis[now.x+1][now.y]==0)//lower dot is legal
                {
                    now.x+=1;
                    p=CreateNode(now.x,now.y);
                    Push(q,p);
                    vis[now.x][now.y]=1;
                    maze[now.x][now.y]='$';points++;
                }
                else
                {
                    q->top->flag++;
                }
                break;
            case 3:
                if(LegalPosition(now.x,now.y+1,n,m)==1 && vis[now.x][now.y+1]==0)//right dot is legal
                {
                    now.y+=1;
                    p=CreateNode(now.x,now.y);
                    Push(q,p);
                    vis[now.x][now.y]=1;
                    maze[now.x][now.y]='$';points++;
                }
                else
                {
                    q->top->flag++;
                }
                break;
            case 4:
                if(LegalPosition(now.x-1,now.y,n,m)==1 && vis[now.x-1][now.y]==0)//upper dot is legal
                {
                    now.x-=1;
                    p=CreateNode(now.x,now.y);
                    Push(q,p);
                    vis[now.x][now.y]=1;
                    maze[now.x][now.y]='$';points++;
                }
                else                                            /** node now comes as the end of current path **/
                {
                    p=Pop(q);
                    free(p);
                    if(isEmpty(q))
                    {
                        break;
                    }
                    else
                    {
                        q->top->flag++;
                        if(q->top->flag==5)
                        {
                            q->top->flag=1;
                        }
                        now.x=q->top->x;
                        now.y=q->top->y;
                    }
                }
                break;
            default:
            {
                p=Pop(q);
                free(p);
            }
        }
    }while(isEmpty(q)!=1);//while栈非空
    printf("%d dots you'll reach\n",points);
    printf("They are covered with '$'\n");
    OutPutMaze(maze,n,m);
    ResetMaze(maze,n,m);                                       /** Restore the maze for BFS use */
    printf("\n");
}


typedef struct q_node                                          /** Node stored in queue */
{

    int x;               // line coordinate
    int y;               // column coordinate
    int step;            // the distance between the dot and starting dot
    struct q_node *succ; // a pointer point to the next dot in queue
}QueueNode;

QueueNode trace[maxn][maxn];                                  /** Matrix trace，record the coordinate before the dot  **/

typedef struct {
/* 队列 */
    QueueNode *front;
    QueueNode *back;
    int size; // num of nodes in queue
}Queue;

Queue *InitQueue()                                            /** Initializing the queue */
{

    Queue* que = (Queue *)malloc(sizeof(Queue));
    que->front = NULL;
    que->back = NULL;
    que->size = 0;
    return que;
}

QueueNode* CreateNode_Queue(x,y,step)
{
    QueueNode* p=(QueueNode *)malloc(sizeof(QueueNode));
    p->x=x;p->y=y;
    p->succ=NULL;p->step=step;
    return p;
}

int QueueIsEmpty(Queue *que)                                 /** Judge whether the queue is empty */
{
    return que->size==0 ? 1:0;

}

int IsEnd(int n, int m, int x, int y)
{
    return x==0 || y==0 || x==n-1 || y==m-1 ? 1:0;
}

void EnQueue(Queue *que, QueueNode* now)                     /** Push node into the queue */
{
    if(QueueIsEmpty(que))
    {
        que->front=now;
        que->back=now;

    }
    else
    {
        que->back->succ=now;
        que->back=now;
    }
    que->size++;
}
QueueNode *DeQueue(Queue *que)                               /** Pop the front node in the queue */
{
    QueueNode* p=NULL;
    if(QueueIsEmpty(que))
    {
        return NULL;
    }
    else
    {
        p=que->front;
        que->front=p->succ;
        que->size--;
        return p;
    }
}

void BFS(char maze[maxn][maxn], int n, int m)
{
    Queue *q = InitQueue();
    memset(vis, 0, sizeof(vis));                             /** Reset matrix vis */
    memset(trace, 0, sizeof(trace));
    QueueNode *p=NULL;
    int x_start,y_start;

    FindStart(maze,n,m,&x_start,&y_start);                   /** Finding out the coordinate of starting dot **/

    QueueNode now;now.succ=NULL;                             /** Create node now and initialing it */
    now.step=0;

    p=CreateNode_Queue(x_start,y_start,0);
    EnQueue(q,p);
    vis[p->x][p->y]=1;

    do{
        now.x=q->front->x;now.y=q->front->y;                 /** Reading information from front node of the queue */
        now.step=q->front->step;
        if(IsEnd(n,m,x_start,y_start)==1)
        {
            break;
        }
        if(vis[now.x][now.y-1]==0 && LegalPosition(now.x,now.y-1,n,m)==1)     /** left dot is legal */
        {
            p=CreateNode_Queue(now.x,now.y-1,now.step+1);
            vis[p->x][p->y]=1;
            trace[p->x][p->y].x=now.x;
            trace[p->x][p->y].y=now.y;
            EnQueue(q,p);
            if(IsEnd(n,m,p->x,p->y))                         /** If the node is the end dot */
            {
                break;
            }
        }
        if(vis[now.x-1][now.y]==0 && LegalPosition(now.x-1,now.y,n,m)==1)    /** Upper dot is legal */
        {
            p=CreateNode_Queue(now.x-1,now.y,now.step+1);
            vis[p->x][p->y]=1;
            trace[p->x][p->y].x=now.x;
            trace[p->x][p->y].y=now.y;
            EnQueue(q,p);
            if(IsEnd(n,m,p->x,p->y))
            {
                break;
            }
        }
        if(vis[now.x][now.y+1]==0 && LegalPosition(now.x,now.y+1,n,m)==1)    /** Right dot is legal */
        {
            p=CreateNode_Queue(now.x,now.y+1,now.step+1);
            vis[p->x][p->y]=1;
            trace[p->x][p->y].x=now.x;
            trace[p->x][p->y].y=now.y;
            EnQueue(q,p);
            if(IsEnd(n,m,p->x,p->y))
            {
                break;
            }
        }
        if(vis[now.x+1][now.y]==0 && LegalPosition(now.x+1,now.y,n,m)==1)    /** Lower dot is legal */
        {
            p=CreateNode_Queue(now.x+1,now.y,now.step+1);
            vis[p->x][p->y]=1;
            trace[p->x][p->y].x=now.x;
            trace[p->x][p->y].y=now.y;
            EnQueue(q,p);
            if(IsEnd(n,m,p->x,p->y))
            {
                break;
            }
        }
        DeQueue(q);
    }while(QueueIsEmpty(q)==0);                                            /** Repeat while the queue isn't empty */
    if(IsEnd(n,m,p->x,p->y))                                               /** If have found the ending dot p */
    {
        printf("%d step(s) to escape!\n",p->step+1);
        printf("The shortest way has been pointed out with '*'\n");
        if(p->x==x_start && p->y==y_start)
        {
            OutPutMaze(maze,n,m);
            return;
        }
        now.x=p->x;now.y=p->y;
        while(1)
        {
            maze[now.x][now.y]='*';
            now=trace[now.x][now.y];
            if(now.x==x_start && now.y==y_start)
            {
                break;
            }
        }
        OutPutMaze(maze,n,m);
    }
    else
    {
        printf("Impossible!\n");
    }
}



int main()
{
    int o = 0;
    int i,j;
    FILE *fp=NULL;
    fp=fopen("maze.in","r");
    if(fp==NULL)
    {
        printf("File doesn't exit!\n");
        exit(0);
    }
    while (fscanf(fp,"%d %d",&n,&m)!=EOF)
    {
        o += 1;
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                fscanf(fp," %c", &maze[i][j]);
            }
        }                                                                   /** Reading maze information from file */
        printf("--------Case #%d--------\n", o);
        DFS(maze,n,m);
        BFS(maze,n,m);
    }
    fclose(fp);
    return 0;
}
