#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string doc, word;
    getline(cin, doc);
    getline(cin, word);

    int pos = doc.find(word), count = 0;
    while (pos != string::npos) {
        count++;
        pos = doc.find(word, pos + word.length());
    }

    cout << count;
}