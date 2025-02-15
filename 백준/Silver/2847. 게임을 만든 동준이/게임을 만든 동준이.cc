#include<bits/stdc++.h>
using namespace std;

vector<int>v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,num,count = 0;
    cin>>n;

    while (n--) {
        cin>>num;
        v.push_back(num);
    }

    for (int i = v.size()-1; i>= 1; i--) {
        if (v[i-1] >= v[i]) {
            while (v[i-1] >= v[i]) {
                v[i-1]--;
                count++;
            }
        }
    }
    cout<<count;
}