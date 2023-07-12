#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a1,a2,g,n,flag=1;
    cin>>a1>>a2>>g>>n;
    for(int x=n;x<=100;x++){
        if(a1*x+a2<g*x){
            flag=0;
            break;
        }
    }
    if(flag==1)
        cout<<1;
    else
        cout<<0;
}