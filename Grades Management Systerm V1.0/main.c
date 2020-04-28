#include <stdio.h>
#include <stdlib.h>

#define N 30
int  ReadScore(int score[],long Number[]);
int  descending(int a,int b);
int  ascending(int a,int b);
void Selectsort(int score[],long Number[],int n,int (*compare)(int ,int ));
void SortNumber(int score[],long Number[],int n);
int  FindSore(int score[],long Number[],int n,int number,int *prank);
int main()
{
    int score[N],n=0,i=-1,sum=0,number=0,choice=9,rank=0;      /* n为学生人数,number为要查询成绩的学号,choice为用户的菜单选择 */
    int ex=0,good=0,mid=0,ok=0,notok=0;
    long Number[N];      /*储存学生学号*/
    double average;

    A:;
    printf("1.Input record\n");           /* 菜单栏 */
    printf("2.Calculate total and average score of course\n");
    printf("3.Sort in descending order by score\n");
    printf("4.Sore in ascending order by score\n");
    printf("5.Sort in ascending order by number\n");
    printf("6.Search by number\n");
    printf("7.Statistic analysis\n");
    printf("8.List record\n");
    printf("9.exit\n");
    printf("Please enter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:                                               /* 读取学生成绩，统计学生人数 */
            n=ReadScore(score,Number);
            break;
        case 2:                                               /* 计算平均成绩和总分 */
            do{
                i++;
                sum+=score[i];
            }while (score[i]>=0);
            sum+=1;
            average=(float)sum/n;
            break;
        case 3:
            printf("The descending order is:\n");               /* 从高到低排出成绩表 */
            Selectsort(score,Number,n,descending);
            for(i=0;i<n;i++)
            {
                printf("%ld,%d\n",Number[i],score[i]);
            }
            break;
        case 4:
            printf("The ascending order is:\n");               /* 从低到高排出成绩表 */
            Selectsort(score,Number,n,ascending);
            for(i=0;i<n;i++)
            {
                printf("%ld,%d\n",Number[i],score[i]);
            }
            break;
        case 5:
            printf("Sort in number order:\n");                 /* 按学号排出成绩表 */
            SortNumber(score,Number,n);
            for(i=0;i<n;i++)
            {
                printf("%ld,%d\n",Number[i],score[i]);
            }
            break;
        case 6:                                              /* 查找成绩,输出排名和成绩 */
            Selectsort(score,Number,n,descending);
            printf("The grade of the score you want check is %d，his rank is %d\n",FindSore(score,Number,n,number,&rank),rank);
            break;
        case 7:                                               /* 学生成绩分类统计 */

            for(i=0;i<n;i++)
            {
                if(score[i]<=100 && score[i]>=90)
                {
                    ex++;
                }
                if(score[i]>=80 && score[i]<=89)
                {
                    good++;
                }
                if(score[i]>=70 && score[i]<=79)
                {
                    mid++;
                }
                if(score[i]>=60 && score[i]<=69)
                {
                    ok++;
                }
                if(score[i]>=0 && score[i]<=59)
                {
                    notok++;
                }
            }
            printf("100~90 accounts for %f%%\n",(float)ex*100/n);
            printf("89~80 accounts for %f%%\n",(float)good*100/n);
            printf("79~70 accounts for %f%%\n",(float)mid*100/n);
            printf("69~60 accounts for %f%%\n",(float)ok*100/n);
            printf("0~59 accounts for %f%%\n",(float)notok*100/n);
            break;
        case 8:
            SortNumber(score, Number, n);
            printf("Students' scores:\n");
            for(i=0;i<n;i++)
            {
                printf("%ld,%d\n",Number[i],score[i]);
            }
            printf("The total score of this course is %d and the average is %f\n",sum,average);
            break;
        case 9:
            return 0;
        default:
            goto A;
    }
    goto A;
}

/* 函数功能：读取学生成绩及学号，当输入成绩为-1时停止输入，并返回学生人数*/

int  ReadScore(int score[],long Number[])
{
    int i=-1;
    printf("当输入成绩为-1时，停止输入\n");

    do{
        i++;
        printf("please input number,score:");
        scanf("%ld,%d",&Number[i],&score[i]);
    }while(score[i]>=0 && Number[i]>=0);
    return i;
}

/* 函数功能：按降序排列学生成绩 */
int  descending(int a,int b)
{
    return a>b;
}

/* 函数功能：按升序排列学生成绩 */
int ascending(int a,int b)
{
    return a<b;
}

/* 按学号由小到大排出成绩表 */
void SortNumber(int score[],long Number[],int n)
{
    int i,j,temp1;
    long temp2;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(Number[j]<Number[i])
            {
                temp1=score[i];
                score[i]=score[j];
                score[j]=temp1;
                temp2=Number[i];
                Number[i]=Number[j];
                Number[j]=temp2;
            }
        }
    }
}

/* 按学号查询成绩 */
int FindSore(int score[],long Number[],int n,int number,int *prank)
{
    int i=0;
    printf("Please input the number you want check:");
    scanf("%d",&number);
    while (Number[i]!=number && i<n)
    {
        i++;
    }
    *prank=i+1;
    return score[i];
}

/* 升序\降序  排序函数 */
void Selectsort(int score[],long Number[],int n,int (*compare)(int ,int ))
{
    int i,j,temp1;
    long temp2;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((*compare)(score[j],score[i]))
            {
                temp1=score[i];
                score[i]=score[j];
                score[j]=temp1;
                temp2=Number[i];
                Number[i]=Number[j];
                Number[j]=temp2;
            }
        }
    }
}
