#include <iostream> 
#include <queue>
using namespace std;
const int A = 100001;
int arr[A], n, k;
queue<pair<int, int>> q;
int bfs() {
	arr[n] = 1;
	q.push({ n,0 });
	while (!q.empty())
	{
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();
		if (pos == k)
			return time;
		int arr2[3] = { pos + 1, pos - 1, pos * 2 };
		for (int x = 0; x < 3; x++) {
			int newpos = arr2[x];
				if (newpos >= 0 && newpos < A) {
					if (arr[newpos] == 0) {
						q.push({ newpos,time + 1 });
						arr[newpos] = 1;
					}
				}
		}
	}
}
int main()
{
	cin >> n >> k; 	
	cout << bfs(); 	
	return 0;
}