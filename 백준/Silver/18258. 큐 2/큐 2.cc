#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    queue<int> q;
    string str;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        
        if(str == "push")
        {
            int number;
            cin >> number;
            q.push(number);
        } 
        
        else if(str == "pop")
        {
            if(!q.empty())
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
        } 
        
        else if(str == "size")
        {
            cout << q.size() << "\n";
        } 
        
        else if(str == "empty")
        {
            cout << q.empty() << "\n";
        } 
        
        else if(str == "front")
        {
            if(!q.empty())
            {
                cout << q.front() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        } 
        
        else if(str == "back")
        {
            if(!q.empty())
            {
                cout << q.back() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        } 
    }
    return 0;
}