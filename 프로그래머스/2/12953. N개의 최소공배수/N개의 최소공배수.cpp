#include <string>
#include <iostream>
#include <vector>

using namespace std;

int func(int a,int b){
    if(b == 0)
        return a;
    return func(b, a%b);
}
int solution(vector<int> arr) {
    if(arr.size() == 1)
        return arr[0];
    
    int answer = 0, current;
    for(int i=0;i<arr.size();i++){
        if(i==0){
            int mul = arr[i] * arr[i+1];
            int div = func(arr[i], arr[i+1]);
            current = mul / div;
            answer = current;
        }
        else{
            current = current*arr[i] /func(current,arr[i]);
        }
        cout<<current<<" ";
    }
    
    return current;
}