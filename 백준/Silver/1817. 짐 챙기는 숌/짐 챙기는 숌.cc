#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,sum=0,count=0,book;
    cin>>n>>m;

    for(int i=0;i<n;i++) {
        cin>>book;
        if (sum+book<m) // 작을 때는 그냥 계속 넣기
            sum+=book;
        else if (sum+book ==m) { // 같을 때면 개수 더해주고 sum값 0으로 초기화
            count++;
            sum=0;
        }
        else { // 크다면, 그다음 book값으로 sum 초기화 및 개수 증가
            sum=book;
            count++;
        }
    }

    if (sum>0 && sum<=m)
        count++;

    cout<<count;
}