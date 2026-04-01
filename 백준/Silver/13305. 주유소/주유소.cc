#include <iostream>
#include <vector>
using namespace std;

vector<long long> cost, dist;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 입력 받기
    for (int i = 0; i < n - 1; i++)
    {
        long long dis;
        cin >> dis;
        dist.push_back(dis);
    }

    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        cost.push_back(temp);
    }

    int index = 0;
    long long result = 0;
    while (index < n - 1)
    {

        if (cost[index] >= cost[index + 1])
        {
            result += cost[index] * dist[index];
            index++;
        }
        else
        {
            long long temp = 0;
            bool found = false;
            for (int j = index + 1; j < n; j++)
            {
                temp += dist[j - 1];
                if (cost[index] >= cost[j])
                {
                    result += cost[index] * temp;
                    index = j;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                result += cost[index] * temp;
                break;
            }
        }
    }

    cout << result;
}