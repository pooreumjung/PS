#include<iostream>
#include<string>
using namespace std; 
string eight[8] = { "000","001","010","011","100","101","110","111" };
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string n;
    cin >> n;
    for (int i = 0; i < n.length(); i++) 
    {
        if (n[i] == '0')
        {
            if (i == 0) // 수가 0인 경우를 제외하고 반드시 1로 시작해야한다. 
                cout << "0";
            else
                cout << eight[0];
        }
        else if (n[i] == '1')
        {
            if (i == 0)
                cout << "1";
            else
                cout << eight[1];
        }
        else if (n[i] == '2')
        {
            if (i == 0)
                cout << "10";
            else
                cout << eight[2];
        }
        else if (n[i] == '3')
        {
            if (i == 0)
                cout << "11";
            else
                cout << eight[3];
        }
        else if (n[i] == '4')
            cout << eight[4];
        else if (n[i] == '5')
            cout << eight[5];
        else if (n[i] == '6')
            cout << eight[6];
        else if (n[i] == '7')
            cout << eight[7];
    }
}