#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>arr(9);
void find(int sum) {
	int index1, index2,sum2=sum;
	for (int x = 0; x < arr.size(); x++) {
		for (int y = x + 1; y < arr.size(); y++) {
			sum = sum2;
			sum -= arr[x];
			sum -= arr[y];
			if (sum == 100) {
				index1 = x;
				index2 = y;
				break;
			}
		}
	}
	for (int x = 0; x < arr.size(); x++) {
		if (x == index1 || x == index2)
			continue;
		else
			cout << arr[x] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sum = 0;
	for (int x = 0; x < arr.size(); x++) {
		cin >> arr[x];
		sum += arr[x];
	}
	sort(arr.begin(), arr.end());
	find(sum);
}