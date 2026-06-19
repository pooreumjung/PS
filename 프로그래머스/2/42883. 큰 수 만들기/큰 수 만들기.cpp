#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (char c : number) {
        while (!answer.empty() && k > 0 && answer.back() < c) {
            answer.pop_back();
            k--;
        }
        answer.push_back(c);
    }

    // 아직 덜 지웠으면 뒤에서 제거
    if (k > 0) {
        answer.erase(answer.size() - k);
    }

    return answer;
}