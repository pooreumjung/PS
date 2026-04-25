#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int M;
        cin >> M;
        vector<int> result;
        priority_queue<int> maxHeap;                            // 작은 쪽 (중앙값 포함)
        priority_queue<int, vector<int>, greater<int>> minHeap; // 큰 쪽

        for (int i = 1; i <= M; i++)
        {
            int x;
            cin >> x;

            // 1. 삽입
            if (maxHeap.empty() || x <= maxHeap.top())
                maxHeap.push(x);
            else
                minHeap.push(x);

            // 2. 균형 맞추기
            if (maxHeap.size() > minHeap.size() + 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (minHeap.size() > maxHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // 3. 홀수 번째 중앙값 출력
            if (i % 2 == 1)
                result.push_back(maxHeap.top());
        }
        cout << result.size() << '\n';

        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << ' ';
            if ((i + 1) % 10 == 0)
                cout << '\n';
        }
        cout << '\n';
    }
}
