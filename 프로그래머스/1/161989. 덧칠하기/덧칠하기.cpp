#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int paintedUntil = 0;

    for (int s : section) {
        if (s > paintedUntil) {
            answer++;
            paintedUntil = s + m - 1;
        }
    }

    return answer;
}