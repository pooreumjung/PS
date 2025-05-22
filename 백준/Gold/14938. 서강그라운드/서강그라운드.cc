#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

long long dist[101][101];
long length[101];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m,r;
	cin >> n >> m>>r;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INT_MAX;
		}
	}

	for (int i = 1; i <= n; i++)
		cin >> length[i];
	
	for (int i = 0; i < r; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		if (dist[start][end] > time)
			dist[start][end] = time;
		if (dist[end][start] > time)
			dist[end][start] = time;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	long max = -1;
	for (int i = 1; i <= n; i++) {
		long long sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)
				sum += length[i];
			else if (dist[i][j] != INT_MAX && dist[i][j] <= m)
				sum += length[j];
		}
		if (sum > max)
			max = sum;
	}
	cout << max;
}