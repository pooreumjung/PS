#include<iostream>
using namespace std;
int main(){
    int sum=0;
    int a,num;
    cin>>a;
    cin>>num;
    for(int x=0;x<num;x++){
        int price,n;
        cin>>price>>n;
        sum+=price*n;
    }
    if(sum==a)
        cout<<"Yes";
    else
        cout<<"No";
    
    
    
    
    
}