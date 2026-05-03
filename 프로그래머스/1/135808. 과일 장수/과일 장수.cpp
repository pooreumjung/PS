#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0, index=0;
    sort(score.begin(), score.end(),greater<>());
    
    while(index<score.size()){        
        index = index + m -1;
        if(index>=score.size())
            break;       
        answer+=score[index]*m;            
        index++;
    }
    
    return answer;
}