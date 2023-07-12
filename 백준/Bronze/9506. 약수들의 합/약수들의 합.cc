#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
int find(int input){
    int cnt=0,flag=0;
    for(int x=1;x<=input/2;x++){
        if(input%x==0){
            arr.push_back(x);
            cnt+=x;
            }
    }
    if(cnt==input)
        flag=1;
    else
        flag=0;
    return flag;
}
int main(){
    while(1){
        int a;
        cin>>a;
        if(a==-1)
            break;
        int flag=find(a);
        if(flag==0)
            cout<<a<<" is NOT perfect."<<endl;
        else{
            cout<<a<<" = ";
            for(int x=0;x<arr.size();x++){
                if(x==arr.size()-1)
                    cout<<arr[x]<<endl;
                else
                    cout<<arr[x]<<" + ";               
                }
            }
        arr.clear();
    }    
}