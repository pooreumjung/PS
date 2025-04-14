#include<bits/stdc++.h>
using namespace std;


bool isTeamName(string s) {

    // 팀명은 10글자 이하
    if (s.length()>10)
        return false;

    int upperCount=0, lowerCount=0,numCount=0;
    for (int i=0;i<s.length();i++) {
        if (s[i]>='A' && s[i]<='Z')
            upperCount++;
        else if (s[i]>='a' && s[i]<='z')
            lowerCount++;
        else if (s[i]>='0' && s[i]<='9')
            numCount++;
    }

    // 팀명이 숫자로만 이루어지면 안됨
    if (numCount == s.length())
        return false;

    // 대문자가 소문자보다 적어야 함
    if (upperCount > lowerCount)
        return false;
    return true;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,ans=0;
    cin>>n;

    while (n--) {
        string s;
        cin>>s;

        if (isTeamName(s)) {
            cout<<s;
            return 0;
        }
    }
}