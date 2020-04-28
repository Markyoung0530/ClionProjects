#include <stdio.h>
#include <string.h>

#define N 30
void Read(char name[N][15],long number[],int score[N][6],int n,int subject);
void Calbycourse(int score[N][6],int n,int subject,int sum[6]);
void Calbystu(int score[N][6],int n,int subject,int sumt[6]);
void Selectsort(int score[N][6],int sumt[6],int subject,long number[],char name[N][15],int n,int (*compare)(int ,int));
int  descending(int a,int b);
int  ascending(int a,int b);
void Sortbynumber(int n,int score[N][6], long number[],char name[N][15],int sumt[6],int subject);
void Sortbyname(int n,int score[N][6],long number[],char name[N][15],int sumt[6],int subject);
void Searchbynumber(int score[N][6],long number[],char name[N][15],int n,int *prank,int sumt[6],int subject,long num);
void Searchbyname(int score[N][6],long number[],char name[N][15],int n,char *pnamestu,int *prank,int sumt[6],int subject);
void Analysis(int ex[],int good[],int mid[],int ok[],int notok[],int score[N][6],int subject,int n);
int main()
{
    int score[N][6],n=0,subject=0,choice;
    int sum[6],sumt[N],rank;   /* sum储存各学科总分，sumt储存各学生总分 */
    int i,j;
    long number[N],num;
    char name[N][15],namestu;
    int ex[6],good[6],mid[6],ok[6],notok[6];
    printf("1.Input record\n");
    printf("2.Calculate total and average score of every course\n");
    printf("3.Calculate total and average score of every student\n");
    printf("4.Sort in descending order by total score of every student\n");
    printf("5.Sort in ascending order by total score of every student\n");
    printf("6.Sort in ascending order by number\n");
    printf("7.Sort in dictionary order by name\n");
    printf("8.Search by number\n");
    printf("9.Search by name\n");
    printf("10.Statistic analysis for every course\n");
    printf("11.List record\n");
    printf("0.Exit\n");
    A:;
    printf("Please enter your choice:");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            printf("How many students are there:");
            scanf("%d",&n);
            printf("How mant subjects are there:");
            scanf("%d",&subject);
            Read(name,number,score,n,subject);

            Calbycourse(score,n,subject,sum);             /* 计算各学科总分和平均分 */
            Calbystu(score,n,subject,sumt);        /* 计算各学生平均成绩和总成绩 */

            break;

        case 2:
            Calbycourse(score,n,subject,sum);             /* 计算各学科总分和平均分 */
            printf("Total and average scores of each subject is blow\n");
            for(i=0;i<subject;i++)
            {
                printf("Subject%-4d total %-4d average %-8.2f",i+1,sum[i],sum[i]/(float)n);
                printf("\n");
            }
            break;

        case 3:
            Calbystu(score,n,subject,sumt);        /* 计算各学生平均成绩和总成绩 */
            printf("Total and average scores of each student is blow\n");
            for(i=0;i<n;i++)
            {
                printf("Student%-4d total %-4d average %-8.2f",i+1,sumt[i],sumt[i]/(float)subject);
                printf("\n");
            }
            break;

        case 4:
            /* 按总分降序排列学生 */
            printf("The descending order:\n");
            Selectsort(score,sumt,subject,number,name,n,descending);
            for(i=0;i<n;i++)
            {
                printf("No.%-4d%-8ld%-10s%-4d",i+1,number[i],name[i],sumt[i]);
                printf("\n");
            }
            break;

        case 5:
            /* 按总分升序排列 */
            printf("The ascending order:\n");
            Selectsort(score,sumt,subject,number,name,n,ascending);
            for(i=0;i<n;i++)
            {
                printf("No.%-4d%-8ld%-10s%-4d",i+1,number[i],name[i],sumt[i]);
                printf("\n");
            }
            break;

        case 6:
            /* 按学号从小到大排序 */
            printf("Sort by students' number\n");
            Sortbynumber(n,score,number,name,sumt,subject);
            for(i=0;i<n;i++)
            {
                printf("%-8ld%-10s%-3d\n",number[i],name[i],sumt[i]);
            }
            break;

        case 7:
            /* 按名字排序 */
            printf("Sort by students' name\n");
            Sortbyname(n,score,number,name,sumt,subject);
            for(i=0;i<n;i++)
            {
                printf("%-10s%-8ld%-3d\n",name[i],number[i],sumt[i]);
            }
            break;

        case 8:
            /* 按学号查询学生成绩 */
            printf("Please input the student number you wanna search:");     /* 按学号查找学生成绩 */
            scanf("%ld",&num);
            Selectsort(score,sumt,subject,number,name,n,descending);
            Searchbynumber(score,number,name,n,&rank,sumt,subject,num);
            printf("The student you search ranks No.%-3d",rank);
            for(i=0;i<subject;i++)
            {
                printf("%-4d",score[rank-1][i]);
            }
            printf("\n");
            break;

        case 9:
            /* 按姓名查询成绩 */
            printf("Please input the student' name you wanna search:");
            scanf("%s",&namestu);
            Selectsort(score,sumt,subject,number,name,n,descending);
            Searchbyname(score,number,name,n,&namestu,&rank,sumt,subject);
            printf("The student you search ranks No.%-3d",rank);
            for(i=0;i<subject;i++)
            {
                printf("%-4d",score[rank-1][i]);
            }
            printf("\n");

            break;
        case 10:
            /* 统计各分数段人数 */
            Analysis(ex,good,mid,ok,notok,score,subject,n);
            for(i=0;i<subject;i++)
            {
                printf("Subject %d:\n",i+1);
                printf("100~90:%-4.2f%%\n89~80:%-4.2f%%\n79~70:%-4.2f%%\n69~60:%-4.2f%%\n00~59:%-4.2f%%\n",100*ex[i]/(float)n,100*good[i]/(float)n,100*mid[i]/(float)n,100*ok[i]/(float)n,100*notok[i]/(float)n);
            }
            break;

        case 11:
            /* 每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分 */

            for(i=0;i<n;i++)
            {
                printf("%-10ld%-10s",number[i],name[i]);
                for(j=0;j<subject;j++)
                {
                    printf("%-4d",score[i][j]);
                }
                printf("%-5d%-4.2f\n",sumt[i],sumt[i]/(float)subject);
            }
            for(i=0;i<subject;i++)
            {
                printf("Subject %d,sum:%-5d average:%-4.2f\n",i+1,sum[i],sum[i]/(float)n);
            }

            break;
        case 0:
            return 0;
        default:goto A;
    }
    goto A;

}

/* 函数功能:读取学生多门成绩及学号 */
void Read(char name[N][15],long number[],int score[N][6],int n,int subject)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("Name of student%d:",i+1);
        scanf("%s",name[i]);
        printf("Number of student%d:",i+1);
        scanf("%ld",&number[i]);
        for(j=0;j<subject;j++)
        {
            printf("Subject%d:",j+1);
            scanf("%d",&score[i][j]);
        }
    }
}

/* 函数功能:计算各科总分 */
void Calbycourse(int score[N][6],int n,int subject,int sum[6])
{
    int i,j;
    int temp=0;
    for(i=0;i<subject;i++)
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            temp+=score[j][i];
        }
        sum[i]=temp;
    }
}

/* 函数功能:计算各学生总分 */
void Calbystu(int score[N][6],int n,int subject,int sumt[6])
{
    int i,j;
    int temp=0;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<subject;j++)
        {
            temp+=score[i][j];
        }
        sumt[i]=temp;
    }
}

/* 升序\降序排列学生成绩 */
void Selectsort(int score[N][6],int sumt[6],int subject,long number[],char name[N][15],int n,int (*compare)(int ,int ))
{
    int i,j,k,temp1=0;
    long temp2=0;
    char temp3[15];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((*compare)(sumt[j],sumt[i]))
            {
                for(k=0;k<subject;k++)
                {
                    temp1=score[i][k];
                    score[i][k]=score[j][k];
                    score[j][k]=temp1;
                    temp2=number[i];
                    number[i]=number[j];
                    number[j]=temp2;
                    strcpy(temp3,name[i]);
                    strcpy(name[i],name[j]);
                    strcpy(name[j],temp3);
                    temp1=sumt[i];
                    sumt[i]=sumt[j];
                    sumt[j]=temp1;
                }
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

/* 函数功能:按学号排序 */
void Sortbynumber(int n,int score[N][6], long number[],char name[N][15],int sumt[6],int subject)
{
    int i,j,temp2;
    long temp1;
    char temp3[N];
    Calbystu(score,n,subject,sumt);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(number[j]<number[i])
            {
                temp1=number[j];
                number[j]=number[i];
                number[i]=temp1;
                temp2=sumt[j];
                sumt[j]=sumt[i];
                sumt[i]=temp2;
                strcpy(temp3,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp3);
            }
        }
    }
}

/* 按学生姓名排序 */
void Sortbyname(int n,int score[N][6],long number[],char name[N][15],int sumt[6],int subject)
{
    int i,j,temp2;
    long temp1;
    char temp3[N];
    Calbystu(score,n,subject,sumt);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(name[j],name[i])<0)
            {
                temp1=number[j];
                number[j]=number[i];
                number[i]=temp1;
                temp2=sumt[j];
                sumt[j]=sumt[i];
                sumt[i]=temp2;
                strcpy(temp3,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp3);
            }
        }
    }
}
/* 函数功能:按学号查询学生成绩及排名（先降序排列） */
void Searchbynumber(int score[N][6],long number[],char name[N][15],int n,int *prank,int sumt[6],int subject,long num)
{
    int i=0;
    Selectsort(score,sumt,subject,number,name,n,descending);
    while(number[i]!=num)
    {
        i++;
    }
    *prank=i+1;
}

/* 按名字查询学生成绩及排名（先降序排列）*/
void  Searchbyname(int score[N][6],long number[],char name[N][15],int n,char *pnamestu,int *prank,int sumt[6],int subject)
{
    int i=0;
    Selectsort(score,sumt,subject,number,name,n,descending);
    while(strcmp(pnamestu,name[i])!=0)
    {
        i++;
    }
    *prank=i+1;
}

/* 统计各分数段人数 */
void Analysis(int ex[],int good[],int mid[],int ok[],int notok[],int score[N][6],int subject,int n)
{
    int i,j;
    for(i=0;i<subject;i++)
    {
        for(j=0;j<n;j++)
        {

            if (score[j][i] <= 100 && score[j][i] >= 90)
            {
                ex[i]++;
            }
            if (score[j][i] >= 80 && score[j][i] <= 89)
            {
                good[i]++;
            }
            if (score[j][i] >= 70 && score[j][i] <= 79)
            {
                mid[i]++;
            }
            if (score[j][i] >= 60 && score[j][i] <= 69)
            {
                ok[i]++;
            }
            if (score[j][i] >= 0 && score[j][i] <= 59)
            {
                notok[i]++;
            }
        }
    }
}