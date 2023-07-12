#include <iostream>
using namespace std;
int main()
{
    int T, C;
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        cin >> C;
        cout << C/25 << " " << (C%25)/10 << " " << ((C%25)%10)/5 << " " << C%5 << "\n";
    }
}