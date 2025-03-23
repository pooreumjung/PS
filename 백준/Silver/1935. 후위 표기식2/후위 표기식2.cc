#include <bits/stdc++.h>
using namespace std;

stack<char> myStack;
deque<double>dq;
double arr[26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);  // 소수점 아래 둘째 자리까지 고정

    int n;
    cin>>n;

    string s;
    cin>>s;

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    for(int i=0;i<s.length();i++) {
        char c = s[i];
        if(c>='A' && c<='Z') {
            dq.push_back(arr[c-'A']);
        }
        else {
            double temp;
            double op2 = dq.back();
            dq.pop_back();
            double op1 = dq.back();
            dq.pop_back();

            switch(c) {
                case '*' :
                    temp=op1*op2;
                    break;
                case '/' :
                    temp=op1/op2;
                    break;
                case '+' :
                    temp=op1+op2;
                    break;
                case '-' :
                    temp=op1-op2;
                    break;
            }
            dq.push_back(temp);
        }

    }
    cout << dq.front();
}