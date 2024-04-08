#include<iostream>
#include<vector>
using namespace std;
#define MAX 1000001

int N, M;
vector<long>tree, arr;
int initTree(int start, int end, int node);
void update(int start, int end, int node, int index, long value);
int findEvenSum(int start, int end, int node, int l, int r);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	arr.resize(N);
	tree.resize(MAX * 4);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] % 2 == 0)
			arr[i] = 1;
		else
			arr[i] = 0;
	}
	initTree(0, N - 1, 1);
	int query, index;
	long l, r, value;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> query;
		if (query == 1) {
			cin >> index >> value;
			int d = arr[index - 1];
			if (value % 2 == 0)
				arr[index - 1] = 1;
			else
				arr[index - 1] = 0;
			long diff = arr[index - 1] - d;
			update(0, N - 1, 1, index - 1, diff);
		}
		else if (query == 2) {
			cin >> l >> r;
			cout << findEvenSum(0, N - 1, 1, l - 1, r - 1) << '\n';
		}
		else {
			cin >> l >> r;
			int len = r - l + 1;
			cout << len - findEvenSum(0, N - 1, 1, l - 1, r - 1) << '\n';
		}
	}
}

int initTree(int start, int end, int node)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = initTree(start, mid, node * 2) + initTree(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int index, long value)
{
	if (index<start || index>end)
		return;
	tree[node] += value;
	if (start!=end) {
		int mid = (start + end) / 2;
		update(start, mid, node * 2, index, value);
		update(mid + 1, end, node * 2 + 1, index, value);
	}
}

int findEvenSum(int start, int end, int node, int l, int r)
{
	if (l > end || r < start)
		return 0;
	if (l <= start && end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	return findEvenSum(start, mid, node * 2, l, r) + findEvenSum(mid + 1, end, node * 2 + 1, l, r);
}
