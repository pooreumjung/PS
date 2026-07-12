#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> numbers;

    for (int i = 1; i <= n; i++) 
        numbers.push_back(i);
    
    long long factorial = 1;
    for (int i = 2; i <= n; i++) 
        factorial *= i;
    
    // 1-based 순서를 0-based 인덱스로 변경
    k--;
    while (n > 0) {
        factorial /= n;

        int index = k / factorial;

        answer.push_back(numbers[index]);
        numbers.erase(numbers.begin() + index);

        k %= factorial;
        n--;
    }

    return answer;
}