#include<iostream>
using namespace std;
int find(int n){
    int sum,flag=0,ind=0;
    for(int x=1;x<n;x++){
        sum=x;
        int d=x;
        while(d>0){
           sum+=d%10; 
           d/=10; 
        }
        if(sum==n){
            flag=1;
            ind=x;
            break;
        }            
    }
    if(flag==1)
        return ind;
    else
        return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int d=find(n);
    cout<<d;
}