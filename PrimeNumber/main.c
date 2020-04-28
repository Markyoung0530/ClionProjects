#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,j,m,find=0;
    printf("Number:180110416\n");
    printf("Subject No.3 - program No.1.1\n");
    printf("Please input m:");
    scanf("%d",&m);
    if(m<1)
    {
        do{
            printf("Error!\nInput again:");
            scanf("%d",&m);
        }while(m<1);
    }
    if(m==1)         printf("1 is not a prime number!");
    if(m==2||m==3)   printf("It is a prime number!\n");
    else      /*  m为非123的正整数时 */
    {
        for(i=2;i<=(int)(sqrt(m));i++)
        {
            if(m%i==0)     /*  如果可以分解  */
            {
                find=1;
                printf("%d=%d",m,i);
                m=m/i;
                break;
            }
        }
        if(find==0)/* 如果是素数（不能分解） */
        {
            printf("It is a prime number!\n");
        }
        else/* 如果不是素数 */
        {
            for(j=2;j<m+1;j++)
            {
                if(m%j==0)
                {
                    do{
                        m=m/j;
                        printf("*%d",j);
                    }while(m%j==0);
                }
            }
        }
    }
    return 0;
}