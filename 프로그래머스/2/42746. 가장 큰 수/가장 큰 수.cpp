#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);

    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);

    if (numbers[0] == 0) return "0";

    string answer = "";
    for (int n : numbers) {
        answer += to_string(n);
    }

    return answer;
}