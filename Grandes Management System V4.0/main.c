#include <stdio.h>
#include <string.h>

#define N 30
typedef struct student
{
    int score[6];
    long number;
    char name[15];
}STUDENT;
void Read(STUDENT stu[],int n,int subject);
void Calbycourse(STUDENT stu[],int n,int subject,int sum[6]);
void Calbystu(STUDENT stu[],int n,int subject,int sumt[6]);
void Selectsort(STUDENT stu[],int sumt[6],int subject,int n,int (*compare)(int ,int));
int  descending(int a,int b);
int  ascending(int a,int b);
void Sortbynumber(STUDENT stu[],int sumt[6],int subject,int n);
void Sortbyname(STUDENT stu[],int n,int sumt[6],int subject);
void Searchbynumber(STUDENT stu[],int n,int sumt[6],int subject,long num,int *prank);
void Searchbyname(STUDENT stu[],int n,char *pnamestu,int sumt[6],int subject,int *prank);
void Analysis(int ex[],int good[],int mid[],int ok[],int notok[],STUDENT stu[],int subject,int n);
int main()
{
    int n=0,subject=0,choice,rank;
    int sum[6],sumt[N];   /* sum储存各学科总分，sumt储存各学生总分 */
    int i,j;
    long num;
    char namestu;
    int ex[6],good[6],mid[6],ok[6],notok[6];
    STUDENT stu[N];
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
            Read(stu,n,subject);

            Calbycourse(stu,n,subject,sum);             /* 计算各学科总分和平均分 */
            Calbystu(stu,n,subject,sumt);        /* 计算各学生平均成绩和总成绩 */

            break;

        case 2:
            Calbycourse(stu,n,subject,sum);             /* 计算各学科总分和平均分 */
            printf("Total and average scores of each subject is blow\n");
            for(i=0;i<subject;i++)
            {
                printf("Subject%-4d total %-4d average %-8.2f",i+1,sum[i],sum[i]/(float)n);
                printf("\n");
            }
            break;

        case 3:
            Calbystu(stu,n,subject,sumt);        /* 计算各学生平均成绩和总成绩 */
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
            Selectsort(stu,sumt,subject,n,descending);
            for(i=0;i<n;i++)
            {
                printf("No.%-4d%-8ld%-10s%-4d",i+1,stu[i].number,stu[i].name,sumt[i]);
                printf("\n");
            }
            break;

        case 5:
            /* 按总分升序排列 */
            printf("The ascending order:\n");
            Selectsort(stu,sumt,subject,n,ascending);
            for(i=0;i<n;i++)
            {
                printf("No.%-4d%-8ld%-10s%-4d",i+1,stu[i].number,stu[i].name,sumt[i]);
                printf("\n");
            }
            break;

        case 6:
            /* 按学号从小到大排序 */
            printf("Sort by students' number\n");
            Sortbynumber(stu,sumt,subject,n);
            for(i=0;i<n;i++)
            {
                printf("%-8ld%-10s%-3d\n",stu[i].number,stu[i].name,sumt[i]);
            }
            break;

        case 7:
            /* 按名字排序 */
            printf("Sort by students' name\n");
            Sortbyname(stu,n,sumt,subject);
            for(i=0;i<n;i++)
            {
                printf("%-10s%-8ld%-3d\n",stu[i].name,stu[i].number,sumt[i]);
            }
            break;

        case 8:
            /* 按学号查询学生成绩 */
            printf("Please input the student number you wanna search:");     /* 按学号查找学生成绩 */
            scanf("%ld",&num);
            Selectsort(stu,sumt,subject,n,descending);
            Searchbynumber(stu,n,sumt,subject,num,&rank);
            printf("The student you search ranks No.%-3d",rank);
            for(i=0;i<subject;i++)
            {
                printf("%-4d",stu[rank-1].score[i]);
            }
            printf("\n");
            break;

        case 9:
            /* 按姓名查询成绩 */
            printf("Please input the student' name you wanna search:");
            scanf("%s",&namestu);
            Selectsort(stu,sumt,subject,n,descending);
            Searchbyname(stu,n,&namestu,sumt,subject,&rank);
            printf("The student you search ranks No.%-3d",rank);
            for(i=0;i<subject;i++)
            {
                printf("%-4d",stu[rank-1].score[i]);
            }
            printf("\n");

            break;
        case 10:
            /* 统计各分数段人数 */
            Analysis(ex,good,mid,ok,notok,stu,subject,n);
            for(i=0;i<subject;i++)
            {
                printf("Subject %d:\n",i+1);
                printf("100~90:%-4.2f%%\n89~80:%-4.2f%%\n79~70:%-4.2f%%\n69~60:%-4.2f%%\n00~59:%-4.2f%%\n",
                        100*ex[i]/(float)n,100*good[i]/(float)n,100*mid[i]/(float)n,100*ok[i]/(float)n,100*notok[i]/(float)n);
            }
            break;

        case 11:
            /* 每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分 */

            for(i=0;i<n;i++)
            {
                printf("%-10ld%-10s",stu[i].number,stu[i].name);
                for(j=0;j<subject;j++)
                {
                    printf("%-4d",stu[i].score[j]);
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
void Read(STUDENT stu[],int n,int subject)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("Name of student%d:",i+1);
        scanf("%s",stu[i].name);
        printf("Number of student%d:",i+1);
        scanf("%ld",&stu[i].number);
        for(j=0;j<subject;j++)
        {
            printf("Subject%d:",j+1);
            scanf("%d",&stu[i].score[j]);
        }
    }
}

/* 函数功能:计算各科总分 */
void Calbycourse(STUDENT stu[],int n,int subject,int sum[6])
{
    int i,j;
    int temp=0;
    for(i=0;i<subject;i++)
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            temp+=stu[j].score[i];
        }
        sum[i]=temp;
    }
}

/* 函数功能:计算各学生总分 */
void Calbystu(STUDENT stu[],int n,int subject,int sumt[6])
{
    int i,j;
    int temp=0;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<subject;j++)
        {
            temp+=stu[i].score[j];
        }
        sumt[i]=temp;
    }
}

/* 升序\降序排列学生成绩 */
void Selectsort(STUDENT stu[],int sumt[6],int subject,int n,int (*compare)(int ,int))
{
    int i,j,temp1=0;
    STUDENT temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((*compare)(sumt[j],sumt[i]))
            {

                    temp=stu[j];
                    stu[j]=stu[i];
                    stu[i]=temp;
                    temp1=sumt[i];
                    sumt[i]=sumt[j];
                    sumt[j]=temp1;
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
void Sortbynumber(STUDENT stu[],int sumt[6],int subject,int n)
{
    int i,j;
    STUDENT temp;
    Calbystu(stu,n,subject,sumt);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(stu[j].number<stu[i].number)
            {
                temp=stu[j];
                stu[j]=stu[i];
                stu[i]=temp;
            }
        }
    }
}

/* 按学生姓名排序 */
void Sortbyname(STUDENT stu[],int n,int sumt[6],int subject)
{
    int i,j;
    STUDENT temp;
    Calbystu(stu,n,subject,sumt);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(stu[j].name,stu[i].name)<0)
            {
                temp=stu[j];
                stu[j]=stu[i];
                stu[i]=temp;
            }
        }
    }
}
/* 函数功能:按学号查询学生成绩及排名（先降序排列） */
void Searchbynumber(STUDENT stu[],int n,int sumt[6],int subject,long num,int *prank)
{
    int i=0;
    Selectsort(stu,sumt,subject,n,descending);
    while(stu[i].number!=num)
    {
        i++;
    }
    *prank=i+1;
}

/* 按名字查询学生成绩及排名（先降序排列）*/
void  Searchbyname(STUDENT stu[],int n,char *pnamestu,int sumt[6],int subject,int *prank)
{
    int i=0;
    Selectsort(stu,sumt,subject,n,descending);
    while(strcmp(pnamestu,stu[i].name)!=0)
    {
        i++;
    }
    *prank=i+1;
}

/* 统计各分数段人数 */
void Analysis(int ex[],int good[],int mid[],int ok[],int notok[],STUDENT stu[],int subject,int n) {
    int i, j;
    for (i = 0; i < subject; i++) {
        for (j = 0; j < n; j++) {

            if (stu[j].score[i] <= 100 && stu[j].score[i] >= 90) {
                ex[i]++;
            }
            if (stu[j].score[i] >= 80 && stu[j].score[i] <= 89) {
                good[i]++;
            }
            if (stu[j].score[i] >= 70 && stu[j].score[i] <= 79) {
                mid[i]++;
            }
            if (stu[j].score[i] >= 60 && stu[j].score[i] <= 69) {
                ok[i]++;
            }
            if (stu[j].score[i] >= 0 && stu[j].score[i] <= 59) {
                notok[i]++;
            }
        }
    }
}
