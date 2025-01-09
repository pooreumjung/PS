#include<bits/stdc++.h>
using namespace std;

string x, y;

int main(){
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y;
    if(x.size() >= y.size()) cout << "go";
    else cout << "no";
    return 0;
}