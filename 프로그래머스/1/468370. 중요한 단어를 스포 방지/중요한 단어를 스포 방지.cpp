#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int n = message.size();

    vector<bool> spoiled(n, false);

    for (auto range : spoiler_ranges) {
        for (int i = range[0]; i <= range[1]; i++) {
            if (0 <= i && i < n) {
                spoiled[i] = true;
            }
        }
    }

    unordered_set<string> spoilerWords;
    unordered_set<string> normalWords;

    int i = 0;

    while (i < n) {
        if (message[i] == ' ') {
            i++;
            continue;
        }

        int start = i;
        bool hasSpoiler = false;

        while (i < n && message[i] != ' ') {
            if (spoiled[i]) {
                hasSpoiler = true;
            }
            i++;
        }

        string word = message.substr(start, i - start);

        if (hasSpoiler) {
            spoilerWords.insert(word);
        } else {
            normalWords.insert(word);
        }
    }

    int answer = 0;

    for (string word : spoilerWords) {
        if (normalWords.find(word) == normalWords.end()) {
            answer++;
        }
    }

    return answer;
}