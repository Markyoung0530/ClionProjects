#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int MakeNumber10(void);
int MakeNumber4(void);
int main()
{
    int a,b,c,j,w=0,rate;/*a,b Ϊ��������,c�������㷨��,eΪ��ȷ��,jΪѭ��������,wΪ��������,rateΪ��ȷ��*/
    float e,d;/*dΪ�û������Ĵ�*/
    char op;
    srand(time(NULL));
    for(j=0;j<=10;j++)
    {
        a=MakeNumber10();
        b=MakeNumber10();
        c=MakeNumber4();
        switch(c)
        {
            case 1:
                op = '+';
                e=a+b;
                break;
            case 2:
                op = '-';
                e=a-b;
                break;
            case 3:
                op = '*';
                e=a*b;
                break;
            case 4:
                op = '/';
                e=a/b;
                break;
        }
            printf("%d %c %d=",a,op,b);
            scanf("%f",&d);
            if(fabs(e-d)<=0.01)
            {
                printf("Right!\n");
            }
            if(fabs(e-d)>=0.01)
            {
                printf("You fail to work out this question\n");
                w++;
            }
    }
    rate =(10-w)*10;
    printf("Your accuracy is %d%%\n",rate);
    if(w<=2)  printf("You pass the test!!");
    else   printf("Sorry,you fail to pass this test.");
    return 0;
}

/*��������:����1~10�������*/
int MakeNumber10(void)
{
    int a;
    a=rand()%10+1;
    return a;
}


/*��������:����1~4�������*/
int MakeNumber4(void)
{
    int a;
    a=rand()%4+1;
    return a;
}
