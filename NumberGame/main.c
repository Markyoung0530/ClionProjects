#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int MakeNumber(void);

int main()
{
    int magic,n=0,c,u;
    static int k;
    magic=MakeNumber();
    if(magic==1)
    {
        for(;n<30;)
        {
            if((30-n)%3==1)  k=1;
            else if((30-n)%3==2)  k=2;
            else  k=MakeNumber();
            n=n+k;c=n;
            if(k==1)  printf("Computer give one number %d\n",n);
            if(k==2)  printf("Computer give two number %d,%d\n",n-1,n);
            if(n==30)  break;
            printf("Now it's your turn to give number,you want give 1 or 2 number(s)?");
            scanf("%d",&k);
            n=n+k;u=n;
            if(k==1)  printf("You give %d\n",n);
            if(k==2)  printf("You give %d,%d\n",n-1,n);
        }
        if(c==30)  printf("Computer win!!\n");
        if(u==30)  printf("Congratulations,you win!!\n");
    }
    if(magic==2)
    {
        for(;n<30;)
        {
            printf("You want give 1 or 2 number(s)?");
            scanf("%d",&k);
            n=n+k;u=n;
            if(k==1)  printf("You give %d\n",n);
            if(k==2)  printf("You give %d,%d\n",n-1,n);
            if((30-n)%3==1)  k=1;
            else if((30-n)%3==2)  k=2;
            else  k=MakeNumber();
            n=n+k;c=n;
            if(k==1)  printf("Computer give one number %d\n",n);
            if(k==2)  printf("Computer give two number %d,%d\n",n-1,n);
        }
        if(c==30)  printf("Computer win!!\n");
        if(u==30)  printf("Congratulations,you win!!\n");
    }
    return 0;
}


int MakeNumber(void)
{
    int magic;
    srand(time(NULL));
    magic = rand()%2+1;
    return magic;
}
