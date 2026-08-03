#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;

    for (int work : works)
        pq.push(work);

    while (n-- && !pq.empty()) {
        int work = pq.top();
        pq.pop();
        work--;

        if (work > 0)
            pq.push(work);
    }
    
    while(!pq.empty()){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}