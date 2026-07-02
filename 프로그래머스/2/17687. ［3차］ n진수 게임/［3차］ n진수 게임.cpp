#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string func(int number, int n){
    if(number == 0)
        return "0";
    
    string ans = "";    
    while(number > 0){
        int div = number % n;
        number /= n;
        
        if(div < 10)
            ans.push_back(div+'0');
        else{
            div -= 10;
            ans.push_back(div+'A');
        }
    }
    
        
    reverse(ans.begin(), ans.end());
    return ans;
}

string solution(int n, int t, int m, int p) {
    string answer = "", arr="";
    int size = t * m, count=0, index=p-1;
    
    while(true){
        if(arr.length() >= size)
            break;
        arr += func(count, n);
        count++;
    }
        
    while(t--){
        answer.push_back(arr[index]);
        index += m;
    }
            
    return answer;
}


