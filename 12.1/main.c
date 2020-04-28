#include <stdio.h>

int main()
{
    typedef struct date
    {
        int year;
        int month;
        int day;
    }DATE;
    typedef struct profession
    {
        char college[10];
        char title[10];
        char post[10];
    }PROFESSION;
    typedef struct student
    {
        char name[10];
        char sex[1];
        DATE birthday;
        PROFESSION profession;
    }STUDENT;
    return 0;
}