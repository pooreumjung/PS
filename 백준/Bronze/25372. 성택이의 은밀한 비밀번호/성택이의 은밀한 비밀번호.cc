#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    string s;

    cin >> n;
    while(n--){
        cin >> s;
        if(s.size() >= 6 && s.size() <= 9){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
}