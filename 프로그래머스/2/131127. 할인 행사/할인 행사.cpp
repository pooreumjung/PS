#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,int> mp;
int answer = 0;

void func(vector<string>wants, vector<int>numbers){
    
    bool isPossible = true;
    for(int i=0;i<wants.size();i++){
        string wantFruit = wants[i];
        int wantCount = numbers[i];

        if(mp[wantFruit] < wantCount){
            isPossible = false;
            break;
        }
    }
    
    if(isPossible) answer++;
}

int solution(vector<string> wants, vector<int> numbers, vector<string> discount) {
    
    int total = 0;
    for(int number:numbers)
        total += number;
    
    for(int i=0; i<total;i++)
        mp[discount[i]]++;
    func(wants, numbers);
        
    for(int i=total; i<discount.size();i++){
        mp[discount[i]]++;
        mp[discount[i-total]]--;
                
        func(wants, numbers);
    }
            
    return answer;
}