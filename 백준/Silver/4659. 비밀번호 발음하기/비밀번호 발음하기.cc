#include<bits/stdc++.h>
using namespace std;

bool func1(string s) { // 모음 여부 검사

    if (s.find('a') != string::npos)
        return true;
    if (s.find('e') != string::npos)
        return true;
    if (s.find('i') != string::npos)
        return true;
    if (s.find('o') != string::npos)
        return true;
    if (s.find('u') != string::npos)
        return true;
    return false;
}

bool func2(string s) { // 연속된 자음 or 모음 검사, 길이가 3보다 작으면 무조건 true

    if (s.length()<=2)
        return true;
    for (int i=0; i<s.length()-2; i++) {
        if (s[i] =='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
            if (s[i+1] =='a' || s[i+1]=='e' || s[i+1]=='i' || s[i+1]=='o' || s[i+1]=='u') {
                if (s[i+2] =='a' || s[i+2]=='e' || s[i+2]=='i' || s[i+2]=='o' || s[i+2]=='u') {
                    return false;
                }
            }
        }
        else if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
            if (s[i+1] != 'a' && s[i+1] != 'e' && s[i+1] != 'i' && s[i+1] != 'o' && s[i+1] != 'u') {
                if (s[i+2] != 'a' && s[i+2] != 'e' && s[i+2] != 'i' && s[i+2] != 'o' && s[i+2] != 'u') {
                    return false;
                }
            }
        }
    }
    return true;
}

bool func3(string s) { // 같은 글자 연속 여부 검사, 단 ee와 oo는 허용
    for (int i=0; i<s.length()-1; i++) {
        if (s[i] == s[i+1]) {
            string temp = string(1, s[i]) + s[i + 1];
            if (temp != "ee" &&  temp!="oo")
                return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    while (true) {
        cin>>s;
        if (s == "end")
            break;

        bool check1 = func1(s);
        if (!check1) {
            cout<<"<"<<s<<">"<<" "<<"is not acceptable."<<'\n';
            continue;
        }

        bool check2 = func2(s);
        if (!check2) {
            cout<<"<"<<s<<">"<<" "<<"is not acceptable."<<'\n';
            continue;
        }

        bool check3 = func3(s);
        if (!check3) {
            cout<<"<"<<s<<">"<<" "<<"is not acceptable."<<'\n';
            continue;
        }

        cout<<"<"<<s<<">"<<" "<<"is acceptable."<<'\n';
    }
}