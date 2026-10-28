#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> v;
vector<tuple<int,int,int>>v2;
int index = 0;

void init(){
    int dia=0, iron = 0, stone = 0;
    
    for(int i=0; i<v.size();i++){
        if(i%5 == 0 && i>0){            
            tuple<int,int,int> cur = make_tuple(dia,iron,stone);
            v2.push_back(cur);
            dia = iron = stone = 0;
        }   
     
        if(v[i] == "diamond")
            dia++;
        else if(v[i] == "iron")  
            iron++;
        else stone++;         
    }
    
    tuple<int,int,int> cur = make_tuple(dia,iron,stone);
    v2.push_back(cur);
}

int func(int count, int i){  
    int total = 0;
    if(index >= v2.size()) return total;
    
    tuple<int,int,int> cur;
    
    while(count--){
        if(index >= v2.size()) break;        
        cur = v2[index];
        // 다이아 곡괭이
        if(i==0)
            total += get<0>(cur) + get<1>(cur) + get<2>(cur);        
        // 철 곡괭이
        else if(i==1)
            total += 5*get<0>(cur) + get<1>(cur) + get<2>(cur);        
        // 돌 곡괭이
        else
            total += 25*get<0>(cur) + 5*get<1>(cur) + get<2>(cur);                        
        index++;
    }
        
    return total;
}

int solution(vector<int> picks, vector<string> minerals) {
    int totalPicks = picks[0] + picks[1] + picks[2];
    int limit = min((int)minerals.size(), totalPicks * 5);

    minerals.resize(limit);
    int answer = 0, i=0, size = minerals.size();
    v = minerals;
            
    init(); // 광물 집합 수 세팅
    sort(v2.begin(), v2.end(), greater<tuple<int,int,int>>()); // 내림차순 정렬
                           
    for(int i=0; i<picks.size();i++)
        answer += func(picks[i],i);                        
        
    return answer;
}