#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define NAME_LEN 15
#define M 6

typedef struct student
{
    long studentID;         /*学生学号*/
    char studentName[10];   /*学生姓名*/
    int score[M];           /*学生分数*/
    int sum;                /*各门总分*/
    float aver;             /*平均分*/
}STUDENT;

void Readscore(STUDENT stu[],int m,int n);

void Aver(STUDENT stu[],int n,int m,int sum_course[],float aver_course[]);

int Ascending(int a,int b);

int Descending(int a,int b);

int Ascending_long(long a,long b);

int Search_number(int number,STUDENT stu[],int n);

void Print(STUDENT stu[],int m,int n);

void List(int sum_course[],float aver_course[],STUDENT stu[],int a,int b);

void Score_sort(STUDENT stu[],int n,int (*compare)(int ,int ));

void Number_sort(STUDENT stu[],int m,int n,int (*compare)(long ,long ));

void Name_sort(STUDENT stu[],int m,int n);

int Search_name(char str[NAME_LEN],STUDENT stu[],int n);

void Analysis(int m,int n,STUDENT stu[],int ex[],int good[],int mid[],int ok[],int notok[]);

void Swap_stu(STUDENT *stu1,STUDENT *stu2);

void Menu();

void Writeto_File(STUDENT student[],int n,int m);

void Read_from_File(STUDENT student[],int *n,int *m);



int main()
{
    int m=0,n=0,choice,ex[M]={0},good[M]={0},mid[M]={0},ok[M]={0},notok[M]={0};/* m课程数，n人数 */
    int ret;
    float aver_course[N];
    int sum_course[N]={0};
    int wanted_number,i,j;
    float rate1[M],rate2[M],rate3[M],rate4[M],rate5[M];
    char wanted_name[NAME_LEN];
    STUDENT stu[N];
    for(j=0;j<n;j++)
    {
        for(i=0;i<m;i++)
        {
            stu[j].score[i]=0;
        }
    }


    Menu();

    scanf("%d",&choice);
    while(choice!=1&&choice!=13)
    {
        while(getchar()!='\n');
        printf("Please choose 1 or 13 first!\n");
        printf("Try again:");
        scanf("%d",&choice);
    }

    if(choice==1)
    {
        printf("Please input the number of students and courses:");
        scanf("%d%*c%d",&n,&m);
        Readscore(stu,m,n);
        Aver(stu,n,m,sum_course,aver_course);
    }

    else if(choice==13)
    {
        Read_from_File(stu,&n,&m);
        Aver(stu,n,m,sum_course,aver_course);
    }

    do{
        printf("\n");
        printf("Your choice:");
        ret=scanf("%d",&choice);
        while(ret!=1)
        {
            printf("Input wrong!Try again:");
            ret=scanf("%d",&choice);
        }
        switch (choice)
        {
            case 2:
            {
                printf("The total and average score of every course:\n");
                for(i=0;i<m;i++)
                {
                    printf("%d  %f\n",sum_course[i],aver_course[i]);
                }
                break;
            }
            case 3:
            {
                printf("The total and average score of every student:\n");
                for(i=0;i<n;i++)
                {
                    printf("%d  %f\n",stu[i].sum,stu[i].aver);
                }
                break;
            }
            case 4:
            {
                Score_sort(stu,n,Descending);
                Print(stu,m,n);
                break;
            }
            case 5:
            {
                Score_sort(stu,n,Ascending);
                Print(stu,m,n);
                break;
            }
            case 6:
            {
                Number_sort(stu,m,n,Ascending_long);
                Print(stu,m,n);
                break;
            }
            case 7:
            {
                Name_sort(stu,m,n);
                Print(stu,m,n);
                break;
            }
            case 8:
            {
                Score_sort(stu,n,Descending);
                printf("Please input the number you want:");
                scanf("%d",&wanted_number);
                i=Search_number(wanted_number,stu,n);
                if(i==-1)
                    printf("Not found!\n");
                else
                {
                    printf("The rank is %d\n",i+1);
                    printf("The wanted scores are:");
                    for(j=0;j<m;j++)
                    {
                        printf("%4d ",stu[i].score[j]);
                    }
                }
                break;
            }
            case 9:
            {
                Score_sort(stu,n,Descending);
                printf("Please input the name you want:");
                getchar();
                gets(wanted_name);
                i=Search_name(wanted_name,stu,n);
                if(i==-1)
                    printf("Not found!\n");
                else
                {
                    printf("The rank is %d\n",i+1);
                    printf("The wanted scores are:");
                    for(j=0;j<m;j++)
                    {
                        printf("%4d ",stu[i].score[j]);
                    }
                }
                break;
            }
            case 10:
            {
                Analysis(m,n,stu,ex,good,mid,ok,notok);
                for(i=0;i<m;i++)
                {
                    rate1[i]=(float)ex[i]/n;  rate2[i]=(float)good[i]/n;  rate3[i]=(float)mid[i]/n;
                    rate4[i]=(float)ok[i]/n;  rate5[i]=(float)notok[i]/n;

                    printf("course %d People:%d %d %d %d %d\n",i,ex[i],good[i],mid[i],ok[i],notok[i]);

                    printf("course %d Rate:%f %f %f %f %f\n",i,rate1[i],rate2[i],rate3[i],rate4[i],rate5[i]);
                }
                break;
            }
            case 11:
            {
                Score_sort(stu,n,Descending);
                List(sum_course,aver_course,stu,m,n);
                break;
            }
            case 12:
            {
                Writeto_File(stu,n,m);
                break;
            }
            case 13:
            {
                Read_from_File(stu,&n,&m);
                Print(stu,m,n);
            }
            default:
                break;
        }
    }while(choice!=0);
    return 0;
}


void Readscore(STUDENT stu[],int m,int n)/*输入学生信息*/
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("Student%d's ID:",i+1);
        scanf("%ld",&stu[i].studentID);
        printf("Student%d's name:",i+1);
        scanf("%s",stu[i].studentName);
        printf("Input the scores of every course:\n");
        for(j=0;j<m;j++)
        {
            printf("Score%d:",j+1);
            scanf("%d",&stu[i].score[j]);
        }
    }
}


void Aver(STUDENT stu[],int n,int m,int sum_course[],float aver_course[])/*分别对学生与课程求总分和平均分*/
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum_course[i]+=stu[j].score[i];
        }
        aver_course[i]=(float)sum_course[i]/n;
    }
    for(i=0;i<n;i++)
    {
        stu[i].sum=0;
        stu[i].aver=0;
        for(j=0;j<m;j++)
        {
            stu[i].sum+=stu[i].score[j];
        }
        stu[i].aver=(float)stu[i].sum/m;
    }
}

void Score_sort(STUDENT stu[],int n,int (*compare)(int ,int ))/* 按成绩升序/降序排列 */
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((*compare)(stu[j].sum,stu[k].sum))  k=j;
        }
        if(k!=i)
        {
            Swap_stu(&stu[i],&stu[k]);
        }
    }
}

void Number_sort(STUDENT stu[],int m,int n,int (*compare)(long ,long ))/*调用函数指针compare指向的函数对学号进行排序*/
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((*compare)(stu[j].studentID,stu[k].studentID))  k=j;
        }
        if(k!=i)
        {
            Swap_stu(&stu[i],&stu[k]);
        }
    }
}

void Name_sort(STUDENT stu[],int m,int n)/*对姓名进行排序*/
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(strcmp(stu[j].studentName,stu[k].studentName)<0) k=j;
        }
        if(k!=i)
        {
            Swap_stu(&stu[i],&stu[k]);
        }
    }
}

int Ascending(int a,int b)/*使数据升序排序*/
{
    return a<b;
}

int Descending(int a,int b)/*使数据降序排序*/
{
    return a>b;
}

int Ascending_long(long a,long b)
{
    return a<b;
}


int Search_number(int number,STUDENT stu[],int n)/*按值在数组中查找某个数，若找到，返回下标值；否则返回-1*/
{
    int i;
    for(i=0;i<n;i++)
    {
        if(number==stu[i].studentID)  return i;
    }
    return -1;
}

void Analysis(int m,int n,STUDENT stu[],int a[],int b[],int c[],int d[],int e[])/*统计每门课程各分数段人数*/
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(stu[i].score[j]>=90&&stu[i].score[j]<=100)         a[i]++;
            else if(stu[i].score[j]>=80&&stu[i].score[j]<90  )    b[i]++;
            else if(stu[i].score[j]>=70&&stu[i].score[j]<80  )    c[i]++;
            else if(stu[i].score[j]>=60&&stu[i].score[j]<70  )    d[i]++;
            else                                                  e[i]++;
        }
    }
}

void Print(STUDENT stu[],int m,int n)/*打印学生分数表*/
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("%ld  %s",stu[i].studentID,stu[i].studentName);
        for(j=0;j<m;j++)
        {
            printf(" %d",stu[i].score[j]);
        }
        printf(" %d",stu[i].sum);
        printf("\n");
    }
}

void List(int sum_course[],float aver_course[],STUDENT stu[],int m,int n)/*打印学生学号，成绩，姓名以及学生人数和平均分*/
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("%ld  %s\n",stu[i].studentID,stu[i].studentName);
        printf("Every course:");
        for(j=0;j<m;j++)
        {
            printf("%d  ",stu[i].score[j]);
        }
        printf("\n");
        printf("Sum and aver:%d  %f\n",stu[i].sum,stu[i].aver);
    }
    printf("Course sum and aver:");
    for(j=0;j<m;j++)
    {
        printf("course No.%d  %d  %f\n",j+1,sum_course[j],aver_course[j]);
    }
}


int Search_name(char str[],STUDENT stu[],int n)/*按名字查找分数，找到则返回下标值，否则返回-1*/
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(str,stu[i].studentName)==0)  return i;
    }
    return -1;
}

void Swap_stu(STUDENT *stu1,STUDENT *stu2)
{
    STUDENT temp;
    temp=*stu1;
    *stu1=*stu2;
    *stu2=temp;
}

void Menu()
{
    printf("1.Input record\n");
    printf("2.Calculate total & average score of every course\n");
    printf("3.Calculate total & average score of every student\n");
    printf("4.Sort in descending order by total score of every student\n");
    printf("5.Sort in ascending order by total score of every student\n");
    printf("6.Sort in ascending order by number\n");
    printf("7.Sort in dictionary order by name\n");
    printf("8.Search by number\n");
    printf("9.Search by name\n");
    printf("10.Statistic analysis for every course\n");
    printf("11.List record\n");
    printf("12.Write to a file\n");
    printf("13.Read from a file\n");
    printf("0.Exit\n");
    printf("Enter your choice:");
}

void Writeto_File(STUDENT student[],int n,int m)
{
    FILE *fp;
    int i,j;
    fp=fopen("student.txt","w");
    if(fp==NULL)
    {
        printf("Failure to open!\n");
        exit(0);
    }
    fprintf(fp,"%d\t%d\n",n,m);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%ld  %s",student[i].studentID,student[i].studentName);
        for(j=0;j<m;j++)
        {
            fprintf(fp,"  %d  ",student[i].score[j]);
        }
        fprintf(fp,"%d  %f\n",student[i].sum,student[i].aver);
    }
    fclose(fp);
}

void Read_from_File(STUDENT student[],int *n,int *m)
{
    FILE *fp;
    int i,j;
    fp=fopen("student.txt","r");
    if(fp==NULL)
    {
        printf("Failure to open!\n");
        exit(0);
    }
    fscanf(fp,"%d\t%d",n,m);
    for(i=0;i<*n;i++)
    {
        fscanf(fp,"%ld  %s",&student[i].studentID,student[i].studentName);
        for(j=0;j<*m;j++)
        {
            fscanf(fp,"  %d  ",&student[i].score[j]);
        }
        fscanf(fp,"%d  %f\n",&student[i].sum,&student[i].aver);
    }
    fclose(fp);
}