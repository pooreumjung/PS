#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<limits.h>
using namespace std;

#define INF INT_MAX
typedef pair<int, int> cur;
priority_queue <cur, vector<cur>, greater<cur>> pq;
vector<vector<cur>> V(801);
vector<int> Res(801), Visit(801);
int N, M, A, B, C, i, idx, tmp, a, b, c, d, e;
int Ans;
bool Chk1, Chk2 , Chk3;

void Dijkstra(int start) {
    fill(Res.begin(), Res.end(), INF);
    fill(Visit.begin(), Visit.end(), 0);
    Res[start] = 0;
    pq.push({ 0,start });

    while (!pq.empty()) {
        idx = pq.top().second;
        pq.pop();
        if (Visit[idx]) continue;
        else Visit[idx]++;

        for (i = 0; i < V[idx].size(); i++) {
            C = V[idx][i].first;
            if (!Visit[C]) {
                tmp = Res[idx] + V[idx][i].second;
                if (tmp < Res[C]) {
                    Res[C] = tmp;
                    pq.push({ Res[C],C });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        V[A].push_back({ B,C });
        V[B].push_back({ A,C });
    }

    cin >> A >> B;

    Dijkstra(1);
    if (Res[A] == INF && Res[B] == INF)
        Chk1 = true;
    a = Res[A]; b = Res[B];

    Dijkstra(N);
    if (Res[A] == INF && Res[B] == INF)
        Chk2 = true;
    d = Res[A]; e = Res[B];

    Dijkstra(A);
    if (Res[B] == INF)
        Chk3 = true;
    c = Res[B];

    Ans = min(min(a + c + e, b + c + d), min(a + c + c + d, a + c + c + e));
    
    if (Chk1 || Chk2 || Chk3)
        Ans = -1;

    cout << Ans;
}