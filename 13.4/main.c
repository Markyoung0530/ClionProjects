#include <stdio.h>
#define N 80
int Copy(const char *aname,const char *bname);
int main()
{
    char sourceFileName[N];
    char goalFileName[N];
    printf("Please input source filename:");
    scanf("%s",sourceFileName);
    printf("Please input goal filename:");
    scanf("%s",goalFileName);
    if(Copy(sourceFileName,goalFileName))
    {
        printf("Succeed to copy!\n");
    }
    else
    {
        printf("Fail to copy!\n");
    }
    return 0;
}

int Copy(const char *aname,const char *bname)
{
    FILE *fpsource=NULL,*fpgoal=NULL;
    int ch,m=1;
    if((fpsource=fopen(aname,"r"))==NULL)
    {
        m=0;
    }
    if((fpgoal=fopen(bname,"w"))==NULL)
    {
        m=0;
    }
    while((ch=fgetc(fpsource))!=EOF)
    {
        if(fputc(ch,fpgoal)==EOF)
        {
            m=0;
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