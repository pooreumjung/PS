#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, dasom, num,person=0;
    cin>>n;

    for(int i=0;i<n;i++) { // 입력 받기
        cin>>num;
        if (i==0) // 다솜의 득표수 저장
            dasom = num;
        else {
            // 나머지 사람들의 득표수를 내림 차순 정렬
            pq.push(num);
        }
    }

    while(!pq.empty()) {
        int count = pq.top(); // 최대 득표수 가져오기
        if (dasom >count) // 다솜이가 투표수 1등이 되는 경우
            break;
        pq.pop();
        count--;
        pq.push(count);
        dasom++;
        person++;
    }

    cout<<person;
}