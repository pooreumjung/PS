#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;
void hanoi(int n, int start, int mid, int dest){
    // n이 1개라면 그냥 바로
    if(n == 1){
        vector<int>temp;
        temp.push_back(start);
        temp.push_back(dest);
        answer.push_back(temp);
        return;
    }
    
    // 1. 원판 n-1개를 시작 기둥에서 보조 기둥으로 옮기기
    hanoi(n-1, start, dest, mid);
    vector<int>temp;
    temp.push_back(start);
    temp.push_back(dest);
    answer.push_back(temp);
    
    // 보조 기둥에 있는 n-1개를 다시 목적지 기둥으로 옮기기
    hanoi(n-1, mid, start, dest);
}

vector<vector<int>> solution(int n) {
    
    hanoi(n, 1,2,3);
    return answer;
}