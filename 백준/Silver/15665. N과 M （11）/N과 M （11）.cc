#include<iostream>
using namespace std;
int arr[9];
int arr2[9];
int arr3[9];
int direct[10000];
int n, m,cnt=0;
void abc(int a);
int compare(const void* a, const void* b);
int main() {
	cin >> n >> m;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	qsort(arr, n, sizeof(int), compare);
	int d = 0;
	for (int x = 0; x < n; x++) {
		int k = arr[x];
		direct[k]++;
	}
	for (int x = 0; x < 10000; x++) {
		if (direct[x] >= 1) {
			arr3[d] = x;
			d += 1;
		}
	}
	for (int x = 0; x < 9; x++) {
		if (arr3[x] >= 1)
			cnt++;
	}
	abc(0);

}
int compare(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	if (n1 > n2)
		return 1;
	if (n1 < n2)
		return -1;
	else
		return 0;

}
void abc(int a) {
	if (a == m) {
		for (int x = 0; x < m; x++) {
			cout << arr2[x] << " ";
		}
		cout << "\n";
		return;
	}
	for (int x = 0; x < cnt; x++) {
		arr2[a] = arr3[x];
		abc(a + 1);
		arr2[a] = 0;
	}



}