#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int MakeNumber(void);
int main()
{
    srand(time(NULL));
    int a,b,c,i,w=0,j;/*a,b Ϊ�������,cΪѧ�������Ĵ�,iΪѭ�����Ʋ���,wΪ��������*/
    int accuracy;
    for(j=1;j<=10;j++)
    {
        a=MakeNumber();
        b=MakeNumber();
        for(i=1;i<=3;i++)
        {
            printf("%d * %d =",a,b);
            scanf("%d",&c);
            if(c==a*b)  break;
        }
        if(c!=a*b)
        {
            printf("You fail to work out this question\n");
            w++;
        }
    }
    accuracy=(10-w)*10;
    printf("Your accuracy is %d%%\n",accuracy);
    if(w<=2)   printf("You pass it!");
    else  printf("Sorry you fail in the test.");
    return 0;
}


/*��������:���������*/
int MakeNumber(void)
{
    int a;
    a=rand()%10+1;
    return a;
}
