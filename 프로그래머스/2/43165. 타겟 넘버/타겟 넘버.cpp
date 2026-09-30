#include <string>
#include <vector>

using namespace std;
int answer = 0, numberSize = 0;
vector<bool>visited;
vector<int>arr;

void dfs(int target, int sum, int index){
    if(index == numberSize){
        if(sum == target)
            answer++;
        return;
    }
    
    
    dfs(target, sum+arr[index], index+1);
    dfs(target, sum-arr[index], index+1);
    
    
}

int solution(vector<int> numbers, int target) {
    numberSize = numbers.size();
    visited.resize(numberSize, false);
    arr = numbers;
    
    dfs(target, 0,0);    
    return answer;
}