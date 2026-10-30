#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int>answer(n);
    stack<int>s;
    
    for(int i=0; i<n; i++){
        // 현재 가격이 스택top에 위치한 가격보다 낮다면
        while(!s.empty() && prices[s.top()] > prices[i]){
            int topIndex = s.top();
            s.pop();
            answer[topIndex] = i -topIndex; // 가격이 유지된 시간
        }
        s.push(i);
    }
    
    // 끝까지 가겨이 떨어지지 않은 주식들
    while(!s.empty()){
        int topIndex = s.top();
        s.pop();
        answer[topIndex] = n-1-topIndex;
    }
    
    return answer;
}


