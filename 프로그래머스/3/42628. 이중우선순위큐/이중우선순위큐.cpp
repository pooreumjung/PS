#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;

    for (const string& operation : operations) {
        char op = operation[0];
        int number = stoi(operation.substr(2));

        if (op == 'I') {
            ms.insert(number);
        } 
        else if (!ms.empty()) {
            if (number == -1) {
                // 최솟값 삭제
                ms.erase(ms.begin());
            } 
            else if (number == 1) {
                // 최댓값 삭제
                ms.erase(prev(ms.end()));
            }
        }
    }

    if (ms.empty()) {
        return {0, 0};
    }

    int minValue = *ms.begin();
    int maxValue = *prev(ms.end());

    return {maxValue, minValue};
}