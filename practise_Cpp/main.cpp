#include <iostream>
#define fault -1
using namespace std;
int coins(const int c[], int bmax, int amount);
int main()
{
    int c[2] = {2,5};
    coins(c,2,6);
    return 0;
}

int coins(const int c[],int bmax,int amount)
{
    int i=0,x=0,temp=0;
    int* out=(int*)malloc(sizeof(int)* (amount+1));
    for(i=0;i<amount+1;i++)
    {
        for(x=0;x<bmax;x++){
            temp=i-c[x];
            if(temp==0){
                out[i]=1;
            }
            else if(temp>0){
                if(out[temp]>=0){
                    if(out[i]>=out[temp]+1){
                        out[i]=out[temp]+1;
                    }
                }
                else if(out[temp] == fault){
                    out[i] = fault;
                }
            }
        }
    }
    cout << out[amount] << endl;
}
