#include<bits/stdc++.h>
using namespace std;

char arr[101][101];

int func(string s, string check) {

    int count =0;
    string temp = "";
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '.') {
            temp += s[i];
        }
        else { // 'X'를 만나면 누울 수 있는 자리가 있는지 check
            if (temp.find(check)!= string::npos) {
                count++;
            }
            temp = "";
        }
    }

    if (temp.find(check)!= string::npos) {
        count++;
    }

    return count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, heightCount = 0, widthCount = 0;
    string check = "..";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<string> height;
    vector<string> width;
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            s += arr[i][j];
        }
        width.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            s += arr[j][i];
        }
        height.push_back(s);
    }

    for (int i = 0; i < height.size(); i++) {
        heightCount += func(height[i], check);
    }

    for (int i = 0; i < width.size(); i++) {
        widthCount += func(width[i], check);
    }

    cout << widthCount << " " << heightCount;
}