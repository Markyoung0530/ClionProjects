#include <stdio.h>
#include <stdlib.h>
typedef struct date
{
    int year,month,day;
}DATE;
typedef struct student
{
    long stunumber;
    char name[10],sex;
    DATE birthday;
    int score[4];
}STUDENT;
int main()
{
    FILE *fp;
    int i,j,sum[30];
    STUDENT stu[30]={{100310121,"王刚",'M',{1991,5,19},{72,83,90,82}},
                     {100310122,"李小明",'M',{1992,8,20},{88,2,78,78}},
                     {100310123,"王丽红",'F',{1991,9,19},{98,72,89,66}},
                     {100310124,"陈莉莉",'F',{1992,3,22},{87,95,78,90}}
                    };
    fp=fopen("score,txt","w");
    if(fp==NULL)
    {
        printf("Fail to open a new file!\n");
        exit(1);
    }
    for(i=0;i<4;i++)
    {
        sum[i]=0;
        for(j=0;j<4;j++)
        {
            sum[i]+=stu[i].score[j];
        }
        fprintf(fp,"%10ld%10s%4c%6d/%02d/%02d%4d%4d%4d%4d%7.1f\n",
                stu[i].stunumber,stu[i].name,stu[i].sex,
                stu[i].birthday.year,stu[i].birthday.month,
                stu[i].birthday.day,stu[i].score[0],
                stu[i].score[1], stu[i].score[2],
                stu[i].score[3],sum[i]/4.0);
    }
    fclose(fp);
    return 0;
}