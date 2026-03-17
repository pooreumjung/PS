#include <iostream>
#include <string>
using namespace std;

string input;
void func(int start, int len)
{
    if (len == 1)
        return;

    int third = len / 3;

    for (int i = start + third; i < start + 2 * third; i++)
        input[i] = ' ';
    func(start, third);
    func(start + 2 * third, third);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N)
    {
        int len = 1;
        for (int i = 0; i < N; i++)
            len *= 3;

        input = string(len, '-');
        func(0, len);

        cout << input << '\n';
    }
}