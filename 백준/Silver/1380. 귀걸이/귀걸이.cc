#include<bits/stdc++.h>
using namespace std;

int check[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, count = 1;;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        cin.ignore();
        map<int, string> mp;
        for (int i = 1; i <= n; i++) {
            string s;
            getline(cin, s);
            mp.insert({i, s});
            check[i] = 0;
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            int num;
            char a;
            cin >> num >> a;
            check[num]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (check[i] <2) {
                string name = mp[i];
                cout << count << " " << name << '\n';
                break;
            }
        }

        memset(check, 0, sizeof(int)*101);
        count++;
    }
}