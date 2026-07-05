#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int make_total(string s) {
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));

    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> times;

    for (auto book : book_time) {
        int start = make_total(book[0]);
        int end = make_total(book[1]) + 10;

        times.push_back({start, end});
    }

    sort(times.begin(), times.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto cur : times) {
        int start = cur.first;
        int end = cur.second;

        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }

        pq.push(end);
    }

    return pq.size();
}