#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;
vector<string> str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, index = 0;
    cin >> n;
    cin.ignore();

    string s;
    while (n--) {
        getline(cin, s);
        int pos = s.find(' ');
        string name = s.substr(0, pos);
        string date = s.substr(pos + 1);
        str.push_back(name);
        string temp = "";
        vector<string> v;


        for (int i = 0; i < date.length(); i++) {
            if (date[i] == ' ') {
                if (temp.length() == 1) {
                    string s = "0";
                    temp = s + temp;
                }
                v.push_back(temp);
                temp = "";
            } else {
                temp += date[i];
            }
        }
        v.push_back(temp);

        string result = "";
        for (int i = v.size() - 1; i >= 0; i--) {
            result += v[i];
        }

        mp.insert({result, index++});
    }

    cout<<str[mp.rbegin()->second]<<'\n'<<str[mp.begin()->second];
}