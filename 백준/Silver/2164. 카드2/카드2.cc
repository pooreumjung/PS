#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    queue<int> q;
 
    cin >> n;
    for (int i = 1; i <= n;i++){
        q.push(i);
    }
    int temp;
    while(1){
        temp = q.front();
        q.pop();
        if(q.empty()){
            break;
        }
        q.push(q.front());
        q.pop();
    }
    cout << temp;
    return 0;
}
