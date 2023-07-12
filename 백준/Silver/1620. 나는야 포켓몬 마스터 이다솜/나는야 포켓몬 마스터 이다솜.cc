#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<string, int>arr;
vector<string>input;
int main(){
    ios_base::sync_with_stdio(false);     
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        string str;
        cin>>str;
        input.push_back(str);          
        arr.insert({str,x+1});        
    }
    for(int x=0;x<m;x++){
        string st;
        cin>>st;
        if (st[0] >= '0' && st[0] <= '9') {
            int index=stoi(st);
            cout<<input[index-1]<<'\n';                                                            ;
            }
        else
            cout<<arr.find(st)->second<<'\n';            
    }   
}