#include<iostream>
using namespace std;
int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int sum = A * 60 + B + C;

    cout << (sum / 60) % 24 << " " << sum % 60;
}