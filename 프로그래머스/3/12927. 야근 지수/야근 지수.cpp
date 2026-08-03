#include <string>
#include <vector>
#include <set>

using namespace std;
multiset<int, greater<int>> ms;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    for(int i = 0; i<works.size(); i++)
        ms.insert(works[i]);
    
    while(n--){
        if(!ms.empty()){
            int work = *ms.begin();
            work--;
            ms.erase(ms.begin());
            if(work > 0)
                ms.insert(work);
        }
    }   
    
    for(int work:ms)
        answer += work*work;
    
    return answer;
}