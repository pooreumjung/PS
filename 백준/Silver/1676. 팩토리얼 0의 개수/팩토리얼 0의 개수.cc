#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int exp_two=0,exp_five=0;
    int ans = 0;
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int tmp = i;
        if(tmp%5==0) 
        {
            while(tmp%5==0)
            {
                exp_five++;
                tmp/=5;
            }
            /*
             while(tmp)
            {
                if(tmp%5==0) exp_five++;
                tmp/=5;
            }
            */
        }

        else if(tmp%2==0) 
        {
            while(tmp%2==0)
            {
                exp_two++;
                tmp/=2;
            }
            /*
            while(tmp)
            {
                if(tmp%2==0) exp_two++;
                tmp/=2;
            }
            */
        }
    }

    if(exp_two < exp_five) ans = exp_two;
    else ans = exp_five;

    cout<<ans;

    return 0;
}