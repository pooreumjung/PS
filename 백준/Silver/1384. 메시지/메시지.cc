#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int groupNum = 0;
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            return 0;
        cin.ignore();

        string s;

        vector<string> messages;
        vector<string> names;

        for (int i = 0; i < n; i++) {
            getline(cin, s);
            int index = s.find(' ');
            string name = s.substr(0, index);
            string message = s.substr(index + 1, s.length());
            messages.push_back(message);
            names.push_back(name);
        }

        groupNum++;
        cout << "Group " << groupNum << '\n';

        for (int i = 0; i < n; i++) {
            string message = messages[i];
            string temp = "";
            for (int j = 0; j < messages[i].length(); j++) {
                if (message[j] == ' ')
                    continue;
                temp += message[j];
            }
            messages[i] = temp;
        }

        bool check = false;
        for (int i = 0; i < n; i++) {
            string message = messages[i];
            string B = names[i];
            int count = 0;
            for (int j = 0; j < message.length(); j++) {
                if (message[j] != ' ' && message[j] == 'N') {
                    check = true;
                    count = j + 1;
                    int index = i;
                    // 왼쪽으로 count수만큼 이동하기
                    while (count--) {
                        if (index == 0)
                            index = n - 1;
                        else
                            index--;
                    }
                    string A = names[index];
                    cout << A << " was nasty about " << B << '\n';
                }
            }
        }
        if (!check)
            cout<<"Nobody was nasty"<<'\n';
        cout<<'\n';
    }
}