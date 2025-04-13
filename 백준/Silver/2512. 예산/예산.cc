#include<bits/stdc++.h>
using namespace std;

vector<int>v;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,price, maxPrice,sum=0, limit=0;;
    cin>>n;

    for(int i=0;i<n;i++) {
        cin>>price;
        sum+=price;
        v.push_back(price);
    }
    cin>>maxPrice;
    sort(v.begin(),v.end());

    if (sum<=maxPrice) {
        cout<<v.back()<<endl;
        return 0;
    }

    for (int i=0; i<n;i++) {
        int curPrice = v[i];
        if (curPrice <= maxPrice/(n-i)) {
           maxPrice -= curPrice;
        }else {
            limit = maxPrice/(n-i);
            maxPrice -= limit;
            break;
        }
    }
    cout<<limit;
}