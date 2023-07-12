#include<iostream>
using namespace std;
int arr[2000001]; //기존의 데이터를 담을 추가 배열 생성
void merge(int a[], int m, int middle, int n);
void mergesort(int b[], int m, int n);
int arr2[2000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; x++)
		cin >> arr2[x];
	for (int x = 0; x < m; x++)
		cin >> arr2[x+n];
	mergesort(arr2, 0, n+m-1);
	for (int x = 0; x < n+m; x++)
		cout << arr2[x] << " ";

}
void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	//작은 순서대로 배열에 삽입
	while (i <= middle && j <= n) {
		if (a[i] < a[j]) {
			arr[k] = a[i];
			i++;
		}
		else {
			arr[k] = a[j];
			j++;
		}
		k++;
	}
	//남은 데이터도 삽입
	if (i > middle) {
		for (int x = j; x <= n; x++) {
			arr[k] = a[x];
			k++;
		}
	}
	else
		for (int x = i; x <= middle; x++) {
			arr[k] = a[x];
			k++;
		}
	//정렬된 배열을 삽입
	for (int x = m; x <= n; x++)
		a[x] = arr[x];
}
void mergesort(int b[], int m, int n) {
	//크기가 1보다 큰 경우
	if (m < n) {
		int middle = (m + n) / 2;
		mergesort(b, m, middle);
		mergesort(b, middle + 1, n);
		merge(b, m, middle, n);

	}
}
