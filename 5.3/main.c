#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int moment;
    int flag;
    int student;
}TIME;

//统计学生输入的用餐时间，并判断输入的合法性
void record(TIME start[], TIME end[], int M, int N)
{
    int i;
    for (i = 0; i < M; i++)
    {
        scanf("%d", &start[i].moment);
        scanf("%d", &end[i].moment);
        if(start[i].moment<0||end[i].moment>N||start[i].moment>end[i].moment)
        {
            printf("ERROR!\n");
            exit(0);
        }
        start[i].flag=1;
        end[i].flag=0;
        start[i].student=0;
        end[i].student=0;
    }
}
//对起始时间和终止时间进行排序
void sort(TIME *a, int left, int right)
{
    if(left >= right)
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left].moment;    //设置枢轴
    while(i < j)
    {
        while(i < j && key <= a[j].moment)
        {
            j--;
        }
        a[i].moment = a[j].moment;
        while(i < j && key >= a[i].moment)
        {
            i++;
        }
        a[j].moment = a[i].moment;
    }
    a[i].moment = key;
    sort(a, left, i - 1);       //递归对枢轴两边数组进行排序
    sort(a, i + 1, right);
}

void Merge(TIME start[],TIME end[],TIME merge[],int M)
{
    int i=0,j=0;
    int k;
    sort(start,0,M-1);
    sort(end,0,M-1);
    for(k=0;k<2*M;k++)
    {
        if(start[i].moment<=end[j].moment)
        {
            merge[k] = start[i];
            i++;
        }
        else
        {
            merge[k] = end[j];
            j++;
        }
    }
}

//计算用餐人数最多时间段的起始时间和终止时间
void Period(TIME merge[],  int M)
{
    int number=0;
    int i,max=0;
    int is_continuous=0;
    for(i=0;i<2*M;i++)
    {
        if(merge[i].flag==1)
        {
            number++;
            merge[i].student=number;
        }
        else if(merge[i].flag==0)
        {
            merge[i].student=number;
            number--;
        }
        if(number>max)  max=number;
    }
    for(i=0;i<2*M;i++)
    {
        if(merge[i].student==max&&is_continuous==0)
        {
            printf("%d ",merge[i].moment);
            is_continuous=1;
        }
        else if(merge[i].student==max&&i==2*M-1)
        {
            printf("%d\n",merge[i].moment);
        }
        else if(is_continuous==1)
        {
            if(merge[i].student==max&&merge[i+1].moment==merge[i].moment)
            {
                continue;
            }
            else if(merge[i].student==max&&merge[i+1].moment!=merge[i].moment+1)
            {
                printf("%d\n",merge[i].moment);
                is_continuous=0;
            }
            else if(merge[i].student!=max)
            {
                printf("%d\n",merge[i-1].moment);
                is_continuous=0;
            }
        }
    }
}

int main()
{
    int M,N;
    scanf("%d",&N);//输入时间段数量
    scanf("%d",&M);//输入学生人数
    TIME *start, *end, *merge; //分别存储起始时间和终止时间以及合并后的序列
    start=(TIME *)malloc(M*(sizeof(TIME)));
    end=(TIME *)malloc(M*(sizeof(TIME)));
    merge=(TIME *)malloc((2*M)*sizeof(TIME));
    record(start, end, M, N); //录入学生登记的时间段
    Merge(start,end,merge,M);
    Period(merge,M);   //输出用餐人数最多时间段的起始时间和终止时间
    free(start);
    free(end);
    free(merge);
    return 0;
}