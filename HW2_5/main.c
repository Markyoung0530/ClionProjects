#include<stdio.h>
#define MAX 30
#define inf 100000000
typedef char valType;
typedef int wghType;
typedef struct HFM_node
{
    valType data;
    wghType weight;
    int parent;
    int lchild;
    int rchild;
}HFMnode;
typedef struct HFM_code
{
    char code[MAX];
    int start;
}HFMcode;
void createHFMtree(HFMnode *node,int n)
{
    int i,m1,m2,l,r;
    for(i=n+1;i<=2*n-1;i++)
    {
        m1=m2=inf;
        l=r=0;
        int k;
        for(k=1;k<=i-1;k++)
            if(node[k].parent==0)
            {
                if(node[k].weight<m1)
                {
                    m2=m1;
                    r=l;
                    m1=node[k].weight;
                    l=k;
                }
                else if(node[k].weight<m2)
                {
                    m2=node[k].weight;
                    r=k;
                }
            }
        node[i].weight=node[l].weight+node[r].weight;
        node[i].lchild=l;
        node[i].rchild=r;
        node[l].parent=i;
        node[r].parent=i;
    }
}
void createHFMcode(HFMnode *node, HFMcode *hcode,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        HFMcode d;
        d.start=n;
        int num=i;
        int father=node[num].parent;
        while(father!=0)
        {
            if(node[father].lchild==num)
                d.code[d.start--]='0';
            else d.code[d.start--]='1';
            num=father;
            father=node[num].parent;
        }
        hcode[i]=d;
    }
}
void printHFMcode(HFMnode * node,HFMcode * hcode,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%c: ",node[i].data);
        for(int k=hcode[i].start+1;k<=n;k++)
            putchar(hcode[i].code[k]);
        puts("");
    }
}
int main()
{
    HFMnode node[2*MAX];HFMcode hcd[MAX];
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
    {
        printf("输入第%d个节点的值\n",i);
        scanf("%c",&node[i].data);
        printf("输入它的权重\n");
        scanf("%d\n",&node[i].weight);
    }
    for(i=1;i<=2*n-1;i++)
        node[i].parent=node[i].lchild=node[i].rchild=0;
    createHFMtree(node,n);
    createHFMcode(node,hcd,n);
    printHFMcode(node,hcd,n);
    return 0;
}
