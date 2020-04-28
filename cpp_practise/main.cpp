#include <iostream>
#include "A.h"
int main()
{
    A *p = new A[10];

    for(int i = 0; i<10; i++)
    {
        p[i].set(i);
    }
    delete []p;
    return 0;
}
