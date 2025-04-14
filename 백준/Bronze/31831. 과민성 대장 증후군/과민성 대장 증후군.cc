#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,ans=0;
    cin>>n>>m;

    long long x, stressSum=0;

    for(int i=0;i<n;i++) {
        long long x;
        cin>>x;

        stressSum+=x;
        if (stressSum<0)
            stressSum=0;
        if (stressSum>=m)
            ans++;
    }
    cout<<ans;
}