#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<int>input1;
set<int>input2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        int a;
        cin>>a;
        input1.insert(a);
    }
    for(int x=0;x<m;x++){
        int a;
        cin>>a;
        input2.insert(a);
    }
    int first = 0;
    set<int>::iterator iter;
    for (iter = input1.begin(); iter != input1.end(); iter++) {
        if (input2.find(*iter) == input2.end()) {
            first++;
        }
    }
    int second = 0;
    for (iter = input2.begin(); iter != input2.end(); iter++) {
        if (input1.find(*iter) == input1.end()) {
            second++;
        }
    }
    cout << first + second;    
}