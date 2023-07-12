#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	if (a < b)
		return true;
	else
		return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,k;
	cin >> n >> k;
	vector<int>arr(n);
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	sort(arr.begin(), arr.end(),cmp);
	cout << arr[k - 1];

}