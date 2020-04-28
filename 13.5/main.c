#include <stdio.h>
#define N 80
int Collect(const char *sourcename,char const *goalname);
int main()
{
    char sourcename[N],goalname[N];
    printf("Please input source file name:");
    scanf("%s",sourcename);
    printf("Please input goal source file name:");
    scanf("%s",goalname);
    if(Collect(sourcename,goalname))
    {
        printf("Succeed to collect!\n");
    }
    else
    {
        printf("Fail to collect!\n");
    }
    return 0;
}

int Collect(const char *sourcename,char const *goalname)
{
    FILE *fpsource=NULL,*fpgoal=NULL;
    int ch,m=1;
    if((fpsource=fopen(sourcename,"r"))==NULL)
    {
        m=0;
    }
    if((fpgoal=fopen(goalname,"a"))==NULL)
    {
        m=0;
    }
    while((ch=fgetc(fpsource))!=EOF)
    {
        {
            if(fputc(ch,fpgoal)==EOF)
            {
                m=0;
            }
        }
    }
    fflush(fpgoal);
    if(fpsource!=NULL)
    {
        fclose(fpsource);
    }
    if(fpgoal!=NULL)
    {
        fclose(fpgoal);
    }
    return m;
}