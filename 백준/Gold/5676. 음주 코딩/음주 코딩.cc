#include<iostream>
#include<vector>
using namespace std;

int N, K;
vector<int>arr, tree;
int l, r, index, value,a;
char query;
int initTree(int start, int end, int node);
int updateTree(int start, int end, int node, int index, int value);
int findSum(int start, int end, int node, int l, int r);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> N >> K) {
		// 각 배열들 초기화 및 입력
		arr.resize(N);
		tree.resize(N * 4);
		for (int i = 0; i < N; i++) {
			cin >> a;
			if (a > 0)
				arr[i] = 1;
			else if (a == 0)
				arr[i] = 0;
			else
				arr[i] = -1;
		}
		// 세그먼트 트리 구현
		initTree(0, N - 1, 1);
		for (int i = 0; i < K; i++) {
			cin >> query;
			if (query == 'C') {
				cin >> index >> value;
				if (value > 0)
					value = 1;
				else if (value == 0)
					value = 0;
				else
					value = -1;
				updateTree(0, N - 1, 1, index - 1, value);
			}
			else {
				cin >> l >> r;
				int res = findSum(0, N - 1, 1, l - 1, r - 1);
				if (res == 1)
					cout << '+';
				else if (res == 0)
					cout << 0;
				else
					cout << '-';
			}

		}
		cout << '\n';
	}

}

int initTree(int start, int end, int node)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = initTree(start, mid, node * 2) * initTree(mid + 1, end, node * 2 + 1);
}

int updateTree(int start, int end, int node, int index, int value)
{
	if (index<start || index>end)
		return tree[node];
	if(start==end)
		return tree[node] = value;
	int mid = (start + end) / 2;
	return tree[node] = updateTree(start, mid, node * 2, index, value) * updateTree(mid + 1, end, node * 2 + 1, index, value);
}

int findSum(int start, int end, int node, int l, int r)
{
	if (l > end || r < start)
		return 1;
	if (l <= start && end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	return findSum(start, mid, node * 2, l, r) * findSum(mid + 1, end, node * 2 + 1, l, r);

}
