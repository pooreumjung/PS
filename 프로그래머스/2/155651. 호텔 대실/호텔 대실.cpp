#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>>times;
int make_time(string s){
    int hour = stoi(s.substr(0,2));
    int minute = stoi(s.substr(3));
    
    return 60*hour + minute;
}

int solution(vector<vector<string>> book_times) {
    
    for(vector<string>book_time: book_times){
        int start_time = make_time(book_time[0]);
        int end_time = make_time(book_time[1])+10;
        
        times.push_back(make_pair(start_time, end_time));
    }
    
    sort(times.begin(), times.end());
    priority_queue<int,vector<int>, greater<int>>pq;
    int answer = 0;
    
    
    for(auto cur:times){
        int start = cur.first;
        int end = cur.second;
        
        if(!pq.empty() && start >= pq.top())
            pq.pop();
        
        pq.push(end);
    }
    
    return pq.size();
}

// 끝나는 시간 생각하기
// 먼저 19시 30분, 14시 20분은 19시 20분보다 빠르니 방 추가
// 15:00는 15:30분보다 빠르니 방 추가
// 그럼 pq는 15:30, 17:10, 19:30
// 그다음 16시 40분은 15시 30분보다 느리니 방 사용하고, 15시 30분 빼고 18시 30분 추가
// 18시 20분은 17시 10분보다 느리니 방 사용하고, 15시 10분 빼기
