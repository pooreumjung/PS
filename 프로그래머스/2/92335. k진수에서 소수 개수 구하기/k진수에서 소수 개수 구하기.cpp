#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long long num){
    if(num == 1 || num == 0)
        return false;
    for(int i=2; i<=sqrt(num);i++){
        if(num % i ==0)
            return false;
    }
    return true;
}

// 최대 13자리
string func(int n,int k){
    string temp = "";
    while(n>0){
        int num = n % k;
        temp.push_back(num+'0');
        n /= k;               
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int solution(int n, int k) {
    int answer = 0;    
    string num = func(n,k), temp = "";
    
    for(int i=0; i<num.length();i++){
        // 0인 경우
        if(num[i]== '0'){
            // P0인 경우
            if(!temp.empty()){
                long long num = stoll(temp);
                if(isPrime(num))
                    answer++;
                cout<<num<<" ";
                temp = "";
            }            
        }
        // 0이 아닌 경우 => 일단 붙여
        else                       
            temp.push_back(num[i]);                     
    }
    if(!temp.empty()){
        long long num = stoll(temp);
        if(isPrime(num))
            answer++; 
        cout<<num;
    }
    return answer;
}
