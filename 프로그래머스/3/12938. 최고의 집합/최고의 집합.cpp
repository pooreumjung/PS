#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    // n개의 자연수를 만들 수 없음
    if (n > s) 
        return {-1};
    
    int quotient = s / n;
    int remainder = s % n;

    // 작은 값부터 넣기
    for (int i = 0; i < n - remainder; i++) 
        answer.push_back(quotient);
    
    // 나머지만큼 +1
    for (int i = 0; i < remainder; i++) 
        answer.push_back(quotient + 1);

    return answer;
}