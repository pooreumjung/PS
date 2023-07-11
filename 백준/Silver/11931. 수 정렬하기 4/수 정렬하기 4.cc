#include<iostream>
using namespace std;
int arr[1000000];
int func(const void* a, const void* b);
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);



	int n;
	cin >> n;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	qsort(arr, n, sizeof(int), func);
	for (int x = n - 1; x >= 0; x--)
		cout << arr[x] << "\n";
}
int func(const void* a, const void* b)
{
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	if (n1 < n2)
		return -1;
	else if (n1 > n2)
		return 1;
	else
		return 0;
}