#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(int argc, const char* argv[]) {
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		int k,dif=0;
		cin >> k;
		vector<int>arr(k);
		for (int x = 0; x < k; x++)
			cin >> arr[x];
		sort(arr.begin(), arr.end());
		for (int x = 1; x < k; x++) {
			if (arr[x] - arr[x - 1] > dif)
				dif = arr[x] - arr[x - 1];
		}
		cout << "Class " << x + 1 << "\n";
		cout << "Max " << arr[k-1] << ", Min " <<arr[0] << ", Largest gap " << dif << "\n";
	}
}