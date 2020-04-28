#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int MakeNumber(void);
typedef struct cards
{
    char suit[10];
    char face[6];
}CARD;

int main()
{
    CARD card[54+1];
    char f[][6]={"A","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    int i,j,k=0,magic=0;
    for(i=0;i<54;i++)
    {
        strcpy(card[i].face,"NULL");
    }
    for(i=0;i<54;i++)
    {
        if(i%4==0)
            strcpy(card[i].suit,"Spades");
        if(i%4==1)
            strcpy(card[i].suit,"Hearts");
        if(i%4==2)
            strcpy(card[i].suit,"Clubs");
        if(i%4==3)
            strcpy(card[i].suit,"Diamonds");
    }
    for(i=0,k=0;i<54;i=i+4,k++)        /* 54张牌 */
    {

            for(j=i;j<i+4;j++)  /* 四个不同的花色分给同一个牌面 */
            {
                strcpy(card[j].face,f[k]);
            }

    }


    srand((unsigned int)time(NULL));    /* 洗牌 */
    for(i=0;i<53;i++)
    {
        for(j=i+1;j<54;j++)
        {
            magic=MakeNumber();
            if(magic==1)
            {
                card[54]=card[j];
                card[j]=card[i];
                card[i]=card[54];
            }
        }
    }
    for(i=0;i<54;i++)
    {
        printf("No.%-4d suit:%-9s face:%-4s\n",i+1,card[i].suit,card[i].face);
    }
    return 0;
}

/* 产生随机数 */
int MakeNumber(void)
{
    int magic;
    magic=rand() % 2;
    return magic;
}
