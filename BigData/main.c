#include <stdio.h>
#include <stdlib.h>
#define size 51
int main()
{
    int data[size]={0};                      /* 储存50位数，初始化为0，不使用data【0】 */
    int index=1;                             /* 数组元素个数，表示阶乘值的位数 */
    int n;                                   /* 准备计算的阶乘中的最大的数 */
    int i,j,k;
    data[1]=1;                               /* 初始化，令1!=1 */
    printf("Input n:");
    scanf("%d",&n);
    for(i=1;j<=n;i++)                        /* 计算1～n之间所有数的阶乘 */
    {
        for(j=1;j<=index;j++)                /* 计算阶乘i! */
        {
            data[j]=data[j]*i;               /* 每一个数字都乘以i */
        }
        for(k=1;k<index;k++)
        {
            if(data[k]>=10)                  /* 若阶乘值的每位数字大于或等于10，则进位 */
            {
                data[k+1]=data[k+1]+data[k]/10;/* 当前位向前进位 */
                data[k]=data[k]%10;          /* 进位后的值 */
            }
        }
        /* 单独处理最高位，若计算之后的最高位大于或等于10，则位数index加1 */
        while (data[index]>=10 && index<=size-1)
        {
            data[index+1]=data[index]/10;     /* 向最高位进位 */
            data[index]=data[index]%10;       /* 进位之后的值 */
            index++;                          /* 位数index加1 */
        }
        if(index<=size-1)                     /* 检验数组是否溢出，若未溢出，则打印阶乘值 */
        {
            printf("%d!=",i);
            for(j=index;j>0;j--)              /* 从最高位打印每一位阶乘值 */
            {
                printf("%d",data[j]);
            }
            printf("\n");
        }
        else                                   /* 若大于50，数组溢出，则提示错误信息 */
        {
            printf("Overflow!\n");
            exit(1);
        }
    }
    return 0;
}