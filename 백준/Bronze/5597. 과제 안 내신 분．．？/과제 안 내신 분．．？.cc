#include<iostream>
using namespace std;
int arr[31];
int main(){
    for(int x=0;x<28;x++){
        int a;
        cin>>a;
        arr[a]=1;
    }
    for(int x=1;x<31;x++){
        if(arr[x]!=1)
            cout<<x<<endl;
    }
    
}