#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer, size1;
vector<bool>visited;
vector<string>words;

// 문자 개수 다름 여부 체크
bool findDif(string s1, string s2){
    int count = 0;
    for(int i=0;i<s1.length();i++){
        if(s1[i] != s2[i])
            count++;
    }
    
    return count == 1;
}

void dfs(string current, int count, string target){
    // 목표 단어에 도달한 경우
    if(current == target){
        answer = min(answer, count);
        return;
    }
    
    for(int i=0; i<size1; i++){
        if(!visited[i] && findDif(current, words[i])){
            visited[i] = true;
            dfs(words[i],count+1,target);
            visited[i] = false;
        }
    }
    
}

int solution(string begin, string target, vector<string> words2) {
    // 전역 변수 데이터 할당
    words = words2;    
    size1 = words.size();
    answer = 99999999;
    
    bool isPossible = false;    
    visited.resize(size1, false);
    
    // target이 배열에 있는지    
    for(string word: words){
        if(word == target){
            isPossible = true;
            break;
        }
    }
    if(!isPossible) return 0;
           
    // 시작 단어부터 DFS 탐색
    dfs(begin,0,target);
    
    return answer == 99999999 ? 0 : answer;
}