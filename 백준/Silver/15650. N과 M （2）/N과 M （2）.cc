#include<iostream>
using namespace std;
int arr[8] = { 1,2,3,4,5,6,7,8 };
int arr2[8];
int arr3[8];
int n, m;
void abc(int a,int b);
int main() {
	cin >> n >> m;
	abc(0,0);

}
void abc(int a,int b) {
	if (a == m) {
		for (int x = 0; x < m; x++)
			cout << arr2[x] << " ";
		cout << endl;
		return;
	}
	for (int x = b; x < n; x++) {
		arr2[a] = arr[x];
		abc(a + 1,x+1);
		arr2[a] = 0;
	}



}