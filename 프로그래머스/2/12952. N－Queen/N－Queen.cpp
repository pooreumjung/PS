#include <string>
#include <vector>

using namespace std;
int answer = 0;

int col[13];
bool used1[30], used2[30];

void dfs(int n, int row){
    if(row == n){
        answer++;
        return;
    }
    
    for(int i=0;i<n;i++){
        // 같은 열에 있는 경우
        if(col[i])
            continue;
        // 우측 대각선 아래에 있는 경우
        if(used1[row+i])
            continue;
        // 좌측 대각선 아래에 있는 경우
        if(used2[row-i+n])
            continue;
        
        // 선택
        col[i] = true;
        used1[row+i] = true;
        used2[row-i+n] = true;
        
        // 다음 행 탐색
        dfs(n, row+1);
        
        // 해제
        col[i] = false;
        used1[row+i] = false;
        used2[row-i+n] = false;
    }
}

int solution(int n) {
    dfs(n, 0);
    return answer;
}