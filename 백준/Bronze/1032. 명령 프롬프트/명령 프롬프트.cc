#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    cin.ignore();

    string s,result;
    for(int i=0;i<n;i++) {
        cin>>s;
        if (i==0)
            result = s;
        else {
            for (int i=0;i<s.length();i++) {
                if (s[i]!= result[i])
                    result[i] = '?';
            }
        }
    }

    cout<<result;
}