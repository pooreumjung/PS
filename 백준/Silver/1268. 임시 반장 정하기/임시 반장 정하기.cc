#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > arr;

int checkSameClass(int num, int size) {
    int test = 5, index = 0;
    set<int> s;
    while (test--) {
        int value = arr[num][index];
        for (int i = 0; i < size; i++) {
            if (i == num)
                continue;
            if (arr[i][index] == value)
                s.insert(i);
        }
        index++;
    }

    return s.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, max = 0, result;
    cin >> n;

    arr.resize(n, vector<int>(10));
    bool check = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int count = checkSameClass(i, n);
        if (count > max) {
            max = count;
            result = i + 1;
            check = true;
        }
    }

    if (!check)
        cout << 1;
    else
        cout << result;
}