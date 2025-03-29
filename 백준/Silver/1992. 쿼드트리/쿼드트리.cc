#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> video;

void quadTree(int x, int y, int size) {
    int first = video[x][y];
    bool isSame = true;

    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (video[i][j] != first) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        cout << first;
    } else {
        cout << "(";
        int newSize = size / 2;
        quadTree(x, y, newSize);                   // 왼쪽 위
        quadTree(x, y + newSize, newSize);         // 오른쪽 위
        quadTree(x + newSize, y, newSize);         // 왼쪽 아래
        quadTree(x + newSize, y + newSize, newSize); // 오른쪽 아래
        cout << ")";
    }
}

int main() {
    int n;
    cin >> n;
    video.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < n; ++j) {
            video[i][j] = line[j] - '0';
        }
    }

    quadTree(0, 0, n);
    return 0;
}
