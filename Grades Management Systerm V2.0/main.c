#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 30
void Read(char name[N][15],long number[],int score[],int n);
void CalScore(int score[],int n,int *psum,double *paverage);
void Selectsort(int score[],long number[],char name[N][15],int n,int (*compare)(int ,int ));
int  descending(int a,int b);
int  ascending(int a,int b);
void Sortbynumber(int score[],long number[],char name[N][15],int n);
void Sortbyname(int score[],long number[],char name[N][15],int n);
int  Searchbynumber(int score[],long number[],char name[N][15],int n,long num,int *prank);
int  Searchbyname(int score[],long number[],char name[N][15],int n,char *pnamestu,int *prank);
int main()
{
    char name[N][15],namestu;
    int n,score[N],sum=0,i,rank=0;
    long number[N],num;
    double average=0;
    int ex=0,good=0,mid=0,ok=0,notok=0;/* 统计各分数段比例 */
    int choice=9;

    printf("1.Input record\n");           /* 菜单栏 */
    printf("2.Calculate total and average score of course\n");
    printf("3.Sort in descending order by score\n");
    printf("4.Sore in ascending order by score\n");
    printf("5.Sort in ascending order by number\n");
    printf("6.Sort in dictionary order by name\n");
    printf("7.Search by number\n");
    printf("8.Search by name\n");
    printf("9.Statistic analysis!\n");
    printf("10.List record\n");
    printf("0.Exit\n");
    A:;
    printf("Please enter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("How many students are there:");                 /* 读取学生信息 */
            scanf("%d",&n);
            getchar();
            Read(name,number,score,n);
            break;
        case 2:
            CalScore(score,n,&sum,&average);                        /* 计算课程总分和平均分 */
            printf("The average score of this course is %f\n",average);
            printf("The total score of this course is %d\n",sum);
            break;
        case 3:
            Selectsort(score,number,name,n,descending);      /* 按成绩降序给出名次表 */
            printf("The descending order is:\n");
            for(i=0;i<n;i++)
            {
                printf("No.%-3d%-10ld%-10s\n",i+1,number[i],name[i]);
            }
            break;
        case 4:
            Selectsort(score,number,name,n,ascending);       /* 按成绩升序给出名次表 */
            printf("The ascending order is:\n");
            for(i=0;i<n;i++)
            {
                printf("No.%-3d%-10ld%-10s\n",i+1,number[i],name[i]);
            }
            break;
        case 5:
            Sortbynumber(score,number,name,n);               /* 学号由小到大排出成绩表 */
            printf("Sort by number:\n");
            for(i=0;i<n;i++)
            {
                printf("%-10ld%-10s%-3d\n",number[i],name[i],score[i]);
            }
            break;
        case 6:
            Sortbyname(score,number,name,n);                /* 按学生名字排序 */
            printf("Sort by name:\n");
            for(i=0;i<n;i++)
            {
                printf("%-10ld%-10s%-1d\n",number[i],name[i],score[i]);
            }
            break;
        case 7:
            printf("Please input the student number you wanna search:");     /* 按学号查找学生成绩 */
            scanf("%ld",&num);
            printf("The score of this student is %d and he ranks %d\n",Searchbynumber(score,number,name,n,num,&rank),rank);
        case 8:
            printf("Please input the name of student you wanna search:");    /* 按名字查找学生成绩 */
            scanf("%s",&namestu);
            printf("The score of this student is %d and he ranks %d\n",Searchbyname(score,number,name,n,&namestu,&rank),rank);
            break;
        case 9:
            for(i=0;i<n;i++)                                                 /* 统计各分数段人数 */
            {
                if (score[i] <= 100 && score[i] >= 90) {
                    ex++;
                }
                if (score[i] >= 80 && score[i] <= 89) {
                    good++;
                }
                if (score[i] >= 70 && score[i] <= 79) {
                    mid++;
                }
                if (score[i] >= 60 && score[i] <= 69) {
                    ok++;
                }
                if (score[i] >= 0 && score[i] <= 59) {
                    notok++;
                }
            }
            printf("100~90 has %d students, accounts for %f%%\n",ex,(float)ex*100/n);
            printf("89~80 has %d students, accounts for %f%%\n",good,(float)good*100/n);
            printf("79~70 has %d students, accounts for %f%%\n",mid,(float)mid*100/n);
            printf("69~60 has %d students, accounts for %f%%\n",ok,(float)ok*100/n);
            printf("0~59 has %d students, accounts for %f%%\n",notok,(float)notok*100/n);
            break;
        case 10:
            /* 输出每个学生的学号、姓名、考试成绩以及课程总分和平均分 */
            for(i=0;i<n;i++)
            {
                printf("Student%d %-10ld%-10s%-3d",i+1,number[i],name[i],score[i]);
                printf("\n");
            }
            printf("And the total score of this course is %d ,the average is %f",sum,average);
            break;
        case 0:
            return 0;
    }
    goto A;
}

/* 读取学生姓名，学号，成绩 */
void Read(char name[][15],long number[],int score[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Name of student %d:",i+1);
        scanf("%s",name[i]);
        printf("number,score:");
        scanf("%ld,%d",&number[i],&score[i]);
    }
}

/* 计算平均成绩 */
void CalScore(int score[],int n,int *psum, double *paverage)
{
    int i;
    for(i=0;i<n;i++)
    {
        *psum+=score[i];
    }
    *paverage=(double)*psum/n;
}

/* 分数升序\降序排列函数 */
void Selectsort(int score[],long number[],char name[N][15],int n,int (*compare)(int ,int ))
{
    int i,j,temp1;
    long temp2;
    char temp3[15];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((*compare)(score[j],score[i]))
            {
                temp1=score[i];
                score[i]=score[j];
                score[j]=temp1;
                temp2=number[i];
                number[i]=number[j];
                number[j]=temp2;
                strcpy(temp3,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp3);

            }
        }
    }
}

/* 函数功能：按降序排列成绩 */
int  descending(int a,int b)
{
    return a>b;
}

/* 函数功能：按升序排列学生成绩 */
int ascending(int a,int b)
{
    return a<b;
}

/* 函数功能：学号由小到大排序 */
void Sortbynumber(int score[],long number[],char name[N][15],int n)
{
    int i,j,temp1;
    long temp2;
    char temp3[15];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(number[j]<number[i])
            {
                temp1=score[i];
                score[i]=score[j];
                score[j]=temp1;
                temp2=number[i];
                number[i]=number[j];
                number[j]=temp2;
                strcpy(temp3,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp3);

            }
        }
    }
}

/* 函数功能：按学生姓名排序 */
void Sortbyname(int score[],long number[],char name[N][15],int n)
{
    int i,j,temp1;
    long temp2;
    char temp3[15];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(name[i],name[j])>0)
            {
                temp1=score[i];
                score[i]=score[j];
                score[j]=temp1;
                temp2=number[i];
                number[i]=number[j];
                number[j]=temp2;
                strcpy(temp3,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp3);

            }
        }
    }
}

/* 函数功能:按学号查询学生成绩及排名（先降序排列） */
int Searchbynumber(int score[],long number[],char name[N][15],int n,long num,int *prank)
{
    int i=0;
    Selectsort(score,number,name,n,descending);
    while(number[i]!=num)
    {
        i++;
    }
    *prank=i+1;
    return score[i];
}

/* 按名字查询学生成绩及排名（先降序排列）*/
int  Searchbyname(int score[],long number[],char name[N][15],int n,char *pnamestu,int *prank)
{
    int i=0;
    Selectsort(score,number,name,n,descending);
    while(strcmp(pnamestu,name[i])!=0)
    {
        i++;
    }
    *prank=i+1;
    return score[i];
}