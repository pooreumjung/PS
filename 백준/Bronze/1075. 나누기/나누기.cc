#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,f;
    cin>>n>>f;
    int r=n%100;
    n=n-r;
    for(int i=0;i<100;i++)
    {
        if(n%f==0)break;
        n+=1;
    }
    int res=n%100;
    if(res/10==0)printf("0");
    printf("%d",res);
    return 0;
}