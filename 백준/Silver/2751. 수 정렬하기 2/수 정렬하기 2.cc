#include<iostream>
using namespace std;
int compare(const void* a, const void* b);
int main() {
	int n;
	cin >> n;
	int arr[n] = { 0 };
	
	for (int x = 0; x < n; x++) 
		cin>>arr[x];
	
	qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);
	for (int x = 0; x < n; x++)
		cout << arr[x] << "\n";
}
int compare(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	if (n1 > n2)
		return 1;
	if (n1 < n2)
		return -1;
	return 0;

}