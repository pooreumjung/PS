#include<iostream>
#include<vector>
#include<string>
using namespace std;

int failTable[1000001];

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    string parent, pattern;
    getline(cin, parent);
    getline(cin, pattern);
    int parentSize = parent.length(), patternSize = pattern.length();

    // 실패함수 전처리
    fill(failTable, failTable + 1000001, 0);
    for (int i = 1, j = 0; i < patternSize; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = failTable[j - 1];
        if (pattern[i] == pattern[j]) 
            failTable[i] = ++j;
    }

    // KMP
    vector<int> ans;
    for (int i = 0, j = 0; i < parentSize; i++) {
        while (j > 0 && parent[i] != pattern[j]) j = failTable[j - 1];
        if (parent[i] == pattern[j]) {
            if (j == patternSize - 1) {
                ans.push_back(i - patternSize + 2);
                j = failTable[j];
            }
            else
                j++;
        }
    }

    // 출력
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it << '\n';
}
