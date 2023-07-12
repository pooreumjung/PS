#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
queue<int>q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,temp=0;
    cin>>n;
    for(int x=1;x<=n;x++)
         q.push(x);
    while(1){
        temp=q.front();
        cout<<temp<<" ";
        q.pop();
        if(q.empty())
            break;
        int d=q.front();
        q.push(d);
        q.pop();
    }
    
}