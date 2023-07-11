#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
bool visited[8];
int v[8] = { 1,2,3,4,5,6,7,8 };
int arr[8];
void abc(int cnt) {
	if (cnt == n) {
		for (int x = 0; x < n; x++)
			cout << arr[x] << " ";
		cout << '\n';
		return;
	}
	for (int x = 0; x < n; x++) {
		if (!visited[x]) {
			visited[x] = true;
			arr[cnt] = v[x];
			abc(cnt + 1);
			visited[x] = 0;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	abc(0);
}
