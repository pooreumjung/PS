#include <iostream>
#include <vector>
#include <set>

using namespace std;
set<int>s;
vector<int>v;
vector<bool>isUsed;

void func(int sum, int index, int size){
    s.insert(sum);    
    if(size == v.size())
        return;
    if(index == v.size())
        index = 0;
    func(sum+v[index], index+1, size+1);        
}

int solution(vector<int> elements) {    
    v = elements;
    isUsed.resize(elements.size());
    for(int i=0; i<elements.size();i++){        
        fill(isUsed.begin(), isUsed.end(), false);
        func(elements[i], i+1, 1);        
    }
        
    return s.size();
}