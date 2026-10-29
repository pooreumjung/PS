#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for (char digit : number) {
        // 스택(answer)의 맨 뒤 요소가 현재 숫자보다 작고, 제거할 횟수(k)가 남아있다면 제거
        while (!answer.empty() && k > 0 && answer.back() < digit) {
            answer.pop_back();
            k--;
        }
        answer.push_back(digit);
    }
            
    // 내림차순 등으로 인해 k가 남아있는 경우 뒤에서부터 k개 잘라내기
    if (k > 0) {
        answer.resize(answer.size() - k);
    }
    
    return answer;
}