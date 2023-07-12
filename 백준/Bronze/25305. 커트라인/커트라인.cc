#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>arr;
int main(){
    int a,b;
  cin>>a>>b;
    for(int x=0;x<a;x++){
        int in;
        cin>>in;
        arr.push_back(in);
    }
    sort(arr.begin(),arr.end());
    cout<<arr[arr.size()-b];
   
    
}