#include<bits/stdc++.h>
using namespace std;

vector<int>v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,num,sum =0;
    cin>>n;

    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int> >q;

    for(int i=0;i<n;i++) {
        cin>>num;
        pq.push(num);
    }

    for(int i=0;i<n;i++) {
        cin>>num;
        q.push(num);
    }


    while (!pq.empty() && !q.empty()) {
        sum += pq.top() * q.top();
        pq.pop();
        q.pop();
    }

    cout<<sum;
    
}