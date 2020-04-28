#include <stdio.h>
int parition(int *A, int p, int r);
void swap(int *A, int x, int y);
int main() {
    int A[8] = {13,19,9,5,12,4,7,8};
    parition(A, 0, 7);
    return 0;
}

int parition(int *A, int p, int r)
{
    int x = A[r];
    int i = p-1;
    int j,temp;
    for(j = p;j < r;j++)
    {
        if(A[j] <= x)
        {
            i++;
            swap(A, i, j);
        }
    }
    swap(A, i+1, r);
    return i+1;
}

void swap(int *A, int x, int y)
{
    int temp;
    temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}