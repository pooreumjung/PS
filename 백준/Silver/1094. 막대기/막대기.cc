#include<iostream>
 
#define endl "\n"
using namespace std;
 
int X;
 
void Input()
{
    cin >> X;
}
 
void Solution()
{
    int Len = 64;
    int Cnt = 0;
    while (X > 0)
    {
        if (Len > X) Len = Len / 2;
        else
        {
            X = X - Len;
            Cnt++;
        }
    }
    cout << Cnt << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    
    Solve();
 
    return 0;
}