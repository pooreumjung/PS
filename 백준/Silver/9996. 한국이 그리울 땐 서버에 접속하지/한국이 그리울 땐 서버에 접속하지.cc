#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    string pattern, s;
    cin>>pattern;

    int index = pattern.find('*');

    string start = pattern.substr(0,index);
    string end = pattern.substr(index+1);
    int startLen = start.length();
    int endLen = end.length();
    
    while (n--) {
        cin>>s;
        if (s.length() < startLen+endLen) {
            // 최소 패턴의 길이와는 같아야함
            cout<<"NE"<<'\n';
            continue;
        }
        string s1 = s.substr(0,startLen);
        string s2 = s.substr(s.length()-endLen,endLen);
        if (s1 != start || s2 != end) {
            // 다르다면 불가능
            cout<<"NE"<<'\n';
            continue;
        }
        cout<<"DA"<<'\n';
    }
}