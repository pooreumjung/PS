#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int sum = 0, answer=0, left = 0, right = people.size()-1;
    
    while(left <= right){
        if(people[left] + people[right] <= limit)
            left++;
        right--;
        answer++;       
    }

    return answer;
}