#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string numbers = "412";
    string answer = "";

    while (n > 0) {
        answer = numbers[n % 3] + answer;
        n = (n - 1) / 3;
    }
    return answer;
}