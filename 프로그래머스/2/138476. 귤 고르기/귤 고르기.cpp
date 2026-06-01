#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
map<int,int>mp;
vector<int>v;
int solution(int k, vector<int> tangerine) {
    
    for(int i=0;i<tangerine.size();i++)
        mp[tangerine[i]]++;
    
    for(auto it = mp.begin();it!=mp.end();it++)
        v.push_back(it->second);
    
    sort(v.begin(), v.end());
    
    int answer = 0, size = tangerine.size(), mpSize = mp.size();    
    
    for(int i=0;i<v.size();i++){
        int count = v[i];
        if(size - count < k)
            break;
        else if(size - count >= k){
            size -= count;
            mpSize--;
        }
        
    }
    return mpSize;
}