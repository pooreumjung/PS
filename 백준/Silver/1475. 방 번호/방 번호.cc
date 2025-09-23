#include <bits/stdc++.h>
using namespace std;

vector<int> arr(10, 0);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s = to_string(n);
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - '0';
        // 6이 이미 차있다면 9로 바꾸기
        if (index == 6)
        {
            if (arr[6] > arr[9])
                arr[9]++;
            else
                arr[6]++;
        }
        else if (index == 9)
        {
            if (arr[9] > arr[6])
                arr[6]++;
            else
                arr[9]++;
        }
        else
        {
            arr[index]++;
        }
    }

    cout << *max_element(arr.begin(), arr.end());
}