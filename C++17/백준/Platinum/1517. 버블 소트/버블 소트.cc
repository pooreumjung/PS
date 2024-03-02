#include<iostream>
#include<vector>
using namespace std;

static vector<int>A;
vector<int>temp;
void merge_sort(int start, int end);
static long result;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	A = vector<int>(N + 1, 0);
	temp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> A[i];
	result = 0;
	merge_sort(1, N);
	cout << result;
}
void merge_sort(int start, int end) {

	if (end - start < 1)
		return;

	int middle = start + (end - start) / 2;

	merge_sort(start, middle);
	merge_sort(middle + 1, end);

	for (int i = start; i <= end; i++)
		temp[i] = A[i];

	int index1 = start;
	int k = start;
	int index2 = middle+1;

	while (index1 <= middle && index2 <= end) {
		if (temp[index1] > temp[index2]) {
			A[k] = temp[index2];
			result = result + index2 - k;
			index2++;
			k++;
		}
		else {
			A[k] = temp[index1];
			index1++;
			k++;
		}
	}

	while (index1 <= middle) {
		A[k] = temp[index1];
		k++;
		index1++;
	}
	while (index2 <= end) {
		A[k] = temp[index2];
		k++;
		index2++;
	}
}