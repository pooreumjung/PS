#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
bool check[40];
bool check2[40];
bool check3[40];
int n,cnt1;
void func(int cur) {
	if (cur == n) {
		cnt1++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i] || check2[i + cur] || check3[cur - i + n - 1]) // 
			continue;
			check[i] = 1;
			check2[i + cur] = 1;
			check3[cur + -1 + n - i] = 1;
			func(cur + 1);
			check[i] = 0;
			check2[i + cur] = 0;
			check3[cur + -1 + n - i] = 0;
		
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	func(0);
	cout << cnt1;
}