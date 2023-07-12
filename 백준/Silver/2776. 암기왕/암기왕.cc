#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<int>s1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt;
    cin>>cnt;
    for(int x=0;x<cnt;x++){
        int n,m;
        cin>>n;
        for(int i=0;i<n;i++){
            int input;
            cin>>input;
            s1.insert(input);
        }
        cin>>m;
        for(int j=0;j<m;j++){
            int input;
            cin>>input;
            set<int>::iterator iter;
            iter=s1.find(input);
            if(iter==s1.end())
                cout<<"0"<<'\n';
            else
                cout<<"1"<<'\n';
        }
        s1.clear();
    }        
}