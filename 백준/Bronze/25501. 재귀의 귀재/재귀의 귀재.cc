#include<bits/stdc++.h>
using namespace std;

pair<int,int> recursion(std::string& s, int l, int r, int count){
    if(l >= r) return make_pair(1,count);
    else if(s[l] != s[r]) return make_pair(0,count);
    else return recursion(s, l+1, r-1, count+1);
}

pair<int,int> isPalindrome(std::string& s ){
    return recursion(s, 0, s.length()-1, 1);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    while (n--) {
        string s;
        cin>>s;
        cout<<isPalindrome(s).first<<" "<<isPalindrome(s).second<<endl;
    }
}