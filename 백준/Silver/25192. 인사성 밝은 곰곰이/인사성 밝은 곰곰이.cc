#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,res=0;
    string input;
    cin>>n;
    queue<string>q;


    while (n--) {
        cin>>input;
        q.push(input);
    }

    while (!q.empty()) {
        if (q.front() == "ENTER") { // 새로운 사람이 들어온다 => 개수 세기
            set<string>s;
            q.pop();
            while (true) {
                if (q.empty())
                    break;
                string name=q.front();
                if (name == "ENTER")
                    break;
                q.pop();
                auto it=s.find(name);
                if (it == s.end()) {
                    // 기존에 없던 멤버인 경우에는
                    res++;
                    s.insert(name);
                }
            }
        }
    }
    cout<<res;
}