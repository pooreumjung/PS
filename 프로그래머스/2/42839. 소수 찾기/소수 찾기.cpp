#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
const int MAX = 10000000; 

unordered_set<int> s;
vector<bool> isUsed;
bool visited[MAX]; 
string temp;

void func(string number) {
    if (!number.empty()) {
        s.insert(stoi(number));
    }
    
    for (int i = 0; i < temp.length(); i++) {
        if (isUsed[i]) continue;
        
        isUsed[i] = true;
        func(number + temp[i]); 
        isUsed[i] = false;
    }
}

void init() {
    
    visited[0] = visited[1] = true;
    
    for (int i = 2; i * i < MAX; i++) {
        if (!visited[i]) {
            for (int j = i * i; j < MAX; j += i)
                visited[j] = true;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    temp = numbers;
    isUsed.assign(numbers.length(), false); 
    s.clear();
    
    func("");
    init();
    
    for(int num : s) {
        if(num < MAX && !visited[num]) 
            answer++;
    }
    
    return answer;
}