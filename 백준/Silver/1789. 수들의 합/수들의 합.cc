#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,count=0,sum=0;
    cin>>n;

    for(int i=1;i<=1000000;i++) {
        sum+=i;
        count++;
        if (n == sum)
            break;
        if (sum >n) {
            count--;
            break;
        }
    }
    cout<<count;
}