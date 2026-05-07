#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> clothes(n + 1, 1);

    for (int l : lost)
        clothes[l]--;

    for (int r : reserve)
        clothes[r]++;

    for (int i = 1; i <= n; i++) {
        if (clothes[i] == 2) {
            if (i > 1 && clothes[i - 1] == 0) {
                clothes[i]--;
                clothes[i - 1]++;
            }
            else if (i < n && clothes[i + 1] == 0) {
                clothes[i]--;
                clothes[i + 1]++;
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (clothes[i] > 0)
            answer++;
    }

    return answer;
}