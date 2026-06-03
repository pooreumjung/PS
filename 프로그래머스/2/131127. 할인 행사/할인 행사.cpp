#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string,int>mp;
int func(vector<string>want, vector<int>number){
    for(int i=0;i<number.size();i++){
        auto it = mp.find(want[i]);
        if(it == mp.end())
            return 0;
        if(it -> second != number[i])
            return 0;
    }
    return 1;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0, size = 0, left=0, right=0;
        
    while(true){
        if(right == discount.size()){
            answer += func(want, number);
            break;
        }
        if(right - left < 10){
            mp[discount[right]]++;
            right++;
        }
        else if(right - left == 10){
            answer += func(want, number);
            mp[discount[left]]--;
            left++;
        }                
    }
                
    return answer;
}