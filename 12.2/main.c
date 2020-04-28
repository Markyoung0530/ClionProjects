#include <stdio.h>

typedef struct time
{
    int hour;
    int minute;
    int second;
}TIME;
void Delay()
{
    long t;
    for(t=0;t<683000000;t++);
}
void Update(struct time *pt)
{
        pt->second++;
        if (pt->second == 60)
        {
            pt->second = 0;
            pt->minute++;
        }
        if (pt->minute == 60)
        {
            pt->minute = 0;
            pt->hour++;
        }
        if (pt->hour == 24)
        {
            pt->hour = 0;
        }
}
int main()
{
    int i;
    TIME time={0,0,0};
    for(i=0;i<1000000;i++)
    {
        Update(&time);
        printf("%-3d:%-3d:%-3d\n",time.hour,time.minute,time.second);
        Delay();
    }
    return 0;
}