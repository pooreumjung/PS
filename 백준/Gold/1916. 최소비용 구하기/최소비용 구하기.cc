#include <iostream>
using namespace std;

int INF = 987654321;

int arr[1001][1001];
bool v[1001];
int d[1001];

int n, m, a, b, c, s, e;

int getSmallIndex() {
	int min = INF;
	int index = 1;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 1; i <= n; i++) {
		d[i] = arr[start][i];
	}
	v[start] = 1;
	for (int i = 1; i <= n - 2; i++) 
	{
		int current = getSmallIndex();
		v[current] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (!v[j]) {
				if (d[current] + arr[current][j] < d[j]) {
					d[j] = d[current] + arr[current][j];
				}
			}
		}
	}
}

int main() {
	for (int i = 1; i < 1001; i++)
		for (int j = 1; j < 1001; j++)
			arr[i][j] = INF;
		
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (arr[a][b] > c)
			arr[a][b] = c;
	}
	cin >> s >> e;

	dijkstra(s);
	cout << d[e];

}