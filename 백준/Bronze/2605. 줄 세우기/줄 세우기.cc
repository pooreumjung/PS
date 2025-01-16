#include <bits/stdc++.h>
using namespace std;

stack<int>s;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,number;
    cin >> n;

    for (int i=0;i<n;i++) {
        cin>>number;

        if (i==0) {
            s.push(i+1);
        }
        else {
            stack<int>s2;
            while (number--) {
                s2.push(s.top());
                s.pop();
            }
            s.push(i+1);
            while (!s2.empty()) {
                s.push(s2.top());
                s2.pop();
            }
        }
    }

    vector<int>v;
   while (!s.empty()) {
       v.push_back(s.top());
       s.pop();
   }
    for (int i=v.size()-1;i>=0; i--) {
        cout<<v[i]<<" ";
    }
}