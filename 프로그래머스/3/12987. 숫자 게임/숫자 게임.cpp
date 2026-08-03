#include <string>
#include <vector>
#include <set>

using namespace std;

multiset<int>ms;
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    for(int person: B)
        ms.insert(person);
    
    for(int point: A){
        auto it = ms.upper_bound(point);
        if(it != ms.end()){
            ms.erase(it);
            answer++;
        }            
    }
    
    return answer;
}