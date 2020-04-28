#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//∂®“Â¡⁄Ω”±Ì
typedef struct node
{
    int  adjvex;
    int  w;
    struct node *nextedge;
} edgenode;
//∂®“Â±ﬂºØ
typedef struct
{
    char     data;
    int      id;
    edgenode  *firstedge;
} vexnode;
void CreateGraph(vexnode* Graph,int vexnumber,int arcnumber)
{
    int i = 0, j = 0, k = 0;
    int begin,end,duttem;
    char ch;
    edgenode *p;
    for(i=0; i<vexnumber; i++)
    {
        Graph[i].id =0;
        Graph[i].firstedge =NULL;
    }
    printf("Please enter the values of each vertex in this graph:\n");
    for(i=0; i<vexnumber; i++)
    {
        scanf("%s",&ch);
        Graph[i].data=ch;
    }
    printf("Please enter the starting point and weight of the arc in the figure.\n");
    for(k=0; k<arcnumber; k++)
    {
        scanf("%d %d %d",&begin,&end,&duttem);
        p=(edgenode*)malloc(sizeof(edgenode));
        p->adjvex =end-1;
        p->w =duttem;
        Graph[end-1].id ++;
        p->nextedge =Graph[begin-1].firstedge ;
        Graph[begin-1].firstedge =p;
    }
}
int SearchMapPath(vexnode* Graph,int vexnumber,int arcnumber)
{
    int totaltime=0;
    int m=0;
    int i,j,k,t;
    char sv[100];
    int front,rear;
    int *topology_queue,*vl,*ve,*el,*ee;
    front=rear=-1;
    t=0;
    topology_queue=(int*)malloc(vexnumber*sizeof(int));
    vl=(int*)malloc(vexnumber*sizeof(int));
    ve=(int*)malloc(vexnumber*sizeof(int));
    el=(int*)malloc(arcnumber*sizeof(int));
    ee=(int*)malloc(arcnumber*sizeof(int));
    edgenode *p;
    for(i=0; i<vexnumber; i++)                 ve[i]=0;
    for(i=0; i<vexnumber; i++)
    {
        if(Graph[i].id==0)                 topology_queue[++rear]=i;
        m++;
    }
    while(front!=rear)
    {
        front++;
        j=topology_queue[front];
        m++;
        p=Graph[j].firstedge ;
        while(p)
        {
            k=p->adjvex ;
            Graph[k].id --;
            if(ve[j]+p->w >ve[k])                 ve[k]=ve[j]+p->w ;
            if(Graph[k].id ==0)                 topology_queue[++rear]=k;
            p=p->nextedge ;
        }
    }
    if(m<vexnumber)
    {
        printf("\nError Existence loop\n");
        return 0;
    }
    totaltime=ve[vexnumber-1];
    for(i=0; i<vexnumber; i++)               vl[i]=totaltime;
    for(i=vexnumber-2; i>=0; i--)
    {
        j=topology_queue[i];
        p=Graph[j].firstedge;
        while(p)
        {
            k=p->adjvex ;
            if((vl[k]-p->w )<vl[j])                 vl[j]=vl[k]-p->w;
            p=p->nextedge;
        }
    }
    i=0;
    for(j=0; j<vexnumber; j++)
    {
        p=Graph[j].firstedge;
        while(p)
        {
            k=p->adjvex;
            ee[++i]=ve[j];
            el[i]=vl[k]-p->w;
            if(el[i]==ee[i])
            {
                sv[t]=Graph[j].data;
                t++;
            }
            p=p->nextedge;
        }
    }
    printf("The critical path nodes are£∫");
    sv[t]=Graph[vexnumber-1].data;
    for(i=0; i<=t; i++)
    {
        printf("%c",sv[i]);
        if(i!=t)                printf("--->");
    }
    printf("\n");
    return 1;
}
int main( )
{
    int vexnumber,arcnumber,totaltime=0;
    printf("«Î ‰»ÎΩ⁄µ„ ˝:");
    scanf("%d",&vexnumber);
    printf("«Î ‰»Îarc∏ˆ ˝:");
    scanf("%d",&arcnumber);
    vexnode* Graph=(vexnode*)malloc(vexnumber*sizeof(vexnode));
    CreateGraph(Graph,vexnumber,arcnumber);
    SearchMapPath(Graph,vexnumber,arcnumber);
    return 0;
}
