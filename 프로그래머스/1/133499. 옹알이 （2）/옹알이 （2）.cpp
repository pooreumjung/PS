#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> sounds = {"aya", "ye", "woo", "ma"};

    for (string word : babbling) {
        int idx = 0;
        string prev = "";
        bool possible = true;

        while (idx < word.length()) {
            bool matched = false;

            for (string sound : sounds) {
                // 현재 idx 위치에서 sound가 시작하는지 확인
                if (word.find(sound, idx) == idx) {
                    // 같은 발음 연속이면 불가능
                    if (prev == sound) {
                        possible = false;
                        break;
                    }

                    prev = sound;
                    idx += sound.length();
                    matched = true;
                    break;
                }
            }

            // 어떤 발음도 현재 위치에서 매칭 안 됨
            if (!matched) {
                possible = false;
                break;
            }

            if (!possible) break;
        }

        if (possible) answer++;
    }

    return answer;
}