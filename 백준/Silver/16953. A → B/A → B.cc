#include<bits/stdc++.h>
using namespace std;
queue<pair<long long int, long long int>>q;
map<long long int, bool>mp;
long long int a, b;
int bfs() {
    q.push({ a,0 });
    mp.insert(make_pair(a,true));
    while (!q.empty()) {
        long long int pos = q.front().first;
        long long int time = q.front().second;
        q.pop();
        if (pos == b)
            return time+1;
        long long int d = (pos * 10) + 1;
        long long int arr2[2] = { pos * 2,d };
        for(int i=0;i<2;i++){
            long long int newpos = arr2[i];
            if (newpos <= 1000000000) {
                if (!mp[newpos]) {
                    q.push({ newpos,time + 1 });
                    mp[newpos] = true;
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    cout << bfs();
}