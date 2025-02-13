#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    if (s.find('0')==string::npos) { // 0이 없으면 30의 배수를 만들 수 없음
        cout<<-1;
        return 0;
    }

    int sum=0;
    for (int i=0;i<s.length();i++) { // 합 구하기
        sum+=s[i]-'0';
    }

    if (sum!=0&& sum %3 !=0) { // 각 자릿수의 합이 3의 배수가 아니면 30의 배수가 아님
        cout<<-1;
        return 0;
    }

    sort(s.begin(),s.end(), greater<char>());
    cout<<s;

}