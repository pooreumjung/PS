#include <iostream>
#include <vector>


using namespace std;

int ans;
int N;
vector<int> v;

int main(){
    cin>>N;

    v.push_back(-99999); 

    for(int i=0; i<N; i++) {
        int x;
        cin>>x;
        if(x>v.back()) {
            v.push_back(x);
            ans++;
        }

        else {
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }

   
    cout<<ans;

}
