#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int>mp;

int solution(vector<vector<string>> clothesList) {
    int answer = 0;
    for(vector<string>clothes: clothesList){
        string name = clothes[0];
        string type = clothes[1];
        
        mp[type]++;
    }
    
    int total = 1;
    for(auto const&[type,count]: mp)
        total *= (count+1);
    
    answer = total-1;    
    return answer;
}