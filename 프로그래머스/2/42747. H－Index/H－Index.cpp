#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());

    int n = citations.size();
    int answer = 0;

    for (int i = 0; i < n; i++) {
        int h = n - i; // 현재 위치부터 끝까지 논문 개수

        if (citations[i] >= h) {
            answer = h;
            break;
        }
    }

    return answer;
}