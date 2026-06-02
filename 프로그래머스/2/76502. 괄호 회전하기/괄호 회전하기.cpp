#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

deque<char>dq;

bool func(){
    stack<char>myStack;
    for(int i=0;i<dq.size();i++){
        if(dq[i] == '}'){
            if(!myStack.empty() && myStack.top() == '{')
                myStack.pop();
            else
                return false;
        }
        else if(dq[i] == ')'){
            if(!myStack.empty() && myStack.top() == '(')
                myStack.pop();
            else
                return false;
        }
        else if(dq[i] == ']'){
            if(!myStack.empty() && myStack.top() == '[')
                myStack.pop();
            else
                return false;
        }
        else
            myStack.push(dq[i]);        
    }
    
    if(myStack.empty())
        return true;
    else
        return false;
}


int solution(string s) {
    int answer = 0, count=0;
    bool isPossilbe = false;
    
    for(char c: s)
        dq.push_back(c);
    
    while(count < s.length()){
                
        if(func()){
            answer++;            
        }                    
        
        dq.push_back(dq.front());
        dq.pop_front();
        count++;
    }
    
    return answer;
}