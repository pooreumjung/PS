#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    
    int answer = 0, n = name.length();
    
    // 상하 조작 횟수 계산
    for(int i=0; i<n; i++)
        answer += min(name[i]-'A', 'Z'-name[i]+1);
    
    // 좌우 조작 횟수 계산
    int min_move = n-1;
    
    for(int i=0; i<n; i++){
        // 연속된 'A'의 시작과 끝을 찾기
        int next_i = i+1;
        while(next_i < n && name[next_i] == 'A')
            next_i++;
        
        int case_turn_back = 2*i + (n-next_i); // 우측으로 가다가 좌측으로 틀기
        int case_reverse_first = i + 2*(n-next_i); // 왼족으로 가다가 우측 트기
        
        int best_case = min(case_turn_back, case_reverse_first);
        min_move = min(min_move, best_case);
        
    }
        
    answer += min_move; // 알파벳 변경 횟수 + 최소 커서 이동 횟수
    return answer;
}