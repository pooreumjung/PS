#include <bits/stdc++.h>
using namespace std;

string func1(string s)
{
    list<char> l;
    auto it = l.end();
    for (char c : s)
    {
        switch (c)
        {
        case '<':
            if (it != l.begin())
                it--;
            break;
        case '>':
            if (it != l.end())
                it++;
            break;
        case '-':
            if (it != l.begin())
                it = l.erase(--it);
            break;
        default:
            l.insert(it, c);
            break;
        }
    }
    string result = "";
    for (char c : l)
        result += c;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        cout << func1(s) << '\n';
    }
}