#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int compare(int a, int b) {
	if (a < b)
		return 1;
	else return 0;
}
int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	sort(arr.begin(), arr.end(), compare);
	int temp = 0;
	for (int x = 0; x < n; x++) {
		if (arr[x] == temp)
			continue;
		cout << arr[x] << " ";
		temp = arr[x];
	}
}
