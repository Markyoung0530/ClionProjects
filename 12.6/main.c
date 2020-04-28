#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
}STACK;
STACK *head,*pr;
STACK *Create(int num);
STACK *Push(int num);
int   Pop(void);
int node=0;
int main()
{
    int pushnum[]={99,88,77,66,55,44},popnum[6];
    int i;
    for(i=0;i<6;i++)
    {
        Push(pushnum[i]);
        printf("Pop No.%d Data:%d\n",6-i,pushnum[i]);
    }
    for(i=0;i<6;i++)
    {
        popnum[i]=Pop();
        printf("Pop No.%d Data:%d\n",6-i,popnum[i]);
    }
    return 0;
}


STACK *Create(int num)
{
    STACK *p;
    p=(STACK *)malloc(sizeof(STACK));
    if(p==NULL)
    {
        printf("Fail to allocate!\n");
        exit(1);
    }
    p->next=NULL;
    p->data=num;
    return p;
}

STACK *Push(int num)
{
    if(node==0)
    {
        head=Create(num);
        pr=head;
        node++;
    }
    else
    {
        pr->next=Create(num);
        pr=pr->next;
        node++;
    }
    return pr;
}

int   Pop(void)
{
    STACK *p=head;
    int result;
    for(;;)
    {
        if(p->next==NULL)
        {
            break;
        }
        else
        {
            pr=p;
            p=p->next;
            node--;
        }
    }
    pr->next=NULL;
    result=p->data;
    free(p);
    return result;
}