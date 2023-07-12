#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
int arr[30];
int n,m,cnt1;
void func(int cur,int sum) {
	if (cur == n) {
		if (sum == m)
			cnt1++;
		return;
	}
	func(cur + 1, sum);
	func(cur + 1, sum + arr[cur]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n>>m;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	func(0,0);
	if (m == 0)
		cnt1--;
	cout << cnt1;
}