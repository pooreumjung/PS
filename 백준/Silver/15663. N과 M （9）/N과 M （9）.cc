#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
bool visited[8];
vector<int>v;
int arr[8];
void abc(int cnt) {
	if (cnt == m) {
		for (int x = 0; x < m; x++)
			cout << arr[x] << " ";
		cout << endl;
		return;
	}
	int tmp = -1;
	for (int x = 0; x < n; x++) {
		if (visited[x]==0&&tmp!=v[x]) {
			visited[x] = true;
			arr[cnt] = v[x];
			tmp = arr[cnt];
			abc(cnt+1);
			visited[x] = 0;               
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int x = 0; x < n; x++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	abc(0);
}
