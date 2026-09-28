#include <string>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

// 한 번에 한 명의 유저 신고, 횟수 제한 x, 그러나 1회로 기록
// k번 이상 신고된 유자 => 게시판 정지, 
map<string, unordered_set<string>> list1, list2; // list1은 string을 신고한 사람들, list2는 string이 신고한 사람들
unordered_set<string> reportList; // k번 이상 신고 당해 정지 먹은 사람들
vector<int>result;

vector<int> solution(vector<string> id_list, vector<string> reports, int k) {
    
    // 세팅
    for(string report: reports){
        int index = report.find(' ');
        string name1 = report.substr(0,index); // 신고한 사람
        string name2 = report.substr(index+1); // 신고당한 사람
        
        list1[name2].insert(name1);
        list2[name1].insert(name2);
    }
    
    result.resize(id_list.size(),0);
            
    // k번 이상 신고당한사람 찾기
    for(auto it = list1.begin(); it!= list1.end(); it++){
        if(it->second.size() >= k)
            reportList.insert(it->first);
    }
    
    // result 세팅
    int index = 0;
    for(string id:id_list){
        auto it = list2.find(id);
        if(it != list2.end()){
            for(string name: it->second){
                if(reportList.find(name) != reportList.end())
                  result[index]++;  
            }
        }
        index++;
    }
 
    return result;
}

// frodo 2번 신고 당함, neo 두 번 신고 당함, muzi 한 번 신고당함