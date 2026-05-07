#include <string>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
int funcBonus(char c){
    if(c== 'S')
        return 1;
    else if(c=='D')
        return 2;
    else
        return 3;
}

int solution(string dartResult) {
    int answer = 0, index=0;
    
    // num값, 곱할 값
    vector<pair<int,int>>v;
    
    while(index < dartResult.length()){
        char c = dartResult[index];
        
        // 숫자인 경우        
        if(c >= '0' && c <= '9'){
            int num = c-'0';
            if(c=='1'){
                if(dartResult[index+1] == '0'){
                    num = 10;
                    index++;
                }
            }
            num = pow(num, funcBonus(dartResult[++index]));
            v.push_back(make_pair(num, 1));                        
        }
                        
        // 옵션인 경우
        else if(c == '#'){
            v[v.size()-1].second *= -1;
        }
        else if(c == '*'){
            v[v.size()-1].second *=2;
            if(v.size()-2>=0)
                v[v.size()-2].second *=2;
        }
        index++;
        
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
        answer += v[i].first * v[i].second;
    }
    return answer;
}

/*
S -> 1제곱, D => 2제곱, T => 3제곱
* => 점수 2배, # => 점수 마이너스
*는 *과 중첩 가능(2배, 4배, 6배)
*는 #과 중첩 가능(-2배, -4배)
#은 한개만 적용
*/