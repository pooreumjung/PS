#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,l,h;
    cin>>n>>l;

    vector<int> v;
    for(int i=0;i<n;i++) {
        cin>>h;
        v.push_back(h);
    }

    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++) {
        if (l<v[i])
            break;
        l++;
    }

    cout<<l;
}